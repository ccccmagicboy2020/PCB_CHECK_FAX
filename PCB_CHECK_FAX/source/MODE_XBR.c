//=============================================================================
//公司名称：深圳市
//文件名称：MODE_XBR.c
//功能概要：MODE_XBR驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#include "INCLUDE_EXT.h"
#include "MODE_XBR.h"


unsigned char XBR_WR = 0;//写数据成功标志，写数据前清除

XBR_PARA  Xbr_Para;


//=============================================================================
//文件名称：void MODE_XBR_Send(unsigned char Cmd)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void MODE_XBR_Send(unsigned char Cmd)
{

	switch(Cmd)
	{
	case PACKET_CMD_GET:
		//读取雷达模组实时数据
		TxBuffer_1[0] = PACKET_HEADER_BYTE1;
		TxBuffer_1[1] = PACKET_HEADER_BYTE2;
		TxBuffer_1[2] = 6;
		TxBuffer_1[3] = PACKET_CMD_GET;
		TxBuffer_1[14] = PACKET_TAIL_BYTE1;
		TxBuffer_1[15] = PACKET_TAIL_BYTE2;
		TxLen_1 = 6;
		
		Usart1_send(TxBuffer_1,TxLen_1);
	break;
	case PACKET_CMD_SET:
		//发送让模组进入测试状态命令
		TxBuffer_1[0] = PACKET_HEADER_BYTE1;
		TxBuffer_1[1] = PACKET_HEADER_BYTE2;
		TxBuffer_1[2] = 17;
		TxBuffer_1[3] = PACKET_CMD_SET;
		TxBuffer_1[4] = (Para.XBR_TH >> 16) & 0xFF;
		TxBuffer_1[5] = (Para.XBR_TH >> 8) & 0xFF;
		TxBuffer_1[6] = Para.XBR_TH & 0xFF;
		TxBuffer_1[7] = Para.XBR_LIGHT_TH & 0xFF;
		TxBuffer_1[8] = (Para.XBR_DELAY_NUM >> 8) & 0xFF;
		TxBuffer_1[9] = Para.XBR_DELAY_NUM & 0xFF;
		TxBuffer_1[10] = (Para.XBR_ID >> 24) & 0xFF;
		TxBuffer_1[11] = (Para.XBR_ID >> 16) & 0xFF;
		TxBuffer_1[12] = (Para.XBR_ID >> 8) & 0xFF;
		TxBuffer_1[13] = Para.XBR_ID & 0xFF;
		TxBuffer_1[14] = 1;//测试标志位
		TxBuffer_1[15] = PACKET_TAIL_BYTE1;
		TxBuffer_1[16] = PACKET_TAIL_BYTE2;
		TxLen_1 = 17;
		
		Usart1_send(TxBuffer_1,TxLen_1);
		break;

	case 3:
		//转发PC机命令
		memcpy(TxBuffer_1,CmdBuffer_2,CmdBuffer_2[2]);
		TxLen_1 = CmdBuffer_2[2];
		Usart1_send(TxBuffer_1,TxLen_1);
		
		//for(i=0;i<TxBuffer_1[2];i++)printf("TxBuffer_1[%d] = 0x%x\r\n",i,TxBuffer_1[i]);
			
		break;
	case 4:
		memcpy(TxBuffer_1,CmdBuffer_2,CmdBuffer_2[2]);
		TxLen_1 = CmdBuffer_2[2];
		Usart1_send(TxBuffer_1,TxLen_1);
		//for(i=0;i<TxBuffer_1[2];i++)printf("TxBuffer_1[%d] = 0x%x\r\n",i,TxBuffer_1[i]);
		break;
	case 5:
		break;
	case 7:
			if(O_OUT_READ() != 0)
			{
				printf("模块输出为高\r\n");
			}
			else
			{
				printf("模块输出为低\r\n");
			}
		break;

	default:break;
	}

}

