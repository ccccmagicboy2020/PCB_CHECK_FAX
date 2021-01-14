//=============================================================================
//�ļ����ƣ�IT.h
//���ܸ�Ҫ��IT����ͷ�ļ�
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================
#ifndef IT_H
#define IT_H

#include "stm32f1xx.h"

extern uint32_t uhADCxConvertedValue;
extern uint32_t ADC_ConvertedValue;
extern float ADC_ConvertedValueLocal;

//=============================================================================
//�ļ����ƣ�void HAL_SYSTICK_Callback(void)
//���ܸ�Ҫ��ϵͳʱ���жϻص����� 
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void HAL_SYSTICK_Callback(void);

//=============================================================================
//�ļ����ƣ�void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//���ܸ�Ҫ�������жϽ��ջص����� 
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

//=============================================================================
//�ļ����ƣ�void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
//���ܸ�Ҫ�������жϷ��ͽ����ص����� 
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);


//=============================================================================
//�ļ����ƣ�void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//���ܸ�Ҫ����ʱ���жϻص�����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

//=============================================================================
//�ļ����ƣ�void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//���ܸ�Ҫ��GPIO�жϻص����� 
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);



//=============================================================================
//�ļ����ƣ�void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle)
//���ܸ�Ҫ��ADC�жϻص�����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle);


#endif
