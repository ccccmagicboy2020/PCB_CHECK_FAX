//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_FUN.c
//���ܸ�Ҫ��BSP_FUN����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================


#include "INCLUDE_EXT.h"
#include "BSP_FUN.h"


//=============================================================================
//�ļ����ƣ�int fputc(int ch, FILE *f)
//���ܸ�Ҫ��retarget the C library printf function to the USART
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

int fputc(int ch, FILE *f)
{

	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1,0xFFFF);
	//HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1,0xFFFF);

  return ch;
}


//=============================================================================
//�ļ����ƣ�int fgetc(FILE *f)
//���ܸ�Ҫ��retarget the C library printf function to the USART
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

int fgetc(FILE *f)
{
    uint8_t ch;

		HAL_UART_Receive(&huart2,(uint8_t *)&ch,1,0xffff);
    return ch;
}


//=============================================================================
//�ļ����ƣ�void delay_init(unsigned char SYSCLK)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void delay_init(unsigned char SYSCLK)
{
  
  
}

//=============================================================================
//�ļ����ƣ�void delay_us(unsigned long nus)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void delay_us(unsigned long nus)
{
    char a=0;
    for(;nus != 0;nus--)
        for(a=0;a<5;a++);
}

//=============================================================================
//�ļ����ƣ�void delay_ms(unsigned int nms)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void delay_ms(unsigned int nms)
{
	delay = nms;
	while(delay != 0);
}

//=============================================================================
//�ļ����ƣ�void delay_xms(unsigned int nms)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void delay_xms(unsigned int nms)
{
	delay = nms;
	while(delay != 0);
}


//=============================================================================
//�ļ����ƣ�void delay_s(unsigned int ns)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void delay_s(unsigned int ns)
{
	delay = ns * 1000;
	while(delay != 0);
}

//=============================================================================
//�ļ����ƣ�void led_spark(void)
//���ܸ�Ҫ��toggle the led every 500ms
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void led_spark(void)
{
    static __IO uint32_t timingdelaylocal = 0;

    if(timingdelaylocal){

        if(timingdelaylocal < 500){
            //gd_eval_led_on(LED2);
        }else{
            //gd_eval_led_off(LED2);
        }

        timingdelaylocal--;
    }else{
        timingdelaylocal = 1000;
    }
}

//=============================================================================
//�ļ����ƣ�void Sys_Soft_Reset(void)
//���ܸ�Ҫ��ʱ�ӳ�ʼ��
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void Sys_Soft_Reset(void)
{
    // ���ϵͳ�Ƿ��ǴӴ���ģʽ������ 
    if (__HAL_PWR_GET_FLAG(PWR_FLAG_SB) != RESET)
    {
        printf("�������Ѹ�λ\r\n");
        // ���������־λ 
        __HAL_PWR_CLEAR_FLAG(PWR_FLAG_SB);
        //������л��ѱ�־λ 
        __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
    }
    else if(__HAL_PWR_GET_FLAG(PWR_FLAG_WU) != RESET)
    {
        printf("RTC �������Ѹ�λ\r\n");
        // ���������־λ 
        __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
    }
    else if(__HAL_PWR_GET_FLAG(PWR_FLAG_PVDO) != RESET)
    {
        printf("PVD��ظ�λ\r\n");
        // ���������־λ 
        __HAL_PWR_CLEAR_FLAG(PWR_FLAG_PVDO);
    }
    /*
    else if(__HAL_PWR_GET_FLAG(PWR_FLAG_VREFINTRDY) != RESET)
    {
      
    }
    else if(__HAL_PWR_GET_FLAG(PWR_FLAG_VOS) != RESET)
    {
      
    }
    else if(__HAL_PWR_GET_FLAG(PWR_FLAG_REGLP) != RESET)
    {
      
    }*/
    else
    {
        printf("ϵͳ���ϵ�����\r\n");
        //printf("������KEY1�ɽ������ģʽ\r\n");
    }

}

//=============================================================================
//�ļ����ƣ�unsigned int Get_JTAG_ID(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

