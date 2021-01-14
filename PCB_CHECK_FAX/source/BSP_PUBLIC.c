//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_PUBLIC.c
//功能概要：BSP_PUBLIC驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================


#include "INCLUDE_EXT.h"
#include "BSP_PUBLIC.h"

extern void SystemClock_Config(void);





//=============================================================================
//文件名称：void PVD_Init(void)
//功能概要：掉电检测初始化
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void PVD_Init(void)
{

 }


//=============================================================================
//文件名称：uint8_t RCC_GetSYSCLKSource(void)
//功能概要：读取系统时钟
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

uint8_t RCC_GetSYSCLKSource(void)
{
  return ((uint8_t)(RCC->CFGR & RCC_CFGR_SWS));
}

//=============================================================================
//文件名称：void RCC_Configuration(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================


void RCC_Configuration(void)
{

    HAL_RCC_DeInit();	
    SystemClock_Config();
  
}



//=============================================================================
//文件名称：void EnterSleepMode(void)
//功能概要：进入睡眠模式
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void EnterSleepMode(void)
{
  
    HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
    HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
#if 0
    //printf("-------------------------进入Sleep状态----------------------------\r\n");
    PWR_DeInit();
    PWR_BackupAccessCmd(ENABLE);
    //void PWR_PVDLevelConfig(uint32_t PWR_PVDLevel)//This function is not applicable for STM32F030 devices.
    //void PWR_PVDCmd(FunctionalState NewState)//This function is not applicable for STM32F030 devices.
    PWR_WakeUpPinCmd(PWR_WakeUpPin_1,ENABLE);  
    PWR_EnterSleepMode(PWR_SLEEPEntry_WFI);
    PWR_EnterSTOPMode(PWR_Regulator_ON, PWR_STOPEntry_WFI);
    PWR_EnterSTANDBYMode();
    //FlagStatus PWR_GetFlagStatus(PWR_FLAG_WU);//PWR_FLAG_WU  PWR_FLAG_SB  PWR_FLAG_PVDO  PWR_FLAG_VREFINTRDY
    //PWR_ClearFlag(PWR_FLAG_WU);
#endif
}
//=============================================================================
//文件名称：void EnterSTOPMode(void)
//功能概要：进入停止模式
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void EnterSTOPMode(void)
{
    HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
    HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
#if 0
    //printf("-------------------------进入STOP状态----------------------------\r\n");
    //stop模式下，RAM不保持，IO管脚进入高阻态，，，激活就于系统reset
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE); //时钟必须要开启，在这个陷阱中折腾了好几天
    PWR_BackupAccessCmd(ENABLE);    
    PWR_WakeUpPinCmd(PWR_WakeUpPin_1,ENABLE);  
    //PWR_WakeUpPinCmd(PWR_WakeUpPin_2,ENABLE); 
    //PWR_WakeUpPinCmd(PWR_WakeUpPin_3,ENABLE); 
    PWR_ClearFlag(PWR_FLAG_WU); 
    PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);  
#endif
}
//=============================================================================
//文件名称：void EnterSTANDBYMode(void)
//功能概要：进入STANDBY模式
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void EnterSTANDBYMode(void)
{
    //- Disable all used wakeup sources,
    //- Clear all related wakeup flags, 
    //- Re-enable all used wakeup sources,
    //- Enter the Standby mode.
    // 禁用所有唤醒源: 唤醒引脚PA0 
    HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);

    // 清除所有唤醒标志位 
    __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);

    // 使能唤醒引脚：PA0做为系统唤醒输入 
    HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);

    // 清除所有唤醒标志位 
    __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
    
    // 进入待机模式 
    HAL_PWR_EnterSTANDBYMode();
    
    //清除唤醒中断标志
    __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
#if 0
    //printf("-------------------------进入STAND状态----------------------------\r\n");
    //standby模式下，RAM不保持，IO管脚进入高阻态，，，激活就于系统reset
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE); //时钟必须要开启，在这个陷阱中折腾了好几天
    PWR_BackupAccessCmd(ENABLE);    
    PWR_WakeUpPinCmd(PWR_WakeUpPin_1,ENABLE);  
    //PWR_WakeUpPinCmd(PWR_WakeUpPin_2,ENABLE); 
    //PWR_WakeUpPinCmd(PWR_WakeUpPin_3,ENABLE); 
    PWR_ClearFlag(PWR_FLAG_WU); 
    PWR_EnterSTANDBYMode();
