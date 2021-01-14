//=============================================================================
//公司名称：深圳市
//文件名称：MODE_XBR105.h
//功能概要：MODE_XBR105驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================


#ifndef MODE_XBR105_H
#define MODE_XBR105_H

#include <stdint.h>


extern unsigned int		Current_AdMax;//模块最大电流
extern unsigned int		Current_AdMin;//模块最小电流
extern unsigned int		Current_Short;//短路门限电流

extern unsigned int 		V_1V_AdMax;//模块最大工作电压
extern unsigned int 		V_1V_AdMin;//模块最小工作电压
//静止状态平均值
extern unsigned int 		V_3V_AdMax;//模块雷达信号最大值
extern unsigned int 		V_3V_AdMin;//模块雷达信号最小值
//正向运动状态
extern unsigned int 		V_3V_AdMax0;//最大值
extern unsigned int 		V_3V_AdMin0;//最小值
//反向运动状态
extern unsigned int 		V_3V_AdMax1;//最大值
extern unsigned int 		V_3V_AdMin1;//最小值
//无运动时积分量范围
extern unsigned int		SUM0_Max;//最大值
extern unsigned int 		SUM0_Min;//最小值
//运动时积分量范围
extern unsigned int		SUM1_Max;//最大值
extern unsigned int 		SUM1_Min;//最小值

extern unsigned long long ADC_SUM;

//=============================================================================
//文件名称：void MODE_XBR105(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void MODE_XBR105(void);

//=============================================================================
//文件名称：void MODE_XBR105_Clear(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void MODE_XBR105_Clear(void);

//=============================================================================
//文件名称：unsigned char Chip_IsOk(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

unsigned char Chip_IsOk(void);

//=============================================================================
//文件名称：void MODE_XBR105_Alogo(unsigned char Num)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void MODE_XBR105_Alogo(unsigned char Num);


#endif /* MODE_XBR105_H */
