//=============================================================================
//文件名称：IT.h
//功能概要：IT驱动头文件
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================
#ifndef IT_H
#define IT_H

#include "stm32f1xx.h"

extern uint32_t uhADCxConvertedValue;
extern uint32_t ADC_ConvertedValue;
extern float ADC_ConvertedValueLocal;

//=============================================================================
//文件名称：void HAL_SYSTICK_Callback(void)
//功能概要：系统时钟中断回调函数 
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void HAL_SYSTICK_Callback(void);

//=============================================================================
//文件名称：void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//功能概要：串口中断接收回调函数 
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

//=============================================================================
//文件名称：void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
//功能概要：串口中断发送结束回调函数 
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);


//=============================================================================
//文件名称：void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//功能概要：定时器中断回调程序
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

//=============================================================================
//文件名称：void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//功能概要：GPIO中断回调函数 
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);



//=============================================================================
//文件名称：void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle)
//功能概要：ADC中断回调程序
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* AdcHandle);


#endif

