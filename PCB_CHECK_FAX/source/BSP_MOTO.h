//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_MOTO.h
//功能概要：BSP_MOTO驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================


#ifndef BSP_MOTO_H_
#define BSP_MOTO_H_


#define MOTO_FORW_PIN               GPIO_PIN_5
#define MOTO_FORW_GPIO_PORT         GPIOA
#define MOTO_FORW_GPIO_CLK          RCU_GPIOA

#define MOTO_BACK_PIN               GPIO_PIN_6
#define MOTO_BACK_GPIO_PORT         GPIOA
#define MOTO_BACK_GPIO_CLK          RCU_GPIOA

#define MOTO_FORW_ON()	HAL_GPIO_WritePin(MOTO_FORW_GPIO_PORT, MOTO_FORW_PIN, GPIO_PIN_SET)
#define MOTO_FORW_OFF()	HAL_GPIO_WritePin(MOTO_FORW_GPIO_PORT, MOTO_FORW_PIN, GPIO_PIN_RESET)

#define MOTO_BACK_ON()	HAL_GPIO_WritePin(MOTO_BACK_GPIO_PORT, MOTO_BACK_PIN, GPIO_PIN_SET)
#define MOTO_BACK_OFF()	HAL_GPIO_WritePin(MOTO_BACK_GPIO_PORT, MOTO_BACK_PIN, GPIO_PIN_RESET)

/**********************************************************************
* 程序 : void GPIO_MOTO_Init(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void GPIO_MOTO_Init(void);

/**********************************************************************
* 程序 : void MOTO_Control(unsigned char Sate)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void MOTO_Control(unsigned char Sate);

#endif
