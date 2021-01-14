//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_KEY.h
//���ܸ�Ҫ��BSP_KEY����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================


#ifndef BSP_KEY_H
#define BSP_KEY_H

#define KEY_1_PIN                   GPIO_PIN_15
#define KEY_1_GPIO_PORT             GPIOC
#define KEY_1_GPIO_CLK              RCU_GPIOC

#define KEY_2_PIN                   GPIO_PIN_14
#define KEY_2_GPIO_PORT             GPIOC
#define KEY_2_GPIO_CLK              RCU_GPIOC

#define KEY_3_PIN                   GPIO_PIN_13
#define KEY_3_GPIO_PORT             GPIOC
#define KEY_3_GPIO_CLK              RCU_GPIOC

#define KEY_1_READ()  HAL_GPIO_ReadPin(KEY_1_GPIO_PORT, KEY_1_PIN)
#define KEY_2_READ()  HAL_GPIO_ReadPin(KEY_2_GPIO_PORT, KEY_2_PIN)
#define KEY_3_READ()  HAL_GPIO_ReadPin(KEY_3_GPIO_PORT, KEY_3_PIN)

/**********************************************************************
* ���� : void GPIO_KEY_Init(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void GPIO_KEY_Init(void);

#endif
