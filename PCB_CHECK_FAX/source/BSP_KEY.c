//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_KEY.c
//���ܸ�Ҫ��BSP_KEY����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================

#include "stm32f1xx_hal.h"
#include "systick.h"
#include <stdio.h>
#include <math.h>
#include "BSP_KEY.h"




/**********************************************************************
* ���� : void GPIO_KEY_Init(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void GPIO_KEY_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;

    // ʹ��GPIOAʱ�� 
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
		//KEY1
    GPIO_InitStruct.Pin = KEY_1_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    //GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(KEY_1_GPIO_PORT, &GPIO_InitStruct);
		//KEY2
    GPIO_InitStruct.Pin = KEY_2_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    //GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(KEY_2_GPIO_PORT, &GPIO_InitStruct);
		//KEY3
    GPIO_InitStruct.Pin = KEY_3_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    //GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(KEY_3_GPIO_PORT, &GPIO_InitStruct);

}
