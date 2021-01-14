//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_HC74HC4051A.c
//���ܸ�Ҫ��BSP_HC74HC4051A�����ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================

#include "INCLUDE_EXT.h"
#include "BSP_74HC4051A.h"



//=============================================================================
//�ļ����ƣ�void GPIO_HC4051A_Init(void)
//���ܸ�Ҫ����ʼ��
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void GPIO_HC4051A_Init(void)
{
	
    GPIO_InitTypeDef  GPIO_InitStruct;
    
    // ʹ��GPIOAʱ�� 
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
//�ļ����ƣ�void HC4051A_Delay(unsigned int nms)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void HC4051A_Delay(unsigned int nms)
{
  unsigned int i;
  while(nms--)
    for(i=0;i<1;i++);
}


//=============================================================================
//�ļ����ƣ�void HC4051A_Set_ColABC(unsigned char i)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
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
//�ļ����ƣ�void HC4051A_Set_RowAB(unsigned char j)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
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


