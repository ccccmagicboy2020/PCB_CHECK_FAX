//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：Global.c
//功能概要：Global驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#include "INCLUDE_EXT.h"

   
/*Global Variable*/

uint8_t temp_cout;

char UART1_RxBuff[1000] = {0};
char UART1_RxCmd[1000] = {0};
unsigned int UART1_RxLen = 0;
unsigned char UART1_RxFlag = 0;
char UART1_TxBuff[100] = {0};
unsigned int UART1_TxLen = 0;
unsigned char UART1_TxFlag = 0;

char UART2_RxBuff[1000] = {0};
char UART2_RxCmd[1000] = {0};
unsigned int UART2_RxLen = 0;
unsigned char UART2_RxFlag = 0;
char UART2_TxBuff[100] = {0};
unsigned int UART2_TxLen = 0;
unsigned char UART2_TxFlag = 0;

char UART3_RxBuff[1000] = {0};
char UART3_RxCmd[1000] = {0};
unsigned int UART3_RxLen = 0;
unsigned char UART3_RxFlag = 0;
char UART3_TxBuff[100] = {0};
unsigned int UART3_TxLen = 0;
unsigned char UART3_TxFlag = 0;

char UART4_RxBuff[1000] = {0};
char UART4_RxCmd[1000] = {0};
unsigned int UART4_RxLen = 0;
unsigned char UART4_RxFlag = 0;
char UART4_TxBuff[100] = {0};
unsigned int UART4_TxLen = 0;
unsigned char UART4_TxFlag = 0;

char UART5_RxBuff[1000] = {0};
char UART5_RxCmd[1000] = {0};
unsigned int UART5_RxLen = 0;
unsigned char UART5_RxFlag = 0;
char UART5_TxBuff[100] = {0};
unsigned int UART5_TxLen = 0;
unsigned char UART5_TxFlag = 0;

unsigned char Mqtt_state = 0;
unsigned char Mqtt_step = 0;
unsigned char Mqtt_return = 0;
const char *strcmd_System = "System started";
const char *strcmd_System_ok = "System ok";
const char *strcmd_KaiGuan = "KaiGuan";
const char *strcmd_Kai = "Topic: KaiGuan, Data: 1";
const char *strcmd_Guan = "Topic: KaiGuan, Data: 0";
const char *strcmd_WenDu = "WenDu:";

unsigned char Ble_state = 0;
unsigned char Ble_step = 0;
unsigned char Ble_return = 0;


//=============================================================================
//文件名称：void GLOBAL_NVIC_Init(void)
//功能概要：全局中断优先级初始化
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_NVIC_Init(void)
{
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);
	HAL_NVIC_SetPriority(USART2_IRQn, 2, 0);
	HAL_NVIC_SetPriority(USART3_IRQn, 3, 0);
	//HAL_NVIC_SetPriority(UART4_IRQn, 4, 0);
	//HAL_NVIC_SetPriority(UART5_IRQn, 5, 0);
	//57
	//SENDSTD:500000:7D8:7E8:000:7FF:7D8:08:0000000000000000:
	//77
	//SENDEXT:500000:18DB33F1:18DB33F1:00000000:FFFFFFFF:7D8:08:0000000000000000:

}

//=============================================================================
//文件名称：void GLOBAL_GPIO_Init(void)
//功能概要：全局初始化GPIO
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_GPIO_Init(void)
{
#if 0
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, WIFI_IO0_Pin|WIFI_REST_Pin|WIFI_ON_Pin|LED1_Pin 
                          |LED2_Pin|PWM_ON_Pin|IN8_Pin|IN9_Pin 
                          |IN3_Pin|IN2_Pin|IN1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, CLK_Pin|SPI_SS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, CS_Pin|SCL_Pin|SDA_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, IN7_Pin|IN6_Pin|IN5_Pin|IN4_Pin 
                          |RF_ON_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO1_Pin|GPIO2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin 
                           PCPin */
  GPIO_InitStruct.Pin = WIFI_IO0_Pin|WIFI_REST_Pin|WIFI_ON_Pin|PWM_ON_Pin 
                          |IN8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin 
                           PCPin PCPin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|IN9_Pin|IN3_Pin 
                          |IN2_Pin|IN1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = ZD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ZD_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = K1_Pin|K2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = CLK_Pin|GPIO1_Pin|GPIO2_Pin|SPI_SS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = DAT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(DAT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin 
                           PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = SCL_Pin|SDA_Pin|IN7_Pin|IN6_Pin 
                          |IN5_Pin|IN4_Pin|RF_ON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = SW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(SW_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = GPIO3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIO3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = CODE_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(CODE_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = BRK_IN_Pin|OIL_IN_Pin|KEY_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = PIR_REC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PIR_REC_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
#endif
}

//=============================================================================
//文件名称：void GLOBAL_USART1_UART_Init(unsigned int baudrate)
//功能概要：全局初始化串口1
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_USART1_UART_Init(unsigned int baudrate)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = baudrate;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }

}

//=============================================================================
//文件名称：void GLOBAL_USART2_UART_Init(unsigned int baudrate)
//功能概要：全局初始化串口2
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_USART2_UART_Init(unsigned int baudrate)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = baudrate;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }

}

//=============================================================================
//文件名称：void GLOBAL_USART3_UART_Init(unsigned int baudrate)
//功能概要：全局初始化串口3
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_USART3_UART_Init(unsigned int baudrate)
{

  huart3.Instance = USART3;
  huart3.Init.BaudRate = baudrate;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }

}

//=============================================================================
//文件名称：void GLOBAL_UART4_Init(unsigned int baudrate)
//功能概要：全局初始化串口4
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_UART4_Init(unsigned int baudrate)
{
/*
  huart4.Instance = UART4;
  huart4.Init.BaudRate = baudrate;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
*/
}

