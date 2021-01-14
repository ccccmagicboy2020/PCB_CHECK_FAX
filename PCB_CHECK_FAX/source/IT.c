//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�IT.h
//���ܸ�Ҫ��IT����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================

#include "INCLUDE_EXT.h"
#include "IT.h"

#define USART_REC_LEN  			100  	//�����������ֽ��� 200
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
extern uint8_t  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern uint16_t USART_RX_STA;         		//����״̬���	

uint32_t uhADCxConvertedValue;
uint32_t ADC_ConvertedValue;
float ADC_ConvertedValueLocal;



//=============================================================================
//�ļ����ƣ�void HAL_SYSTICK_Callback(void)
//���ܸ�Ҫ��ϵͳʱ���жϻص����� 
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================
/*
void HAL_SYSTICK_Callback(void)
{
  //sysTickUptimems++;
    //ϵͳû�г�ʼ���ã������д�ѭ��
    //if( ! Init_Finish) return;
    //��ѭ��ͳ��
    //Call_Loop_timer();
}*/

//=============================================================================
//�ļ����ƣ�void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//���ܸ�Ҫ�������жϽ��ջص����� 
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    uint8_t value1 = 0;
    uint8_t value2 = 0;
		uint8_t value3 = 0;
    //uint8_t value4 = 0;
    //uint8_t value5 = 0;
    //Prevent unused argument(s) compilation warning 
    UNUSED(huart);
    
    if(huart->Instance==USART1)
    {
				//ת������
				value1 = RxByte1;
				RxBuffer_1[RxLen_1++] = RxByte1;
				//RxBuffer_1[RxLen_1++] = value1;
				if((RxLen_1>= 24) & (RxBuffer_1[2] >= 24))
				{
					RxLen_1 = 0;
					RxBuffer_1[2] = 0;
				}
				if((RxLen_1 == 1) & (RxByte1 != PACKET_HEADER_BYTE1))
				{
					RxBuffer_1[0] = 0;
					RxLen_1 = 0;
				}
				if((RxLen_1 == 2) & (RxByte1 != PACKET_HEADER_BYTE2))
				{
					RxBuffer_1[0] = 0;
					RxLen_1 = 0;
				}
				/*
				if((RxLen_1 < 2) & (RxByte1 != 0xAA))
				{
					RxBuffer_1[0] = 0;
					RxLen_1 = 0;
				}*/
				
				if((RxLen_1 == RxBuffer_1[2]) & (RxLen_1 != 0))
				{
					ReceiveFlag_1 = 1;
					memcpy(CmdBuffer_1,RxBuffer_1,RxLen_1);
					RxBuffer_1[0] = 0;
					RxLen_1 = 0;//������ݳ���
					if(CmdBuffer_1[3] == PACKET_CMD_SET)
					{
						XBR_WR = 1;
						//printf("д�����ݳɹ�\r\n");
					}
				}
			
			
				/*
				if((RxBuffer_1[0] != 0xFA) 
					& (RxBuffer_1[0] != 0xFD)
					& (RxLen_1 > 19))
				{
					RxBuffer_1[0] = 0;
					RxLen_1 = 0;
				}

				if((RxBuffer_1[0] == 0xFA) & (RxLen_1 == 19))
				{
					ReceiveFlag_1 = 1;
					memcpy(CmdBuffer_1,RxBuffer_1,RxLen_1);
					RxBuffer_1[0] = 0;
					RxLen_1 = 0;
				}

				if((RxBuffer_1[0] == 0xFD) & (RxLen_1 == 1))
				{
					ReceiveFlag_1 = 1;
					memcpy(CmdBuffer_1,RxBuffer_1,RxLen_1);
					RxBuffer_1[0] = 0;
					RxLen_1 = 0;//
				}*/
				
				

		//HAL_UART_Transmit(&huart1, (uint8_t *)&RxByte1, 1, 0xFFFF);

        HAL_UART_Receive_IT(&huart1,&RxByte1,1);

        // Enable the UART Data Register not empty Interrupt 
        __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);  
        
    }
    else if(huart->Instance==USART2)
    {
			

		//ת������
		value2 = RxByte2;
		RxBuffer_2[RxLen_2++] = value2;
		
		if((RxLen_2> 27) & (RxBuffer_2[2] > 27))
		{
			RxLen_2 = 0;
			RxBuffer_2[2] = 0;
		}
		if((RxLen_2 == 1) & (RxByte2 != PACKET_HEADER_BYTE1))
		{
			RxBuffer_2[0] = 0;
			RxLen_2 = 0;
		}
		if((RxLen_2 == 2) & (RxByte2 != PACKET_HEADER_BYTE2))
		{
			RxBuffer_2[0] = 0;
			RxLen_2 = 0;
		}
		
		/*
		if((RxLen_2 < 2) & (RxByte2 != 0xAA))
		{
			RxBuffer_2[0] = 0;
			RxLen_2 = 0;
		}*/
		
		if((RxLen_2 == RxBuffer_2[2]) & (RxLen_2 != 0))
		{
			ReceiveFlag_2 = 1;
			memcpy(CmdBuffer_2,RxBuffer_2,RxLen_2);
			RxBuffer_2[0] = 0;
			RxLen_2 = 0;//������ݳ���
			
		}
		



        HAL_UART_Receive_IT(&huart2,&RxByte2,1);
        
        // Enable the UART Data Register not empty Interrupt 
        __HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);  
    }
    else if(huart->Instance==USART3)
    {
				//ת������
				value3 = RxByte3;
			
        HAL_UART_Receive_IT(&huart3,&RxByte3,1);
        
        /* Enable the UART Data Register not empty Interrupt */  
        __HAL_UART_ENABLE_IT(&huart3, UART_IT_RXNE);  
    }

}

