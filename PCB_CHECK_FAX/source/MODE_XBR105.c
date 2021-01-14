//=============================================================================
//��˾���ƣ�������
//�ļ����ƣ�MODE_XBR105.c
//���ܸ�Ҫ��MODE_XBR105����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================

#include "INCLUDE_EXT.h"
#include "MODE_XBR105.h"


unsigned int		Current_AdMax = 0;//ģ��������
unsigned int		Current_AdMin = 0xFFFFFF;//ģ����С����
unsigned int		Current_Short = 0;//��·���޵���

unsigned int 		V_1V_AdMax = 0;//ģ���������ѹ
unsigned int 		V_1V_AdMin = 0xFFFFFF;//ģ����С������ѹ
//��ֹ״̬ƽ��ֵ
unsigned int 		V_3V_AdMax = 0;//ģ���״��ź����ֵ
unsigned int 		V_3V_AdMin = 0xFFFFFF;//ģ���״��ź���Сֵ
//�����˶�״̬
unsigned int 		V_3V_AdMax0 = 0;//���ֵ
unsigned int 		V_3V_AdMin0 = 0xFFFFFF;//��Сֵ
//�����˶�״̬
unsigned int 		V_3V_AdMax1 = 0;//���ֵ
unsigned int 		V_3V_AdMin1 = 0xFFFFFF;//��Сֵ
//���˶�ʱ��������Χ
unsigned int		SUM0_Max = 0;//���ֵ
unsigned int 		SUM0_Min = 0xFFFFFF;//��Сֵ
//�˶�ʱ��������Χ
unsigned int		SUM1_Max = 0;//���ֵ
unsigned int 		SUM1_Min = 0xFFFFFF;//��Сֵ

unsigned long long ADC_SUM = 0;
	
