//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_PUBLIC.c
//���ܸ�Ҫ��BSP_PUBLIC����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================


#include "INCLUDE_EXT.h"
#include "BSP_PUBLIC.h"

extern void SystemClock_Config(void);





//=============================================================================
//�ļ����ƣ�void PVD_Init(void)
//���ܸ�Ҫ���������ʼ��
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void PVD_Init(void)
{

 }


//=============================================================================
//�ļ����ƣ�uint8_t RCC_GetSYSCLKSource(void)
//���ܸ�Ҫ����ȡϵͳʱ��
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

uint8_t RCC_GetSYSCLKSource(void)
{
  return ((uint8_t)(RCC->CFGR & RCC_CFGR_SWS));
}

//=============================================================================
//�ļ����ƣ�void RCC_Configuration(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================


void RCC_Configuration(void)
{

    HAL_RCC_DeInit();	
    SystemClock_Config();
  
}



//=============================================================================
//�ļ����ƣ�void EnterSleepMode(void)
//���ܸ�Ҫ������˯��ģʽ
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void EnterSleepMode(void)
{
  
    HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
    HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
#if 0
    //printf("-------------------------����Sleep״̬----------------------------\r\n");
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
//�ļ����ƣ�void EnterSTOPMode(void)
//���ܸ�Ҫ������ֹͣģʽ
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void EnterSTOPMode(void)
{
    HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
    HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
#if 0
    //printf("-------------------------����STOP״̬----------------------------\r\n");
    //stopģʽ�£�RAM�����֣�IO�ܽŽ������̬�������������ϵͳreset
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE); //ʱ�ӱ���Ҫ����������������������˺ü���
    PWR_BackupAccessCmd(ENABLE);    
    PWR_WakeUpPinCmd(PWR_WakeUpPin_1,ENABLE);  
    //PWR_WakeUpPinCmd(PWR_WakeUpPin_2,ENABLE); 
    //PWR_WakeUpPinCmd(PWR_WakeUpPin_3,ENABLE); 
    PWR_ClearFlag(PWR_FLAG_WU); 
    PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);  
#endif
}
//=============================================================================
//�ļ����ƣ�void EnterSTANDBYMode(void)
//���ܸ�Ҫ������STANDBYģʽ
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void EnterSTANDBYMode(void)
{
    //- Disable all used wakeup sources,
    //- Clear all related wakeup flags, 
    //- Re-enable all used wakeup sources,
    //- Enter the Standby mode.
    // �������л���Դ: ��������PA0 
    HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);

    // ������л��ѱ�־λ 
    __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);

    // ʹ�ܻ������ţ�PA0��Ϊϵͳ�������� 
    HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);

    // ������л��ѱ�־λ 
    __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
    
    // �������ģʽ 
    HAL_PWR_EnterSTANDBYMode();
    
    //��������жϱ�־
    __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
#if 0
    //printf("-------------------------����STAND״̬----------------------------\r\n");
    //standbyģʽ�£�RAM�����֣�IO�ܽŽ������̬�������������ϵͳreset
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE); //ʱ�ӱ���Ҫ����������������������˺ü���
    PWR_BackupAccessCmd(ENABLE);    
    PWR_WakeUpPinCmd(PWR_WakeUpPin_1,ENABLE);  
    //PWR_WakeUpPinCmd(PWR_WakeUpPin_2,ENABLE); 
    //PWR_WakeUpPinCmd(PWR_WakeUpPin_3,ENABLE); 
    PWR_ClearFlag(PWR_FLAG_WU); 
    PWR_EnterSTANDBYMode();
#endif
}

