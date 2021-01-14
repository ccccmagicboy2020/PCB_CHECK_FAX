//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_FUN.c
//功能概要：BSP_FUN驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================


#include "INCLUDE_EXT.h"
#include "BSP_FUN.h"


//=============================================================================
//文件名称：int fputc(int ch, FILE *f)
//功能概要：retarget the C library printf function to the USART
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

int fputc(int ch, FILE *f)
{

	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1,0xFFFF);
	//HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1,0xFFFF);

  return ch;
}


//=============================================================================
//文件名称：int fgetc(FILE *f)
//功能概要：retarget the C library printf function to the USART
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

int fgetc(FILE *f)
{
    uint8_t ch;

		HAL_UART_Receive(&huart2,(uint8_t *)&ch,1,0xffff);
    return ch;
}


//=============================================================================
//文件名称：void delay_init(unsigned char SYSCLK)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void delay_init(unsigned char SYSCLK)
{
  
  
}

//=============================================================================
//文件名称：void delay_us(unsigned long nus)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void delay_us(unsigned long nus)
{
    char a=0;
    for(;nus != 0;nus--)
        for(a=0;a<5;a++);
}

//=============================================================================
//文件名称：void delay_ms(unsigned int nms)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void delay_ms(unsigned int nms)
{
	delay = nms;
	while(delay != 0);
}

//=============================================================================
//文件名称：void delay_xms(unsigned int nms)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void delay_xms(unsigned int nms)
{
	delay = nms;
	while(delay != 0);
}


//=============================================================================
//文件名称：void delay_s(unsigned int ns)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void delay_s(unsigned int ns)
{
	delay = ns * 1000;
	while(delay != 0);
}

//=============================================================================
//文件名称：void led_spark(void)
//功能概要：toggle the led every 500ms
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
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
//文件名称：void Sys_Soft_Reset(void)
//功能概要：时钟初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void Sys_Soft_Reset(void)
{
    // 检测系统是否是从待机模式启动的 
    if (__HAL_PWR_GET_FLAG(PWR_FLAG_SB) != RESET)
    {
        printf("待机唤醒复位\r\n");
        // 清除待机标志位 
        __HAL_PWR_CLEAR_FLAG(PWR_FLAG_SB);
        //清除所有唤醒标志位 
        __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
    }
    else if(__HAL_PWR_GET_FLAG(PWR_FLAG_WU) != RESET)
    {
        printf("RTC 按键唤醒复位\r\n");
        // 清除待机标志位 
        __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
    }
    else if(__HAL_PWR_GET_FLAG(PWR_FLAG_PVDO) != RESET)
    {
        printf("PVD监控复位\r\n");
        // 清除待机标志位 
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
        printf("系统是上电启动\r\n");
        //printf("长按下KEY1可进入待机模式\r\n");
    }

}

//=============================================================================
//文件名称：unsigned int Get_JTAG_ID(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
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
//文件名称：unsigned int Get_MCU_ID(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

unsigned int Get_MCU_ID(void)
{

	System_Manage.Unique_ID1 = *(uint32_t *)(0x1FFFF7AC);        //UNIQUE_ID[31: 0]
	System_Manage.Unique_ID2 = *(uint32_t *)(0x1FFFF7B0);        //UNIQUE_ID[63:32]
	System_Manage.Unique_ID3 = *(uint32_t *)(0x1FFFF7B4);        //UNIQUE_ID[95:63]
	
	return  0;
}

//=============================================================================
//文件名称：void IWDG_Init(uint32_t prer,uint32_t rlr)
//功能概要：独立看门狗初始化,void IWDG_Init(4，625)
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void IWDG_Init(uint32_t prer,uint32_t rlr)
{
    IWDG->KR=0X5555;      //解除寄存器保护        
    IWDG->PR=prer;         // 写入初始化分频值
    IWDG->RLR=rlr;            // 写入自动装载值
    IWDG->KR=0XAAAA;     //开启寄存器保护
    IWDG->KR=0XCCCC;       //启动看门狗
}

