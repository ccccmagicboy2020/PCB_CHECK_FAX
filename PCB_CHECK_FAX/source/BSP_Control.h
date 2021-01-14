//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_Control.h
//功能概要：BSP_Control驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================


#ifndef BSP_CONTROL_H_
#define BSP_CONTROL_H_

#define PRT_DTR_PIN                   	GPIO_PIN_7
#define PRT_DTR_GPIO_PORT             	GPIOA
#define PRT_DTR_GPIO_CLK              	RCU_GPIOA

#define O_OUT_PIN                   	GPIO_PIN_3
#define O_OUT_GPIO_PORT             	GPIOB
#define O_OUT_GPIO_CLK              	RCU_GPIOB

#define CON1_PIN                   		GPIO_PIN_7
#define CON1_GPIO_PORT             		GPIOB
#define CON1_GPIO_CLK              		RCU_GPIOB

#define RADER_GND_PIN                   GPIO_PIN_8
#define RADER_GND_GPIO_PORT             GPIOA
#define RADER_GND_GPIO_CLK              RCU_GPIOA

#define RADER_VCC_PIN                   GPIO_PIN_7
#define RADER_VCC_GPIO_PORT             GPIOA
#define RADER_VCC_GPIO_CLK              RCU_GPIOA

#define BEEP_GND_PIN                   	GPIO_PIN_1
#define BEEP_GND_GPIO_PORT             	GPIOE
#define BEEP_GND_GPIO_CLK              	RCU_GPIOE

#define BEEP_IO_PIN                   	GPIO_PIN_3
#define BEEP_IO_GPIO_PORT             	GPIOE
#define BEEP_IO_GPIO_CLK              	RCU_GPIOE

#define BEEP_VCC_PIN                   	GPIO_PIN_5
#define BEEP_VCC_GPIO_PORT             	GPIOE
#define BEEP_VCC_GPIO_CLK              	RCU_GPIOE

#define PRT_DTR_READ()  HAL_GPIO_ReadPin(PRT_DTR_GPIO_PORT, PRT_DTR_PIN)
#define O_OUT_READ()  HAL_GPIO_ReadPin(O_OUT_GPIO_PORT, O_OUT_PIN)
#define CON1_ON()	HAL_GPIO_WritePin(CON1_GPIO_PORT, CON1_PIN, GPIO_PIN_SET)
#define CON1_OFF()	HAL_GPIO_WritePin(CON1_GPIO_PORT, CON1_PIN, GPIO_PIN_RESET)

#define RADER_GND_ON()	HAL_GPIO_WritePin(RADER_GND_GPIO_PORT, RADER_GND_PIN, GPIO_PIN_SET)
#define RADER_GND_OFF()	HAL_GPIO_WritePin(RADER_GND_GPIO_PORT, RADER_GND_PIN, GPIO_PIN_RESET)
#define RADER_VCC_ON()	HAL_GPIO_WritePin(RADER_VCC_GPIO_PORT, RADER_VCC_PIN, GPIO_PIN_SET)
#define RADER_VCC_OFF()	HAL_GPIO_WritePin(RADER_VCC_GPIO_PORT, RADER_VCC_PIN, GPIO_PIN_RESET)
#define BEEP_GND_ON()	HAL_GPIO_WritePin(BEEP_GND_GPIO_PORT, BEEP_GND_PIN, GPIO_PIN_SET)
#define BEEP_GND_OFF()	HAL_GPIO_WritePin(BEEP_GND_GPIO_PORT, BEEP_GND_PIN, GPIO_PIN_RESET)
#define BEEP_IO_ON()	HAL_GPIO_WritePin(BEEP_IO_GPIO_PORT, BEEP_IO_PIN, GPIO_PIN_SET)
#define BEEP_IO_OFF()	HAL_GPIO_WritePin(BEEP_IO_GPIO_PORT, BEEP_IO_PIN, GPIO_PIN_RESET)
#define BEEP_VCC_ON()	HAL_GPIO_WritePin(BEEP_VCC_GPIO_PORT, BEEP_VCC_PIN, GPIO_PIN_SET)
#define BEEP_VCC_OFF()	HAL_GPIO_WritePin(BEEP_VCC_GPIO_PORT, BEEP_VCC_PIN, GPIO_PIN_RESET)

//=============================================================================
//文件名称：void GPIO_CONTROL_Init(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void GPIO_CONTROL_Init(void);

//=============================================================================
//文件名称：unsigned char MODE_Input_Dtr(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

unsigned char MODE_Input_Dtr(void);

//=============================================================================
//文件名称：unsigned char MODE_Input_O_Out(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

unsigned char MODE_Input_O_Out(void);



#endif
