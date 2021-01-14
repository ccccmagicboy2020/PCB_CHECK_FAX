//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_BEEP.h
//功能概要：BSP_BEEP驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#ifndef _BSP_BEEP_H_
#define _BSP_BEEP_H_

#define BEEP_PIN                   GPIO_PIN_11
#define BEEP_GPIO_PORT             GPIOA
#define BEEP_GPIO_CLK              RCU_GPIOA

#define BEEP_ON()	HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_PIN, GPIO_PIN_SET)
#define BEEP_OFF()	HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_PIN, GPIO_PIN_RESET)

#define BEEP_TOGGLE()	HAL_GPIO_TogglePin(BEEP_GPIO_PORT, BEEP_PIN)

extern volatile unsigned char Beep_flag;
extern volatile unsigned int Beep_times;

/**********************************************************************
* 程序 : void GPIO_BEEP_Init(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void GPIO_BEEP_Init(void);

/**********************************************************************
* 程序 : void BEEP_Delay(unsigned int nms))
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void BEEP_Delay(unsigned int nms);

/**********************************************************************
* 程序 : void BEEP_Set(unsigned char State)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void BEEP_Set(unsigned char State);

/**********************************************************************
* 程序 : void BEEP_Start(unsigned int times)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void BEEP_Start(unsigned int times);

/**********************************************************************
* 程序 : void BEEP_Stop(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void BEEP_Stop(void);

/**********************************************************************
* 程序 : void BEEP_Wait(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void BEEP_Wait(void);


#endif
