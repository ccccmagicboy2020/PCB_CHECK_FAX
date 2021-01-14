//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：IT.h
//功能概要：IT驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#include "INCLUDE_EXT.h"
#include "IT.h"

#define USART_REC_LEN  			100  	//定义最大接收字节数 200
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收
extern uint8_t  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern uint16_t USART_RX_STA;         		//接收状态标记	

uint32_t uhADCxConvertedValue;
uint32_t ADC_ConvertedValue;
float ADC_ConvertedValueLocal;



//=============================================================================
//文件名称：void HAL_SYSTICK_Callback(void)
//功能概要：系统时钟中断回调函数 
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================
/*
void HAL_SYSTICK_Callback(void)
{
  //sysTickUptimems++;
    //系统没有初始化好，不进行大循环
    //if( ! Init_Finish) return;
    //大循环统计
    //Call_Loop_timer();
}*/

//=============================================================================
//文件名称：void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//功能概要：串口中断接收回调函数 
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
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
				//转存数据
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
					RxLen_1 = 0;//清除数据长度
					if(CmdBuffer_1[3] == PACKET_CMD_SET)
					{
						XBR_WR = 1;
						//printf("写入数据成功\r\n");
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
			

		//转存数据
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
			RxLen_2 = 0;//清除数据长度
			
		}
		



        HAL_UART_Receive_IT(&huart2,&RxByte2,1);
        
        // Enable the UART Data Register not empty Interrupt 
        __HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);  
    }
    else if(huart->Instance==USART3)
    {
				//转存数据
				value3 = RxByte3;
			
        HAL_UART_Receive_IT(&huart3,&RxByte3,1);
        
        /* Enable the UART Data Register not empty Interrupt */  
        __HAL_UART_ENABLE_IT(&huart3, UART_IT_RXNE);  
    }

}

//=============================================================================
//文件名称：void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
//功能概要：串口中断发送结束回调函数 
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
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
//文件名称：void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//功能概要：定时器中断回调程序
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================
void TIM2_IRQHandlerCallback(void);
void TIM3_IRQHandlerCallback(void);
void TIM4_IRQHandlerCallback(void);
/*
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  //uint8_t i =0;
  if(htim->Instance==TIM1)//10us定时器
  {
      //sysTickUptimeus++;
      //Pir_TimeCount++;//10us计数
  }
  else if(htim->Instance==TIM2)//1ms定时器
  {

      //TIM2_IRQHandlerCallback();//调试程序扫描
      //TimingDelay_Decrement();//采用定时器进行延时计数，比较准确
      //复位起的总中断次数 
      sysTickUptimems++;//MS计数

      //系统没有初始化好，不进行大循环 
      if( ! Init_Finish) return;
      //大循环统计

      Call_Loop_timer();

        
  }
  else if(htim->Instance==TIM3)//125KPWM
  {

  }
  else if(htim->Instance==TIM4)//38KPWM
  {

  }
  else if(htim->Instance==TIM5)//总定时器
  {
      //TIM4_IRQHandlerCallback();
      //TIM5_IRQHandlerCallback();
  }
  else if(htim->Instance==TIM6)//总定时器
  {
      sysTickUptimeus++;10us定时器
      Pir_TimeCount++;//10us计数
  }
}
*/
//=============================================================================
//文件名称：void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//功能概要：GPIO中断回调函数 
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
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
//文件名称：void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle)
//功能概要：ADC中断回调程序
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle)
{ 

	uhADCxConvertedValue = HAL_ADC_GetValue(AdcHandle);

}
