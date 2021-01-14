//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�systick.c
//���ܸ�Ҫ��systick����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================

#include "stm32f1xx_hal.h"
#include "systick.h"
#include "INCLUDE_EXT.h"



volatile uint32_t delay;

_SYSTEM_CLK  SysClkCount;


//=============================================================================
//�ļ����ƣ�void systick_config(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
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
//�ļ����ƣ�void delay_1ms(uint32_t count)
//���ܸ�Ҫ����
//����˵����count: count in milliseconds
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
//=============================================================================

void delay_1ms(uint32_t count)
{
    delay = count;

    while(0U != delay){
    }
}

//=============================================================================
//�ļ����ƣ�void delay_decrement(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
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
//�ļ����ƣ�unsigned char TaskRunTime_nMs(unsigned char _inx, unsigned short _Time)
//���ܸ�Ҫ����
//����˵����task run Time
//�������أ�1 taskrun 0 task on run
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
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
//�ļ����ƣ�void HAL_IncTick(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: 738275730@qq.com
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
	//һ���ȡһ��ADC
	//Radar_ObtainAdc(Radar_GetAdc);
	//Radar_ObtainAdc_Call(Get_Adc(2));

	if(Beep_times != 0)
	{
		Beep_times--;
		BEEP_TOGGLE();
	}

}