//=============================================================================
//文件名称：void IWDG_Feed(void)
//功能概要：独立看门狗喂狗函数
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void IWDG_Feed(void)
{
    IWDG->KR=0XAAAA;                                  
}

//=============================================================================
//文件名称：void Get_CHIP_ID(void)
//功能概要：获取芯片ID
//参数说明：96位的ID是stm32唯一身份标识，可以以8bit、16bit、32bit读取
//           提供了大端和小端两种表示方法
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void Get_CHIP_ID(void)
{
#if 1
      u32 ChipUniqueID[3];
      //地址从小到大,先放低字节，再放高字节：小端模式
      //地址从小到大,先放高字节，再放低字节：大端模式
      ChipUniqueID[2] = *(__IO u32*)(0X1FFFF7E8);  // 低字节
      ChipUniqueID[1] = *(__IO u32 *)(0X1FFFF7EC); // 
      ChipUniqueID[0] = *(__IO u32 *)(0X1FFFF7F0); // 高字节
      //printf("######## 芯片的唯一ID为: X-X-X  rn",ChipUniqueID[0],ChipUniqueID[1],ChipUniqueID[2]);
      printf("--------芯片唯一ID为：%x-%x-%x----------\r\n",ChipUniqueID[0],ChipUniqueID[1],ChipUniqueID[2]);
          //此条语句输出32位
#else   //调整了大小端模式，与ISP下载软件的一致
      u8 temp[12];   
      u32 temp0,temp1,temp2;
      temp0=*(__IO u32*)(0x1FFFF7E8);    //产品唯一身份标识寄存器（96位）
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
      printf("--------STM32芯片ID为: %.2X%.2X%.2X%.2X-%.2X%.2X%.2X%.2X-%.2X%.2X%.2X%.2X --------\r\n",
      temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7],temp[8],temp[9],temp[10],temp [11]); //串口打印出芯片ID
#endif
}

//=============================================================================
//文件名称：void MCO_Output(void)
//功能概要：各类时钟输出测试
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void MCO_Output(void)
{
  
    GPIO_InitTypeDef  GPIO_InitStruct;

    // 使能GPIOA时钟 
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    //1、设置PA.8为复用Push-Pull模式。 
    GPIO_InitStruct.Pin = GPIO_PIN_8; 
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH; 
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; 
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct); 
    //2、选择输出时钟源。 
    //时钟的选择由时钟配置寄存器(RCC_CFGR)中的MCO[2:0]位控制。 
    //RCC_MCOConfig(RCC_MCO); 
  
    HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_SYSCLK, RCC_MCO1SOURCE_HSI);
      
    //uint32_t HAL_RCC_GetSysClockFreq(void)
    //参数RCC_MCO为要输出的内部时钟： 
    //RCC_MCO_NoClock --- 无时钟输出 
    //RCC_MCO_SYSCLK --- 输出系统时钟（SysCLK） 
    //RCC_MCO_HSI --- 输出内部高速8MHz的RC振荡器的时钟（HSI） 
    //RCC_MCO_HSE --- 输出高速外部时钟信号（HSE） 
    //RCC_MCO_PLLCLK_Div2 --- 输出PLL倍频后的二分频时钟（PLLCLK/2）
}

//=============================================================================
//文件名称：void Printf_SystemRccClocks(void)
//功能概要：打印系统时钟
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
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
//文件名称：PrintfLogo
//功能概要：打印例程名称和例程发布日期, 接上串口线后，打开PC机的超级终端软件可以观察结果
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void PrintfLogo(void)
{
    printf("\r\n");
	printf("---------------------------------------------------------\r\n");
    printf("* name   : %s\r\n", EXAMPLE_NAME);	// 打印例程名称 
    printf("* version   : %s\r\n", DEMO_VER);		// 打印例程版本 
    printf("* date   : %s\r\n", EXAMPLE_DATE);	// 打印例程日期 

    // 打印ST固件库版本，这3个定义宏在stm32f10x.h文件中 
    //printf("* 固件库版本 : V%d.%d.%d (STM32F4xx_StdPeriph_Driver)\r\n", __STM32F4XX_STDPERIPH_VERSION_MAIN,
    //__STM32F4XX_STDPERIPH_VERSION_SUB1,__STM32F4XX_STDPERIPH_VERSION_SUB2);
    printf("* \r\n");	// 打印一行空格 
    printf("* QQ    : 738275730 \r\n");
    printf("* WeChat    : 13670085303 \r\n");
    printf("* Email : xhhu@phosense-tech.com \r\n");
    printf("* Copyright www.phosense-tech.com \r\n");
	printf("---------------------------------------------------------\r\n");
}