unsigned int Get_JTAG_ID(void)
{
	if( *( uint8_t *)( 0xE00FFFE8 ) & 0x08 )
	{
		return   ( ( *( uint8_t *)( 0xE00FFFD0 ) & 0x0F ) << 8 ) |
		( ( *( uint8_t *)( 0xE00FFFE4 ) & 0xFF ) >> 3  )  | 
		( ( *( uint8_t *)( 0xE00FFFE8 ) & 0x07 ) << 5 ) + 1 ;
	}

	return  0;
}


//=============================================================================
//�ļ����ƣ�unsigned int Get_MCU_ID(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

unsigned int Get_MCU_ID(void)
{

	System_Manage.Unique_ID1 = *(uint32_t *)(0x1FFFF7AC);        //UNIQUE_ID[31: 0]
	System_Manage.Unique_ID2 = *(uint32_t *)(0x1FFFF7B0);        //UNIQUE_ID[63:32]
	System_Manage.Unique_ID3 = *(uint32_t *)(0x1FFFF7B4);        //UNIQUE_ID[95:63]
	
	return  0;
}

//=============================================================================
//�ļ����ƣ�void IWDG_Init(uint32_t prer,uint32_t rlr)
//���ܸ�Ҫ���������Ź���ʼ��,void IWDG_Init(4��625)
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void IWDG_Init(uint32_t prer,uint32_t rlr)
{
    IWDG->KR=0X5555;      //����Ĵ�������        
    IWDG->PR=prer;         // д���ʼ����Ƶֵ
    IWDG->RLR=rlr;            // д���Զ�װ��ֵ
    IWDG->KR=0XAAAA;     //�����Ĵ�������
    IWDG->KR=0XCCCC;       //�������Ź�
}

//=============================================================================
//�ļ����ƣ�void IWDG_Feed(void)
//���ܸ�Ҫ���������Ź�ι������
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void IWDG_Feed(void)
{
    IWDG->KR=0XAAAA;                                  
}

//=============================================================================
//�ļ����ƣ�void Get_CHIP_ID(void)
//���ܸ�Ҫ����ȡоƬID
//����˵����96λ��ID��stm32Ψһ��ݱ�ʶ��������8bit��16bit��32bit��ȡ
//           �ṩ�˴�˺�С�����ֱ�ʾ����
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void Get_CHIP_ID(void)
{
#if 1
      u32 ChipUniqueID[3];
      //��ַ��С����,�ȷŵ��ֽڣ��ٷŸ��ֽڣ�С��ģʽ
      //��ַ��С����,�ȷŸ��ֽڣ��ٷŵ��ֽڣ����ģʽ
      ChipUniqueID[2] = *(__IO u32*)(0X1FFFF7E8);  // ���ֽ�
      ChipUniqueID[1] = *(__IO u32 *)(0X1FFFF7EC); // 
      ChipUniqueID[0] = *(__IO u32 *)(0X1FFFF7F0); // ���ֽ�
      //printf("######## оƬ��ΨһIDΪ: X-X-X  rn",ChipUniqueID[0],ChipUniqueID[1],ChipUniqueID[2]);
      printf("--------оƬΨһIDΪ��%x-%x-%x----------\r\n",ChipUniqueID[0],ChipUniqueID[1],ChipUniqueID[2]);
          //����������32λ
#else   //�����˴�С��ģʽ����ISP���������һ��
      u8 temp[12];   
      u32 temp0,temp1,temp2;
      temp0=*(__IO u32*)(0x1FFFF7E8);    //��ƷΨһ��ݱ�ʶ�Ĵ�����96λ��
      temp1=*(__IO u32*)(0x1FFFF7EC);
      temp2=*(__IO u32*)(0x1FFFF7F0);
      temp[0] = (u8)(temp0 & 0x000000FF);
      temp[1] = (u8)((temp0 & 0x0000FF00)>>8);
      temp[2] = (u8)((temp0 & 0x00FF0000)>>16);
      temp[3] = (u8)((temp0 & 0xFF000000)>>24);
      temp[4] = (u8)(temp1 & 0x000000FF);
      temp[5] = (u8)((temp1 & 0x0000FF00)>>8);
      temp[6] = (u8)((temp1 & 0x00FF0000)>>16);
      temp[7] = (u8)((temp1 & 0xFF000000)>>24);
      temp[8] = (u8)(temp2 & 0x000000FF);
      temp[9] = (u8)((temp2 & 0x0000FF00)>>8);
      temp[10] = (u8)((temp2 & 0x00FF0000)>>16);
      temp[11] = (u8)((temp2 & 0xFF000000)>>24);
      printf("--------STM32оƬIDΪ: %.2X%.2X%.2X%.2X-%.2X%.2X%.2X%.2X-%.2X%.2X%.2X%.2X --------\r\n",
      temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp [11]); //���ڴ�ӡ��оƬID
#endif
}

