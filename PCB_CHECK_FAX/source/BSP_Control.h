//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_Control.h
//���ܸ�Ҫ��BSP_Control����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================


#ifndef BSP_CONTROL_H_
#define BSP_CONTROL_H_

#define PRT_DTR_PIN                   	GPIO_PIN_7
#define PRT_DTR_GPIO_PORT             	GPIOA
#define PRT_DTR_GPIO_CLK              	RCU_GPIOA

#define O_OUT_PIN                   	GPIO_PIN_3
#define O_OUT_GPIO_PORT             	GPIOB
#define O_OUT_GPIO_CLK              	RCU_GPIOB

#define CON1_PIN                   		GPIO_PIN_7
#define CON1_GPIO_PORT             		GPIOB
#define CON1_GPIO_CLK              		RCU_GPIOB

#define RADER_GND_PIN                   GPIO_PIN_8
#define RADER_GND_GPIO_PORT             GPIOA
#define RADER_GND_GPIO_CLK              RCU_GPIOA

#define RADER_VCC_PIN                   GPIO_PIN_7
#define RADER_VCC_GPIO_PORT             GPIOA
#define RADER_VCC_GPIO_CLK              RCU_GPIOA

#define BEEP_GND_PIN                   	GPIO_PIN_1
#define BEEP_GND_GPIO_PORT             	GPIOE
#define BEEP_GND_GPIO_CLK              	RCU_GPIOE

#define BEEP_IO_PIN                   	GPIO_PIN_3
#define BEEP_IO_GPIO_PORT             	GPIOE
#define BEEP_IO_GPIO_CLK              	RCU_GPIOE

#define BEEP_VCC_PIN                   	GPIO_PIN_5
#define BEEP_VCC_GPIO_PORT             	GPIOE
#define BEEP_VCC_GPIO_CLK              	RCU_GPIOE

#define PRT_DTR_READ()  HAL_GPIO_ReadPin(PRT_DTR_GPIO_PORT, PRT_DTR_PIN)
#define O_OUT_READ()  HAL_GPIO_ReadPin(O_OUT_GPIO_PORT, O_OUT_PIN)
#define CON1_ON()	HAL_GPIO_WritePin(CON1_GPIO_PORT, CON1_PIN, GPIO_PIN_SET)
#define CON1_OFF()	HAL_GPIO_WritePin(CON1_GPIO_PORT, CON1_PIN, GPIO_PIN_RESET)

#define RADER_GND_ON()	HAL_GPIO_WritePin(RADER_GND_GPIO_PORT, RADER_GND_PIN, GPIO_PIN_SET)
#define RADER_GND_OFF()	HAL_GPIO_WritePin(RADER_GND_GPIO_PORT, RADER_GND_PIN, GPIO_PIN_RESET)
#define RADER_VCC_ON()	HAL_GPIO_WritePin(RADER_VCC_GPIO_PORT, RADER_VCC_PIN, GPIO_PIN_SET)
#define RADER_VCC_OFF()	HAL_GPIO_WritePin(RADER_VCC_GPIO_PORT, RADER_VCC_PIN, GPIO_PIN_RESET)
#define BEEP_GND_ON()	HAL_GPIO_WritePin(BEEP_GND_GPIO_PORT, BEEP_GND_PIN, GPIO_PIN_SET)
#define BEEP_GND_OFF()	HAL_GPIO_WritePin(BEEP_GND_GPIO_PORT, BEEP_GND_PIN, GPIO_PIN_RESET)
#define BEEP_IO_ON()	HAL_GPIO_WritePin(BEEP_IO_GPIO_PORT, BEEP_IO_PIN, GPIO_PIN_SET)
#define BEEP_IO_OFF()	HAL_GPIO_WritePin(BEEP_IO_GPIO_PORT, BEEP_IO_PIN, GPIO_PIN_RESET)
#define BEEP_VCC_ON()	HAL_GPIO_WritePin(BEEP_VCC_GPIO_PORT, BEEP_VCC_PIN, GPIO_PIN_SET)
#define BEEP_VCC_OFF()	HAL_GPIO_WritePin(BEEP_VCC_GPIO_PORT, BEEP_VCC_PIN, GPIO_PIN_RESET)

//=============================================================================
//�ļ����ƣ�void GPIO_CONTROL_Init(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void GPIO_CONTROL_Init(void);

//=============================================================================
//�ļ����ƣ�unsigned char MODE_Input_Dtr(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

unsigned char MODE_Input_Dtr(void);

//=============================================================================
//�ļ����ƣ�unsigned char MODE_Input_O_Out(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

unsigned char MODE_Input_O_Out(void);



#endif
