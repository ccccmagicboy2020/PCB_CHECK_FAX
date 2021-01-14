//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_BEEP.c
//功能概要：BSP_BEEP驱动文件
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
#include "BSP_BEEP.h"

volatile unsigned char Beep_flag = 0;
volatile unsigned int Beep_times = 0;


/**********************************************************************
* 程序 : void GPIO_BEEP_Init(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void GPIO_BEEP_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;
    
    // 使能GPIOA时钟 
    __HAL_RCC_GPIOA_CLK_ENABLE();
    //__HAL_RCC_GPIOB_CLK_ENABLE();
    //__HAL_RCC_GPIOC_CLK_ENABLE();

		//BEEP
    GPIO_InitStruct.Pin = BEEP_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStruct);
}


/**********************************************************************
* 程序 : void BEEP_Delay(unsigned int nms))
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void BEEP_Delay(unsigned int nms)
{
  unsigned int i;
  while(nms--)
    for(i=0;i<1;i++);
}

/**********************************************************************
* 程序 : void BEEP_Set(unsigned char State)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void BEEP_Set(unsigned char State)
{
	
	if(State != 0)
	{
		BEEP_ON();
	}
	else
	{
		BEEP_OFF();
	}
	
}

/**********************************************************************
* 程序 : void BEEP_Start(unsigned int times)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void BEEP_Start(unsigned int times)
{
	Beep_flag = 1;
	Beep_times = times;
}

/**********************************************************************
* 程序 : void BEEP_Stop(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void BEEP_Stop(void)
{
	Beep_flag = 0;
	Beep_times = 0;
	BEEP_OFF();
}

/**********************************************************************
* 程序 : void BEEP_Wait(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void BEEP_Wait(void)
{
	while(Beep_times != 0)
	BEEP_Stop();
}