//=============================================================================
//�ļ����ƣ�void MCO_Output(void)
//���ܸ�Ҫ������ʱ���������
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void MCO_Output(void)
{
  
    GPIO_InitTypeDef  GPIO_InitStruct;

    // ʹ��GPIOAʱ�� 
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    //1������PA.8Ϊ����Push-Pullģʽ�� 
    GPIO_InitStruct.Pin = GPIO_PIN_8; 
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH; 
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; 
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct); 
    //2��ѡ�����ʱ��Դ�� 
    //ʱ�ӵ�ѡ����ʱ�����üĴ���(RCC_CFGR)�е�MCO[2:0]λ���ơ� 
    //RCC_MCOConfig(RCC_MCO); 
  
    HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_SYSCLK, RCC_MCO1SOURCE_HSI);
      
    //uint32_t HAL_RCC_GetSysClockFreq(void)
    //����RCC_MCOΪҪ������ڲ�ʱ�ӣ� 
    //RCC_MCO_NoClock --- ��ʱ����� 
    //RCC_MCO_SYSCLK --- ���ϵͳʱ�ӣ�SysCLK�� 
    //RCC_MCO_HSI --- ����ڲ�����8MHz��RC������ʱ�ӣ�HSI�� 
    //RCC_MCO_HSE --- ��������ⲿʱ���źţ�HSE�� 
    //RCC_MCO_PLLCLK_Div2 --- ���PLL��Ƶ��Ķ���Ƶʱ�ӣ�PLLCLK/2��
}

//=============================================================================
//�ļ����ƣ�void Printf_SystemRccClocks(void)
//���ܸ�Ҫ����ӡϵͳʱ��
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void Printf_SystemRccClocks(void)
{
	uint8_t SYSCLKSource;

	//RCC_ClkInitTypeDef  SystemRCC_Clocks;

  //void HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency)
  
	printf("System start...\r\n");
	//SYSCLKSource = RCC_GetSYSCLKSource();
        SYSCLKSource = HAL_RCC_GetSysClockFreq();
	if(SYSCLKSource==0x04)
		printf("SYSCLKSource is HSE\r\n");
	else if(SYSCLKSource==0x00)
		printf("SYSCLKSource is HSI\r\n");
	else if(SYSCLKSource==0x08)
		printf("SYSCLKSource is PL!\r\n");
/*
	RCC_GetClocksFreq(&SystemRCC_Clocks);
	printf("SYS clock =%dMHz \r\n",(uint32_t)SystemRCC_Clocks.SYSCLK_Frequency/1000000);
	printf("HCLK clock =%dMHz \r\n",(uint32_t)SystemRCC_Clocks.HCLK_Frequency/1000000);
	printf("PCLK clock =%dMHz \r\n",(uint32_t)SystemRCC_Clocks.PCLK_Frequency/1000000);
	printf("ADCCLK clock =%dMHz \r\n",(uint32_t)SystemRCC_Clocks.ADCCLK_Frequency/1000000);	
        printf("CECCLK clock =%dMHz \r\n",(uint32_t)SystemRCC_Clocks.CECCLK_Frequency/1000000);	
        printf("I2C1CLK clock =%dMHz \r\n",(uint32_t)SystemRCC_Clocks.I2C1CLK_Frequency/1000000);	
        printf("USART1CLK clock =%dMHz \r\n",(uint32_t)SystemRCC_Clocks.USART1CLK_Frequency/1000000);	
        */
}

