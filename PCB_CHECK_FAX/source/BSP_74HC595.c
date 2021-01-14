//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_HC595.c
//���ܸ�Ҫ��BSP_HC595����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================

#include "INCLUDE_EXT.h"
#include "BSP_74HC595.h"






//=============================================================================
//�ļ����ƣ�void GPIO_HC595_Init(void)
//���ܸ�Ҫ����ʼ��
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void GPIO_HC595_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;
    
    // ʹ��GPIOAʱ�� 
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOD_CLK_ENABLE();

		//MC74HC595 U7
		//RCLK
    GPIO_InitStruct.Pin = RCLK_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(RCLK_GPIO_PORT, &GPIO_InitStruct);
	//SRCLK
    GPIO_InitStruct.Pin = SRCLK_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(SRCLK_GPIO_PORT, &GPIO_InitStruct);
	//DATA
    GPIO_InitStruct.Pin = DATA_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(DATA_GPIO_PORT, &GPIO_InitStruct);
	//LED1_1
    //GPIO_InitStruct.Pin = SRCLK1_PIN;
    //GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    //GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    //GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    //HAL_GPIO_Init(SRCLK1_GPIO_PORT, &GPIO_InitStruct);
		
		//MC74HC595 U8
		//RCLK
    GPIO_InitStruct.Pin = RCLK_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(RCLK_GPIO_PORT, &GPIO_InitStruct);
	//SRCLK
    GPIO_InitStruct.Pin = SRCLK_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(SRCLK_GPIO_PORT, &GPIO_InitStruct);
	//QH
    //GPIO_InitStruct.Pin = EN_D1_PIN;
    //GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    //GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    //GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    //HAL_GPIO_Init(EN_D1_GPIO_PORT, &GPIO_InitStruct);
	//EN_1_C1
    //GPIO_InitStruct.Pin = SRCLK1_PIN;
    //GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    //GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    //GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    //HAL_GPIO_Init(SRCLK1_GPIO_PORT, &GPIO_InitStruct);
	
		//MC74HC595 U14
		//RCLK_1
    GPIO_InitStruct.Pin = RCLK1_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(RCLK1_GPIO_PORT, &GPIO_InitStruct);
	//SRCLK_1
    GPIO_InitStruct.Pin = SRCLK1_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(SRCLK1_GPIO_PORT, &GPIO_InitStruct);
	//EN_D1
    GPIO_InitStruct.Pin = EN_D1_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(EN_D1_GPIO_PORT, &GPIO_InitStruct);
	//EN_1_C1
    //GPIO_InitStruct.Pin = SRCLK1_PIN;
    //GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    //GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    //GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    //HAL_GPIO_Init(SRCLK1_GPIO_PORT, &GPIO_InitStruct);
		
		//MC74HC595 U15
		//RCLK_2
    GPIO_InitStruct.Pin = RCLK2_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(RCLK2_GPIO_PORT, &GPIO_InitStruct);
	//SRCLK_2
    GPIO_InitStruct.Pin = SRCLK2_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(SRCLK2_GPIO_PORT, &GPIO_InitStruct);
	//EN_D2
    GPIO_InitStruct.Pin = EN_D2_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(EN_D2_GPIO_PORT, &GPIO_InitStruct);
	//EN_1_C3
    //GPIO_InitStruct.Pin = SRCLK1_PIN;
    //GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    //GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    //GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    //HAL_GPIO_Init(SRCLK1_GPIO_PORT, &GPIO_InitStruct);
		
		// ����CS��Ӧ����

    //HAL_GPIO_WritePin(EEPROM_PORT_I2C_CS, EEPROM_I2C_CS_PIN, GPIO_PIN_RESET);//CS 
    //HAL_GPIO_WritePin(EEPROM_PORT_I2C_SCL, EEPROM_I2C_SCL_PIN, GPIO_PIN_RESET);//SCL
    //HAL_GPIO_WritePin(EEPROM_PORT_I2C_SDA, EEPROM_I2C_SDA_PIN, GPIO_PIN_RESET);//SDA 

		//U10 U11 U12
		//COL_A
    GPIO_InitStruct.Pin = COL_A_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(COL_A_GPIO_PORT, &GPIO_InitStruct);
	//COL_B
    GPIO_InitStruct.Pin = COL_B_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;//GPIO_PULLUP GPIO_PULLDOWN  GPIO_NOPULL
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//GPIO_SPEED_FREQ_LOW GPIO_SPEED_FREQ_MEDIUM  GPIO_SPEED_FREQ_HIGH
    HAL_GPIO_Init(COL_B_GPIO_PORT, &GPIO_InitStruct);

		//U14
		//RCLK1_ON();
		//SRCLK1_ON();
		//EN_D1_ON();
		RCLK1_OFF();
		SRCLK1_OFF();
		EN_D1_OFF();
		//U15
		//RCLK2_ON();//��ֹ��¼��һֱ��¼
		//SRCLK2_ON();
		//EN_D2_ON();
		RCLK2_OFF();//������¼��ʱ
		SRCLK2_OFF();
		EN_D2_OFF();
		//U7
		//RCLK_ON();
		//SRCLK_ON();
		//DATA_ON();
		RCLK_OFF();
		SRCLK_OFF();
		DATA_OFF();
		//U8
		//RCLK_ON();
		//SRCLK_ON();
		//DATA_ON();
		//RCLK_OFF();
		//SRCLK_OFF();
		//DATA_OFF();
		
		//U10 U11 U12
		//COL_A_ON();
		COL_A_OFF();

		//COL_B_ON();
		COL_B_OFF();
}



