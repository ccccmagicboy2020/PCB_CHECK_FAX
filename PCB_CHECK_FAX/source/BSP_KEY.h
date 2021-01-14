//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_KEY.h
//功能概要：BSP_KEY驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================


#ifndef BSP_KEY_H
#define BSP_KEY_H

#define KEY_1_PIN                   GPIO_PIN_15
#define KEY_1_GPIO_PORT             GPIOC
#define KEY_1_GPIO_CLK              RCU_GPIOC

#define KEY_2_PIN                   GPIO_PIN_14
#define KEY_2_GPIO_PORT             GPIOC
#define KEY_2_GPIO_CLK              RCU_GPIOC

#define KEY_3_PIN                   GPIO_PIN_13
#define KEY_3_GPIO_PORT             GPIOC
#define KEY_3_GPIO_CLK              RCU_GPIOC

#define KEY_1_READ()  HAL_GPIO_ReadPin(KEY_1_GPIO_PORT, KEY_1_PIN)
#define KEY_2_READ()  HAL_GPIO_ReadPin(KEY_2_GPIO_PORT, KEY_2_PIN)
#define KEY_3_READ()  HAL_GPIO_ReadPin(KEY_3_GPIO_PORT, KEY_3_PIN)

/**********************************************************************
* 程序 : void GPIO_KEY_Init(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void GPIO_KEY_Init(void);

#endif