//=============================================================================
//�ļ����ƣ�PrintfLogo
//���ܸ�Ҫ����ӡ�������ƺ����̷�������, ���ϴ����ߺ󣬴�PC���ĳ����ն�������Թ۲���
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void PrintfLogo(void)
{
    printf("\r\n");
	printf("---------------------------------------------------------\r\n");
    printf("* name   : %s\r\n", EXAMPLE_NAME);	// ��ӡ�������� 
    printf("* version   : %s\r\n", DEMO_VER);		// ��ӡ���̰汾 
    printf("* date   : %s\r\n", EXAMPLE_DATE);	// ��ӡ�������� 

    // ��ӡST�̼���汾����3���������stm32f10x.h�ļ��� 
    //printf("* �̼���汾 : V%d.%d.%d (STM32F4xx_StdPeriph_Driver)\r\n", __STM32F4XX_STDPERIPH_VERSION_MAIN,
    //__STM32F4XX_STDPERIPH_VERSION_SUB1,__STM32F4XX_STDPERIPH_VERSION_SUB2);
    printf("* \r\n");	// ��ӡһ�пո� 
    printf("* QQ    : 738275730 \r\n");
    printf("* WeChat    : 13670085303 \r\n");
    printf("* Email : xhhu@phosense-tech.com \r\n");
    printf("* Copyright www.phosense-tech.com \r\n");
	printf("---------------------------------------------------------\r\n");
}

//=============================================================================
//�ļ����ƣ�Get_ChipInfo(void)
//���ܸ�Ҫ����ȡоƬFlash ��С
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void Get_ChipInfo(void)
{
        uint32_t ChipUniqueID[3];
        u16 STM32_FLASH_SIZE = 0;
        uint32_t MCU_Id = 0 ;
        uint32_t Soft_Version = 0;
        //uint32_t Rev_Id = 0;
        //uint32_t Dev_Id = 0;
        //uint32_t Boot_Mode = 0;
        
        //ChipUniqueID[0] = *(__IO u32 *)(0X1FFFF7F0); // ???
        //ChipUniqueID[1] = *(__IO u32 *)(0X1FFFF7EC); //
        //ChipUniqueID[2] = *(__IO u32 *)(0X1FFFF7E8); // ???
        
        //HAL_GetUID(ChipUniqueID);
				ChipUniqueID[0] = HAL_GetUIDw0();
				ChipUniqueID[1] = HAL_GetUIDw1();
				ChipUniqueID[2] = HAL_GetUIDw2();
        
        STM32_FLASH_SIZE= *(u16*)(0x1FFFF7E0);    //���������Ĵ���  
        
        MCU_Id =DBGMCU->IDCODE; // Read MCU Id, 32-bit access 
        
        printf("-------- оƬ��ΨһIDΪ: %X-%X-%X \r\n",ChipUniqueID[0],ChipUniqueID[1],ChipUniqueID[2]);  
        
        printf("-------- оƬflash������Ϊ: %dK \r\n", STM32_FLASH_SIZE);
        
        printf("-------- MCU_Id: %d \r\n",MCU_Id);
        
        printf("-------- ��¼����: "__DATE__" - "__TIME__"\r\n");
        
        Soft_Version = HAL_GetHalVersion();
        printf("-------- Soft_Version:0x%x \r\n",Soft_Version);
        //Rev_Id = HAL_GetREVID();
        //Dev_Id = HAL_GetDEVID();
        //Boot_Mode = HAL_SYSCFG_GetBootMode();
        //���ʹ�ù̼���汾��
       printf("--------����̼���汾: V %d.%d.%d --------\r\n",(Soft_Version>>24)&0xFF,(Soft_Version>>16)&0xFF,(Soft_Version>>8)&0xFF);
       //printf("--------����̼���汾: V %d.%d.%d --------\r\n",__STM32L0XX_STDPERIPH_VERSION_MAIN,__STM32L0XX_STDPERIPH_VERSION_SUB1,__STM32F0XX_STDPERIPH_VERSION_SUB2);

	   //System_Manage.JTAG_ID = Get_JTAG_ID();
	   //printf("JTAG_ID = 0x%2x \r\n",System_Manage.JTAG_ID);
	   //if(System_Manage.JTAG_ID == 0x041)printf("The MCU is ST \r\n");
	   //if(System_Manage.JTAG_ID == 0x7A3)printf("The MCU is GD \r\n");

}

//=============================================================================
//�ļ����ƣ�void error_handler(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void error_handler(void)
{
	while(1)
	{
		printf("system run error!\r\n");
		//delay_ms(1000);
	}
}

//=============================================================================
//�ļ����ƣ�ErrorStatus memory_compare(uint8_t* src, uint8_t* dst, uint8_t length) 
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

