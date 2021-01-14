//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_HC595.c
//功能概要：BSP_HC595驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================


#ifndef BSP_HC595_H_
#define BSP_HC595_H_

//#define true  1
//#define false 0

/*
#define PRT_DTR_PIN                   GPIO_PIN_7
#define PRT_DTR_GPIO_PORT             GPIOA
#define PRT_DTR_GPIO_CLK              RCU_GPIOA

#define O_OUT_PIN                   GPIO_PIN_3
#define O_OUT_GPIO_PORT             GPIOB
#define O_OUT_GPIO_CLK              RCU_GPIOB

#define KEY_1_PIN                   GPIO_PIN_15
#define KEY_1_GPIO_PORT             GPIOC
#define KEY_1_GPIO_CLK              RCU_GPIOC

#define KEY_2_PIN                   GPIO_PIN_14
#define KEY_2_GPIO_PORT             GPIOC
#define KEY_2_GPIO_CLK              RCU_GPIOC

#define KEY_3_PIN                   GPIO_PIN_13
#define KEY_3_GPIO_PORT             GPIOC
#define KEY_3_GPIO_CLK              RCU_GPIOC

#define MOTO_FORW_PIN               GPIO_PIN_5
#define MOTO_FORW_GPIO_PORT         GPIOA
#define MOTO_FORW_GPIO_CLK          RCU_GPIOA

#define MOTO_BACK_PIN               GPIO_PIN_6
#define MOTO_BACK_GPIO_PORT         GPIOA
#define MOTO_BACK_GPIO_CLK          RCU_GPIOA

#define BEEP_PIN                   GPIO_PIN_11
#define BEEP_GPIO_PORT             GPIOA
#define BEEP_GPIO_CLK              RCU_GPIOA

#define LED_CON_PIN                GPIO_PIN_1
#define LED_CON_GPIO_PORT          GPIOB
#define LED_CON_GPIO_CLK           RCU_GPIOB
*/
#define RCLK1_PIN                   GPIO_PIN_8
#define RCLK1_GPIO_PORT             GPIOA
#define RCLK1_GPIO_CLK              RCU_GPIOA

#define COL_A_PIN                   GPIO_PIN_12
#define COL_A_GPIO_PORT             GPIOA
#define COL_A_GPIO_CLK              RCU_GPIOA

#define COL_B_PIN                   GPIO_PIN_15
#define COL_B_GPIO_PORT             GPIOA
#define COL_B_GPIO_CLK              RCU_GPIOA

#define EN_D2_PIN                   GPIO_PIN_4
#define EN_D2_GPIO_PORT             GPIOB
#define EN_D2_GPIO_CLK              RCU_GPIOB

#define SRCLK2_PIN                   GPIO_PIN_5
#define SRCLK2_GPIO_PORT             GPIOB
#define SRCLK2_GPIO_CLK              RCU_GPIOB

#define RCLK2_PIN                   GPIO_PIN_6
#define RCLK2_GPIO_PORT             GPIOB
#define RCLK2_GPIO_CLK              RCU_GPIOB

#define RCLK_PIN                   GPIO_PIN_7
#define RCLK_GPIO_PORT             GPIOB
#define RCLK_GPIO_CLK              RCU_GPIOB

#define DATA_PIN                   GPIO_PIN_8
#define DATA_GPIO_PORT             GPIOB
#define DATA_GPIO_CLK              RCU_GPIOB

#define SRCLK_PIN                   GPIO_PIN_9
#define SRCLK_GPIO_PORT             GPIOB
#define SRCLK_GPIO_CLK              RCU_GPIOB

#define ROW_A_PIN                   GPIO_PIN_12
#define ROW_A_GPIO_PORT             GPIOB
#define ROW_A_GPIO_CLK              RCU_GPIOB

#define ROW_B_PIN                   GPIO_PIN_13
#define ROW_B_GPIO_PORT             GPIOB
#define ROW_B_GPIO_CLK              RCU_GPIOB

#define SRCLK1_PIN                   GPIO_PIN_14
#define SRCLK1_GPIO_PORT             GPIOB
#define SRCLK1_GPIO_CLK              RCU_GPIOB

#define EN_D1_PIN                   GPIO_PIN_15
#define EN_D1_GPIO_PORT             GPIOB
#define EN_D1_GPIO_CLK              RCU_GPIOB
/*
#define PRT_DTR_READ()  HAL_GPIO_ReadPin(PRT_DTR_GPIO_PORT, PRT_DTR_PIN)
#define O_OUT_READ()  HAL_GPIO_ReadPin(O_OUT_GPIO_PORT, O_OUT_PIN)
#define KEY_1_READ()  HAL_GPIO_ReadPin(O_OUT_GPIO_PORT, O_OUT_PIN)
#define KEY_2_READ()  HAL_GPIO_ReadPin(O_OUT_GPIO_PORT, O_OUT_PIN)
#define KEY_3_READ()  HAL_GPIO_ReadPin(O_OUT_GPIO_PORT, O_OUT_PIN)

//GPIOA
#define MOTO_FORW_ON()	HAL_GPIO_WritePin(MOTO_FORW_GPIO_PORT, MOTO_FORW_PIN, GPIO_PIN_SET)
#define MOTO_FORW_OFF()	HAL_GPIO_WritePin(MOTO_FORW_GPIO_PORT, MOTO_FORW_PIN, GPIO_PIN_RESET)

#define MOTO_BACK_ON()	HAL_GPIO_WritePin(MOTO_BACK_GPIO_PORT, MOTO_BACK_PIN, GPIO_PIN_SET)
#define MOTO_BACK_OFF()	HAL_GPIO_WritePin(MOTO_BACK_GPIO_PORT, MOTO_BACK_PIN, GPIO_PIN_RESET)

#define BEEP_ON()	HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_PIN, GPIO_PIN_SET)
#define BEEP_OFF()	HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_PIN, GPIO_PIN_RESET)

#define LED_CON_ON()	HAL_GPIO_WritePin(LED_CON_GPIO_PORT, LED_CON_PIN, GPIO_PIN_SET)
#define LED_CON_OFF()	HAL_GPIO_WritePin(LED_CON_GPIO_PORT, LED_CON_PIN, GPIO_PIN_RESET)
*/

