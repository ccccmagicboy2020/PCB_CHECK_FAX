//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_LED.c
//功能概要：BSP_LED驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================


#include "INCLUDE_EXT.h"
#include "BSP_LED.h"


/**********************************************************************
* 程序 : void GPIO_LED_Init(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void GPIO_LED_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;
    
    // 使能GPIOA时钟 
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();

		//LED
    GPIO_InitStruct.Pin = LED_CON_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(LED_CON_GPIO_PORT, &GPIO_InitStruct);
		//D2
    GPIO_InitStruct.Pin = D2_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(D2_GPIO_PORT, &GPIO_InitStruct);
		//D3
    GPIO_InitStruct.Pin = D3_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(D3_GPIO_PORT, &GPIO_InitStruct);
}

/**********************************************************************
* 程序 : void LED_Set(unsigned char State)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void LED_Set(unsigned char State)
{
	
	switch(State)
	{
		case 1:
			D2_ON();
			break;
		case 2:
			D2_OFF();
			break;
		case 3:
			D3_ON();
			break;
		case 4:
			D3_ON();
			break;
		case 5:
			LED_CON_ON();
			break;
		case 6:
			LED_CON_OFF();
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			break;
		
	}

}

/**********************************************************************
* 程序 : void LED_Set(unsigned char State)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void LED_HC595_Set(unsigned int State)
{
	HC595_Show_led(State);
}


