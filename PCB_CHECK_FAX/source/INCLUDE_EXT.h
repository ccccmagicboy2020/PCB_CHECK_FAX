//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：INCLUDE_EXT.h
//功能概要：INCLUDE_EXT驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#ifndef _INCLUDE_EXT_H
#define _INCLUDE_EXT_H

#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "stdarg.h"
#include "ctype.h"
#include <math.h>
#include "float.h"
//#include "absacc.h"
#include<time.h>
#include "main.h"
//#include "adc.h"
//#include "fatfs.h"
//#include "rtc.h"
//#include "spi.h"
#include "usart.h"
#include "gpio.h"
//#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "adc.h"
#include "systick.h"


//#include "BSP.h"
//#include "BSP_DELAY.h"
#include "BSP_Flash.h"
//#include "BSP_HBS640.h"
//#include "BSP_I2C.h"
//#include "BSP_NRF24L01.h"
//#include "BSP_SPI.h"
//#include "BSP_UART.h"
#include "BSP_Control.h"
#include "BSP_ADC.h"
#include "BSP_BEEP.h"
#include "BSP_KEY.h"
#include "BSP_LED.h"
#include "BSP_MOTO.h"
#include "BSP_74HC595.h"
#include "BSP_Flash.h"
#include "BSP_Printer.h"
#include "BSP_74HC4051A.h"
#include "BSP_74HC4052A.h"
#include "BSP_74HC595.h"
#include "BSP_FUN.h"
#include "BSP_PUBLIC.h"

#include "Global.h"
#include "DataType.h"
#include "Typedef.h"
#include "IT.h"


#include "MODE_XBR.h"
#include "MODE_XBR105.h"
#include "MODE_XBR201.h"
#include "MODE_XBR401.h"
#include "MODE_XBR202.h"
#include "INCLUDE_EXT.h"
//#include "INTERRUPT_EXT.h"


#define HARDWARE_VERSION	0X03
#define SOFTWARE_VERSION	0X01


//PCB CHECK INFO
typedef struct
{
    unsigned char    	check_status;      //测试状态标志
    unsigned int	   	Current;        		//电流值
    unsigned int	   	V_1V;     					//1.2V电压值
    unsigned int	   	V_AD;     					//3V电压值
    unsigned char 	 	out_st;       			//输出状态---3次检测全正确为0，
															//第一次检测应为高，否则加1，第二次检测应为低，否则加10，第三次检测应为高，否则加100
	unsigned int		SUM0;//
	unsigned int		SUM1;//

	unsigned int    	V_ADMAX;
	unsigned int	 	V_ADMIN;
	unsigned int	 	V_ADMAX0;
	unsigned int		V_ADMIN0;
	unsigned int	 	V_ADMAX1;
	unsigned int		V_ADMIN1;

	unsigned char		NUM_H0;
	unsigned char 		NUM_L0;

	unsigned char		NUM_H1;
	unsigned char		NUM_L1;

	unsigned char		read_light; 
	unsigned char 		light_ad;					//感光AD值
	unsigned char		read_tx;
    unsigned char    	tx_data[16];       //发送数据
		
	unsigned char 	errCode;
}PCB_INFO;

typedef enum 
{
    WORK_START = 0,
    WORK_NORMAL = 1,
    WORK_SLEEP = 2,
    WORK_STUDY = 3,
    WORK_STOP = 4,
    WORK_END = 5,
} system_typedef_enum;


typedef struct
{  
	unsigned char    System_Flag;
	unsigned char    Work_Mode;
	unsigned int JTAG_ID;
	unsigned int Unique_ID1;        //UNIQUE_ID[31: 0]
	unsigned int Unique_ID2;        //UNIQUE_ID[63:32]
	unsigned int Unique_ID3;        //UNIQUE_ID[95:63]
	

	
}SYSTEM_MANAGE;

extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;





#define RXBUFFER_MAX	50
#define TXBUFFER_MAX	50
#define CMDBUFFER_MAX	50

extern unsigned char RxByte1;
extern unsigned char RxByte2;
extern unsigned char RxByte3;
extern unsigned char RxByte4;
extern unsigned char RxByte5;
//UART1
extern unsigned char RxBuffer_1[RXBUFFER_MAX];  //
extern unsigned char TxBuffer_1[TXBUFFER_MAX];		//
extern unsigned char RxLen_1;//
extern unsigned char TxLen_1;	//
extern unsigned char TxLenCount_1;	//
extern unsigned char *pointer_1;		//
extern unsigned char ReceiveFlag_1;	// =1,

//extern unsigned char CmdBuffer[CMDBUFFER_MAX][RXBUFFER_MAX];//
extern unsigned char CmdBuffer_1[CMDBUFFER_MAX];//
extern unsigned char CmdCount_1;//
extern unsigned char CmdWord_1;//


//UART2
extern unsigned char RxBuffer_2[RXBUFFER_MAX];  //
extern unsigned char TxBuffer_2[TXBUFFER_MAX];		//
extern unsigned char RxLen_2;//
extern unsigned char TxLen_2;	//
extern unsigned char TxLenCount_2;	//
extern unsigned char *pointer_2;		//
extern unsigned char ReceiveFlag_2;	// =1,

//extern unsigned char CmdBuffer_2[CMDBUFFER_MAX][RXBUFFER_MAX];//
extern unsigned char CmdBuffer_2[CMDBUFFER_MAX];//
extern unsigned char CmdCount_2;//
extern unsigned char CmdWord_2;//

//UART3
extern unsigned char RxBuffer_3[RXBUFFER_MAX];  //
extern unsigned char TxBuffer_3[TXBUFFER_MAX];		//
extern unsigned char RxLen_3;//
extern unsigned char TxLen_3;	//
extern unsigned char TxLenCount_3;	//
extern unsigned char *pointer_3;		//
extern unsigned char ReceiveFlag_3;	// =1,