//=============================================================================
//文件名称：Get_ChipInfo(void)
//功能概要：获取芯片Flash 大小
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
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
        
        STM32_FLASH_SIZE= *(u16*)(0x1FFFF7E0);    //闪存容量寄存器  
        
        MCU_Id =DBGMCU->IDCODE; // Read MCU Id, 32-bit access 
        
        printf("-------- 芯片的唯一ID为: %X-%X-%X \r\n",ChipUniqueID[0],ChipUniqueID[1],ChipUniqueID[2]);  
        
        printf("-------- 芯片flash的容量为: %dK \r\n", STM32_FLASH_SIZE);
        
        printf("-------- MCU_Id: %d \r\n",MCU_Id);
        
        printf("-------- 烧录日期: "__DATE__" - "__TIME__"\r\n");
        
        Soft_Version = HAL_GetHalVersion();
        printf("-------- Soft_Version:0x%x \r\n",Soft_Version);
        //Rev_Id = HAL_GetREVID();
        //Dev_Id = HAL_GetDEVID();
        //Boot_Mode = HAL_SYSCFG_GetBootMode();
        //输出使用固件库版本号
       printf("--------代码固件库版本: V %d.%d.%d --------\r\n",(Soft_Version>>24)&0xFF,(Soft_Version>>16)&0xFF,(Soft_Version>>8)&0xFF);
       //printf("--------代码固件库版本: V %d.%d.%d --------\r\n",__STM32L0XX_STDPERIPH_VERSION_MAIN,__STM32L0XX_STDPERIPH_VERSION_SUB1,__STM32F0XX_STDPERIPH_VERSION_SUB2);

	   //System_Manage.JTAG_ID = Get_JTAG_ID();
	   //printf("JTAG_ID = 0x%2x \r\n",System_Manage.JTAG_ID);
	   //if(System_Manage.JTAG_ID == 0x041)printf("The MCU is ST \r\n");
	   //if(System_Manage.JTAG_ID == 0x7A3)printf("The MCU is GD \r\n");

}

//=============================================================================
//文件名称：void error_handler(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
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
//文件名称：ErrorStatus memory_compare(uint8_t* src, uint8_t* dst, uint8_t length) 
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
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
//文件名称：void HAL_GPIO_Pin_Setting(GPIO_TypeDef *gpio, uint32_t nPin, uint32_t mode, uint32_t pull, uint32_t speed)
//功能概要：CPIO设置
//参数说明：重新设置GPIO
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
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
//文件名称：HAL_GPIO_PinState GPIO_ReadPinInput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//功能概要：读取引脚输入状态
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
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
//文件名称：GPIO_PinState HAL_GPIO_ReadPinOutput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//功能概要：读取引脚输出状态
//参数说明：无
//函数返回：无
//作者    ：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
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
//文件名称：void spi_config(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void spi_config(void)
{

}


//=============================================================================
//文件名称：void early_init(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void early_init(void)
{
	//sys_clock_config();      //system clock initial

	//nvic_configuation();     //system nvic initial

	//sys_tick_init();         //systick timer initial
	
	//sys_timer_init();        //system timer initial
	
}

//=============================================================================
//文件名称：void early_task(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void early_task(void)
{
	//SystemInfo_SaveInit();  //check if need config system params
	
	//Bt_Util_Init();         //system status initial
	
}

//=============================================================================
//文件名称：void later_init(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
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
//文件名称：void later_task(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void later_task(void)
{
	//Display_InitScreen();
	//Display_Cartoon();
}

//=============================================================================
//文件名称：void main_loop(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
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


