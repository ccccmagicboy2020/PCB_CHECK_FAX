//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_LED.c
//功能概要：BSP_LED驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================


#ifndef BSP_LED_H
#define BSP_LED_H

#define LED_CON_PIN                   GPIO_PIN_1
#define LED_CON_GPIO_PORT             GPIOB
#define LED_CON_GPIO_CLK              RCU_GPIOB

#define D2_PIN                   GPIO_PIN_1
#define D2_GPIO_PORT             GPIOB
#define D2_GPIO_CLK              RCU_GPIOB

#define D3_PIN                   GPIO_PIN_1
#define D3_GPIO_PORT             GPIOB
#define D3_GPIO_CLK              RCU_GPIOB

#define LED_CON_ON()	HAL_GPIO_WritePin(LED_CON_GPIO_PORT, LED_CON_PIN, GPIO_PIN_SET)
#define LED_CON_OFF()	HAL_GPIO_WritePin(LED_CON_GPIO_PORT, LED_CON_PIN, GPIO_PIN_RESET)

#define D2_ON()	HAL_GPIO_WritePin(D2_GPIO_PORT, D2_PIN, GPIO_PIN_SET)
#define D2_OFF()	HAL_GPIO_WritePin(D2_GPIO_PORT, D2_PIN, GPIO_PIN_RESET)

#define D3_ON()	HAL_GPIO_WritePin(D3_GPIO_PORT, D3_PIN, GPIO_PIN_SET)
#define D3_OFF()	HAL_GPIO_WritePin(D3_GPIO_PORT, D3_PIN, GPIO_PIN_RESET)
/**********************************************************************
* 程序 : void GPIO_LED_Init(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void GPIO_LED_Init(void);

/**********************************************************************
* 程序 : void LED_Set(unsigned char State)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void LED_Set(unsigned char State);

/**********************************************************************
* 程序 : void LED_Set(unsigned char State)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void LED_HC595_Set(unsigned int State);

#endif
