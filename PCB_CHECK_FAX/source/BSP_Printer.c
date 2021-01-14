//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_Printer.c
//功能概要：BSP_Printer.c驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#include "stm32f1xx_hal.h"
#include "systick.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "INCLUDE_EXT.h"
#include "BSP_Printer.h"




/**********************************************************************
* 程序 : void Usart1_send_char(char Data)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Usart1_send_char(char Data)
{
	  HAL_UART_Transmit(&huart1, (unsigned char *)&Data, 1,0xFFFF);
}

/**********************************************************************
* 程序 : void Usart2_send_char(char Data)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Usart2_send_char(char Data)
{
		HAL_UART_Transmit(&huart2, (unsigned char *)&Data, 1,0xFFFF);
}

/**********************************************************************
* 程序 : void Usart3_send_char(char Data)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Usart3_send_char(char Data)
{
		HAL_UART_Transmit(&huart2, (unsigned char *)&Data, 1,0xFFFF);
}

/**********************************************************************
* 程序 : void Usart4_send_char(char)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Usart4_send_char(char Data)
{
		HAL_UART_Transmit(&huart2, (unsigned char *)&Data, 1,0xFFFF);
}

/**********************************************************************
* 程序 : void Usart5_send_char(char Data)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Usart5_send_char(char Data)
{
		HAL_UART_Transmit(&huart2, (unsigned char *)&Data, 1,0xFFFF);
}



/**********************************************************************
* 程序 : void Usart1_send(unsigned char *str,unsigned char len)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Usart1_send(unsigned char *str,unsigned char len)
{
	unsigned char i;

	for(i=0;i<len;i++)Usart1_send_char(str[i]);
	//HAL_UART_Transmit(&huart1, str, len,0xFFFF);
}

/**********************************************************************
* 程序 : void Usart2_send(unsigned char *str,unsigned char len)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Usart2_send(unsigned char *str,unsigned char len)
{
	unsigned char i;

	for(i=0;i<len;i++)Usart2_send_char(str[i]);
}

/**********************************************************************
* 程序 : void Usart3_send(unsigned char *str,unsigned char len)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Usart3_send(unsigned char *str,unsigned char len)
{
	unsigned char i;

	for(i=0;i<len;i++)Usart3_send_char(str[i]);
}

/**********************************************************************
* 程序 : void Usart4_send(unsigned char *str,unsigned char len)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Usart4_send(unsigned char *str,unsigned char len)
{
	unsigned char i;

	for(i=0;i<len;i++)Usart4_send_char(str[i]);
}




/**********************************************************************
* 程序 : void Usart5_send(unsigned char *str,unsigned char len)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Usart5_send(unsigned char *str,unsigned char len)
{
	unsigned char i;

	for(i=0;i<len;i++)Usart5_send_char(str[i]);
}




