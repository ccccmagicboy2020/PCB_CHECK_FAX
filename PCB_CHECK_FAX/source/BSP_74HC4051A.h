//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_74HC4051A.h
//���ܸ�Ҫ��BSP_74HC4051A����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================

#ifndef BSP_74HC4051A_H_
#define BSP_74HC4051A_H_


#define COL_A_PIN                   GPIO_PIN_12
#define COL_A_GPIO_PORT             GPIOA
#define COL_A_GPIO_CLK              RCU_GPIOA

#define COL_B_PIN                   GPIO_PIN_15
#define COL_B_GPIO_PORT             GPIOA
#define COL_B_GPIO_CLK              RCU_GPIOA

#define COL_C_PIN                   GPIO_PIN_8
#define COL_C_GPIO_PORT             GPIOB
#define COL_C_GPIO_CLK              RCU_GPIOB

#define ROW_A_PIN                   GPIO_PIN_12
#define ROW_A_GPIO_PORT             GPIOB
#define ROW_A_GPIO_CLK              RCU_GPIOB

#define ROW_B_PIN                   GPIO_PIN_13
#define ROW_B_GPIO_PORT             GPIOB
#define ROW_B_GPIO_CLK              RCU_GPIOB

#define COL_A_ON()	HAL_GPIO_WritePin(COL_A_GPIO_PORT, COL_A_PIN, GPIO_PIN_SET)
#define COL_A_OFF()	HAL_GPIO_WritePin(COL_A_GPIO_PORT, COL_A_PIN, GPIO_PIN_RESET)

#define COL_B_ON()	HAL_GPIO_WritePin(COL_B_GPIO_PORT, COL_B_PIN, GPIO_PIN_SET)
#define COL_B_OFF()	HAL_GPIO_WritePin(COL_B_GPIO_PORT, COL_B_PIN, GPIO_PIN_RESET)

#define COL_C_ON()	HAL_GPIO_WritePin(COL_C_GPIO_PORT, COL_C_PIN, GPIO_PIN_SET)
#define COL_C_OFF()	HAL_GPIO_WritePin(COL_C_GPIO_PORT, COL_C_PIN, GPIO_PIN_RESET)

#define ROW_A_ON()	HAL_GPIO_WritePin(ROW_A_GPIO_PORT, ROW_A_PIN, GPIO_PIN_SET)
#define ROW_A_OFF()	HAL_GPIO_WritePin(ROW_A_GPIO_PORT, ROW_A_PIN, GPIO_PIN_RESET)

#define ROW_B_ON()	HAL_GPIO_WritePin(ROW_B_GPIO_PORT, ROW_B_PIN, GPIO_PIN_SET)
#define ROW_B_OFF()	HAL_GPIO_WritePin(ROW_B_GPIO_PORT, ROW_B_PIN, GPIO_PIN_RESET)


//=============================================================================
//�ļ����ƣ�void GPIO_HC4051A_Init(void)
//���ܸ�Ҫ����ʼ��
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void GPIO_HC4051A_Init(void);

//=============================================================================
//�ļ����ƣ�void HC4051A_Delay(unsigned int nms)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void HC4051A_Delay(unsigned int nms);

//=============================================================================
//�ļ����ƣ�void HC4051A_Set_ColABC(unsigned char i)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void HC4051A_Set_ColABC(unsigned char i);

//=============================================================================
//�ļ����ƣ�void HC4051A_Set_RowAB(unsigned char j)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void HC4051A_Set_RowAB(unsigned char j);



#endif
