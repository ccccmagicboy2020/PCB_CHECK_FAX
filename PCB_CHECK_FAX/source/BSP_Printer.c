//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_Printer.c
//���ܸ�Ҫ��BSP_Printer.c����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================

#include "stm32f1xx_hal.h"
#include "systick.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "INCLUDE_EXT.h"
#include "BSP_Printer.h"




/**********************************************************************
* ���� : void Usart1_send_char(char Data)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Usart1_send_char(char Data)
{
	  HAL_UART_Transmit(&huart1, (unsigned char *)&Data, 1,0xFFFF);
}

/**********************************************************************
* ���� : void Usart2_send_char(char Data)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Usart2_send_char(char Data)
{
		HAL_UART_Transmit(&huart2, (unsigned char *)&Data, 1,0xFFFF);
}

/**********************************************************************
* ���� : void Usart3_send_char(char Data)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Usart3_send_char(char Data)
{
		HAL_UART_Transmit(&huart2, (unsigned char *)&Data, 1,0xFFFF);
}

/**********************************************************************
* ���� : void Usart4_send_char(char)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Usart4_send_char(char Data)
{
		HAL_UART_Transmit(&huart2, (unsigned char *)&Data, 1,0xFFFF);
}

/**********************************************************************
* ���� : void Usart5_send_char(char Data)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Usart5_send_char(char Data)
{
		HAL_UART_Transmit(&huart2, (unsigned char *)&Data, 1,0xFFFF);
}



/**********************************************************************
* ���� : void Usart1_send(unsigned char *str,unsigned char len)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Usart1_send(unsigned char *str,unsigned char len)
{
	unsigned char i;

	for(i=0;i<len;i++)Usart1_send_char(str[i]);
	//HAL_UART_Transmit(&huart1, str, len,0xFFFF);
}

/**********************************************************************
* ���� : void Usart2_send(unsigned char *str,unsigned char len)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Usart2_send(unsigned char *str,unsigned char len)
{
	unsigned char i;

	for(i=0;i<len;i++)Usart2_send_char(str[i]);
}

/**********************************************************************
* ���� : void Usart3_send(unsigned char *str,unsigned char len)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Usart3_send(unsigned char *str,unsigned char len)
{
	unsigned char i;

	for(i=0;i<len;i++)Usart3_send_char(str[i]);
}

/**********************************************************************
* ���� : void Usart4_send(unsigned char *str,unsigned char len)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Usart4_send(unsigned char *str,unsigned char len)
{
	unsigned char i;

	for(i=0;i<len;i++)Usart4_send_char(str[i]);
}




/**********************************************************************
* ���� : void Usart5_send(unsigned char *str,unsigned char len)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Usart5_send(unsigned char *str,unsigned char len)
{
	unsigned char i;

	for(i=0;i<len;i++)Usart5_send_char(str[i]);
}