//=============================================================================
//�ļ����ƣ�void HC595_Delay(unsigned int nms)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void HC595_Delay(unsigned int nms)
{
  unsigned int i;
  while(nms--)
    for(i=0;i<1;i++);
}


//=============================================================================
//�ļ����ƣ�void HC595_Show_led(unsigned int led_data)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void HC595_Show_led(unsigned int led_data)
{
	unsigned char i;
	
	RCLK_OFF();
	SRCLK_OFF();
	//DATA_OFF;
	HC595_Delay(3);
	
	for(i=0;i<16;i++)
	{
		if((led_data&0x8000)==0)DATA_OFF();
		else DATA_ON();
		led_data<<=1;
		
		SRCLK_ON();
		HC595_Delay(3);
		SRCLK_OFF();
	}
	DATA_OFF();
	HC595_Delay(3);
	RCLK_ON();
	HC595_Delay(3);
	RCLK_OFF();
	
}


//=============================================================================
//�ļ����ƣ�void HC595_Set_Power1(unsigned char con_data)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void HC595_Set_Power1(unsigned char con_data)
{
	unsigned char i;
	
	RCLK1_OFF();
	SRCLK1_OFF();
	//DATA_OFF();
	HC595_Delay(3);
	
	for(i=0;i<8;i++)
	{
		if((con_data&0x80)==0)EN_D1_OFF();
		else EN_D1_ON();
		con_data<<=1;
		
		SRCLK1_ON();
		HC595_Delay(3);
		SRCLK1_OFF();
	}
	EN_D1_OFF();
	HC595_Delay(3);
	RCLK1_ON();
	HC595_Delay(3);
	RCLK1_OFF();
	
}


//=============================================================================
//�ļ����ƣ�void HC595_Set_Power2(unsigned char con_data)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void HC595_Set_Power2(unsigned char con_data)
{
	unsigned char i;

	RCLK2_OFF();
	SRCLK2_OFF();
	//DATA_OFF;
	HC595_Delay(3);
	
	for(i=0;i<8;i++)
	{
		if((con_data&0x80)==0)EN_D2_OFF();
		else EN_D2_ON();
		con_data<<=1;
		
		SRCLK2_ON();
		HC595_Delay(3);
		SRCLK2_OFF();
	}
	EN_D2_OFF();
	HC595_Delay(3);
	RCLK2_ON();
	HC595_Delay(3);
	RCLK2_OFF();

}

//=============================================================================
//�ļ����ƣ�void HC595_Set_Power3(unsigned int con_data)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void HC595_Set_Power3(unsigned int con_data)
{
	unsigned char i;
	
	RCLK1_OFF();
	SRCLK1_OFF();
	//EN_D1_OFF();
	HC595_Delay(3);
	
	for(i=0;i<32;i++)
	{
		if((con_data&0x80000000)==0)EN_D1_OFF();
		else EN_D1_ON();
		con_data<<=1;
		
		SRCLK1_ON();
		HC595_Delay(3);
		SRCLK1_OFF();
	}
	EN_D1_OFF();
	HC595_Delay(3);
	RCLK1_ON();
	HC595_Delay(3);
	RCLK1_OFF();
	
}

