//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_74HC4052A.h
//功能概要：BSP_74HC4052A驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#ifndef BSP_74HC4052A_H_
#define BSP_74HC4052A_H_


#define COL_A_PIN                   GPIO_PIN_12
#define COL_A_GPIO_PORT             GPIOA
#define COL_A_GPIO_CLK              RCU_GPIOA

#define COL_B_PIN                   GPIO_PIN_15
#define COL_B_GPIO_PORT             GPIOA
#define COL_B_GPIO_CLK              RCU_GPIOA

#define ROW_A_PIN                   GPIO_PIN_12
#define ROW_A_GPIO_PORT             GPIOB
#define ROW_A_GPIO_CLK              RCU_GPIOB

#define ROW_B_PIN                   GPIO_PIN_13
#define ROW_B_GPIO_PORT             GPIOB
#define ROW_B_GPIO_CLK              RCU_GPIOB

#define COL_A_ON()	HAL_GPIO_WritePin(COL_A_GPIO_PORT, COL_A_PIN, GPIO_PIN_SET)
#define COL_A_OFF()	HAL_GPIO_WritePin(COL_A_GPIO_PORT, COL_A_PIN, GPIO_PIN_RESET)

#define COL_B_ON()	HAL_GPIO_WritePin(COL_B_GPIO_PORT, COL_B_PIN, GPIO_PIN_SET)
#define COL_B_OFF()	HAL_GPIO_WritePin(COL_B_GPIO_PORT, COL_B_PIN, GPIO_PIN_RESET)

#define ROW_A_ON()	HAL_GPIO_WritePin(ROW_A_GPIO_PORT, ROW_A_PIN, GPIO_PIN_SET)
#define ROW_A_OFF()	HAL_GPIO_WritePin(ROW_A_GPIO_PORT, ROW_A_PIN, GPIO_PIN_RESET)

#define ROW_B_ON()	HAL_GPIO_WritePin(ROW_B_GPIO_PORT, ROW_B_PIN, GPIO_PIN_SET)
#define ROW_B_OFF()	HAL_GPIO_WritePin(ROW_B_GPIO_PORT, ROW_B_PIN, GPIO_PIN_RESET)


//=============================================================================
//文件名称：void GPIO_HC4052A_Init(void)
//功能概要：初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void GPIO_HC4052A_Init(void);

//=============================================================================
//文件名称：void HC4052A_Delay(unsigned int nms)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void HC4052A_Delay(unsigned int nms);

//=============================================================================
//文件名称：void HC4052A_Set_ColAB(unsigned char i)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void HC4052A_Set_ColAB(unsigned char i);

//=============================================================================
//文件名称：void HC4052A_Set_RowAB(unsigned char j)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void HC4052A_Set_RowAB(unsigned char j);



#endif
