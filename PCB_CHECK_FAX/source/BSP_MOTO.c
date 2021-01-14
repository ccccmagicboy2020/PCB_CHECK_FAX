//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_MOTO.c
//功能概要：BSP_MOTO驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#include "stm32f1xx_hal.h"
#include "systick.h"
#include <stdio.h>
#include <math.h>
#include "BSP_MOTO.h"

/**********************************************************************
* 程序 : void GPIO_MOTO_Init(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void GPIO_MOTO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	// 使能GPIOA时钟 
	__HAL_RCC_GPIOA_CLK_ENABLE();
	//__HAL_RCC_GPIOB_CLK_ENABLE();
	//__HAL_RCC_GPIOC_CLK_ENABLE();

	//MOTO_FORW
	GPIO_InitStruct.Pin = MOTO_FORW_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
	HAL_GPIO_Init(MOTO_FORW_GPIO_PORT, &GPIO_InitStruct);
//MOTO_BACK
	GPIO_InitStruct.Pin = MOTO_BACK_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
	HAL_GPIO_Init(MOTO_BACK_GPIO_PORT, &GPIO_InitStruct);

	MOTO_FORW_OFF();
	MOTO_BACK_OFF();
}


/**********************************************************************
* 程序 : void MOTO_Control(unsigned char Sate)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void MOTO_Control(unsigned char Sate)
{
	if(Sate == 1)//go
	{
		MOTO_FORW_ON();
		MOTO_BACK_OFF();
	}
	else if(Sate == 2)//back
	{
		MOTO_FORW_OFF();
		MOTO_BACK_ON();
	}
	else if(Sate == 3)//stop
	{
		MOTO_FORW_ON();
		MOTO_BACK_ON();
	}
	else//open
	{
		MOTO_FORW_OFF();
		MOTO_BACK_OFF();
	}
	
}

