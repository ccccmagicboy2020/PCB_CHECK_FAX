//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_Control.c
//功能概要：BSP_Control驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#include "INCLUDE_EXT.h"
#include "BSP_Control.h"

//=============================================================================
//文件名称：void GPIO_CONTROL_Init(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void GPIO_CONTROL_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
	
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
	
	//DTR
	GPIO_InitStruct.Pin = PRT_DTR_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
	HAL_GPIO_Init(PRT_DTR_GPIO_PORT, &GPIO_InitStruct);

	//OUT
	GPIO_InitStruct.Pin = O_OUT_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
	HAL_GPIO_Init(O_OUT_GPIO_PORT, &GPIO_InitStruct);

	//CON1
	GPIO_InitStruct.Pin = CON1_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
	HAL_GPIO_Init(CON1_GPIO_PORT, &GPIO_InitStruct);



	/*
	//RADER_GND
	GPIO_InitStruct.Pin = RADER_GND_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
	HAL_GPIO_Init(RADER_GND_GPIO_PORT, &GPIO_InitStruct);
	RADER_GND_OFF();
	//RADER_VCC
	GPIO_InitStruct.Pin = RADER_VCC_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
	HAL_GPIO_Init(RADER_VCC_GPIO_PORT, &GPIO_InitStruct);
	RADER_VCC_ON();
	
	//BEEP_GND
	GPIO_InitStruct.Pin = BEEP_GND_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
	HAL_GPIO_Init(BEEP_GND_GPIO_PORT, &GPIO_InitStruct);
	BEEP_GND_OFF();
	//BEEP_VCC
	GPIO_InitStruct.Pin = BEEP_VCC_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
	HAL_GPIO_Init(BEEP_VCC_GPIO_PORT, &GPIO_InitStruct);
	BEEP_VCC_ON();
	//BEEP_IO
	GPIO_InitStruct.Pin = BEEP_IO_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
	HAL_GPIO_Init(BEEP_IO_GPIO_PORT, &GPIO_InitStruct);
	//BEEP_IO_ON();
	BEEP_IO_OFF();
	
  GPIO_InitStruct.Pin = PRT_DTR_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(PRT_DTR_GPIO_PORT, &GPIO_InitStruct);
	
  GPIO_InitStruct.Pin = O_OUT_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(O_OUT_GPIO_PORT, &GPIO_InitStruct);
	
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
	*/
}

//=============================================================================
//文件名称：unsigned char MODE_Input_Dtr(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

unsigned char MODE_Input_Dtr(void)
{
	return PRT_DTR_READ();
}

//=============================================================================
//文件名称：unsigned char MODE_Input_O_Out(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

unsigned char MODE_Input_O_Out(void)
{
	return O_OUT_READ();
}






