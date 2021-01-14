//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：INCLUDE_EXT.c
//功能概要：INCLUDE_EXT.c驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#include "INCLUDE_EXT.h"


unsigned char RxByte1=0;
unsigned char RxByte2=0;
unsigned char RxByte3=0;
unsigned char RxByte4=0;
unsigned char RxByte5=0;

//UART1
unsigned char RxBuffer_1[RXBUFFER_MAX];  //
unsigned char TxBuffer_1[TXBUFFER_MAX];		//
unsigned char RxLen_1=0;//
unsigned char TxLen_1=0;	//
unsigned char TxLenCount_1=0;	//
unsigned char *pointer_1;		//
unsigned char ReceiveFlag_1 = 0;	// =1,

//unsigned char CmdBuffer[CMDBUFFER_MAX][RXBUFFER_MAX];//
unsigned char CmdBuffer_1[CMDBUFFER_MAX];//
unsigned char CmdCount_1 = 0;//
unsigned char CmdWord_1 = 0;//


//UART2

unsigned char RxBuffer_2[RXBUFFER_MAX];  //
unsigned char TxBuffer_2[TXBUFFER_MAX];		//
unsigned char RxLen_2=0;//
unsigned char TxLen_2=0;	//
unsigned char TxLenCount_2=0;	//
unsigned char *pointer_2;		//
unsigned char ReceiveFlag_2;	// =1,

//unsigned char CmdBuffer_2[CMDBUFFER_MAX][RXBUFFER_MAX];//
unsigned char CmdBuffer_2[CMDBUFFER_MAX];//
unsigned char CmdCount_2 = 0;//
unsigned char CmdWord_2 = 0;//

//UART3
unsigned char RxBuffer_3[RXBUFFER_MAX];  //
unsigned char TxBuffer_3[TXBUFFER_MAX];		//
unsigned char RxLen_3=0;//
unsigned char TxLen_3=0;	//
unsigned char TxLenCount_3=0;	//
unsigned char *pointer_3;		//
unsigned char ReceiveFlag_3;	// =1,

//unsigned char CmdBuffer_3[CMDBUFFER_MAX][RXBUFFER_MAX];//
unsigned char CmdBuffer_3[CMDBUFFER_MAX];//
unsigned char CmdCount_3 = 0;//
unsigned char CmdWord_3 = 0;//

//UART4
unsigned char RxBuffer_4[RXBUFFER_MAX];  //
unsigned char TxBuffer_4[TXBUFFER_MAX];		//
unsigned char RxLen_4=0;//
unsigned char TxLen_4=0;	//
unsigned char TxLenCount_4=0;	//
unsigned char *pointer_4;		//
unsigned char ReceiveFlag_4;	// =1,

//unsigned char CmdBuffer_4[CMDBUFFER_MAX][RXBUFFER_MAX];//
unsigned char CmdBuffer_4[CMDBUFFER_MAX];//
unsigned char CmdCount_4 = 0;//
unsigned char CmdWord_4 = 0;//

//UART5
unsigned char RxBuffer_5[RXBUFFER_MAX];  //
unsigned char TxBuffer_5[TXBUFFER_MAX];		//
unsigned char RxLen_5=0;//
unsigned char TxLen_5=0;	//
unsigned char TxLenCount_5=0;	//
unsigned char *pointer_5;		//
unsigned char ReceiveFlag_5;	// =1,

//unsigned char CmdBuffer_5[CMDBUFFER_MAX][RXBUFFER_MAX];//
unsigned char CmdBuffer_5[CMDBUFFER_MAX];//
unsigned char CmdCount_5 = 0;//
unsigned char CmdWord_5 = 0;//

unsigned char rec_data_num;
unsigned char USART1_recnum;
unsigned char USART1_recdata[16];	//与被测灯控板通讯

unsigned char USART2_recnum;
unsigned char USART2_senddata[30];
unsigned char USART2_recdata[30];	//与上位机通讯
unsigned char flag_rec;
unsigned char flag_rec2;

unsigned int  	i;
unsigned int		j;
unsigned int		m;
unsigned int  	KEY1_DOWN=0;
unsigned int 	KEY2_DOWN=0;
unsigned int 	KEY3_DOWN=0;
unsigned int start_command = 0;
unsigned int target_start;

unsigned int power_con=0xffff;
unsigned int  led_data=0;
unsigned int  k = 0;
unsigned int  tempv_16 = 0;
unsigned int  light_ad=0;
unsigned int  max_light_ad = 0;
unsigned int  min_light_ad = 0;
unsigned int 	sum=0;
unsigned int   sum1=0;
unsigned int Mode_Sate = 0;
unsigned int ADC_Value[3];
float VOL_Value[3];
unsigned int Rodar_Times = 0;

