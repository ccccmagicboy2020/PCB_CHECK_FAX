//=============================================================================
//公司名称：深圳市
//文件名称：MODE_XBR201.c
//功能概要：MODE_XBR201驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#include "INCLUDE_EXT.h"
#include "MODE_XBR201.h"






//=============================================================================
//文件名称：void MODE_XBR201(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void MODE_XBR201(void)
{

		Mode_Sate = 0xFFFF;
		LED_HC595_Set(Mode_Sate);
		
		BEEP_Start(100);
		BEEP_Wait();

		MODE_XBR201_Clear();
		HC595_Set_Power1(0xff);
		HC595_Set_Power2(0xff);
		
		//printf(str_start);
		printf("\r\n");

		delay_ms(1000);
		Mode_Sate = 0x0000;
		LED_HC595_Set(Mode_Sate);

		//__disable_irq();//关
		//
		MX_ADC1_Init();
		HAL_ADC_Start(&hadc1);
		HAL_ADCEx_Calibration_Start(&hadc1);//校准
		//delay_ms(8000);
		delay_ms(3000);
		delay_ms(7000);
		Mode_Sate = 0;

		//性能测试
		if(Para.XBR_PE == TRUE)
		{
			//读取16个灯控板上电后的电流、3V电压、1.2V电压、上电后输出状态
			for(i=0;i<4;i++)	//列循环
			{
				HC4052A_Set_ColAB(i);
				
				for(j=0;j<4;j++)	//单列中依次检测4个灯控板
				{
					HC4052A_Set_RowAB(j);

					Get_Adc_Average_All(1000);

					pcb_check_info[i][j].Current = ADC_Value[0];
					pcb_check_info[i][j].V_1V = ADC_Value[1];
					pcb_check_info[i][j].V_AD = ADC_Value[2];
	/*
					printf("模块号：%d\r\n",i*4+j+1);
					printf("电流值：%fmA\r\n",(float)((pcb_check_info[i][j].Current&0xFFF)*3.3/4096)/0.2/100 * 1000);
					printf("1.2V电压值：%fV\r\n",(float)(pcb_check_info[i][j].V_1V&0xFFF)*3.3/4096);
					printf("3.2V电压值：%fV\r\n",(float)(pcb_check_info[i][j].V_AD&0xFFF)*3.3/4096 * 2);
					*/
					printf("mode:%d\r\n",i*4+j+1);
					printf("I:%fmA\r\n",(float)((pcb_check_info[i][j].Current&0xFFF)*3.3/4096)/0.2/100 * 1000);
					printf("1.2V:%fV\r\n",(float)(pcb_check_info[i][j].V_1V&0xFFF)*3.3/4096);
					printf("3.2V:%fV\r\n",(float)(pcb_check_info[i][j].V_AD&0xFFF)*3.3/4096 * 2);
					pcb_check_info[i][j].errCode = 0;

					if(pcb_check_info[i][j].Current > Para.Current_AdMax_201)
					{
						//判断电流是否过大，确定为短路状态
						if(pcb_check_info[i][j].Current > Para.Current_Short_201)
						{
							//printf("模块号：%d短路，请断电\r\n",i*4+j+1);
							printf("mode:%d short,power dowm\r\n",i*4+j+1);
							pcb_check_info[i][j].out_st=1;
							pcb_check_info[i][j].errCode |= 0x01;
						}
						//printf("电流值超上限\r\n");
						printf("The current exceeds the upper limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x02;
					}

					if(pcb_check_info[i][j].Current < Para.Current_AdMin_201)
					{
						//printf("电流值超下限\r\n");
						printf("Current beyond lower limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x04;
					}

					if(pcb_check_info[i][j].V_1V > Para.V_1V_AdMax_201 )
					{
						//printf("1.2V电压值超上限\r\n");
						printf("1.2v beyond upper limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x08;
					}
					if(pcb_check_info[i][j].V_1V < Para.V_1V_AdMin_201)
					{
						//printf("1.2V电压值超下限\r\n");
						printf("1.2V beyond the lower limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x10;
					}

					if(pcb_check_info[i][j].V_AD > Para.V_3V_AdMax_201 )
					{
						//printf("3.2V电压值超上限\r\n");
						printf("3.2v beyond upper limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x20;
					}

					if(pcb_check_info[i][j].V_AD < Para.V_3V_AdMin_201)
					{
						//printf("3.2V电压值超下限\r\n");
						printf("3.2V beyond the lower limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x40;
					}

					//最电流最大最小值
					if(Current_AdMax < pcb_check_info[i][j].Current)
					{
						Current_AdMax = pcb_check_info[i][j].Current&0xFFF;
					}
					if(Current_AdMin > pcb_check_info[i][j].Current)
					{
						Current_AdMin = pcb_check_info[i][j].Current&0xFFF;
					}
					//取1.2V最大最小值
					if(V_1V_AdMax < pcb_check_info[i][j].V_1V)
					{
						V_1V_AdMax = pcb_check_info[i][j].V_1V&0xFFF;
					}
					if(V_1V_AdMin > pcb_check_info[i][j].V_1V)
					{
						V_1V_AdMin = pcb_check_info[i][j].V_1V&0xFFF;
					}
					//取3V最大最小值
					if(V_3V_AdMax < pcb_check_info[i][j].V_AD)
					{
						V_3V_AdMax = pcb_check_info[i][j].V_AD&0xFFF;
					}
					if(V_3V_AdMin > pcb_check_info[i][j].V_AD)
					{
						V_3V_AdMin = pcb_check_info[i][j].V_AD&0xFFF;
					}
					
					/////////////////////////////////
					if(Para.XBR_FUN == TRUE)
					{
						//配置模组测试参数
						for(m=0;m<4;m++)
						{
							MODE_XBR_Send(PACKET_CMD_SET);
							delay_ms(100);
							if(XBR_WR != 0)break;
						}
						if(m>=3)
						{
							printf("Configuration failed\r\n");
							pcb_check_info[i][j].out_st=1;
							pcb_check_info[i][j].errCode |= 0x80;
						}
						XBR_WR = 0;
					}
					else
					{
						//保存模块状态，并显示错误模块
						if(pcb_check_info[i][j].out_st != 0)
						{
							Mode_Sate |= (0x01 << (i * 4 + j));
						}
					}

					//////////////////////////////

				}
			}
	/*
			printf("Current_AdMax = 0x%x\r\n",Current_AdMax);
			printf("Current_AdMin = 0x%x\r\n",Current_AdMin);
			printf("V_1V_AdMax = 0x%x\r\n",V_1V_AdMax);
			printf("V_1V_AdMin = 0x%x\r\n",V_1V_AdMin);
			printf("V_3V_AdMax = 0x%x\r\n",V_3V_AdMax);
			printf("V_3V_AdMin = 0x%x\r\n",V_3V_AdMin);

			printf("最大电流值：%fV\r\n",(float)((Current_AdMax&0xFFF)*3.3/4096)/0.2/100);
			printf("最小电流值：%fV\r\n",(float)((Current_AdMin&0xFFF)*3.3/4096)/0.2/100);

			printf("最大1V电压值：%fV\r\n",(float)(V_1V_AdMax&0xFFF)*3.3/4096);
			printf("最小1V电压值：%fV\r\n",(float)(V_1V_AdMin&0xFFF)*3.3/4096);

			printf("最大中频电压值：%fV\r\n",(float)(V_3V_AdMax&0xFFF)*3.3/4096);
			printf("最小中频电压值：%fV\r\n",(float)(V_3V_AdMin&0xFFF)*3.3/4096);
	*/
		}


		//功能测试
		if(Para.XBR_FUN == TRUE)
		{

			//delay_ms(8000);
			
			for(i=0;i<4;i++)	//列循环
			{
				HC4052A_Set_ColAB(i);
				
				for(j=0;j<4;j++)	//单列中依次检测4个灯控板
				{
					HC4052A_Set_RowAB(j);
					//delay_ms(1000);
					//MODE_XBR201_Send(0x06);
					//delay_ms(3000);
					//无运动时模块应当输出为低
					//printf("模块号：%d\r\n",i*4+j+1);
					printf("mode:%d\r\n",i*4+j+1);

					if(O_OUT_READ() != 0)
					{
						//printf("模块输出错误\r\n");
						printf("Module output error\r\n");
						pcb_check_info[i][j].out_st|=1<<1;
						pcb_check_info[i][j].errCode |= 0x80;

					}

				}
				
			}


			//打开风扇
			MOTO_Control(1);

			delay_ms(1000);
					
			for(i=0;i<4;i++)	//列循环
			{
				HC4052A_Set_ColAB(i);
				
				for(j=0;j<4;j++)	//单列中依次检测4个灯控板
				{
					HC4052A_Set_RowAB(j);
					//delay_ms(2000);
					//printf("模块号：%d\r\n",i*4+j+1);
					printf("mode:%d\r\n",i*4+j+1);

					if(O_OUT_READ() == 0)
					{
						//printf("模块输出错误\r\n");
						printf("Module output error\r\n");
						pcb_check_info[i][j].out_st|=1<<2;
						pcb_check_info[i][j].errCode |= 0x80;
					}

					//保存模块状态，并显示错误模块
					if(pcb_check_info[i][j].out_st != 0)
					{
						Mode_Sate |= (0x01 << (i * 4 + j));
					}

					
				}
			}
		}

		//声音提示
		if(Mode_Sate != 0)
		{
			BEEP_Start(100);
			BEEP_Wait();
			delay_ms(100);
			BEEP_Start(100);
			BEEP_Wait();
			delay_ms(100);
			BEEP_Start(100);
		}
		else
		{
			BEEP_Start(100);
		}
		
		//LED提示
		LED_HC595_Set(Mode_Sate);
		//关闭风扇
		MOTO_Control(3);
		//关闭全部电源
		HC595_Set_Power1(0);
		HC595_Set_Power2(0);
		/*
		TxBuffer_2[0] = PACKET_HEADER_BYTE1;
		TxBuffer_2[1] = PACKET_HEADER_BYTE2;
		TxBuffer_2[2] = 24;
		TxBuffer_2[3] = 0xFB;
		
		TxBuffer_2[4] = (Mode_Sate>>8) & 0xFF;
		TxBuffer_2[5] = Mode_Sate & 0xFF;
		
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
			TxBuffer_2[6+(i * 4) + j] = pcb_check_info[i][j].errCode;

		TxBuffer_2[22] = PACKET_TAIL_BYTE1;
		TxBuffer_2[23] = PACKET_TAIL_BYTE2;
		TxLen_2 = 24;*/
		
		TxBuffer_2[0] = PACKET_HEADER_BYTE1;
		TxBuffer_2[1] = PACKET_HEADER_BYTE2;
		TxBuffer_2[2] = 42;
		TxBuffer_2[3] = PACKET_CMD_TRESULT;
		
		TxBuffer_2[4] = (Mode_Sate>>24) & 0xFF;
		TxBuffer_2[5] = (Mode_Sate>>16) & 0xFF;
		TxBuffer_2[6] = (Mode_Sate>>8) & 0xFF;
		TxBuffer_2[7] = Mode_Sate & 0xFF;
		
		for(i=0;i<8;i++)
			for(j=0;j<4;j++)
			TxBuffer_2[8+(i * 4) + j] = pcb_check_info[i][j].errCode;

		TxBuffer_2[40] = PACKET_TAIL_BYTE1;
		TxBuffer_2[41] = PACKET_TAIL_BYTE2;
		TxLen_2 = TxBuffer_2[2];
		
		Usart2_send(TxBuffer_2,TxLen_2);
		
		__enable_irq();//打开中断全能
		
		delay_ms(3000);
}

//=============================================================================
//文件名称：void MODE_XBR201_Clear(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void MODE_XBR201_Clear(void)
{
	unsigned char i =0;
	unsigned char j =0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<4;j++)
		{
			pcb_check_info[i][j].check_status = 0;	   //测试状态标志
			pcb_check_info[i][j].Current = 0;				//电流值
			pcb_check_info[i][j].V_1V = 0;						//1.2V电压值
			pcb_check_info[i][j].V_AD = 0;						//3V电压值
			pcb_check_info[i][j].out_st = 0; 				//输出状态---3次检测全正确为0，
																	//第一次检测应为高，否则加1，第二次检测应为低，否则加10，第三次检测应为高，否则加100
			pcb_check_info[i][j].SUM0 = 0;//
			pcb_check_info[i][j].SUM1 = 0;//
			
			pcb_check_info[i][j].V_ADMAX = 0;
			pcb_check_info[i][j].V_ADMIN = 0;
			pcb_check_info[i][j].V_ADMAX0 = 0;
			pcb_check_info[i][j].V_ADMIN0 = 0;
			pcb_check_info[i][j].V_ADMAX1 = 0;
			pcb_check_info[i][j].V_ADMIN1 = 0;
			
			pcb_check_info[i][j].NUM_H0 = 0;
			pcb_check_info[i][j].NUM_L0 = 0;
			
			pcb_check_info[i][j].NUM_H1 = 0;
			pcb_check_info[i][j].NUM_L1 = 0;
			
			pcb_check_info[i][j].read_light = 0; 
			pcb_check_info[i][j].light_ad = 0;					//感光AD值
			pcb_check_info[i][j].read_tx = 0;
			memset(pcb_check_info[i][j].tx_data,0,sizeof(pcb_check_info[i][j].tx_data));//发送数据

		}
	}
}


//=============================================================================
//文件名称：void MODE_XBR201_Alogo(unsigned char Num)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================



void MODE_XBR201_Alogo(unsigned char Num)
{
	//unsigned int ADC_VAL = 0;
	printf("模块编号为%d \r\n",Num);

	MODE_XBR105_Clear();

	Mode_Sate = 0x0000;
	Mode_Sate = 0x0001 << Num;
	LED_HC595_Set(Mode_Sate);

	HC595_Set_Power1(Mode_Sate & 0xFF);
	HC595_Set_Power2((Mode_Sate>>8) & 0xFF);
	//HC595_Set_Power3(Mode_Sate & 0xFFFFFF);
	//HC595_Set_Power3(0xFFFFFF);
	//MC74HC595_Set_Power1(0xFF);
	//MC74HC595_Set_Power2(0xFF);
	//HC74HC4052A_Set_ColAB(0);
	//HC74HC4052A_Set_RowAB(0);
	HC4052A_Set_ColAB(Num/4);
	HC4052A_Set_RowAB(Num%4);
	
	printf(str_start);
	BEEP_Start(100);
	BEEP_Wait();

	delay_ms(5000);
	
	for(i=0;i<2;i++)
	{
		//MODE_XBR201_Send(1);
		Usart1_send("hello world\r\n",13);
		delay_ms(1000);
		//MODE_XBR201_Poll();
		Usart1_send("hello world\r\n",13);
	}

	if(O_OUT_READ() != 0)
	{
		printf("模块输出为高\r\n");
	}
	else
	{
		printf("模块输出为低\r\n");
	}


}


