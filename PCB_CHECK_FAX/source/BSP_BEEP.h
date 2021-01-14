//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_BEEP.h
//���ܸ�Ҫ��BSP_BEEP����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================

#ifndef _BSP_BEEP_H_
#define _BSP_BEEP_H_

#define BEEP_PIN                   GPIO_PIN_11
#define BEEP_GPIO_PORT             GPIOA
#define BEEP_GPIO_CLK              RCU_GPIOA

#define BEEP_ON()	HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_PIN, GPIO_PIN_SET)
#define BEEP_OFF()	HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_PIN, GPIO_PIN_RESET)

#define BEEP_TOGGLE()	HAL_GPIO_TogglePin(BEEP_GPIO_PORT, BEEP_PIN)

extern volatile unsigned char Beep_flag;
extern volatile unsigned int Beep_times;

/**********************************************************************
* ���� : void GPIO_BEEP_Init(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void GPIO_BEEP_Init(void);

/**********************************************************************
* ���� : void BEEP_Delay(unsigned int nms))
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void BEEP_Delay(unsigned int nms);

/**********************************************************************
* ���� : void BEEP_Set(unsigned char State)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void BEEP_Set(unsigned char State);

/**********************************************************************
* ���� : void BEEP_Start(unsigned int times)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void BEEP_Start(unsigned int times);

/**********************************************************************
* ���� : void BEEP_Stop(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void BEEP_Stop(void);

/**********************************************************************
* ���� : void BEEP_Wait(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void BEEP_Wait(void);


#endif
