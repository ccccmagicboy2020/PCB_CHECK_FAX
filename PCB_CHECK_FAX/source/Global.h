//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：Global.c
//功能概要：Global驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================


#ifndef GLOBAL_H
#define GLOBAL_H




extern uint8_t temp_cout;

extern char UART1_RxBuff[1000];
extern char UART1_RxCmd[1000];
extern unsigned int UART1_RxLen;
extern unsigned char UART1_RxFlag;
extern char UART1_TxBuff[100];
extern unsigned int UART1_TxLen;
extern unsigned char UART1_TxFlag;

extern char UART2_RxBuff[1000];
extern char UART2_RxCmd[1000];
extern unsigned int UART2_RxLen;
extern unsigned char UART2_RxFlag;
extern char UART2_TxBuff[100];
extern unsigned int UART2_TxLen;
extern unsigned char UART2_TxFlag;

extern char UART3_RxBuff[1000];
extern char UART3_RxCmd[1000];
extern unsigned int UART3_RxLen;
extern unsigned char UART3_RxFlag;
extern char UART3_TxBuff[100];
extern unsigned int UART3_TxLen;
extern unsigned char UART3_TxFlag;

extern char UART4_RxBuff[1000];
extern char UART4_RxCmd[1000];
extern unsigned int UART4_RxLen;
extern unsigned char UART4_RxFlag;
extern char UART4_TxBuff[100];
extern unsigned int UART4_TxLen;
extern unsigned char UART4_TxFlag;

extern char UART5_RxBuff[1000];
extern char UART5_RxCmd[1000];
extern unsigned int UART5_RxLen;
extern unsigned char UART5_RxFlag;
extern char UART5_TxBuff[100];
extern unsigned int UART5_TxLen;
extern unsigned char UART5_TxFlag;

extern unsigned char Mqtt_state;
extern unsigned char Mqtt_step;
extern unsigned char Mqtt_return;
extern const char *strcmd_System;
extern const char *strcmd_System_ok;
extern const char *strcmd_KaiGuan;
extern const char *strcmd_Kai;
extern const char *strcmd_Guan;
extern const char *strcmd_WenDu;


extern unsigned char Ble_state;
extern unsigned char Ble_step;
extern unsigned char Ble_return;

//=============================================================================
//文件名称：void GLOBAL_NVIC_Init(void)
//功能概要：全局中断优先级初始化
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_NVIC_Init(void);


//=============================================================================
//文件名称：void GLOBAL_GPIO_Init(void)
//功能概要：全局初始化GPIO
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_GPIO_Init(void);

//=============================================================================
//文件名称：void GLOBAL_USART1_UART_Init(unsigned int baudrate)
//功能概要：全局初始化串口1
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_USART1_UART_Init(unsigned int baudrate);

//=============================================================================
//文件名称：void GLOBAL_USART2_UART_Init(unsigned int baudrate)
//功能概要：全局初始化串口2
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_USART2_UART_Init(unsigned int baudrate);

//=============================================================================
//文件名称：void GLOBAL_USART3_UART_Init(unsigned int baudrate)
//功能概要：全局初始化串口3
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_USART3_UART_Init(unsigned int baudrate);

//=============================================================================
//文件名称：void GLOBAL_UART4_Init(unsigned int baudrate)
//功能概要：全局初始化串口4
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_UART4_Init(unsigned int baudrate);

//=============================================================================
//文件名称：void GLOBAL_UART5_Init(unsigned int baudrate)
//功能概要：全局初始化串口5
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_UART5_Init(unsigned int baudrate);

//=============================================================================
//文件名称：void GLOBAL_TIM1_Init(void)
//功能概要：全局初始化定时器1
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_TIM1_Init(void);

//=============================================================================
//文件名称：void GLOBAL_TIM2_Init(void)
//功能概要：全局初始化定时器2
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_TIM2_Init(void);

//=============================================================================
//文件名称：void GLOBAL_TIM3_Init(void)
//功能概要：全局初始化定时器3
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_TIM3_Init(void);

//=============================================================================
//文件名称：void GLOBAL_TIM4_Init(void)
//功能概要：全局初始化定时器4
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_TIM4_Init(void);

//=============================================================================
//文件名称：void GLOBAL_TIM5_Init(void)
//功能概要：全局初始化定时器5
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_TIM5_Init(void);

//=============================================================================
//文件名称：void GLOBAL_TIM6_Init(void)
//功能概要：全局初始化定时器6
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_TIM6_Init(void);

//=============================================================================
//文件名称：void GLOBAL_ADC1_Init(void)
//功能概要：全局初始化ADC1
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_ADC1_Init(void);

//=============================================================================
//文件名称：void GLOBAL_ADC2_Init(void)
//功能概要：全局初始化ADC1
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_ADC2_Init(void);

//=============================================================================
//文件名称：void GLOBAL_CAN_Init(void)
//功能概要：全局初始化CAN
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_CAN_Init(void);

//=============================================================================
//文件名称：void GLOBAL_CAN1_Init(void)
//功能概要：全局初始化CAN
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_CAN1_Init(void);

//=============================================================================
//文件名称：void GLOBAL_CAN2_Init(void)
//功能概要：全局初始化CAN
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GLOBAL_CAN2_Init(void);

//=============================================================================
//文件名称：void ClearAll_RC(void)
//功能概要：清除所有遥控器信息
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void ClearAll_RC(void);

//=============================================================================
//文件名称：void GOLBAL_Show_Gps(uint8_t Flag)
//功能概要：显示GPS信息
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void GOLBAL_Show_Gps(uint8_t Flag);


#endif