//=============================================================================
//文件名称：void GLOBAL_UART5_Init(unsigned int baudrate)
//功能概要：全局初始化串口5
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_UART5_Init(unsigned int baudrate)
{
/*
  huart5.Instance = UART5;
  huart5.Init.BaudRate = baudrate;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
*/
}


//=============================================================================
//文件名称：void GLOBAL_TIM1_Init(void)
//功能概要：全局初始化定时器1
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_TIM1_Init(void)
{
#if 0
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 48-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 10-1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
#endif
}

//=============================================================================
//文件名称：void GLOBAL_TIM2_Init(void)
//功能概要：全局初始化定时器2
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_TIM2_Init(void)
{
#if 0
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 48-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1000-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
#endif
}

//=============================================================================
//文件名称：void GLOBAL_TIM3_Init(void)
//功能概要：全局初始化定时器3
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_TIM3_Init(void)
{
#if 0
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 1-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 384-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim3);
#endif
}

//=============================================================================
//文件名称：void GLOBAL_TIM4_Init(void)
//功能概要：全局初始化定时器4
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_TIM4_Init(void)
{
#if 0
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 1-1;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 1263-1;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim4);
#endif
}

//=============================================================================
//文件名称：void GLOBAL_TIM5_Init(void)
//功能概要：全局初始化定时器5
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_TIM5_Init(void)
{
#if 0
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  htim5.Instance = TIM5;
  htim5.Init.Prescaler = 48-1;
  htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim5.Init.Period = 100-1;
  htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim5) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim5, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
#endif
}

//=============================================================================
//文件名称：void GLOBAL_TIM6_Init(void)
//功能概要：全局初始化定时器6
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_TIM6_Init(void)
{
#if 0
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 48-1;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 10-1;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
#endif
}

//=============================================================================
//文件名称：void GLOBAL_ADC1_Init(void)
//功能概要：全局初始化ADC1
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_ADC1_Init(void)
{
  ADC_ChannelConfTypeDef sConfig = {0};

  /** Common config 
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

}

//=============================================================================
//文件名称：void GLOBAL_ADC2_Init(void)
//功能概要：全局初始化ADC1
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_ADC2_Init(void)
{
  ADC_ChannelConfTypeDef sConfig = {0};

  /** Common config 
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

}

//=============================================================================
//文件名称：void GLOBAL_CAN_Init(void)
//功能概要：全局初始化CAN
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_CAN_Init(void)
{
/*
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 45;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_5TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = DISABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = DISABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
*/
}

//=============================================================================
//文件名称：void GLOBAL_CAN1_Init(void)
//功能概要：全局初始化CAN
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_CAN1_Init(void)
{
/*
	hcan1.Instance = CAN1;
	hcan1.Init.Prescaler = 9;
	hcan1.Init.Mode = CAN_MODE_NORMAL;
	hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
	hcan1.Init.TimeSeg1 = CAN_BS1_5TQ;
	hcan1.Init.TimeSeg2 = CAN_BS2_2TQ;
	hcan1.Init.TimeTriggeredMode = DISABLE;
	hcan1.Init.AutoBusOff = DISABLE;
	hcan1.Init.AutoWakeUp = DISABLE;
	hcan1.Init.AutoRetransmission = DISABLE;
	hcan1.Init.ReceiveFifoLocked = DISABLE;
	hcan1.Init.TransmitFifoPriority = DISABLE;
	if (HAL_CAN_Init(&hcan1) != HAL_OK)
	{
	  Error_Handler();
	}

*/
}

//=============================================================================
//文件名称：void GLOBAL_CAN2_Init(void)
//功能概要：全局初始化CAN
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_CAN2_Init(void)
{
/*
	hcan2.Instance = CAN2;
	hcan2.Init.Prescaler = 9;
	hcan2.Init.Mode = CAN_MODE_NORMAL;
	hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
	hcan2.Init.TimeSeg1 = CAN_BS1_5TQ;
	hcan2.Init.TimeSeg2 = CAN_BS2_2TQ;
	hcan2.Init.TimeTriggeredMode = DISABLE;
	hcan2.Init.AutoBusOff = DISABLE;
	hcan2.Init.AutoWakeUp = DISABLE;
	hcan2.Init.AutoRetransmission = DISABLE;
	hcan2.Init.ReceiveFifoLocked = DISABLE;
	hcan2.Init.TransmitFifoPriority = DISABLE;
	if (HAL_CAN_Init(&hcan2) != HAL_OK)
	{
	  Error_Handler();
	}

*/
}

//=============================================================================
//文件名称：void ClearAll_RC(void)
//功能概要：清除所有遥控器信息
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void ClearAll_RC(void)
{
#if 0
    printf("清除所有遥控器信息\r\n");
    memset(RFData_Buff,0,sizeof(RFData_Buff));//清空缓冲区
    
    AT24C0x_WriteBytes(RFData_Buff,RF_DATA_START_ADD, sizeof(RFData_Buff));	//将高频内容写入
    
    memset(RFData_Buff,0,sizeof(RFData_Buff));//清空缓冲区
    
    AT24C0x_ReadBytes(RFData_Buff,RF_DATA_START_ADD, sizeof(RFData_Buff));	//将高频内容读出	
    for(i=0;i<61;i++)
    {
        printf("RFData_Buff[%d]:0x%x \r\n",i,RFData_Buff[i]);
    }
#endif
}

//=============================================================================
//文件名称：void GOLBAL_Show_Gps(uint8_t Flag)
//功能概要：显示GPS信息
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GOLBAL_Show_Gps(uint8_t Flag)
{
#if 0
  Modeule_System.Module_Timer.bUpDataGpsInfoSec = Flag;
#endif
}