volatile uint32_t sysTickUptimems = 0;//ms
volatile uint32_t sysTickUptimeus = 0;//us   

unsigned long sysTickDtrTimems = 0;//ms
unsigned long sysTickOutTimems = 0;//ms
unsigned long sysTickDtrDownTimems = 0;//ms
unsigned long sysTickDtrUpTimems = 0;//ms
unsigned long sysTickOutDownTimems = 0;//ms
unsigned long sysTickOutUpTimems = 0;//ms

unsigned char State = 0;
unsigned char rxbuf[50] = {0};
unsigned char tmp_buf[50] = {0};
unsigned char St = 0xFF;

PCB_INFO pcb_check_info[8][4];

SYSTEM_MANAGE  System_Manage;

const char str_poweron[]={"测试板上电\r\n"};
const char str_start[]={"开始检测\r\n"};
const char str_light0[]={"环境光：\r\n"};
const char str_dark[]={"光线太弱\r\n"};
const char str_bright[]={"光线太强\r\n"};
const char str_num[]={"故障电路板编号：\r\n"};
const char str_current[]={"电    流：\r\n"};
const char str_mA[]={"mA\r\n"};
const char str_short[]={"--短路\r\n"};
const char str_3V[]={"3V  电压：\r\n"};
const char str_1V[]={"1.2V电压：\r\n"};
const char str_light[]={"感光AD值：\r\n"};
const char str_dcv[]={"直流电压：\r\n"};
const char str_out[]={"输出状态：\r\n"};
const char str_readlighterr[]={"读取感光AD值出错！\r\n"};
const char str_readtxerr[]={"读取数据出错！\r\n"};
const char str_th[]={"门限  值：\r\n"};
const char str_ok[]={"准备完毕\r\n"};








//=============================================================================
//文件名称：void rcu_config(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void rcu_config(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
}


//=============================================================================
//文件名称：void gpio_config(void)
//功能概要：无
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void gpio_config(void)
{

}


//=============================================================================
//文件名称：void Clock_Init(void)
//功能概要：时钟初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void Clock_Init(void)
{
  systick_config();
}

//=============================================================================
//文件名称：void System_Init(void)
//功能概要：系统初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void System_Init(void)
{

}

//=============================================================================
//文件名称：void ST_Init(void)
//功能概要：存储空间初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void ST_Init(void)
{

}

//=============================================================================
//文件名称：void Soft_Init(void)
//功能概要：软件初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void Soft_Init(void)
{

}

//=============================================================================
//文件名称：void Hardware_Init(void)
//功能概要：硬件初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void Hardware_Init(void)
{
	
	// peripheral clock enable 
	rcu_config();

	GPIO_HC595_Init();
	
	GPIO_HC4052A_Init();
	
	GPIO_CONTROL_Init();
	
	GPIO_ADC_Init(&hadc1);
	
	GPIO_BEEP_Init();
	
	GPIO_KEY_Init();
	
	GPIO_LED_Init();
	
	GPIO_MOTO_Init();
	
	HC595_Set_Power1(0);
	
	HC595_Set_Power2(0);
	

	
	

}


//=============================================================================
//文件名称：void Data_Init(void)
//功能概要：数据初始化
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================


void Data_Init(void)
{
	System_Manage.System_Flag = 0;
	System_Manage.Work_Mode = WORK_STUDY;//开机为学习模式
	
	ParaInit();
	//GLOBAL_USART1_Set(Para.BaudRate);
	//print_str("测试开始!\r\n");
	//print_char(0);
	//print_char(0x0d);
	start_command=0;		//启动测试命令标志

}


//=============================================================================
//文件名称：void Start_Init(void)
//功能概要：开始工作
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void Start_Init(void)
{
	LED_Set(1);
	
	LED_HC595_Set(0Xffff);
	
	BEEP_Start(100);
	BEEP_Wait();
	delay_ms(100);
	BEEP_Start(100);
	BEEP_Wait();
	delay_ms(100);
	BEEP_Start(100);

	led_data = 0;
	LED_HC595_Set(led_data);

	printf(str_ok);

	
	start_command=1;		//启动测试命令标志
}

//=============================================================================
//文件名称：void SYS_Test(uint8_t state)
//功能概要：系统测试
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================

void SYS_Test(uint8_t state)
{

}

//=============================================================================
//文件名称：void Scheduler_Init(void)
//功能概要：系统调度
//参数说明：无
//函数返回：无
//作者	：胡显辉
//联系方式: Steven.Hu 日期：2020年3月23日 738275730@qq.com
//=============================================================================