#endif
}

//=============================================================================
//文件名称：void EnterSLEEP(void)
//功能概要：进入睡眠模式
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void EnterSLEEP(void)
{
#if 0
    //GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);  //完全失能JTAG/SWD 不关电流也好像不影响
    //GPIO_PinRemapConfig( GPIO_Remap_PD01 , ENABLE );//晶振为GPIO　不关电流也好像不影响
    RCC_LSEConfig(RCC_LSE_OFF);//关闭RTC　 不关电流也好像也不影响
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    //ADC_CONFIG(DISABLE);
    USART_DeInit(USART1);
    USART_DeInit(USART2);
    USART_DeInit(USART3);
    USART_DeInit(USART4);
    USART_DeInit(USART5);
    //EXTI_INITIAL(ENABLE);//以下端口的设置最有影响
    //GPIO_PIN_INITIAL(GPIOA,GPIO_Pin_All,GPIO_Mode_AIN,0); //此处没做外部唤醒　仅用于测试　EXTI合理设置GPIO不影响电流
    //GPIO_PIN_INITIAL(GPIOB,GPIO_Pin_All,GPIO_Mode_AIN,0); 
    //GPIO_PIN_INITIAL(GPIOC,GPIO_Pin_All,GPIO_Mode_AIN,0); 
    //GPIO_PIN_INITIAL(GPIOD,GPIO_Pin_All,GPIO_Mode_AIN,0);
    //PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);//STOP模式
    PWR_EnterSTANDBYMode();//standby模式 
#endif
}

//=============================================================================
//文件名称：Power_Off
//功能概要：关电并进入低能耗状态
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void Power_Off(void)
{
    //Soft_Delay_US(80000);//8000为1ms
#if 0
    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_InitStruct.EXTI_Line = EXTI_Line0 | EXTI_Line1 | EXTI_Line2;//选择外部中断通道
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;//设置中断模式
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿触发中断
    EXTI_InitStruct.EXTI_LineCmd = DISABLE;//关闭外部中断
    EXTI_Init(&EXTI_InitStruct); 
#endif
    EnterSTANDBYMode();

}

//=============================================================================
//文件名称：stop_mode_config
//功能概要：在进入停机模式之前，按照ST官方例程，首先对引脚进行配置，设置成模拟输入状态。
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void stop_mode_config(void)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
{
  GPIO_InitTypeDef GPIO_InitStruct;

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();	
  GPIO_InitStruct.Pin = GPIO_PIN_All;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct); 
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
  __HAL_RCC_GPIOA_CLK_DISABLE();
  __HAL_RCC_GPIOB_CLK_DISABLE();
  __HAL_RCC_GPIOC_CLK_DISABLE();
  __HAL_RCC_GPIOD_CLK_DISABLE();
  
  __HAL_RCC_PWR_CLK_ENABLE();
  //HAL_PWREx_EnableUltraLowPower();
  //HAL_PWREx_EnableFastWakeUp();
  //__HAL_RCC_WAKEUPSTOP_CLK_CONFIG(RCC_STOP_WAKEUPCLOCK_HSI);
}

//=============================================================================
//文件名称：void EnterStopMode_GPIO_Interrupt(void)
//功能概要：配置外部中断唤醒
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void EnterStopMode_GPIO_Interrupt(void)
{
  //config main key with interrupt
  //bsp_init_main_key(BUTTON_MODE_EXTI);
  /*GPIO_InitTypeDef GPIO_InitStruct;

  // GPIO Ports Clock Enable 
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  //Configure GPIO pins : PAPin PAPin 
  GPIO_InitStruct.Pin = WAKE_Pin|K1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  //Configure GPIO pins : PAPin PAPin PAPin PAPin 
  GPIO_InitStruct.Pin = K2_Pin|K3_Pin|K4_Pin|K5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  
  //EXTI interrupt init
  HAL_NVIC_SetPriority(EXTI0_1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_3_IRQn);

  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);
*/
}