ErrorStatus memory_compare(uint8_t* src, uint8_t* dst, uint8_t length) 
{
    while (length--){
        if (*src++ != *dst++)
            return ERROR;
    }
    return SUCCESS;
}


//=============================================================================
//�ļ����ƣ�void HAL_GPIO_Pin_Setting(GPIO_TypeDef *gpio, uint32_t nPin, uint32_t mode, uint32_t pull, uint32_t speed)
//���ܸ�Ҫ��CPIO����
//����˵������������GPIO
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void HAL_GPIO_Pin_Setting(GPIO_TypeDef *gpio, uint32_t nPin, uint32_t mode, uint32_t pull, uint32_t speed)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    GPIO_InitStruct.Pin = nPin;
    GPIO_InitStruct.Mode = mode;
    GPIO_InitStruct.Pull = pull;
    GPIO_InitStruct.Speed = speed;
    HAL_GPIO_Init(gpio, &GPIO_InitStruct);
}

//=============================================================================
//�ļ����ƣ�HAL_GPIO_PinState GPIO_ReadPinInput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//���ܸ�Ҫ����ȡ��������״̬
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

GPIO_PinState HAL_GPIO_ReadPinInput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  GPIO_PinState bitstatus;
  
  /* Check the parameters */
  assert_param(IS_GPIO_PIN_AVAILABLE(GPIOx,GPIO_Pin));
  
  if((GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET)
  {
    bitstatus = GPIO_PIN_SET;
  }
  else
  {
    bitstatus = GPIO_PIN_RESET;
  }
  return bitstatus;
}
//=============================================================================
//�ļ����ƣ�GPIO_PinState HAL_GPIO_ReadPinOutput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//���ܸ�Ҫ����ȡ�������״̬
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================
GPIO_PinState HAL_GPIO_ReadPinOutput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  GPIO_PinState bitstatus;
  
  /* Check the parameters */
  assert_param(IS_GPIO_PIN_AVAILABLE(GPIOx,GPIO_Pin));
  
  if((GPIOx->ODR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET)
  {
    bitstatus = GPIO_PIN_SET;
  }
  else
  {
    bitstatus = GPIO_PIN_RESET;
  }
  return bitstatus;
}




//=============================================================================
//�ļ����ƣ�void spi_config(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void spi_config(void)
{

}


//=============================================================================
//�ļ����ƣ�void early_init(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void early_init(void)
{
	//sys_clock_config();      //system clock initial

	//nvic_configuation();     //system nvic initial

	//sys_tick_init();         //systick timer initial
	
	//sys_timer_init();        //system timer initial
	
}

//=============================================================================
//�ļ����ƣ�void early_task(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void early_task(void)
{
	//SystemInfo_SaveInit();  //check if need config system params
	
	//Bt_Util_Init();         //system status initial
	
}

//=============================================================================
//�ļ����ƣ�void later_init(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void later_init(void)
{
	//Control_Sem_bspInit();    //contorl signal(power/ACC/Light/Led) initial
	
	//ADC_Sem_Configuration();  //ADC signal(throttle/brake/battery power) initial
	
	//Key_bspInit();            //key initial
	
	//Display_bspInit();        //display initial
	
	//CTRLUsart_Init();         //controller communication port initial
	
	//BLEUsart_Init();          //ble communication port initial
	
	//System_GetDeviceID();     //get device unique id
	
}

//=============================================================================
//�ļ����ƣ�void later_task(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void later_task(void)
{
	//Display_InitScreen();
	//Display_Cartoon();
}

//=============================================================================
//�ļ����ƣ�void main_loop(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����	�����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void main_loop(void)
{
	while(1)
	{
		//led_flicker_control();
		
		//Key_Polling();          //20ms polling period
		
		//Capture_Sem_Filter();   //real-time polling when DMA interrupt occurs
		
		//CTRLCmmnt_Polling();    //120ms notify period
		
		//BLECmmnt_Polling();     //120ms notify period
				
		//led_polling();          //real-time polling
		
		//Display_Polling();      //200ms polling period
		
		//buzzer_polling();       //real-time polling
		
		//front_light_polling();  //real-time polling
		
		//alarm_state_polling();  //real-time polling
		
		//SystemIdle_Polling();   //real-time polling
		
	}
}


