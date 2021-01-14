//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_HC74HC4051A.c
//功能概要：BSP_HC74HC4051A驱动文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#include "INCLUDE_EXT.h"
#include "BSP_74HC4051A.h"



//=============================================================================
//文件名称：void GPIO_HC4051A_Init(void)
//功能概要：初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void GPIO_HC4051A_Init(void)
{
	
    GPIO_InitTypeDef  GPIO_InitStruct;
    
    // 使能GPIOA时钟 
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    //__HAL_RCC_GPIOC_CLK_ENABLE();

	//DTR
    GPIO_InitStruct.Pin = COL_A_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(COL_A_GPIO_PORT, &GPIO_InitStruct);
	
    GPIO_InitStruct.Pin = COL_B_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(COL_B_GPIO_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = COL_C_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(COL_C_GPIO_PORT, &GPIO_InitStruct);

}

//=============================================================================
//文件名称：void HC4051A_Delay(unsigned int nms)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void HC4051A_Delay(unsigned int nms)
{
  unsigned int i;
  while(nms--)
    for(i=0;i<1;i++);
}


//=============================================================================
//文件名称：void HC4051A_Set_ColABC(unsigned char i)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void HC4051A_Set_ColABC(unsigned char i)
{
	switch(i)
	{
		case 0:
			COL_A_OFF();
			COL_B_OFF();
			COL_C_OFF();
		break;
		case 1:
			COL_A_ON();
			COL_B_OFF();
			COL_C_OFF();
		break;
		case 2:
			COL_A_OFF();
			COL_B_ON();
			COL_C_OFF();
		break;
		case 3:
			COL_A_ON();
			COL_B_ON();
			COL_C_OFF();
		break;
		case 4:
			COL_A_OFF();
			COL_B_OFF();
			COL_C_ON();
		break;
		case 5:
			COL_A_ON();
			COL_B_OFF();
			COL_C_ON();
		break;
		case 6:
			COL_A_OFF();
			COL_B_ON();
			COL_C_ON();
		break;
		case 7:
			COL_A_ON();
			COL_B_ON();
			COL_C_ON();
		break;

		default:
		break;
	}
		
	HC4051A_Delay(5);	
		
}

//=============================================================================
//文件名称：void HC4051A_Set_RowAB(unsigned char j)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void HC4051A_Set_RowAB(unsigned char j)
{
	//U15 U16 U17
	if(j==0)
	{
		ROW_A_OFF();
		ROW_B_OFF();
	}
	else if(j==1)
	{
		ROW_A_ON();
		ROW_B_OFF();					
	}
	else if(j==2)
	{
		ROW_A_OFF();
		ROW_B_ON();					
	}				
	else //if(j==3)
	{
		ROW_A_ON();
		ROW_B_ON();					
	}
	HC4051A_Delay(5);
					
}