//=============================================================================
//文件名称：void EnterStopMode(void)
//功能概要：配置进入停止模式，等待唤醒
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void EnterStopMode(void)
{
    //HAL_PWREx_EnableUltraLowPower();
    //HAL_PWREx_EnableFastWakeUp();
    //__HAL_RCC_WAKEUPSTOP_CLK_CONFIG(RCC_STOP_WAKEUPCLOCK_HSI);
    HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
}

//=============================================================================
//文件名称：void EnterStopMode_GPIO_Config(void)
//功能概要：配置所有引脚模拟输入
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void EnterStopMode_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    // Enable GPIOs clock 
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    //__HAL_RCC_GPIOH_CLK_ENABLE();

    // Configure all GPIO port pins in Analog Input mode (floating input trigger OFF) 
    GPIO_InitStruct.Pin = GPIO_PIN_All;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct); 
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
    //HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

    // Disable GPIOs clock 
    __HAL_RCC_GPIOA_CLK_DISABLE();
    __HAL_RCC_GPIOB_CLK_DISABLE();
    __HAL_RCC_GPIOC_CLK_DISABLE();
    __HAL_RCC_GPIOD_CLK_DISABLE();
    //__HAL_RCC_GPIOH_CLK_DISABLE();
    
}


//=============================================================================
//文件名称：void MCU_STOP(void)
//功能概要：进入停机模式
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void MCU_STOP(void)
{
	  
  
    HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);//停机模式
    HAL_RCC_DeInit();
    SystemClock_Config();
    /*
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);	//停机模式
    RCC_Configuration();							//恢复系统时钟		
*/
}



void main2(void)
{
  //uint32_t i = 0;
  HAL_Init();
  SystemClock_Config();
  
  while(1)
  {
      //LED_GPIO_Init();
      //LED_ON();
      //for(i=0;i<3;i++)Delay_MS(1000);
      //LED_OFF();
      EnterStopMode_GPIO_Config();//所有引脚配置为模拟输入
      EnterStopMode_GPIO_Interrupt();//相关按键和AS3933唤醒引脚中断输入
      EnterStopMode();
      HAL_Init();
      SystemClock_Config();
  }
}


//=============================================================================
//文件名称：LowPowerIOConfig
//功能概要：低能耗配置
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void LowPowerIOConfig(void)
{

    printf("-------------------------进入LowPowerIOConfig----------------------------\r\n");
    /*

    //STOP状态下，GPIO设置
    //关闭发射电路电源
    //RF_POWER_ON(0);
    //RFCOUT_Zeor();
    //RFDOUT_Zeor();

    //AS3933
    //CS_Zeor();
    //SCLK_Zeor();
    //SDI_Zeor();

    //SD0();
    //WAKE();
    //DAT();
    //CL_DAT();

    //
    EnterStopMode_GPIO_Config();//所有引脚配置为模拟输入
    RF_POWER_GPIO_Init();
    EnterStopMode_GPIO_Interrupt();//睡眠前，相关按键和AS3933唤醒引脚中断输入
    EnterStopMode();

    //复位时钟配置
    HAL_RCC_DeInit();
    //复位全部物理块，初始化Flash接口和 Systick时钟
    //Reset of all peripherals, Initializes the Flash interface and the Systick. 
    HAL_Init();

    //重置环境时钟配置
    //SystemClock_Config();
    
    //EnterStopMode_GPIO_Interrupt();//唤醒后，相关按键和AS3933唤醒引脚中断输入
    //系统初始化
    SYS_InIt();
    //硬件重新初始化，不是必须
    //HW_Init();
    LED_GPIO_Init();
    
    RF_POWER_GPIO_Init();
      
    //RF_SEND_GPIO_Init();
    
    //AS3933_GPIO_Init();

    //AS3933_Init(); 
    
    //硬件初始化完成
    Init_Finish = 1;
    printf("HW_Init Ok ...\r\n");
    
    //软件参数初始化
    SW_Init();
*/
}




//=============================================================================
//文件名称：void PWM_SetCompare1(TIM_TypeDef* TIMx, uint16_t Compare1)
//功能概要：设置占空比
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void PWM_SetCompare1(TIM_TypeDef* TIMx, uint16_t Compare1)
{
  // Check the parameters 
  assert_param(IS_TIM_LIST8_PERIPH(TIMx));
  // Set the Capture Compare1 Register value 
  TIMx->CCR1 = Compare1;
}

