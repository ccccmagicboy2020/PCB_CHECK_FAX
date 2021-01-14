//=============================================================================
//��˾���ƣ�������
//�ļ����ƣ�MODE_XBR201.c
//���ܸ�Ҫ��MODE_XBR201����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================


#include "INCLUDE_EXT.h"
#include "MODE_XBR202.h"



//=============================================================================
//�ļ����ƣ�void MODE_XBR202(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void MODE_XBR202(void)
{
		Mode_Sate = 0xFFFFFF;
		
		BEEP_Start(100);
		BEEP_Wait();

		MODE_XBR202_Clear();
		HC595_Set_Power3(0xffffff);
		
		//printf(str_start);
		printf("\r\n");

		delay_ms(1000);
		
		

		//__disable_irq();//��
		//
		MX_ADC1_Init();
		HAL_ADC_Start(&hadc1);
		HAL_ADCEx_Calibration_Start(&hadc1);//У׼
		delay_ms(7000);
		delay_ms(3000);
		Mode_Sate = 0;

		//���ܲ���
		if(Para.XBR_PE == TRUE)
		{
			//��ȡ24���ƿذ��ϵ��ĵ�����3V��ѹ��1.2V��ѹ���ϵ�����״̬
			for(i=0;i<6;i++)	//��ѭ��
			{
				HC4051A_Set_ColABC(i);
				
				for(j=0;j<4;j++)	//���������μ��4���ƿذ�
				{
					HC4052A_Set_RowAB(j);

					Get_Adc_Average_All(1000);

					pcb_check_info[i][j].Current = ADC_Value[0];
					pcb_check_info[i][j].V_1V = ADC_Value[1];
					pcb_check_info[i][j].V_AD = ADC_Value[2];
	/*
					printf("ģ��ţ�%d\r\n",i*4+j+1);
					printf("����ֵ��%fmA\r\n",(float)((pcb_check_info[i][j].Current&0xFFF)*3.3/4096)/0.2/100 * 1000);
					printf("1.2V��ѹֵ��%fV\r\n",(float)(pcb_check_info[i][j].V_1V&0xFFF)*3.3/4096);
					printf("3.2V��ѹֵ��%fV\r\n",(float)(pcb_check_info[i][j].V_AD&0xFFF)*3.3/4096 * 2);
					*/
					printf("mode:%d\r\n",i*4+j+1);
					printf("I:%fmA\r\n",(float)((pcb_check_info[i][j].Current&0xFFF)*3.3/4096)/0.2/100 * 1000);
					printf("1.2V:%fV\r\n",(float)(pcb_check_info[i][j].V_1V&0xFFF)*3.3/4096);
					printf("3.2V:%fV\r\n",(float)(pcb_check_info[i][j].V_AD&0xFFF)*3.3/4096 * 2);
					pcb_check_info[i][j].errCode = 0;

					if(pcb_check_info[i][j].Current > Para.Current_AdMax_201)
					{
						//�жϵ����Ƿ����ȷ��Ϊ��·״̬
						if(pcb_check_info[i][j].Current > Para.Current_Short_201)
						{
							//printf("ģ��ţ�%d��·����ϵ�\r\n",i*4+j+1);
							printf("mode:%d short,power dowm\r\n",i*4+j+1);
							pcb_check_info[i][j].out_st=1;
							pcb_check_info[i][j].errCode |= 0x01;
						}
						//printf("����ֵ������\r\n");
						printf("The current exceeds the upper limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x02;
					}

					if(pcb_check_info[i][j].Current < Para.Current_AdMin_201)
					{
						//printf("����ֵ������\r\n");
						printf("Current beyond lower limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x04;
					}

					if(pcb_check_info[i][j].V_1V > Para.V_1V_AdMax_201 )
					{
						//printf("1.2V��ѹֵ������\r\n");
						printf("1.2v beyond upper limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x08;
					}
					if(pcb_check_info[i][j].V_1V < Para.V_1V_AdMin_201)
					{
						//printf("1.2V��ѹֵ������\r\n");
						printf("1.2V beyond the lower limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x10;
					}

					if(pcb_check_info[i][j].V_AD > Para.V_3V_AdMax_201 )
					{
						//printf("3.2V��ѹֵ������\r\n");
						printf("3.2v beyond upper limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x20;
					}

					if(pcb_check_info[i][j].V_AD < Para.V_3V_AdMin_201)
					{
						//printf("3.2V��ѹֵ������\r\n");
						printf("3.2V beyond the lower limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x40;
					}

					//����������Сֵ
					if(Current_AdMax < pcb_check_info[i][j].Current)
					{
						Current_AdMax = pcb_check_info[i][j].Current&0xFFF;
					}
					if(Current_AdMin > pcb_check_info[i][j].Current)
					{
						Current_AdMin = pcb_check_info[i][j].Current&0xFFF;
					}
					//ȡ1.2V�����Сֵ
					if(V_1V_AdMax < pcb_check_info[i][j].V_1V)
					{
						V_1V_AdMax = pcb_check_info[i][j].V_1V&0xFFF;
					}
					if(V_1V_AdMin > pcb_check_info[i][j].V_1V)
					{
						V_1V_AdMin = pcb_check_info[i][j].V_1V&0xFFF;
					}
					//ȡ3V�����Сֵ
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
						//����ģ����Բ���
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
						//����ģ��״̬������ʾ����ģ��
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

			printf("������ֵ��%fV\r\n",(float)((Current_AdMax&0xFFF)*3.3/4096)/0.2/100);
			printf("��С����ֵ��%fV\r\n",(float)((Current_AdMin&0xFFF)*3.3/4096)/0.2/100);

			printf("���1V��ѹֵ��%fV\r\n",(float)(V_1V_AdMax&0xFFF)*3.3/4096);
			printf("��С1V��ѹֵ��%fV\r\n",(float)(V_1V_AdMin&0xFFF)*3.3/4096);

			printf("�����Ƶ��ѹֵ��%fV\r\n",(float)(V_3V_AdMax&0xFFF)*3.3/4096);
			printf("��С��Ƶ��ѹֵ��%fV\r\n",(float)(V_3V_AdMin&0xFFF)*3.3/4096);
	*/
		}


		//���ܲ���
		if(Para.XBR_FUN == TRUE)
		{

			//delay_ms(8000);
			
			for(i=0;i<6;i++)	//��ѭ��
			{
				HC4051A_Set_ColABC(i);
				
				for(j=0;j<4;j++)	//���������μ��4���ƿذ�
				{
					HC4052A_Set_RowAB(j);
					//delay_ms(1000);
					//MODE_XBR201_Send(0x06);
					//delay_ms(3000);
					//���˶�ʱģ��Ӧ�����Ϊ��
					//printf("ģ��ţ�%d\r\n",i*4+j+1);
					printf("mode:%d\r\n",i*4+j+1);

					if(O_OUT_READ() != 0)
					{
						//printf("ģ���������\r\n");
						printf("Module output error\r\n");
						pcb_check_info[i][j].out_st|=1<<1;
						pcb_check_info[i][j].errCode |= 0x80;

					}

				}
				
			}


			//�򿪷���
			MOTO_Control(1);

			delay_ms(1000);
					
			for(i=0;i<6;i++)	//��ѭ��
			{
				HC4051A_Set_ColABC(i);
				
				for(j=0;j<4;j++)	//���������μ��4���ƿذ�
				{
					HC4052A_Set_RowAB(j);
					//delay_ms(2000);
					//printf("ģ��ţ�%d\r\n",i*4+j+1);
					printf("mode:%d\r\n",i*4+j+1);

					if(O_OUT_READ() == 0)
					{
						//printf("ģ���������\r\n");
						printf("Module output error\r\n");
						pcb_check_info[i][j].out_st|=1<<2;
						pcb_check_info[i][j].errCode |= 0x80;
					}

					//����ģ��״̬������ʾ����ģ��
					if(pcb_check_info[i][j].out_st != 0)
					{
						Mode_Sate |= (0x01 << (i * 4 + j));
					}

					
				}
			}
		}

		//������ʾ
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
		
		//LED��ʾ
		LED_HC595_Set(Mode_Sate);
		//�رշ���
		MOTO_Control(3);
		//�ر�ȫ����Դ
		HC595_Set_Power3(0);
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
		TxLen_2 = TxBuffer_2[2];*/

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
		
		__enable_irq();//���ж�ȫ��
		
		delay_ms(3000);
}

//=============================================================================
//�ļ����ƣ�void MODE_XBR202_Clear(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void MODE_XBR202_Clear(void)
{
	unsigned char i =0;
	unsigned char j =0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<4;j++)
		{
			pcb_check_info[i][j].check_status = 0;	   //����״̬��־
			pcb_check_info[i][j].Current = 0;				//����ֵ
			pcb_check_info[i][j].V_1V = 0;						//1.2V��ѹֵ
			pcb_check_info[i][j].V_AD = 0;						//3V��ѹֵ
			pcb_check_info[i][j].out_st = 0; 				//���״̬---3�μ��ȫ��ȷΪ0��
																	//��һ�μ��ӦΪ�ߣ������1���ڶ��μ��ӦΪ�ͣ������10�������μ��ӦΪ�ߣ������100
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
			pcb_check_info[i][j].light_ad = 0;					//�й�ADֵ
			pcb_check_info[i][j].read_tx = 0;
			memset(pcb_check_info[i][j].tx_data,0,sizeof(pcb_check_info[i][j].tx_data));//��������

		}
	}
}


//=============================================================================
//�ļ����ƣ�void MODE_XBR202_Alogo(unsigned char Num)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================



void MODE_XBR202_Alogo(unsigned char Num)
{	
	//unsigned char test[10]={0};
	//unsigned int ADC_VAL = 0;
	printf("ģ����Ϊ%d \r\n",Num);

	MODE_XBR202_Clear();

	Mode_Sate = 0x0000;
	Mode_Sate = 0x0001 << Num;
	//LED_HC595_Set(Mode_Sate);

	HC595_Set_Power3(Mode_Sate & 0xFFFFFF);

	HC4051A_Set_ColABC(Num/4);
	HC4052A_Set_RowAB(Num%4);
	
	printf(str_start);
	BEEP_Start(100);
	BEEP_Wait();

	delay_ms(5000);
	/*
	for(i=0;i<2;i++)
	{
		//MODE_XBR_Send(1);
		//delay_ms(1000);
		//MODE_XBR_Poll();
		test[0] = 0x55;
		test[1] = 0xAA;
		test[2] = 0x55;
		test[3] = 0xAA;
		Usart1_send(test,4);
	}*/

	
	if(O_OUT_READ() != 0)
	{
		printf("ģ�����Ϊ��\r\n");
	}
	else
	{
		printf("ģ�����Ϊ��\r\n");
	}


}