#define RCLK1_ON()	HAL_GPIO_WritePin(RCLK1_GPIO_PORT, RCLK1_PIN, GPIO_PIN_SET)
#define RCLK1_OFF()	HAL_GPIO_WritePin(RCLK1_GPIO_PORT, RCLK1_PIN, GPIO_PIN_RESET)

#define COL_A_ON()	HAL_GPIO_WritePin(COL_A_GPIO_PORT, COL_A_PIN, GPIO_PIN_SET)
#define COL_A_OFF()	HAL_GPIO_WritePin(COL_A_GPIO_PORT, COL_A_PIN, GPIO_PIN_RESET)

#define COL_B_ON()	HAL_GPIO_WritePin(COL_B_GPIO_PORT, COL_B_PIN, GPIO_PIN_SET)
#define COL_B_OFF()	HAL_GPIO_WritePin(COL_B_GPIO_PORT, COL_B_PIN, GPIO_PIN_RESET)

#define EN_D2_ON()	HAL_GPIO_WritePin(EN_D2_GPIO_PORT, EN_D2_PIN, GPIO_PIN_SET)
#define EN_D2_OFF()	HAL_GPIO_WritePin(EN_D2_GPIO_PORT, EN_D2_PIN, GPIO_PIN_RESET)

#define SRCLK2_ON()	HAL_GPIO_WritePin(SRCLK2_GPIO_PORT, SRCLK2_PIN, GPIO_PIN_SET)
#define SRCLK2_OFF()	HAL_GPIO_WritePin(SRCLK2_GPIO_PORT, SRCLK2_PIN, GPIO_PIN_RESET)

#define RCLK2_ON()	HAL_GPIO_WritePin(RCLK2_GPIO_PORT, RCLK2_PIN, GPIO_PIN_SET)
#define RCLK2_OFF()	HAL_GPIO_WritePin(RCLK2_GPIO_PORT, RCLK2_PIN, GPIO_PIN_RESET)

#define RCLK_ON()	HAL_GPIO_WritePin(RCLK_GPIO_PORT, RCLK_PIN, GPIO_PIN_SET)
#define RCLK_OFF()	HAL_GPIO_WritePin(RCLK_GPIO_PORT, RCLK_PIN, GPIO_PIN_RESET)

#define DATA_ON()	HAL_GPIO_WritePin(DATA_GPIO_PORT, DATA_PIN, GPIO_PIN_SET)
#define DATA_OFF()	HAL_GPIO_WritePin(DATA_GPIO_PORT, DATA_PIN, GPIO_PIN_RESET)

#define SRCLK_ON()	HAL_GPIO_WritePin(SRCLK_GPIO_PORT, SRCLK_PIN, GPIO_PIN_SET)
#define SRCLK_OFF()	HAL_GPIO_WritePin(SRCLK_GPIO_PORT, SRCLK_PIN, GPIO_PIN_RESET)

#define ROW_A_ON()	HAL_GPIO_WritePin(ROW_A_GPIO_PORT, ROW_A_PIN, GPIO_PIN_SET)
#define ROW_A_OFF()	HAL_GPIO_WritePin(ROW_A_GPIO_PORT, ROW_A_PIN, GPIO_PIN_RESET)

#define ROW_B_ON()	HAL_GPIO_WritePin(ROW_B_GPIO_PORT, ROW_B_PIN, GPIO_PIN_SET)
#define ROW_B_OFF()	HAL_GPIO_WritePin(ROW_B_GPIO_PORT, ROW_B_PIN, GPIO_PIN_RESET)

#define SRCLK1_ON()	HAL_GPIO_WritePin(SRCLK1_GPIO_PORT, SRCLK1_PIN, GPIO_PIN_SET)
#define SRCLK1_OFF()	HAL_GPIO_WritePin(SRCLK1_GPIO_PORT, SRCLK1_PIN, GPIO_PIN_RESET)

#define EN_D1_ON()	HAL_GPIO_WritePin(EN_D1_GPIO_PORT, EN_D1_PIN, GPIO_PIN_SET)
#define EN_D1_OFF()	HAL_GPIO_WritePin(EN_D1_GPIO_PORT, EN_D1_PIN, GPIO_PIN_RESET)



//=============================================================================
//文件名称：void GPIO_HC595_Init(void)
//功能概要：初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void GPIO_HC595_Init(void);

//=============================================================================
//文件名称：void HC595_Delay(unsigned int nms)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void HC595_Delay(unsigned int nms);

//=============================================================================
//文件名称：void HC595_Show_led(unsigned int led_data)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void HC595_Show_led(unsigned int led_data);

//=============================================================================
//文件名称：void HC595_Set_Power1(unsigned char con_data)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void HC595_Set_Power1(unsigned char con_data);

//=============================================================================
//文件名称：void HC595_Set_Power2(unsigned char con_data)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void HC595_Set_Power2(unsigned char con_data);


//=============================================================================
//文件名称：void HC595_Set_Power3(unsigned int con_data)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void HC595_Set_Power3(unsigned int con_data);




#endif