//=============================================================================
//文件名称：void PWM_SetCompare2(TIM_TypeDef* TIMx, uint16_t Compare1)
//功能概要：设置占空比
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//============================================================================

void PWM_SetCompare2(TIM_TypeDef* TIMx, uint16_t Compare2)
{
  // Check the parameters 
  assert_param(IS_TIM_LIST6_PERIPH(TIMx));
  //Set the Capture Compare2 Register value 
  TIMx->CCR2 = Compare2;
}

//=============================================================================
//文件名称：void PWM_SetDutyRatio(TIM_HandleTypeDef *htim,uint32_t Channel,uint8_t value)
//功能概要：调整占空比函数 
//参数说明：value为占空比 value=50 即占空比为50%
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================
/*
void PWM_SetDutyRatio(TIM_HandleTypeDef *htim,uint32_t Channel,uint8_t value)
{
	TIM_OC_InitTypeDef sConfigOC;
	
	uint32_t period=htim->Init.Period+1;
	uint32_t pluse=(value * period)/100;
	
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = pluse;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_ConfigChannel(htim, &sConfigOC, Channel);
	HAL_TIM_PWM_Start(htim, Channel);   
}*/

//=============================================================================
//文件名称：void PWM_SetValue(TIM_HandleTypeDef *htim,uint32_t Channel,uint16_t value)
//功能概要：调整占空比函数 
//参数说明：value为占空比 value=50 即占空比为50%
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================
/*
void PWM_SetValue(TIM_HandleTypeDef *htim,uint32_t Channel,uint16_t value)
{
    TIM_OC_InitTypeDef sConfigOC;
  
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = value;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(htim, &sConfigOC, Channel);
    HAL_TIM_PWM_Start(htim, TIM_CHANNEL_1);  
}*/




//=============================================================================
//文件名称：void GLOBAL_USART1_Set(unsigned int baudrate)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void GLOBAL_USART1_Set(unsigned int baudrate)
{
	GLOBAL_USART1_UART_Init(baudrate);
	HAL_UART_Receive_IT( &huart1 , &RxByte1, 1); 
	__HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);  
	huart1.Instance->SR = 0;

}

//=============================================================================
//文件名称：void GLOBAL_USART2_Set(unsigned int baudrate)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void GLOBAL_USART2_Set(unsigned int baudrate)
{
	GLOBAL_USART2_UART_Init(baudrate);
	HAL_UART_Receive_IT( &huart2 , &RxByte2, 1); 
	__HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);  
	huart2.Instance->SR = 0;

}

//=============================================================================
//文件名称：void GLOBAL_USART3_Set(unsigned int baudrate)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void GLOBAL_USART3_Set(unsigned int baudrate)
{
	GLOBAL_USART3_UART_Init(baudrate);
	HAL_UART_Receive_IT( &huart3 , &RxByte3, 1); 
	__HAL_UART_ENABLE_IT(&huart3, UART_IT_RXNE);  
	huart3.Instance->SR = 0;

}

//=============================================================================
//文件名称：void GLOBAL_UART4_Set(unsigned int baudrate)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void GLOBAL_UART4_Set(unsigned int baudrate)
{/*
	GLOBAL_UART4_Init(baudrate);
	HAL_UART_Receive_IT( &huart4 , &RxByte4, 1); 
	__HAL_UART_ENABLE_IT(&huart4, UART_IT_RXNE);  
	huart4.Instance->SR = 0;
*/
}

//=============================================================================
//文件名称：void GLOBAL_UART5_Set(unsigned int baudrate)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void GLOBAL_UART5_Set(unsigned int baudrate)
{/*
	GLOBAL_UART5_Init(baudrate);
	HAL_UART_Receive_IT( &huart5 , &RxByte5, 1); 
	__HAL_UART_ENABLE_IT(&huart5, UART_IT_RXNE);  
	huart5.Instance->SR = 0;
*/
}

//=============================================================================
//文件名称：void GLOBAL_UART5_Set(unsigned int baudrate)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void GLOBAL_Module_Set(unsigned char module)
{
	switch(module)
	{
	case 0:printf("XBR105 \r\n");
		break;
	case 1:printf("XBR201 \r\n");
		break;
	case 2:printf("XBR401 \r\n");
		break;
	case 3:printf("XBR202 \r\n");
		break;
	default:printf("No Module \r\n");
		break;

	}

}




