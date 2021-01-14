//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_BEEP.c
//���ܸ�Ҫ��BSP_BEEP�����ļ�
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
#include "BSP_BEEP.h"

volatile unsigned char Beep_flag = 0;
volatile unsigned int Beep_times = 0;


/**********************************************************************
* ���� : void GPIO_BEEP_Init(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void GPIO_BEEP_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;
    
    // ʹ��GPIOAʱ�� 
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
* ���� : void BEEP_Delay(unsigned int nms))
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void BEEP_Delay(unsigned int nms)
{
  unsigned int i;
  while(nms--)
    for(i=0;i<1;i++);
}

/**********************************************************************
* ���� : void BEEP_Set(unsigned char State)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
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
* ���� : void BEEP_Start(unsigned int times)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void BEEP_Start(unsigned int times)
{
	Beep_flag = 1;
	Beep_times = times;
}

/**********************************************************************
* ���� : void BEEP_Stop(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void BEEP_Stop(void)
{
	Beep_flag = 0;
	Beep_times = 0;
	BEEP_OFF();
}

/**********************************************************************
* ���� : void BEEP_Wait(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void BEEP_Wait(void)
{
	while(Beep_times != 0)
	BEEP_Stop();
}


