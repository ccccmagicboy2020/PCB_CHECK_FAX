//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_MOTO.h
//���ܸ�Ҫ��BSP_MOTO����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================


#ifndef BSP_MOTO_H_
#define BSP_MOTO_H_


#define MOTO_FORW_PIN               GPIO_PIN_5
#define MOTO_FORW_GPIO_PORT         GPIOA
#define MOTO_FORW_GPIO_CLK          RCU_GPIOA

#define MOTO_BACK_PIN               GPIO_PIN_6
#define MOTO_BACK_GPIO_PORT         GPIOA
#define MOTO_BACK_GPIO_CLK          RCU_GPIOA

#define MOTO_FORW_ON()	HAL_GPIO_WritePin(MOTO_FORW_GPIO_PORT, MOTO_FORW_PIN, GPIO_PIN_SET)
#define MOTO_FORW_OFF()	HAL_GPIO_WritePin(MOTO_FORW_GPIO_PORT, MOTO_FORW_PIN, GPIO_PIN_RESET)

#define MOTO_BACK_ON()	HAL_GPIO_WritePin(MOTO_BACK_GPIO_PORT, MOTO_BACK_PIN, GPIO_PIN_SET)
#define MOTO_BACK_OFF()	HAL_GPIO_WritePin(MOTO_BACK_GPIO_PORT, MOTO_BACK_PIN, GPIO_PIN_RESET)

/**********************************************************************
* ���� : void GPIO_MOTO_Init(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void GPIO_MOTO_Init(void);

/**********************************************************************
* ���� : void MOTO_Control(unsigned char Sate)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void MOTO_Control(unsigned char Sate);

#endif