//=============================================================================
//�ļ����ƣ�void EnterSLEEP(void)
//���ܸ�Ҫ������˯��ģʽ
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void EnterSLEEP(void)
{
#if 0
    //GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);  //��ȫʧ��JTAG/SWD ���ص���Ҳ����Ӱ��
    //GPIO_PinRemapConfig( GPIO_Remap_PD01 , ENABLE );//����ΪGPIO�����ص���Ҳ����Ӱ��
    RCC_LSEConfig(RCC_LSE_OFF);//�ر�RTC�� ���ص���Ҳ����Ҳ��Ӱ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    //ADC_CONFIG(DISABLE);
    USART_DeInit(USART1);
    USART_DeInit(USART2);
    USART_DeInit(USART3);
    USART_DeInit(USART4);
    USART_DeInit(USART5);
    //EXTI_INITIAL(ENABLE);//���¶˿ڵ���������Ӱ��
    //GPIO_PIN_INITIAL(GPIOA,GPIO_Pin_All,GPIO_Mode_AIN,0); //�˴�û���ⲿ���ѡ������ڲ��ԡ�EXTI��������GPIO��Ӱ�����
    //GPIO_PIN_INITIAL(GPIOB,GPIO_Pin_All,GPIO_Mode_AIN,0); 
    //GPIO_PIN_INITIAL(GPIOC,GPIO_Pin_All,GPIO_Mode_AIN,0); 
    //GPIO_PIN_INITIAL(GPIOD,GPIO_Pin_All,GPIO_Mode_AIN,0);
    //PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);//STOPģʽ
    PWR_EnterSTANDBYMode();//standbyģʽ 
#endif
}

//=============================================================================
//�ļ����ƣ�Power_Off
//���ܸ�Ҫ���ص粢������ܺ�״̬
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void Power_Off(void)
{
    //Soft_Delay_US(80000);//8000Ϊ1ms
#if 0
    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_InitStruct.EXTI_Line = EXTI_Line0 | EXTI_Line1 | EXTI_Line2;//ѡ���ⲿ�ж�ͨ��
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;//�����ж�ģʽ
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling; //�½��ش����ж�
    EXTI_InitStruct.EXTI_LineCmd = DISABLE;//�ر��ⲿ�ж�
    EXTI_Init(&EXTI_InitStruct); 
#endif
    EnterSTANDBYMode();

}

//=============================================================================
//�ļ����ƣ�stop_mode_config
//���ܸ�Ҫ���ڽ���ͣ��ģʽ֮ǰ������ST�ٷ����̣����ȶ����Ž������ã����ó�ģ������״̬��
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
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
//�ļ����ƣ�void EnterStopMode_GPIO_Interrupt(void)
//���ܸ�Ҫ�������ⲿ�жϻ���
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
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
//�ļ����ƣ�void EnterStopMode(void)
//���ܸ�Ҫ�����ý���ֹͣģʽ���ȴ�����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void EnterStopMode(void)
{
    //HAL_PWREx_EnableUltraLowPower();
    //HAL_PWREx_EnableFastWakeUp();
    //__HAL_RCC_WAKEUPSTOP_CLK_CONFIG(RCC_STOP_WAKEUPCLOCK_HSI);
    HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
}

//=============================================================================
//�ļ����ƣ�void EnterStopMode_GPIO_Config(void)
//���ܸ�Ҫ��������������ģ������
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
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
//�ļ����ƣ�void MCU_STOP(void)
//���ܸ�Ҫ������ͣ��ģʽ
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void MCU_STOP(void)
{
	  
  
    HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);//ͣ��ģʽ
    HAL_RCC_DeInit();
    SystemClock_Config();
    /*
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);	//ͣ��ģʽ
    RCC_Configuration();							//�ָ�ϵͳʱ��		
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
      EnterStopMode_GPIO_Config();//������������Ϊģ������
      EnterStopMode_GPIO_Interrupt();//��ذ�����AS3933���������ж�����
      EnterStopMode();
      HAL_Init();
      SystemClock_Config();
  }
}


//=============================================================================
//�ļ����ƣ�LowPowerIOConfig
//���ܸ�Ҫ�����ܺ�����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void LowPowerIOConfig(void)
{

    printf("-------------------------����LowPowerIOConfig----------------------------\r\n");
    /*

    //STOP״̬�£�GPIO����
    //�رշ����·��Դ
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
    EnterStopMode_GPIO_Config();//������������Ϊģ������
    RF_POWER_GPIO_Init();
    EnterStopMode_GPIO_Interrupt();//˯��ǰ����ذ�����AS3933���������ж�����
    EnterStopMode();

    //��λʱ������
    HAL_RCC_DeInit();
    //��λȫ������飬��ʼ��Flash�ӿں� Systickʱ��
    //Reset of all peripherals, Initializes the Flash interface and the Systick. 
    HAL_Init();

    //���û���ʱ������
    //SystemClock_Config();
    
    //EnterStopMode_GPIO_Interrupt();//���Ѻ���ذ�����AS3933���������ж�����
    //ϵͳ��ʼ��
    SYS_InIt();
    //Ӳ�����³�ʼ�������Ǳ���
    //HW_Init();
    LED_GPIO_Init();
    
    RF_POWER_GPIO_Init();
      
    //RF_SEND_GPIO_Init();
    
    //AS3933_GPIO_Init();

    //AS3933_Init(); 
    
    //Ӳ����ʼ�����
    Init_Finish = 1;
    printf("HW_Init Ok ...\r\n");
    
    //���������ʼ��
    SW_Init();
*/
}




