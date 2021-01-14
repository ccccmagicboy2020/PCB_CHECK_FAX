//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_MOTO.c
//���ܸ�Ҫ��BSP_MOTO����ͷ�ļ�
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
#include "BSP_MOTO.h"

/**********************************************************************
* ���� : void GPIO_MOTO_Init(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void GPIO_MOTO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	// ʹ��GPIOAʱ�� 
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
* ���� : void MOTO_Control(unsigned char Sate)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
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