//=============================================================================
//文件名称：void MODE_XBR201_Poll(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void MODE_XBR_Poll(void)
{

	float temp = 0;

	if(ReceiveFlag_1 != 0)
	{
		ReceiveFlag_1 = 0;
		/*
		for(i=0;i<CmdBuffer_1[2];i++)
			printf("CmdBuffer_1[%d] = 0x%x\r\n",i,CmdBuffer_1[i]);
			*/
		switch(CmdBuffer_1[3])
		{
			case PACKET_CMD_SET:
				//printf("写入数据成功\r\n");
				printf("Write configtion is ok\r\n");
				memcpy(TxBuffer_2,CmdBuffer_1,CmdBuffer_1[2]);
				TxLen_2 = CmdBuffer_1[2];
				Usart2_send(TxBuffer_2,TxLen_2);

				break;
			case PACKET_CMD_GET:
				//printf("读取数据成功\r\n");
				printf("Read configtion is ok\r\n");
				memset(&Xbr_Para, 0, sizeof(Xbr_Para));
			
				Xbr_Para.XBR_VERSION = CmdBuffer_1[4];
				
				Xbr_Para.XBR_TH = CmdBuffer_1[5];
				Xbr_Para.XBR_TH = Xbr_Para.XBR_TH << 8; 
				Xbr_Para.XBR_TH |= CmdBuffer_1[6];
				Xbr_Para.XBR_TH = Xbr_Para.XBR_TH << 8; 
				Xbr_Para.XBR_TH |= CmdBuffer_1[7];
				
				Xbr_Para.XBR_LIGHT_TH = CmdBuffer_1[8];
				
				Xbr_Para.XBR_DELAY_NUM = CmdBuffer_1[9];
				Xbr_Para.XBR_DELAY_NUM = Xbr_Para.XBR_DELAY_NUM << 8;
				Xbr_Para.XBR_DELAY_NUM |= CmdBuffer_1[10];
			
				Xbr_Para.XBR_ID = CmdBuffer_1[11];
				Xbr_Para.XBR_ID = Xbr_Para.XBR_ID << 8;
				Xbr_Para.XBR_ID |= CmdBuffer_1[12];
				Xbr_Para.XBR_ID = Xbr_Para.XBR_ID << 8;
				Xbr_Para.XBR_ID |= CmdBuffer_1[13];
				Xbr_Para.XBR_ID = Xbr_Para.XBR_ID << 8;
				Xbr_Para.XBR_ID |= CmdBuffer_1[14];
				
				Xbr_Para.XBR_LIGHT_AD = CmdBuffer_1[15];
				
				Xbr_Para.XBR_AVERAGE = CmdBuffer_1[16]<<2;
			
				Xbr_Para.XBR_SUM0 = CmdBuffer_1[17];
				Xbr_Para.XBR_SUM0 = Xbr_Para.XBR_SUM0 << 6;
				Xbr_Para.XBR_SUM0 |= CmdBuffer_1[18];
				Xbr_Para.XBR_SUM0 = Xbr_Para.XBR_SUM0 << 8;
			
				Xbr_Para.XBR_SUM2 = CmdBuffer_1[19];
				Xbr_Para.XBR_SUM2 = Xbr_Para.XBR_SUM0 << 6;
				Xbr_Para.XBR_SUM2 |= CmdBuffer_1[20];
				Xbr_Para.XBR_SUM2 = Xbr_Para.XBR_SUM0 << 8;

				printf("XBR_ID = %d\r\n",Xbr_Para.XBR_ID);
				printf("XBR_CHECKSUM = 0x%x\r\n",Xbr_Para.XBR_CHECKSUM);
				
				memcpy(TxBuffer_2,CmdBuffer_1,CmdBuffer_1[2]);
				TxLen_2 = CmdBuffer_1[2];
				Usart2_send(TxBuffer_2,TxLen_2);
			
				break;
			case PACKET_CMD_START:
				//printf("模块起动\r\n");
				printf("Mode runing\r\n");
				memcpy(TxBuffer_2,CmdBuffer_1,CmdBuffer_1[2]);
				TxLen_2 = CmdBuffer_1[2];
				Usart2_send(TxBuffer_2,TxLen_2);
				break;
			case PACKET_CMD_LIGHTON:
				//printf("引脚输出为高\r\n");
				printf("PINOUT is hight\r\n");
				memcpy(TxBuffer_2,CmdBuffer_1,CmdBuffer_1[2]);
				TxLen_2 = CmdBuffer_1[2];
				Usart2_send(TxBuffer_2,TxLen_2);
				break;
			case PACKET_CMD_LIGHTOFF:
				//printf("引脚输出为低\r\n");
				printf("PINOUT is low\r\n");
				memcpy(TxBuffer_2,CmdBuffer_1,CmdBuffer_1[2]);
				TxLen_2 = CmdBuffer_1[2];
				Usart2_send(TxBuffer_2,TxLen_2);
				break;
			case PACKET_CMD_MODETEST:
				printf("mode testint\r\n");
				memcpy(TxBuffer_2,CmdBuffer_1,CmdBuffer_1[2]);
				TxLen_2 = CmdBuffer_1[2];
				Usart2_send(TxBuffer_2,TxLen_2);
				break;
			default:break;

		}
		
	}



	if(ReceiveFlag_2 != 0)
	{
		ReceiveFlag_2 = 0;
		/*
		for(i=0;i<CmdBuffer_2[2];i++)
			printf("CmdBuffer_2[%d] = 0x%x\r\n",i,CmdBuffer_2[i]);*/
		switch(CmdBuffer_2[3])
		{
			//重置测试
			case PACKET_CMD_REASTAT:
				printf("ReStart Test!\r\n");
				KEY3_DOWN = 1;
				break;

			case PACKET_CMD_GET:
				MODE_XBR_Send(3);
				break;
			case PACKET_CMD_SELECT:
				St = CmdBuffer_2[4];
				break;
			case PACKET_CMD_SET:
				
				Para.XBR_TH = CmdBuffer_2[4];
				Para.XBR_TH = Para.XBR_TH << 8; 
				Para.XBR_TH |= CmdBuffer_2[5];
				Para.XBR_TH = Para.XBR_TH << 8; 
				Para.XBR_TH |= CmdBuffer_2[6];
				
				Para.XBR_LIGHT_TH = CmdBuffer_2[7];
				
				Para.XBR_DELAY_NUM = CmdBuffer_2[8];
				Para.XBR_DELAY_NUM = Para.XBR_DELAY_NUM << 8;
				Para.XBR_DELAY_NUM |= CmdBuffer_2[9];

				Para.XBR_ID = CmdBuffer_2[10];
				Para.XBR_ID = Para.XBR_ID << 8;
				Para.XBR_ID |= CmdBuffer_2[11];
				Para.XBR_ID = Para.XBR_ID << 8;
				Para.XBR_ID |= CmdBuffer_2[12];
				Para.XBR_ID = Para.XBR_ID << 8;
				Para.XBR_ID |= CmdBuffer_2[13];

				Para.XBR_STATUS = CmdBuffer_2[14];
				printf("XBR_TH = %d \r\n", Para.XBR_TH);
				printf("XBR_LIGHT_TH = %d \r\n", Para.XBR_LIGHT_TH);
				printf("XBR_DELAY_NUM = %d \r\n", Para.XBR_DELAY_NUM);
				printf("XBR_ID = %d \r\n", Para.XBR_ID);
				printf("XBR_STATUS = %d \r\n", Para.XBR_STATUS);
				MODE_XBR_Send(3);//
				break;

			case PACKET_CMD_RECOVERYPARA:
				ParaRecovery();
				printf("Recovery factory successfully!\r\n");
				break;

			case PACKET_CMD_SETPARA:
				GLOBAL_Module_Set(CmdBuffer_2[4]);

				if(CmdBuffer_2[4] == 0)
				{
					Para.MODE_Select = CmdBuffer_2[4];//测试105模组
					printf("Para.MODE_Select = %d \r\n", Para.MODE_Select);
					//105
					temp = CmdBuffer_2[5];
					temp = temp / 1000;
					//printf("temp = %f \r\n", temp);
					temp = (((temp * 4096) / 3.3) * 0.2 * 100);
					Para.Current_AdMin_105 = (unsigned int)temp;
					//printf("Para.Current_AdMin_105 = %x \r\n", Para.Current_AdMin_105);
					
					temp = CmdBuffer_2[6];
					temp = temp / 1000;
					//printf("temp = %f \r\n", temp);
					temp = (((temp * 4096) / 3.3) * 0.2 * 100);
					Para.Current_AdMax_105 = (unsigned int)temp;
					
					temp = CmdBuffer_2[7];
					temp = temp / 1000;
					//printf("temp = %f \r\n", temp);
					temp = (((temp * 4096) / 3.3) * 0.2 * 100);
					Para.Current_Short_105 = (unsigned int)temp;
					
					temp = CmdBuffer_2[8];
					temp = temp / 100;
					//printf("temp = %f \r\n", temp);
					temp = ((temp * 4096) / 3.3);
					Para.V_1V_AdMin_105 = (unsigned int)temp;
					//printf("Para.V_1V_AdMin_105 = %x \r\n", Para.V_1V_AdMin_105);
					
					temp = CmdBuffer_2[9];
					temp = temp / 100;
					//printf("temp = %f \r\n", temp);
					temp = ((temp * 4096) / 3.3);
					Para.V_1V_AdMax_105 = (unsigned int)temp;
					
					temp = CmdBuffer_2[10];
					temp = temp / 100;
					//printf("temp = %f \r\n", temp);
					temp = ((temp * 4096) / 3.3);
					Para.V_3V_AdMin_105 = (unsigned int)temp;
					
					temp = CmdBuffer_2[11];
					temp = temp / 100;
					//printf("temp = %f \r\n", temp);
					temp = ((temp * 4096) / 3.3);
					Para.V_3V_AdMax_105 = (unsigned int)temp;
					
					Para.LIGHT_AdMin = (unsigned int)CmdBuffer_2[12];
					//printf("Para.LIGHT_AdMin = %d \r\n", Para.LIGHT_AdMin);
					Para.LIGHT_AdMax = (unsigned int)CmdBuffer_2[13];
					//printf("Para.LIGHT_AdMax = %d \r\n", Para.LIGHT_AdMax);
					Para.LIGHT_AdMax_Delta_Percent = (unsigned int)LIGHT_AD_MAX_DELTA_PERCENT_0;

					//运动时积分量-无运动时积分量
					Para.SUM_Sub = (unsigned int)CmdBuffer_2[14];
					Para.SUM_Sub = Para.SUM_Sub << 8;
					Para.SUM_Sub |= (unsigned int)CmdBuffer_2[15];
					Para.SUM_Sub = Para.SUM_Sub << 8;
					Para.SUM_Sub |= (unsigned int)CmdBuffer_2[16];
					Para.SUM_Sub = Para.SUM_Sub << 8;
					Para.SUM_Sub |= (unsigned int)CmdBuffer_2[17];
					//printf("Para.SUM_Sub = %d \r\n", Para.SUM_Sub);

					Para.XBR_PE = (unsigned int)CmdBuffer_2[18];
					Para.XBR_FUN = (unsigned int)CmdBuffer_2[19];
					Para.XBR_DL = (unsigned int)CmdBuffer_2[20];
					printf("Para.XBR_PE = %d \r\n", Para.XBR_PE);
					printf("Para.XBR_FUN = %d \r\n", Para.XBR_FUN);
					printf("Para.XBR_DL = %d \r\n", Para.XBR_DL);
					//模组波特率
					Para.BaudRate = (unsigned int)CmdBuffer_2[21];
					Para.BaudRate = Para.BaudRate << 8;
					Para.BaudRate |= (unsigned int)CmdBuffer_2[22];
					Para.BaudRate = Para.BaudRate << 8;
					Para.BaudRate |= (unsigned int)CmdBuffer_2[23];
					Para.BaudRate = Para.BaudRate << 8;
					Para.BaudRate |= (unsigned int)CmdBuffer_2[24];
					//模组波特率
					GLOBAL_USART1_Set(Para.BaudRate);
					printf("Para.BaudRate = %d \r\n", Para.BaudRate);
					
					//公共参数
					Para.V_3V_AdMax0 = 0;
					Para.V_3V_AdMin0 = 0;
					
					Para.V_3V_AdMax1 = 0;
					Para.V_3V_AdMin1 = 0;
					
					Para.SUM0_Max = 0;
					Para.SUM0_Min = 0;
					
					Para.SUM1_Max = 0;
					Para.SUM1_Min = 0;

					//运动时积分量-无运动时积分量
					//Para.SUM_Sub = (unsigned int)SUM_SUB;
					
					Para.TH_Max = (unsigned int)TH_MAX_0;
					Para.TH_Min = (unsigned int)TH_MIN_0;
					
					Para.Average_Max = (unsigned int)AVERAGE_MAX_0;
					Para.Average_Min = (unsigned int)AVERAGE_MIN_0;

					
					Para.led_data = 0;
					datmag.flashwrite = 0xAA;
					ParaWrite();
				}
				else if((CmdBuffer_2[4] == 1) | (CmdBuffer_2[4] == 2) | (CmdBuffer_2[4] == 3))
				{
					Para.MODE_Select = CmdBuffer_2[4];//测试201模组
					printf("Para.MODE_Select = %d \r\n", Para.MODE_Select);
					//201
					temp = CmdBuffer_2[5];
					temp = temp / 1000;
					//printf("temp = %f \r\n", temp);
					temp = (((temp * 4096) / 3.3) * 0.2 * 100);
					Para.Current_AdMin_201 = (unsigned int)temp;
					//printf("Para.Current_AdMin_201 = %x \r\n", Para.Current_AdMin_201);

					temp = CmdBuffer_2[6];
					temp = temp / 1000;
					//printf("temp = %f \r\n", temp);
					temp = (((temp * 4096) / 3.3) * 0.2 * 100);
					Para.Current_AdMax_201 = (unsigned int)temp;
					
					temp = CmdBuffer_2[7];
					temp = temp / 1000;
					//printf("temp = %f \r\n", temp);
					temp = (((temp * 4096) / 3.3) * 0.2 * 100);
					Para.Current_Short_201 = (unsigned int)temp;

					temp = CmdBuffer_2[8];
					temp = temp / 100;
					//printf("temp = %f \r\n", temp);
					temp = ((temp * 4096) / 3.3);
					Para.V_1V_AdMin_201 = (unsigned int)temp;
					//printf("Para.V_1V_AdMin_201 = %x \r\n", Para.V_1V_AdMin_201);

					temp = CmdBuffer_2[9];
					temp = temp / 100;
					//printf("temp = %f \r\n", temp);
					temp = ((temp * 4096) / 3.3);
					Para.V_1V_AdMax_201 = (unsigned int)temp;

					temp = CmdBuffer_2[10];
					temp = temp / 100;
					//printf("temp = %f \r\n", temp);
					temp = ((temp * 4096) / 3.3);
					Para.V_3V_AdMin_201 = (unsigned int)temp;
					
					temp = CmdBuffer_2[11];
					temp = temp / 100;
					//printf("temp = %f \r\n", temp);
					temp = ((temp * 4096) / 3.3);
					Para.V_3V_AdMax_201 = (unsigned int)temp;

					Para.LIGHT_AdMin = (unsigned int)CmdBuffer_2[12];
					//printf("Para.LIGHT_AdMin = %d \r\n", Para.LIGHT_AdMin);
					Para.LIGHT_AdMax = (unsigned int)CmdBuffer_2[13];
					//printf("Para.LIGHT_AdMax = %d \r\n", Para.LIGHT_AdMax);
					Para.LIGHT_AdMax_Delta_Percent = (unsigned int)LIGHT_AD_MAX_DELTA_PERCENT_0;

					//运动时积分量-无运动时积分量
					Para.SUM_Sub = (unsigned int)CmdBuffer_2[14];
					Para.SUM_Sub = Para.SUM_Sub << 8;
					Para.SUM_Sub |= (unsigned int)CmdBuffer_2[15];
					Para.SUM_Sub = Para.SUM_Sub << 8;
					Para.SUM_Sub |= (unsigned int)CmdBuffer_2[16];
					Para.SUM_Sub = Para.SUM_Sub << 8;
					Para.SUM_Sub |= (unsigned int)CmdBuffer_2[17];
					//printf("Para.SUM_Sub = %d \r\n", Para.SUM_Sub);

					Para.XBR_PE = (unsigned int)CmdBuffer_2[18];
					Para.XBR_FUN = (unsigned int)CmdBuffer_2[19];
					Para.XBR_DL = (unsigned int)CmdBuffer_2[20];
					printf("Para.XBR_PE = %d \r\n", Para.XBR_PE);
					printf("Para.XBR_FUN = %d \r\n", Para.XBR_FUN);
					printf("Para.XBR_DL = %d \r\n", Para.XBR_DL);
					//模组波特率
					Para.BaudRate = (unsigned int)CmdBuffer_2[21];
					Para.BaudRate = Para.BaudRate << 8;
					Para.BaudRate |= (unsigned int)CmdBuffer_2[22];
					Para.BaudRate = Para.BaudRate << 8;
					Para.BaudRate |= (unsigned int)CmdBuffer_2[23];
					Para.BaudRate = Para.BaudRate << 8;
					Para.BaudRate |= (unsigned int)CmdBuffer_2[24];
					//模组波特率
					GLOBAL_USART1_Set(Para.BaudRate);
					printf("Para.BaudRate = %d \r\n", Para.BaudRate);

					//公共参数
					Para.V_3V_AdMax0 = 0;
					Para.V_3V_AdMin0 = 0;
					
					Para.V_3V_AdMax1 = 0;
					Para.V_3V_AdMin1 = 0;
					
					Para.SUM0_Max = 0;
					Para.SUM0_Min = 0;
					
					Para.SUM1_Max = 0;
					Para.SUM1_Min = 0;

					//运动时积分量-无运动时积分量
					//Para.SUM_Sub = (unsigned int)SUM_SUB;
					
					Para.TH_Max = (unsigned int)TH_MAX_0;
					Para.TH_Min = (unsigned int)TH_MIN_0;
					
					Para.Average_Max = (unsigned int)AVERAGE_MAX_0;
					Para.Average_Min = (unsigned int)AVERAGE_MIN_0;

					Para.led_data = 0;
					datmag.flashwrite = 0xAA;
					ParaWrite();

				}
				break;
			case PACKET_CMD_GETPARA:

				memcpy(TxBuffer_2,CmdBuffer_2,CmdBuffer_2[2]);
				ParaRead();
				GLOBAL_Module_Set(Para.MODE_Select);
				if(CmdBuffer_2[4] == 0)
				{
					printf("Para.MODE_Select = %d \r\n", Para.MODE_Select);
					temp = Para.Current_AdMin_105;
					//printf("temp = %f \r\n", temp);
					temp = temp / 24.7857;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[5] = (unsigned char)(temp);
					
					temp = Para.Current_AdMax_105;
					temp = temp / 24.7857;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[6] = (unsigned char)(temp);
					
					temp = Para.Current_Short_105;
					temp = temp / 24.7857;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[7] = (unsigned char)(temp);
					
					temp = Para.V_1V_AdMin_105;
					//printf("temp = %f \r\n", temp);
					temp = temp / 12.4090;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[8] = (unsigned char)(temp);
					
					temp = Para.V_1V_AdMax_105;
					temp = temp / 12.4090;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[9] = (unsigned char)(temp);
					
					temp = Para.V_3V_AdMin_105;
					temp = temp / 12.4090;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[10] = (unsigned char)(temp);
					
					temp = Para.V_3V_AdMax_105;
					temp = temp / 12.4090;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[11] = (unsigned char)(temp);
					
					TxBuffer_2[12] = Para.LIGHT_AdMin;
					//printf("Para.LIGHT_AdMin_105 = %d \r\n", Para.LIGHT_AdMin_105);
					TxBuffer_2[13] = Para.LIGHT_AdMax;
					//printf("Para.LIGHT_AdMax_105 = %d \r\n", Para.LIGHT_AdMax_105);

					TxBuffer_2[14] = (Para.SUM_Sub >> 24) & 0xFF;
					TxBuffer_2[15] = (Para.SUM_Sub >> 16) & 0xFF;
					TxBuffer_2[16] = (Para.SUM_Sub >> 8) & 0xFF;
					TxBuffer_2[17] = (Para.SUM_Sub >> 0) & 0xFF;
					//printf("Para.SUM_Sub_105 = %d \r\n", Para.SUM_Sub_105);

					TxBuffer_2[18] = Para.XBR_PE & 0xFF;
					TxBuffer_2[19] = Para.XBR_FUN & 0xFF;
					TxBuffer_2[20] = Para.XBR_DL & 0xFF;
					printf("Para.XBR_PE = %d \r\n", Para.XBR_PE);
					printf("Para.XBR_FUN = %d \r\n", Para.XBR_FUN);
					printf("Para.XBR_DL = %d \r\n", Para.XBR_DL);

					//模组波特率
					TxBuffer_2[21] = (Para.BaudRate >> 24) & 0xFF;
					TxBuffer_2[22] = (Para.BaudRate >> 16) & 0xFF;
					TxBuffer_2[23] = (Para.BaudRate >> 8) & 0xFF;
					TxBuffer_2[24] = (Para.BaudRate >> 0) & 0xFF;
					printf("Para.BaudRate = %d \r\n", Para.BaudRate);

					TxLen_2 = TxBuffer_2[2];
					Usart2_send(TxBuffer_2,TxLen_2);

				}
				else if((CmdBuffer_2[4] == 1) | (CmdBuffer_2[4] == 2) | (CmdBuffer_2[4] == 3))
				{
					printf("Para.MODE_Select = %d \r\n", Para.MODE_Select);
					temp = Para.Current_AdMin_201;
					//printf("temp = %f \r\n", temp);
					temp = temp / 24.7857;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[5] = (unsigned char)(temp);
					
					temp = Para.Current_AdMax_201;
					temp = temp / 24.7857;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[6] = (unsigned char)(temp);
					
					temp = Para.Current_Short_201;
					temp = temp / 24.7857;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[7] = (unsigned char)(temp);
					
					temp = Para.V_1V_AdMin_201;
					//printf("temp = %f \r\n", temp);
					temp = temp / 12.4090;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[8] = (unsigned char)(temp);
					
					temp = Para.V_1V_AdMax_201;
					temp = temp / 12.4090;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[9] = (unsigned char)(temp);
					
					temp = Para.V_3V_AdMin_201;
					temp = temp / 12.4090;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[10] = (unsigned char)(temp);

					temp = Para.V_3V_AdMax_201;
					temp = temp / 12.4090;
					//printf("temp = %f \r\n", temp);
					temp = temp + 0.5;
					TxBuffer_2[11] = (unsigned char)(temp);

					TxBuffer_2[12] = Para.LIGHT_AdMin;
					//printf("Para.LIGHT_AdMin = %d \r\n", Para.LIGHT_AdMin);
					TxBuffer_2[13] = Para.LIGHT_AdMax;
					//printf("Para.LIGHT_AdMax = %d \r\n", Para.LIGHT_AdMax);

					TxBuffer_2[14] = (Para.SUM_Sub >> 24) & 0xFF;
					TxBuffer_2[15] = (Para.SUM_Sub >> 16) & 0xFF;
					TxBuffer_2[16] = (Para.SUM_Sub >> 8) & 0xFF;
					TxBuffer_2[17] = (Para.SUM_Sub >> 0) & 0xFF;
					//printf("Para.SUM_Sub = %d \r\n", Para.SUM_Sub);

					TxBuffer_2[18] = Para.XBR_PE & 0xFF;
					TxBuffer_2[19] = Para.XBR_FUN & 0xFF;
					TxBuffer_2[20] = Para.XBR_DL & 0xFF;
					printf("Para.XBR_PE = %d \r\n", Para.XBR_PE);
					printf("Para.XBR_FUN = %d \r\n", Para.XBR_FUN);
					printf("Para.XBR_DL = %d \r\n", Para.XBR_DL);

					//模组波特率
					TxBuffer_2[21] = (Para.BaudRate >> 24) & 0xFF;
					TxBuffer_2[22] = (Para.BaudRate >> 16) & 0xFF;
					TxBuffer_2[23] = (Para.BaudRate >> 8) & 0xFF;
					TxBuffer_2[24] = (Para.BaudRate >> 0) & 0xFF;
					printf("Para.BaudRate = %d \r\n", Para.BaudRate);

					TxLen_2 = TxBuffer_2[2];
					Usart2_send(TxBuffer_2,TxLen_2);
				}

				break;

			default:

				if(ReceiveFlag_2 != 0)
				{
					ReceiveFlag_2 = 0;
					//
					printf("Len:0x%x\r\n",CmdBuffer_2[2]);
					printf("Version:0x%x\r\n",CmdBuffer_2[3]);
					printf("TH:0x%x\r\n",CmdBuffer_2[4]);
					printf("TH_LOW:0x%x\r\n",CmdBuffer_2[5]);
					printf("light_ad:0x%x\r\n",CmdBuffer_2[6]);
					printf("average:0x%x\r\n",CmdBuffer_2[7]);
					printf("SUM0 H:0x%x\r\n",CmdBuffer_2[8]);
					printf("SUM0 L:0x%x\r\n",CmdBuffer_2[9]);
					printf("SUM1 H:0x%x\r\n",CmdBuffer_2[10]);
					printf("SUM1 L:0x%x\r\n",CmdBuffer_2[11]);
					printf("CHECK L:0x%x\r\n",CmdBuffer_2[12]);
			
				}

				break;
		}
		
	}

}

