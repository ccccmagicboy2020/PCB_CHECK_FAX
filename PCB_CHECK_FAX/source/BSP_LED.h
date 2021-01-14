//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_LED.c
//���ܸ�Ҫ��BSP_LED����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================


#ifndef BSP_LED_H
#define BSP_LED_H

#define LED_CON_PIN                   GPIO_PIN_1
#define LED_CON_GPIO_PORT             GPIOB
#define LED_CON_GPIO_CLK              RCU_GPIOB

#define D2_PIN                   GPIO_PIN_1
#define D2_GPIO_PORT             GPIOB
#define D2_GPIO_CLK              RCU_GPIOB

#define D3_PIN                   GPIO_PIN_1
#define D3_GPIO_PORT             GPIOB
#define D3_GPIO_CLK              RCU_GPIOB

#define LED_CON_ON()	HAL_GPIO_WritePin(LED_CON_GPIO_PORT, LED_CON_PIN, GPIO_PIN_SET)
#define LED_CON_OFF()	HAL_GPIO_WritePin(LED_CON_GPIO_PORT, LED_CON_PIN, GPIO_PIN_RESET)

#define D2_ON()	HAL_GPIO_WritePin(D2_GPIO_PORT, D2_PIN, GPIO_PIN_SET)
#define D2_OFF()	HAL_GPIO_WritePin(D2_GPIO_PORT, D2_PIN, GPIO_PIN_RESET)

#define D3_ON()	HAL_GPIO_WritePin(D3_GPIO_PORT, D3_PIN, GPIO_PIN_SET)
#define D3_OFF()	HAL_GPIO_WritePin(D3_GPIO_PORT, D3_PIN, GPIO_PIN_RESET)
/**********************************************************************
* ���� : void GPIO_LED_Init(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void GPIO_LED_Init(void);

/**********************************************************************
* ���� : void LED_Set(unsigned char State)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void LED_Set(unsigned char State);

/**********************************************************************
* ���� : void LED_Set(unsigned char State)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void LED_HC595_Set(unsigned int State);

#endif