#if 1
void Scheduler_Init(void)
{

  if(TaskRunTime_nMs(0, 150))
  {
		
	if(KEY_1_READ() == 1)
	{
		//delay_ms(5);
		if(KEY_1_READ() == 1)
		{
			KEY1_DOWN=1;
			//检测到按键后开始测试
			printf("按键1按下!\r\n");
			/*
			HAL_ADCEx_Calibration_Start(&hadc1);  //校准
			HAL_ADC_Start(&hadc1);   //开启
			HAL_ADC_PollForConversion(&hadc1,50);  //等待转换完成

			if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
			{
					ADC_Value[0]=HAL_ADC_GetState(&hadc1);
					printf("检测AD值为：%drn",ADC_Value[0]);
					VOL_Value[0]=ADC_Value[0]*3.3/4096;
					printf("检测电压值为：%.2fV rn",VOL_Value[0]);
			}*/
		}
	}
				
	if(KEY_2_READ() == 1)
	{
		//delay_ms(5);
		if(KEY_2_READ() == 1)
		{
			
			if(KEY2_DOWN != 0)
			{
				KEY2_DOWN = 0;
			}
			else
			{
				KEY2_DOWN=1;
			}
			//检测到按键后开始测试
			printf("按键2按下!\r\n");
		}
	}
	if(KEY_3_READ() == 1)
	{
		//delay_ms(5);
		if(KEY_3_READ() == 1)
		{
			if(KEY3_DOWN != 0)
			{
				KEY3_DOWN = 0;
			}
			else
			{
				KEY3_DOWN=1;
			}
			/*
			printf("开始\r\n");
			printf("char:%d\r\n",sizeof(char));
			printf("unsigned char:%d\r\n",sizeof(unsigned char));
			printf("short:%d\r\n",sizeof(short));
			printf("unsigned short:%d\r\n",sizeof(unsigned short));
			printf("int:%d\r\n",sizeof(int));
			printf("unsigned int:%d\r\n",sizeof(unsigned int));
			printf("long:%d\r\n",sizeof(long));
			printf("unsigned long:%d\r\n",sizeof(unsigned long));
			printf("long long:%d\r\n",sizeof(long long));
			printf("unsigned long long:%d\r\n",sizeof(unsigned long long));
			printf("float:%d\r\n",sizeof(float));
			printf("double:%d\r\n",sizeof(double));
			*/
			//检测到按键后开始测试
			printf("按键3按下!\r\n");
			
		}
	}
	
  }
  
  if(TaskRunTime_nMs(1, 100))
  {

		if(St != 0xFF)
		{
			if((Para.MODE_Select == 0) & (Para.XBR_DL == 0))
			{
				MODE_XBR105_Alogo(St);
			}
			else if((Para.MODE_Select == 1) & (Para.XBR_DL == 0))
			{
				MODE_XBR201_Alogo(St);
			}
			else if((Para.MODE_Select == 2) & (Para.XBR_DL == 0))
			{
				MODE_XBR401_Alogo(St);
			}
			else if((Para.MODE_Select == 3) & (Para.XBR_DL == 0))
			{
				MODE_XBR202_Alogo(St);
			} 
			else if((Para.MODE_Select == 3) & (Para.XBR_DL != 0))
			{
				//MODE_PM51_Alogo(St);
			}
			else if((Para.MODE_Select == 1) & (Para.XBR_DL != 0))
			{
				//MODE_EN8F_Alogo(St);
			}

			St = 0xFF;
		}
		MODE_XBR_Poll();
		
		if(KEY3_DOWN != 0)
		{
			KEY3_DOWN = 0;
			
			if((Para.MODE_Select == 0) & (Para.XBR_DL == 0))
			{
				MODE_XBR105();
			}
			else if((Para.MODE_Select == 1) & (Para.XBR_DL == 0))
			{
				MODE_XBR201();
			}
			else if((Para.MODE_Select == 2) & (Para.XBR_DL == 0))
			{
				MODE_XBR401();
			}
			else if((Para.MODE_Select == 3) & (Para.XBR_DL == 0))
			{
				MODE_XBR202();
			}
			else if((Para.MODE_Select == 3) & (Para.XBR_DL != 0))
			{
				//MODE_PM51();
			}
			else if((Para.MODE_Select == 1) & (Para.XBR_DL != 0))
			{
				//MODE_EN8F();
			}

		}
		

		if(KEY2_DOWN != 0)
		{
			KEY2_DOWN = 0;
				//MODE_XBR201();
			if(St != 0)
			{
				St = 0;
			}
			else
			{
				St = 2;
			}
					//打开风扇
			MOTO_Control(St + 1);

		}
		

  }
  
}

#endif