//=============================================================================
//�ļ����ƣ�void MODE_XBR105(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void MODE_XBR105(void)
{
		Mode_Sate = 0xFFFF;
		LED_HC595_Set(Mode_Sate);

		BEEP_Start(100);
		BEEP_Wait();

		MODE_XBR105_Clear();
		HC595_Set_Power1(0xff);
		HC595_Set_Power2(0xff);
		
		//printf(str_start);
		printf("\r\n");

		delay_ms(1000);
		Mode_Sate = 0x0000;
		LED_HC595_Set(Mode_Sate);
	
		//__disable_irq();//��
		//
		MX_ADC1_Init();
		HAL_ADC_Start(&hadc1);
		HAL_ADCEx_Calibration_Start(&hadc1);//У׼
		delay_ms(8000);
		//���ܲ���
		if(Para.XBR_PE == TRUE)
		{
			//��ȡ16���ƿذ��ϵ��ĵ�����3V��ѹ��1.2V��ѹ���ϵ�����״̬
			for(i=0;i<4;i++)	//��ѭ��
			{
				HC4052A_Set_ColAB(i);
				
				for(j=0;j<4;j++)	//���������μ��4���ƿذ�
				{
					HC4052A_Set_RowAB(j);

					Get_Adc_Average_All(1000);

					pcb_check_info[i][j].Current = ADC_Value[0];ADC_Value[0] = 0;
					pcb_check_info[i][j].V_1V = ADC_Value[1];ADC_Value[1] = 0;
					pcb_check_info[i][j].V_AD = ADC_Value[2];ADC_Value[2] = 0;

					//printf("ģ��ţ�%d\r\n",i*4+j+1);
					//printf("����ֵ��%fmA\r\n",(float)((pcb_check_info[i][j].Current&0xFFF)*3.3/4096)/0.2/100 * 1000);
					//printf("��ѹֵ��%fV\r\n",(float)(pcb_check_info[i][j].V_1V&0xFFF)*3.3/4096);
					//printf("��Ƶ��ѹֵ��%fV\r\n",(float)(pcb_check_info[i][j].V_AD&0xFFF)*3.3/4096 * 2);
					printf("mode:%d\r\n",i*4+j+1);
					printf("I:%fmA\r\n",(float)((pcb_check_info[i][j].Current&0xFFF)*3.3/4096)/0.2/100 * 1000);
					printf("1.2V:%fV\r\n",(float)(pcb_check_info[i][j].V_1V&0xFFF)*3.3/4096);
					printf("3.2V:%fV\r\n",(float)(pcb_check_info[i][j].V_AD&0xFFF)*3.3/4096 * 2);
					pcb_check_info[i][j].errCode = 0;

					if(pcb_check_info[i][j].Current > Para.Current_AdMax_105)
					{
						//�жϵ����Ƿ����ȷ��Ϊ��·״̬
						if(pcb_check_info[i][j].Current > Para.Current_Short_105)
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

					if(pcb_check_info[i][j].Current < Para.Current_AdMin_105)
					{
						//printf("����ֵ������\r\n");
						printf("Current beyond lower limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x04;
					}

					if(pcb_check_info[i][j].V_1V > Para.V_1V_AdMax_105 )
					{
						//printf("1.2V��ѹֵ������\r\n");
						printf("1.2v beyond upper limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x08;
					}
					if(pcb_check_info[i][j].V_1V < Para.V_1V_AdMin_105)
					{
						//printf("1.2V��ѹֵ������\r\n");
						printf("1.2V beyond the lower limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x10;
					}

					if(pcb_check_info[i][j].V_AD > Para.V_3V_AdMax_105 )
					{
						//printf("��Ƶ��ѹֵ������\r\n");
						printf("3.2v beyond upper limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x20;
					}

					if(pcb_check_info[i][j].V_AD < Para.V_3V_AdMin_105)
					{
						//printf("��Ƶ��ѹֵ������\r\n");
						printf("3.2V beyond the lower limit\r\n");
						pcb_check_info[i][j].out_st=1;
						pcb_check_info[i][j].errCode |= 0x40;
					}
					/*
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
			}

		}

		//���ܲ���
		if(Para.XBR_FUN == TRUE)
		{
			Goble_MX_ADC1_Init();
			HAL_ADC_Start(&hadc1);
			HAL_ADCEx_Calibration_Start(&hadc1);//У׼
			//delay_ms(8000);
			for(i=0;i<4;i++)	//��ѭ��
			{
				HC4052A_Set_ColAB(i);
				
				for(j=0;j<4;j++)	//���������μ��4���ƿذ�
				{
					HC4052A_Set_RowAB(j);
					
					//pcb_check_info[i][j].V_AD=Get_Adc_Average(2,8000);

					//Get_Adc_Average_All(1000);
					//pcb_check_info[i][j].Current = ADC_Value[0];
					//pcb_check_info[i][j].V_1V = ADC_Value[1];
					//pcb_check_info[i][j].V_AD = ADC_Value[2];
					ADC_SUM = 0;

					for(k=0;k<1000;k++)
					{
						ADC_SUM += Get_Adc(2);
					}
					pcb_check_info[i][j].V_AD = ADC_SUM / 1000;

					pcb_check_info[i][j].V_ADMAX0=0;
					pcb_check_info[i][j].V_ADMIN0=0XFFFF;
					sum=0;
					for(k=0;k<8000;k++)
					{
						tempv_16=Get_Adc(2);
		
						if(pcb_check_info[i][j].V_ADMIN0>tempv_16)
							pcb_check_info[i][j].V_ADMIN0=tempv_16;
						if(pcb_check_info[i][j].V_ADMAX0<tempv_16)
							pcb_check_info[i][j].V_ADMAX0=tempv_16;
						
						if(tempv_16>pcb_check_info[i][j].V_AD)tempv_16-=pcb_check_info[i][j].V_AD;
						else tempv_16=pcb_check_info[i][j].V_AD-tempv_16;
						sum+=tempv_16;
					
					}

					pcb_check_info[i][j].SUM0 = sum;

					//printf("ģ��ţ�%d\r\n",i*4+j+1);
					//printf("��̬��Ƶ��ѹֵ��%fV\r\n",(float)(pcb_check_info[i][j].V_AD&0xFFF)*3.3/4096 * 2);
					//printf("��̬��Ƶ��ѹ���ֵ��%fV\r\n",(float)(pcb_check_info[i][j].V_ADMAX0&0xFFF)*3.3/4096 * 2);
					//printf("��̬��Ƶ��ѹ��Сֵ��%fV\r\n",(float)(pcb_check_info[i][j].V_ADMIN0&0xFFF)*3.3/4096 * 2);
					//printf("SUM0ֵ��%4d\r\n",pcb_check_info[i][j].SUM0);
					
					printf("mode:%d\r\n",i*4+j+1);
					printf("Static if:%fV\r\n",(float)(pcb_check_info[i][j].V_AD&0xFFF)*3.3/4096 * 2);
					printf("Static if max:%fV\r\n",(float)(pcb_check_info[i][j].V_ADMAX0&0xFFF)*3.3/4096 * 2);
					printf("Static if min:%fV\r\n",(float)(pcb_check_info[i][j].V_ADMIN0&0xFFF)*3.3/4096 * 2);
					printf("SUM0:%4d\r\n",pcb_check_info[i][j].SUM0);
					
					
					/*
					if(pcb_check_info[i][j].V_AD > Para.V_3V_AdMax0)
					{
						printf("�״��źŷ�����ѹֵ������\r\n");
						pcb_check_info[i][j].out_st|=1<<1;
					}
					if(pcb_check_info[i][j].V_AD < Para.V_3V_AdMin0)
					{
						printf("�״��źŷ�����ѹֵ������\r\n");
						pcb_check_info[i][j].out_st|=1<<1;
					}*/
					/*
					if(pcb_check_info[i][j].V_ADMAX0 > Para.V_3V_AdMax0)
					{
						printf("�״��źŷ������ֵ������\r\n");
						pcb_check_info[i][j].out_st|=1<<1;
					}

					if(pcb_check_info[i][j].V_ADMIN0 < Para.V_3V_AdMin0)
					{
						printf("�״��źŷ�����Сֵ������\r\n");
						pcb_check_info[i][j].out_st|=1<<1;
					}

					if(pcb_check_info[i][j].SUM0 > Para.SUM0_Max)
					{
						printf("�״��źŻ�����������\r\n");
						pcb_check_info[i][j].out_st|=1<<1;
					}

					if(pcb_check_info[i][j].SUM0 < Para.SUM0_Min)
					{
						printf("�״��źŻ�����������\r\n");
						pcb_check_info[i][j].out_st|=1<<1;
					}
					*/

					//���˶�AD������
					if(V_3V_AdMax0 < pcb_check_info[i][j].V_ADMAX0)
					{
						V_3V_AdMax0 = pcb_check_info[i][j].V_ADMAX0;
					}
					if(V_3V_AdMin0 > pcb_check_info[i][j].V_ADMIN0)
					{
						V_3V_AdMin0 = pcb_check_info[i][j].V_ADMIN0;
					}
					//���˶�ʱ��������Χ
					if(SUM0_Max < pcb_check_info[i][j].SUM0)
					{
						SUM0_Max = pcb_check_info[i][j].SUM0;
					}
					if(SUM0_Min > pcb_check_info[i][j].SUM0)
					{
						SUM0_Min = pcb_check_info[i][j].SUM0;
					}

				}
				
			}


			printf("V_3V_AdMax0 = 0x%x\r\n",V_3V_AdMax0 * 2);
			printf("V_3V_AdMin0 = 0x%x\r\n",V_3V_AdMin0 * 2);
			printf("SUM0_Max = 0x%x\r\n",SUM0_Max);
			printf("SUM0_Min = 0x%x\r\n",SUM0_Min);

			//printf("��̬��Ƶ����ѹֵ��%fV\r\n",(float)(V_3V_AdMax0&0xFFF)*3.3/4096);
			//printf("��̬��Ƶ��С��ѹֵ��%fV\r\n",(float)(V_3V_AdMin0&0xFFF)*3.3/4096);
			//printf("��̬��Ƶ���Ի������ֵ��%fV\r\n",(float)(SUM0_Max&0xFFF)*3.3/4096);
			//printf("��̬��Ƶ���Ի�����Сֵ��%fV\r\n",(float)(SUM0_Min&0xFFF)*3.3/4096);

			//�򿪷���
			MOTO_Control(1);

			delay_ms(1000);

			for(i=0;i<4;i++)	//��ѭ��
			{
				HC4052A_Set_ColAB(i);
				
				for(j=0;j<4;j++)	//���������μ��4���ƿذ�
				{
					HC4052A_Set_RowAB(j);
					
					pcb_check_info[i][j].V_ADMAX1=0;
					pcb_check_info[i][j].V_ADMIN1=0XFFFF;
					
					sum=0;
					for(k=0;k<8000;k++)
					{
						tempv_16=Get_Adc(2);

						if(pcb_check_info[i][j].V_ADMIN1>tempv_16)
							pcb_check_info[i][j].V_ADMIN1=tempv_16;
						if(pcb_check_info[i][j].V_ADMAX1<tempv_16)
							pcb_check_info[i][j].V_ADMAX1=tempv_16;
						
						if(tempv_16>pcb_check_info[i][j].V_AD)tempv_16-=pcb_check_info[i][j].V_AD;
						else tempv_16=pcb_check_info[i][j].V_AD-tempv_16;
						sum+=tempv_16;
					
					}
					//sum1=sum;
					//sum1>>=13;
					
					//pcb_check_info[i][j].SUM1=sum>>8;
					pcb_check_info[i][j].SUM1 = sum;

					//printf("ģ��ţ�%d\r\n",i*4+j+1);
					//printf("��̬��Ƶ��ѹֵ��%fV\r\n",(float)(pcb_check_info[i][j].V_AD&0xFFF)*3.3/4096 * 2);
					//printf("��̬��Ƶ��ѹ���ֵ��%fV\r\n",(float)(pcb_check_info[i][j].V_ADMAX1&0xFFF)*3.3/4096 * 2);
					//printf("��̬��Ƶ��ѹ��Сֵ��%fV\r\n",(float)(pcb_check_info[i][j].V_ADMIN1&0xFFF)*3.3/4096 * 2);
					//printf("SUM1ֵ��%4d\r\n",pcb_check_info[i][j].SUM1);
					
					printf("mode:%d\r\n",i*4+j+1);
					printf("Dynamic if:%fV\r\n",(float)(pcb_check_info[i][j].V_AD&0xFFF)*3.3/4096 * 2);
					printf("Dynamic if max:%fV\r\n",(float)(pcb_check_info[i][j].V_ADMAX1&0xFFF)*3.3/4096 * 2);
					printf("Dynamic if min:%fV\r\n",(float)(pcb_check_info[i][j].V_ADMIN1&0xFFF)*3.3/4096 * 2);
					printf("SUM1:%4d\r\n",pcb_check_info[i][j].SUM1);
					
	/*
					if(pcb_check_info[i][j].V_ADMAX1 > Para.V_3V_AdMax1)
					{
						printf("�״��źŷ������ֵ������\r\n");
						pcb_check_info[i][j].out_st|=1<<2;
					}
					
					if(pcb_check_info[i][j].V_ADMIN1 < Para.V_3V_AdMin1)
					{
						printf("�״��źŷ�����Сֵ������\r\n");
						pcb_check_info[i][j].out_st|=1<<2;
					}
					
					if(pcb_check_info[i][j].SUM1 > Para.SUM1_Max)
					{
						printf("�״��źŻ�����������\r\n");
						pcb_check_info[i][j].out_st|=1<<2;
					}

					if(pcb_check_info[i][j].SUM1 < Para.SUM1_Min)
					{
						printf("�״��źŻ�����������\r\n");
						pcb_check_info[i][j].out_st|=1<<2;
					}
					*/

					if((pcb_check_info[i][j].SUM1 > pcb_check_info[i][j].SUM0) &
						((pcb_check_info[i][j].SUM1 - pcb_check_info[i][j].SUM0) > Para.SUM_Sub))
					{
						//printf("�״��źŻ�������������\r\n");
						printf("The radar integral is ok\r\n");
					}
					else
					{
						//printf("�״��źŻ�����������С\r\n");
						printf("The radar integral is too small\r\n");
						pcb_check_info[i][j].out_st|=1<<2;
						pcb_check_info[i][j].errCode |= 0x80;
					}

					//�˶�ʱAD������
					if(V_3V_AdMax1 < pcb_check_info[i][j].V_ADMAX1)
					{
						V_3V_AdMax1 = pcb_check_info[i][j].V_ADMAX1;
					}
					if(V_3V_AdMin1 > pcb_check_info[i][j].V_ADMIN1)
					{
						V_3V_AdMin1 = pcb_check_info[i][j].V_ADMIN1;
					}
					//�˶�ʱ��������Χ
					if(SUM1_Max < pcb_check_info[i][j].SUM1)
					{
						SUM1_Max = pcb_check_info[i][j].SUM1;
					}
					if(SUM1_Min > pcb_check_info[i][j].SUM1)
					{
						SUM1_Min = pcb_check_info[i][j].SUM1;
					}

					//����ģ��״̬������ʾ����ģ��
					if(pcb_check_info[i][j].out_st != 0)
					{
						Mode_Sate |= (0x01 << (i * 4 + j));
					}

					
				}
			}

		}
		printf("V_3V_AdMax1 = 0x%x\r\n",V_3V_AdMax1 * 2);
		printf("V_3V_AdMin1 = 0x%x\r\n",V_3V_AdMin1 * 2);
		printf("SUM1_Max = 0x%x\r\n",SUM1_Max);
		printf("SUM1_Min = 0x%x\r\n",SUM1_Min);

		//printf("��̬��Ƶ����ѹֵ��%fV\r\n",(float)(V_3V_AdMax1&0xFFF)*3.3/4096);
		//printf("��̬��Ƶ��С��ѹֵ��%fV\r\n",(float)(V_3V_AdMin1&0xFFF)*3.3/4096);
		//printf("��̬��Ƶ���Ի������ֵ��%fV\r\n",(float)(SUM1_Max&0xFFF)*3.3/4096);
		//printf("��̬��Ƶ���Ի�����Сֵ��%fV\r\n",(float)(SUM1_Min&0xFFF)*3.3/4096);

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
		HC595_Set_Power1(0);
		HC595_Set_Power2(0);
		/*
		TxBuffer_2[0] = PACKET_HEADER_BYTE1;
		TxBuffer_2[1] = PACKET_HEADER_BYTE2;
		TxBuffer_2[2] = 24;
		TxBuffer_2[3] = PACKET_CMD_TRESULT;
		
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

		__enable_irq();//���ж�ȫ��
		
		delay_ms(3000);
}



//=============================================================================
//�ļ����ƣ�void MODE_XBR105_Clear(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void MODE_XBR105_Clear(void)
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
//�ļ����ƣ�unsigned char Chip_IsOk(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

unsigned char Chip_IsOk(void)
{
	unsigned long SUM=0;
	unsigned int i = 0;
	unsigned int k =0;
	
	for(i=0;i<100;i++)
	{
		SUM += Get_Adc(2);
	}

	k=SUM / 100;
	if((k>30)&&(k<563))
	{
		return 1;
	}
	
	return 0;
}

//=============================================================================
//�ļ����ƣ�void MODE_XBR105_Alogo(unsigned char Num)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void MODE_XBR105_Alogo(unsigned char Num)
{
	//unsigned int ADC_VAL = 0;
	printf("ģ����Ϊ%d \r\n",Num);

	MODE_XBR105_Clear();

	Mode_Sate = 0x0000;
	Mode_Sate = 0x0001 << Num;
	LED_HC595_Set(Mode_Sate);

	HC595_Set_Power1(Mode_Sate & 0xFF);
	HC595_Set_Power2((Mode_Sate>>8) & 0xFF);
	HC4052A_Set_ColAB(Num/4);
	HC4052A_Set_RowAB(Num%4);

	printf(str_start);
	BEEP_Start(100);
	BEEP_Wait();

	delay_ms(5000);

	Goble_MX_ADC1_Init();
	HAL_ADC_Start(&hadc1);
	HAL_ADCEx_Calibration_Start(&hadc1);//У׼

	//�ж��״�оƬ�Ƿ�������������
	//�ϵ�35������ֱ����ѹû�н���1.1V����������ѭ��
	for(j=0;j<60;j++)
	{
		if(Chip_IsOk() != 0)break;
		delay_ms(100);
	}
	if(j<60)printf("Chip_isOk\r\n");
	else 
	{
		printf("Chip_is Fail\r\n");
		return;
	}

	//delay_ms(8000);
	/*
	//for(j=0;j<100;j++)
	while(1)
	{
		ADC_VAL = Get_Adc(2);
		printf("Get_Adc = 0x%x \r\n",ADC_VAL);
		//printch(j);
		ADC_VAL = (ADC_VAL >> 2) & 0xFF;
		//printch(ADC_VAL);
		j++;
		//if(j>1000)return;
	}*/

}