//extern unsigned char CmdBuffer_3[CMDBUFFER_MAX][RXBUFFER_MAX];//
extern unsigned char CmdBuffer_3[CMDBUFFER_MAX];//
extern unsigned char CmdCount_3;//
extern unsigned char CmdWord_3;//

//UART4
extern unsigned char RxBuffer_4[RXBUFFER_MAX];  //
extern unsigned char TxBuffer_4[TXBUFFER_MAX];		//
extern unsigned char RxLen_4;//
extern unsigned char TxLen_4;	//
extern unsigned char TxLenCount_4;	//
extern unsigned char *pointer_4;		//
extern unsigned char ReceiveFlag_4;	// =1,

//extern unsigned char CmdBuffer_4[CMDBUFFER_MAX][RXBUFFER_MAX];//
extern unsigned char CmdBuffer_4[CMDBUFFER_MAX];//
extern unsigned char CmdCount_4;//
extern unsigned char CmdWord_4;//

//UART5
extern unsigned char RxBuffer_5[RXBUFFER_MAX];  //
extern unsigned char TxBuffer_5[TXBUFFER_MAX];		//
extern unsigned char RxLen_5;//
extern unsigned char TxLen_5;	//
extern unsigned char TxLenCount_5;	//
extern unsigned char *pointer_5;		//
extern unsigned char ReceiveFlag_5;	// =1,

//extern unsigned char CmdBuffer_5[CMDBUFFER_MAX][RXBUFFER_MAX];//
extern unsigned char CmdBuffer_5[CMDBUFFER_MAX];//
extern unsigned char CmdCount_5;//
extern unsigned char CmdWord_5;//

extern unsigned char rec_data_num;
extern unsigned char USART1_recnum;
extern unsigned char USART1_recdata[16];	//与被测灯控板通讯

extern unsigned char USART2_recnum;
extern unsigned char USART2_senddata[30];
extern unsigned char USART2_recdata[30];	//与上位机通讯
extern unsigned char flag_rec;
extern unsigned char flag_rec2;


extern unsigned int  	i;
extern unsigned int		j;
extern unsigned int		m;
extern unsigned int  	KEY1_DOWN;
extern unsigned int 	KEY2_DOWN;
extern unsigned int 	KEY3_DOWN;
extern unsigned int start_command;
extern unsigned int target_start;

extern unsigned int power_con;
extern unsigned int  led_data;
extern unsigned int  k;
extern unsigned int  tempv_16;
extern unsigned int  light_ad;
extern unsigned int  max_light_ad;
extern unsigned int  min_light_ad;
extern unsigned int 	sum;
extern unsigned int  sum1;
extern unsigned int Mode_Sate;
extern unsigned int ADC_Value[3];
extern float VOL_Value[3];

extern volatile uint32_t sysTickUptimems;//ms
extern volatile uint32_t sysTickUptimeus;//us   

extern unsigned long sysTickDtrTimems;//ms
extern unsigned long sysTickOutTimems;//ms
extern unsigned long sysTickDtrDownTimems;//ms
extern unsigned long sysTickDtrUpTimems;//ms
extern unsigned long sysTickOutDownTimems;//ms
extern unsigned long sysTickOutUpTimems;//ms

extern unsigned char State;
extern unsigned char rxbuf[50];
extern unsigned char tmp_buf[50];

extern unsigned int LIMITS_16[16];
extern unsigned int PARAMETER_16[16];	//各参数限值
extern unsigned char LIMITS[16];//,LIMITS_0[16]={40,64,93,109,118,90,95,150,30,180,30,41,112,0,0,0};
extern unsigned char PARAMETER_8[16];

extern unsigned char St;
extern PCB_INFO pcb_check_info[8][4];

extern SYSTEM_MANAGE  System_Manage;

extern const char str_poweron[];
extern const char str_start[];

extern const char str_light0[];
extern const char str_dark[];
extern const char str_bright[];

extern const char str_num[];
extern const char str_current[];
extern const char str_mA[];
extern const char str_short[];
extern const char str_3V[];
extern const char str_1V[];
extern const char str_light[];
extern const char str_dcv[];
extern const char str_out[];
extern const char str_readlighterr[];
extern const char str_readtxerr[];
extern const char str_th[];
extern const char str_ok[];


extern void usmart_scan(void);


//声明外部程序
//=============================================================================
//文件名称：void rcu_config(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void rcu_config(void);

//=============================================================================
//文件名称：void gpio_config(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void gpio_config(void);


//=============================================================================
//文件名称：void Clock_Init(void)
//功能概要：时钟初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void Clock_Init(void);

//=============================================================================
//文件名称：void System_Init(void)
//功能概要：系统初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void System_Init(void);

//=============================================================================
//文件名称：void ST_Init(void)
//功能概要：存储空间初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void ST_Init(void);

//=============================================================================
//文件名称：void Soft_Init(void)
//功能概要：软件初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void Soft_Init(void);

//=============================================================================
//文件名称：void Hardware_Init(void)
//功能概要：硬件初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void Hardware_Init(void);

//=============================================================================
//文件名称：void Data_Init(void)
//功能概要：数据初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================


void Data_Init(void);

//=============================================================================
//文件名称：void Start_Init(void)
//功能概要：开始工作
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void Start_Init(void);


//=============================================================================
//文件名称：void SYS_Test(uint8_t state)
//功能概要：系统测试
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void SYS_Test(uint8_t state);



//=============================================================================
//文件名称：void Scheduler_Init(void)
//功能概要：系统调度
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================


void Scheduler_Init(void);






















#endif