//=============================================================================
//�ļ����ƣ�void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
//���ܸ�Ҫ�������жϷ��ͽ����ص����� 
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    UNUSED(huart);
    
    if(huart->Instance==USART1)
    {
      
    }
    else if(huart->Instance==USART2)
    {

    }
    else if(huart->Instance==USART3)
    {

    }
    //else if(huart->Instance==UART4)
    {

    }
    //else if(huart->Instance==UART5)
    {

    }
}


//=============================================================================
//�ļ����ƣ�void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//���ܸ�Ҫ����ʱ���жϻص�����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================
void TIM2_IRQHandlerCallback(void);
void TIM3_IRQHandlerCallback(void);
void TIM4_IRQHandlerCallback(void);
/*
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  //uint8_t i =0;
  if(htim->Instance==TIM1)//10us��ʱ��
  {
      //sysTickUptimeus++;
      //Pir_TimeCount++;//10us����
  }
  else if(htim->Instance==TIM2)//1ms��ʱ��
  {

      //TIM2_IRQHandlerCallback();//���Գ���ɨ��
      //TimingDelay_Decrement();//���ö�ʱ��������ʱ�������Ƚ�׼ȷ
      //��λ������жϴ��� 
      sysTickUptimems++;//MS����

      //ϵͳû�г�ʼ���ã������д�ѭ�� 
      if( ! Init_Finish) return;
      //��ѭ��ͳ��

      Call_Loop_timer();

        
  }
  else if(htim->Instance==TIM3)//125KPWM
  {

  }
  else if(htim->Instance==TIM4)//38KPWM
  {

  }
  else if(htim->Instance==TIM5)//�ܶ�ʱ��
  {
      //TIM4_IRQHandlerCallback();
      //TIM5_IRQHandlerCallback();
  }
  else if(htim->Instance==TIM6)//�ܶ�ʱ��
  {
      sysTickUptimeus++;10us��ʱ��
      Pir_TimeCount++;//10us����
  }
}
*/
//=============================================================================
//�ļ����ƣ�void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//���ܸ�Ҫ��GPIO�жϻص����� 
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================
extern uint8_t PWR_Check_Standby(void);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

  switch(GPIO_Pin)
  {
  case GPIO_PIN_0:
    if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0)//
    {

    }
    else//
    {

    }

    break;
  case GPIO_PIN_1:
    if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)//
    {

    }
    else//
    {

    }

    break;
  case GPIO_PIN_2:

    break;
  case GPIO_PIN_3:/*
    if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == 0)//
    {
			sysTickOutDownTimems = sysTickUptimems;
    }
    else if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == 1)//
    {
			sysTickOutTimems = sysTickUptimems - sysTickOutDownTimems;
    }*/
    break;
    
  case GPIO_PIN_4:
    if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == 1)//
    {

    }
    else//
    {

    }
    break;
    
  case GPIO_PIN_5:
    if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) == 1)//
    {

    }
    else//
    {

    }
    break;
    
  case GPIO_PIN_6:
    if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) == 1)//
    {

    }
    else//
    {

    }
    break;
  case GPIO_PIN_7:/*
    if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) == 0)//
    {
			sysTickDtrDownTimems = sysTickUptimems;
    }
    else if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) == 1)//
    {
			sysTickDtrTimems = sysTickUptimems - sysTickDtrDownTimems;
    }*/
    break;
  case GPIO_PIN_8:

    break;
  case GPIO_PIN_9:
    
    break;
  case GPIO_PIN_10:
    
    break;
  case GPIO_PIN_11:
    
    break;
  case GPIO_PIN_12:

    break;
	
  case GPIO_PIN_13:
    if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 0)
    {

    }
    else
    {

    }
    break;
	
  case GPIO_PIN_14:
    if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14) == 0)
    {

    }
    else
    {

    }
    break;
	
  case GPIO_PIN_15:
    if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == 0)
    {

    }
    else
    {

    }
    break;

	
  default:
    break;
  }

}

//=============================================================================
//�ļ����ƣ�void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle)
//���ܸ�Ҫ��ADC�жϻص�����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle)
{ 

	uhADCxConvertedValue = HAL_ADC_GetValue(AdcHandle);

}
