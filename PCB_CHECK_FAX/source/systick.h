//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：systick.h
//功能概要：systick驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#ifndef SYS_TICK_H
#define SYS_TICK_H

#include <stdint.h>

#define TASK_COUNT                 (13)

typedef struct 
{
  volatile unsigned short      SysTickDelay1msCount[TASK_COUNT];
  volatile unsigned short      TaskRun1msCount[TASK_COUNT]; 
  unsigned short                SysWorkTime;
  unsigned long                 SysTime;
  
}_SYSTEM_CLK;
/*---------------------- variables declare ----------------------------------*/
extern volatile uint32_t delay;
extern _SYSTEM_CLK  SysClkCount;

//=============================================================================
//文件名称：void systick_config(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void systick_config(void);

//=============================================================================
//文件名称：void delay_1ms(uint32_t count)
//功能概要：无
//参数说明：count: count in milliseconds
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void delay_1ms(uint32_t count);

//=============================================================================
//文件名称：void delay_decrement(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void delay_decrement(void);

//=============================================================================
//文件名称：unsigned char TaskRunTime_nMs(unsigned char _inx, unsigned short _Time)
//功能概要：无
//参数说明：task run Time
//函数返回：1 taskrun 0 task on run
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

unsigned char TaskRunTime_nMs(unsigned char _inx, unsigned short _Time);

//=============================================================================
//文件名称：void HAL_IncTick(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void HAL_IncTick(void);


#endif /* SYS_TICK_H */