//=============================================================================
//�ļ����ƣ�void PWM_SetCompare1(TIM_TypeDef* TIMx, uint16_t Compare1)
//���ܸ�Ҫ������ռ�ձ�
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void PWM_SetCompare1(TIM_TypeDef* TIMx, uint16_t Compare1)
{
  // Check the parameters 
  assert_param(IS_TIM_LIST8_PERIPH(TIMx));
  // Set the Capture Compare1 Register value 
  TIMx->CCR1 = Compare1;
}

//=============================================================================
//�ļ����ƣ�void PWM_SetCompare2(TIM_TypeDef* TIMx, uint16_t Compare1)
//���ܸ�Ҫ������ռ�ձ�
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//============================================================================

void PWM_SetCompare2(TIM_TypeDef* TIMx, uint16_t Compare2)
{
  // Check the parameters 
  assert_param(IS_TIM_LIST6_PERIPH(TIMx));
  //Set the Capture Compare2 Register value 
  TIMx->CCR2 = Compare2;
}

//=============================================================================
//�ļ����ƣ�void PWM_SetDutyRatio(TIM_HandleTypeDef *htim,uint32_t Channel,uint8_t value)
//���ܸ�Ҫ������ռ�ձȺ��� 
//����˵����valueΪռ�ձ� value=50 ��ռ�ձ�Ϊ50%
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
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
//�ļ����ƣ�void PWM_SetValue(TIM_HandleTypeDef *htim,uint32_t Channel,uint16_t value)
//���ܸ�Ҫ������ռ�ձȺ��� 
//����˵����valueΪռ�ձ� value=50 ��ռ�ձ�Ϊ50%
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
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
//�ļ����ƣ�void GLOBAL_USART1_Set(unsigned int baudrate)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void GLOBAL_USART1_Set(unsigned int baudrate)
{
	GLOBAL_USART1_UART_Init(baudrate);
	HAL_UART_Receive_IT( &huart1 , &RxByte1, 1); 
	__HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);  
	huart1.Instance->SR = 0;

}

//=============================================================================
//�ļ����ƣ�void GLOBAL_USART2_Set(unsigned int baudrate)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void GLOBAL_USART2_Set(unsigned int baudrate)
{
	GLOBAL_USART2_UART_Init(baudrate);
	HAL_UART_Receive_IT( &huart2 , &RxByte2, 1); 
	__HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);  
	huart2.Instance->SR = 0;

}

//=============================================================================
//�ļ����ƣ�void GLOBAL_USART3_Set(unsigned int baudrate)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void GLOBAL_USART3_Set(unsigned int baudrate)
{
	GLOBAL_USART3_UART_Init(baudrate);
	HAL_UART_Receive_IT( &huart3 , &RxByte3, 1); 
	__HAL_UART_ENABLE_IT(&huart3, UART_IT_RXNE);  
	huart3.Instance->SR = 0;

}

//=============================================================================
//�ļ����ƣ�void GLOBAL_UART4_Set(unsigned int baudrate)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
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
//�ļ����ƣ�void GLOBAL_UART5_Set(unsigned int baudrate)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
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
//�ļ����ƣ�void GLOBAL_UART5_Set(unsigned int baudrate)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
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




