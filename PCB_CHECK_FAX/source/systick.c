//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：systick.c
//功能概要：systick驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#include "stm32f1xx_hal.h"
#include "systick.h"
#include "INCLUDE_EXT.h"



volatile uint32_t delay;

_SYSTEM_CLK  SysClkCount;


//=============================================================================
//文件名称：void systick_config(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void systick_config(void)
{
    /* setup systick timer for 1000Hz interrupts */
    if (SysTick_Config(SystemCoreClock / 1000U)){
        /* capture error */
        while (1){
        }
    }
    /* configure the systick handler priority */
    NVIC_SetPriority(SysTick_IRQn, 0x00U);
}

//=============================================================================
//文件名称：void delay_1ms(uint32_t count)
//功能概要：无
//参数说明：count: count in milliseconds
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

void delay_1ms(uint32_t count)
{
    delay = count;

    while(0U != delay){
    }
}

//=============================================================================
//文件名称：void delay_decrement(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================
extern volatile uint32_t sysTickUptimems;//ms

void delay_decrement(void)
{
  unsigned char i;

	sysTickUptimems++;
	
  for(i = 0; i < TASK_COUNT; i++)
  {
    SysClkCount.TaskRun1msCount[i]++;
    if(SysClkCount.SysTickDelay1msCount[i] > 0)
    {
      SysClkCount.SysTickDelay1msCount[i]--;
    }
  }

}

//=============================================================================
//文件名称：unsigned char TaskRunTime_nMs(unsigned char _inx, unsigned short _Time)
//功能概要：无
//参数说明：task run Time
//函数返回：1 taskrun 0 task on run
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================

unsigned char TaskRunTime_nMs(unsigned char _inx, unsigned short _Time)
{
  if(_inx >= TASK_COUNT)
    return 0;
  
  if(SysClkCount.TaskRun1msCount[_inx] >= _Time)
  {
    SysClkCount.TaskRun1msCount[_inx] = 0;
    return 1;
  }
  else
  {
    return 0;
  }
}

//=============================================================================
//文件名称：void HAL_IncTick(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: 738275730@qq.com
//=============================================================================


extern  __IO uint32_t uwTick;

void HAL_IncTick(void)
{

  uwTick += uwTickFreq;
	
  if (0U != delay)
  {
     delay--;
  }
  
  delay_decrement();
	//一秒读取一次ADC
	//Radar_ObtainAdc(Radar_GetAdc);
	//Radar_ObtainAdc_Call(Get_Adc(2));

	if(Beep_times != 0)
	{
		Beep_times--;
		BEEP_TOGGLE();
	}

}

