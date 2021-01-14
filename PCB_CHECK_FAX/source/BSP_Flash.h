//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：BSP_Flash.c
//功能概要：BSP_Flash驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================


#ifndef _BSP_FLASH_H_
#define _BSP_FLASH_H_


/*****************************************************************************/
#define FLASH_MAX_SIZE           (0x8008FFF)       // 3FFF  7FFF
//#define FLASH_PAGE_SIZE          (0x400)
#define FLASH_PAGE0_STARTADDR    (0x8000000)
/*---------------------------------------------------------------------------*/
#define FLASH_PAGE1_STARTADDR    (FLASH_PAGE0_STARTADDR + FLASH_PAGE_SIZE)
#define FLASH_PAGE2_STARTADDR    (FLASH_PAGE0_STARTADDR + 2 * FLASH_PAGE_SIZE)
#define FLASH_PAGE3_STARTADDR    (FLASH_PAGE0_STARTADDR + 3 * FLASH_PAGE_SIZE)
#define FLASH_PAGE4_STARTADDR    (FLASH_PAGE0_STARTADDR + 4 * FLASH_PAGE_SIZE)
#define FLASH_PAGE5_STARTADDR    (FLASH_PAGE0_STARTADDR + 5 * FLASH_PAGE_SIZE)
#define FLASH_PAGE6_STARTADDR    (FLASH_PAGE0_STARTADDR + 6 * FLASH_PAGE_SIZE)
#define FLASH_PAGE7_STARTADDR    (FLASH_PAGE0_STARTADDR + 7 * FLASH_PAGE_SIZE)
#define FLASH_PAGE8_STARTADDR    (FLASH_PAGE0_STARTADDR + 8 * FLASH_PAGE_SIZE)
#define FLASH_PAGE9_STARTADDR    (FLASH_PAGE0_STARTADDR + 9 * FLASH_PAGE_SIZE)
#define FLASH_PAGE10_STARTADDR   (FLASH_PAGE0_STARTADDR + 10 * FLASH_PAGE_SIZE)
#define FLASH_PAGE11_STARTADDR   (FLASH_PAGE0_STARTADDR + 11 * FLASH_PAGE_SIZE)
#define FLASH_PAGE12_STARTADDR   (FLASH_PAGE0_STARTADDR + 12 * FLASH_PAGE_SIZE)
#define FLASH_PAGE13_STARTADDR   (FLASH_PAGE0_STARTADDR + 13 * FLASH_PAGE_SIZE)
#define FLASH_PAGE14_STARTADDR   (FLASH_PAGE0_STARTADDR + 14 * FLASH_PAGE_SIZE)
#define FLASH_PAGE15_STARTADDR   (FLASH_PAGE0_STARTADDR + 15 * FLASH_PAGE_SIZE)

#define FLASH_PAGE16_STARTADDR   (FLASH_PAGE0_STARTADDR + 16 * FLASH_PAGE_SIZE)
#define FLASH_PAGE17_STARTADDR   (FLASH_PAGE0_STARTADDR + 17 * FLASH_PAGE_SIZE)
#define FLASH_PAGE18_STARTADDR   (FLASH_PAGE0_STARTADDR + 18 * FLASH_PAGE_SIZE)
#define FLASH_PAGE19_STARTADDR   (FLASH_PAGE0_STARTADDR + 19 * FLASH_PAGE_SIZE)
#define FLASH_PAGE20_STARTADDR   (FLASH_PAGE0_STARTADDR + 20 * FLASH_PAGE_SIZE)
#define FLASH_PAGE21_STARTADDR   (FLASH_PAGE0_STARTADDR + 21 * FLASH_PAGE_SIZE)
#define FLASH_PAGE22_STARTADDR   (FLASH_PAGE0_STARTADDR + 22 * FLASH_PAGE_SIZE)
#define FLASH_PAGE23_STARTADDR   (FLASH_PAGE0_STARTADDR + 23 * FLASH_PAGE_SIZE)
#define FLASH_PAGE24_STARTADDR   (FLASH_PAGE0_STARTADDR + 24 * FLASH_PAGE_SIZE)
#define FLASH_PAGE25_STARTADDR   (FLASH_PAGE0_STARTADDR + 25 * FLASH_PAGE_SIZE)
#define FLASH_PAGE26_STARTADDR   (FLASH_PAGE0_STARTADDR + 26 * FLASH_PAGE_SIZE)
#define FLASH_PAGE27_STARTADDR   (FLASH_PAGE0_STARTADDR + 27 * FLASH_PAGE_SIZE)
#define FLASH_PAGE28_STARTADDR   (FLASH_PAGE0_STARTADDR + 28 * FLASH_PAGE_SIZE)
#define FLASH_PAGE29_STARTADDR   (FLASH_PAGE0_STARTADDR + 29 * FLASH_PAGE_SIZE)
#define FLASH_PAGE30_STARTADDR   (FLASH_PAGE0_STARTADDR + 30 * FLASH_PAGE_SIZE)
#define FLASH_PAGE31_STARTADDR   (FLASH_PAGE0_STARTADDR + 31 * FLASH_PAGE_SIZE)

#define FLASH_PAGE32_STARTADDR   (FLASH_PAGE0_STARTADDR + 32 * FLASH_PAGE_SIZE)
#define FLASH_PAGE33_STARTADDR   (FLASH_PAGE0_STARTADDR + 33 * FLASH_PAGE_SIZE)
#define FLASH_PAGE34_STARTADDR   (FLASH_PAGE0_STARTADDR + 34 * FLASH_PAGE_SIZE)
#define FLASH_PAGE35_STARTADDR   (FLASH_PAGE0_STARTADDR + 35 * FLASH_PAGE_SIZE)
#define FLASH_PAGE36_STARTADDR   (FLASH_PAGE0_STARTADDR + 36 * FLASH_PAGE_SIZE)
#define FLASH_PAGE37_STARTADDR   (FLASH_PAGE0_STARTADDR + 37 * FLASH_PAGE_SIZE)
#define FLASH_PAGE38_STARTADDR   (FLASH_PAGE0_STARTADDR + 38 * FLASH_PAGE_SIZE)
#define FLASH_PAGE39_STARTADDR   (FLASH_PAGE0_STARTADDR + 39 * FLASH_PAGE_SIZE)
#define FLASH_PAGE40_STARTADDR   (FLASH_PAGE0_STARTADDR + 40 * FLASH_PAGE_SIZE)
#define FLASH_PAGE41_STARTADDR   (FLASH_PAGE0_STARTADDR + 41 * FLASH_PAGE_SIZE)
#define FLASH_PAGE42_STARTADDR   (FLASH_PAGE0_STARTADDR + 42 * FLASH_PAGE_SIZE)
#define FLASH_PAGE43_STARTADDR   (FLASH_PAGE0_STARTADDR + 43 * FLASH_PAGE_SIZE)
#define FLASH_PAGE44_STARTADDR   (FLASH_PAGE0_STARTADDR + 44 * FLASH_PAGE_SIZE)
#define FLASH_PAGE45_STARTADDR   (FLASH_PAGE0_STARTADDR + 45 * FLASH_PAGE_SIZE)
#define FLASH_PAGE46_STARTADDR   (FLASH_PAGE0_STARTADDR + 46 * FLASH_PAGE_SIZE)
#define FLASH_PAGE47_STARTADDR   (FLASH_PAGE0_STARTADDR + 47 * FLASH_PAGE_SIZE)
#define FLASH_PAGE48_STARTADDR   (FLASH_PAGE0_STARTADDR + 48 * FLASH_PAGE_SIZE)

#define FLASH_PAGE49_STARTADDR   (FLASH_PAGE0_STARTADDR + 49 * FLASH_PAGE_SIZE)
#define FLASH_PAGE50_STARTADDR   (FLASH_PAGE0_STARTADDR + 50 * FLASH_PAGE_SIZE)
#define FLASH_PAGE51_STARTADDR   (FLASH_PAGE0_STARTADDR + 51 * FLASH_PAGE_SIZE)
#define FLASH_PAGE52_STARTADDR   (FLASH_PAGE0_STARTADDR + 52 * FLASH_PAGE_SIZE)
#define FLASH_PAGE53_STARTADDR   (FLASH_PAGE0_STARTADDR + 53 * FLASH_PAGE_SIZE)
#define FLASH_PAGE54_STARTADDR   (FLASH_PAGE0_STARTADDR + 54 * FLASH_PAGE_SIZE)
#define FLASH_PAGE55_STARTADDR   (FLASH_PAGE0_STARTADDR + 55 * FLASH_PAGE_SIZE)
#define FLASH_PAGE56_STARTADDR   (FLASH_PAGE0_STARTADDR + 56 * FLASH_PAGE_SIZE)
#define FLASH_PAGE57_STARTADDR   (FLASH_PAGE0_STARTADDR + 57 * FLASH_PAGE_SIZE)
#define FLASH_PAGE58_STARTADDR   (FLASH_PAGE0_STARTADDR + 58 * FLASH_PAGE_SIZE)
#define FLASH_PAGE59_STARTADDR   (FLASH_PAGE0_STARTADDR + 59 * FLASH_PAGE_SIZE)
#define FLASH_PAGE60_STARTADDR   (FLASH_PAGE0_STARTADDR + 60 * FLASH_PAGE_SIZE)
#define FLASH_PAGE61_STARTADDR   (FLASH_PAGE0_STARTADDR + 61 * FLASH_PAGE_SIZE)
#define FLASH_PAGE62_STARTADDR   (FLASH_PAGE0_STARTADDR + 62 * FLASH_PAGE_SIZE)
#define FLASH_PAGE63_STARTADDR   (FLASH_PAGE0_STARTADDR + 63 * FLASH_PAGE_SIZE)
#define FLASH_PAGE64_STARTADDR   (FLASH_PAGE0_STARTADDR + 64 * FLASH_PAGE_SIZE)
#define FLASH_PAGE65_STARTADDR   (FLASH_PAGE0_STARTADDR + 65 * FLASH_PAGE_SIZE)
#define FLASH_PAGE66_STARTADDR   (FLASH_PAGE0_STARTADDR + 66 * FLASH_PAGE_SIZE)
//
//#define FLASH_PAGE_STARTADDR		FLASH_PAGE64_STARTADDR
//512K
//#define FLASH_PAGE_STARTADDR		(FLASH_PAGE0_STARTADDR + 511 * FLASH_PAGE_SIZE)
//64K
#define FLASH_PAGE_STARTADDR		(FLASH_PAGE0_STARTADDR + 63 * FLASH_PAGE_SIZE)
//64K
#define ERASE_PAGE_START_ADDR           (0x08000000U + 0x400U * 63)


/*---------------------------------------------------------------------------*/
//105 工作电压5V
//定义各限值的初始值
#define CURRENT_MIN_105    (((0.040 * 4096) / 3.3) * 0.2 * 100)
//允许最小电流为(3.3 * CURRENT_MIN_0 / 4096 / 0.2 / 100)*1000=40mA
//电压差放大100倍(pcb_check_info[i][j].Current&0xFFF)*3.3/4096)/0.2/100

#define CURRENT_MAX_105    (((0.060 * 4096) / 3.3) * 0.2 * 100)
//允许最大电流为(3.3 * CURRENT_MAX_0 / 4096 / 0.2 / 100)*1000=60mA

#define CURRENT_SHORT_105  (((0.090 * 4096) / 3.3) * 0.2 * 100)
//短路电流门限为(3.3 * CURRENT_SHORT_0 / 4096 / 0.2 / 100)*1000=90mA

#define V1V_MIN_105    ((1.10 * 4096) / 3.3)
//允许1.2V最小电压为3.3 * V1V_MAX_0 / 4096 = 1.15V

#define V1V_MAX_105    ((1.30 * 4096) / 3.3)
//允许1.2V最大电压为3.3 * V1V_MAX_0 / 4096 = 1.25V

#define V3V_MIN_105    ((0.12 * 4096) / 3.3)
//允许3V最小电压为3.3 * V3V_MIN_0 / 4096 = 0.12V

#define V3V_MAX_105    ((0.45 * 4096) / 3.3)
//允许3V最大电压为3.3 * V3V_MAX_0 / 4096 = 0.45V

#define SUM_SUB		400000
//运动分量减去无运动分量的差值，超过这个值表示模块正常

//201 工作电压12V
//定义各限值的初始值
#define CURRENT_MIN_201    (((0.014 * 4096) / 3.3) * 0.2 * 100)
//允许最小电流为(3.3 * CURRENT_MIN_0 / 4096 / 0.2 / 100)*1000=14mA
//电压差放大100倍(pcb_check_info[i][j].Current&0xFFF)*3.3/4096)/0.2/100

#define CURRENT_MAX_201    (((0.017 * 4096) / 3.3) * 0.2 * 100)
//允许最大电流为(3.3 * CURRENT_MAX_0 / 4096 / 0.2 / 100)*1000=17mA

#define CURRENT_SHORT_201  (((0.025 * 4096) / 3.3) * 0.2 * 100)
//短路电流门限为(3.3 * CURRENT_SHORT_0 / 4096 / 0.2 / 100)*1000=25mA

#define V1V_MIN_201    ((1.10 * 4096) / 3.3)
//允许1.2V最小电压为3.3 * V1V_MAX_0 / 4096 = 1.15V

#define V1V_MAX_201    ((1.30 * 4096) / 3.3)
//允许1.2V最大电压为3.3 * V1V_MAX_0 / 4096 = 1.25V

#define V3V_MIN_201    ((1.45 * 4096) / 3.3)
//允许3V最小电压为3.3 * V3V_MIN_0 / 4096 = 1.45V 电压为1.45V * 2

#define V3V_MAX_201    ((1.60 * 4096) / 3.3)
//允许3V最大电压为3.3 * V3V_MAX_0 / 4096 = 1.60V 电压为1.60V * 2


#define TH_MIN_0			150
//允许测试模式下灯控板最小门限值

#define TH_MAX_0			150
//允许测试模式下灯控板最大门限值

#define LIGHT_AD_MIN_0  30
//30
//允许测试工装电路板感光AD值最小值--环境光线强度最小值

#define LIGHT_AD_MAX_0  190
//180
//允许测试工装电路板感光AD值最小值--环境光线强度最小值

#define LIGHT_AD_MAX_DELTA_PERCENT_0  30
//允许灯控板感光AD值与测试工装电路板感光AD值最大偏差的百分比

#define AVERAGE_MIN_0  41
//允许直流电压最小值为2.0*41/256=0.32V

#define AVERAGE_MAX_0  112
//允许直流电压最大值为2.0*112/256=0.875V



/*---------------------------------------------------------------------------*/


typedef struct
{  
	unsigned short   flashwrite;
}DATA_MANAGE;

typedef struct
{  
	unsigned char   runflag;
	unsigned char   runendflag;
	//////////////////////////////////////////////////////////////
	//XBR105模组
	unsigned int 		Current_AdMin_105;//模块最小电流
	unsigned int 		Current_AdMax_105;//模块最大电流
	unsigned int 		Current_Short_105;//短路门限电流
	//1.2V电压
	unsigned int 		V_1V_AdMin_105;//模块最小工作电压
	unsigned int 		V_1V_AdMax_105;//模块最大工作电压
	//静止状态平均值
	unsigned int 		V_3V_AdMin_105;//模块雷达信号最小值
	unsigned int 		V_3V_AdMax_105;//模块雷达信号最大值

	//////////////////////////////////////////////////////////////
	//XBR201模组
	unsigned int 		Current_AdMin_201;//模块最小电流
	unsigned int 		Current_AdMax_201;//模块最大电流
	unsigned int 		Current_Short_201;//短路门限电流
	//1.2V电压
	unsigned int 		V_1V_AdMin_201;//模块最小工作电压
	unsigned int 		V_1V_AdMax_201;//模块最大工作电压
	//静止状态平均值
	unsigned int 		V_3V_AdMin_201;//模块3V电压最小值
	unsigned int 		V_3V_AdMax_201;//模块3V电压最大值

	//////////////////////////////////////////////////////////////
	//公共参数
	//正向运动状态
	unsigned int 		V_3V_AdMin0;//最小值
	unsigned int 		V_3V_AdMax0;//最大值
	//反向运动状态
	unsigned int 		V_3V_AdMin1;//最小值
	unsigned int 		V_3V_AdMax1;//最大值
	//无运动时积分量范围
	unsigned int 		SUM0_Min;//最小值
	unsigned int		SUM0_Max;//最大值
	//运动时积分量范围
	unsigned int 		SUM1_Min;//最小值
	unsigned int		SUM1_Max;//最大值
	//运动时积分量-无运动时积分量
	unsigned int 		SUM_Sub;
	//光感量
	unsigned int 		LIGHT_AdMin;
	unsigned int 		LIGHT_AdMax;
	unsigned int 		LIGHT_AdMax_Delta_Percent;
	//门限
	unsigned int 		TH_Min;
	unsigned int 		TH_Max;
	//均值
	unsigned int		Average_Min;
	unsigned int 		Average_Max;
	
	//////////////////////////////////////////////////////////////
	//测试参数
	unsigned int XBR_TH;
	unsigned int XBR_LIGHT_TH;
	unsigned int XBR_DELAY_NUM;
	unsigned int XBR_ID;
	unsigned char XBR_STATUS;
	
	//////////////////////////////////////////////////////////////
	//性能测试
	unsigned int		XBR_PE;
	//功能测试
	unsigned int 		XBR_FUN;
	//烧录功能
	unsigned int		XBR_DL;
	//LED
	unsigned int 		led_data;
	//模组波特率
	unsigned int		BaudRate; 
	//模组类型
	unsigned int 		MODE_Select;//0 XBR105 1 XBR201 2 XBR401 3 XBR202
}PARA_MANAGE;

typedef struct
{  
  unsigned short   runflag;
  unsigned short   runendflag;
}PARA_test;

extern uint32_t WriteFlashData;
extern uint32_t addr;
extern  DATA_MANAGE  datmag;
extern  PARA_MANAGE  Para;
extern  PARA_test    Test;

/*---------------------------------------------------------------------------*/


/**********************************************************************
* 程序 : void writeFlashTest(void)
* 功能 : FLASH写入程?
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void writeFlashTest(void);

/**********************************************************************
* 程序 : void printFlashTest(void)
* 功能 : FLASH读取打印程?
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void printFlashTest(void);


/**********************************************************************
* 程序 : void fmc_erase_and_program(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void fmc_erase_and_program(void);

/**********************************************************************
* 程序 : unsigned char writeMessageToFlash(unsigned long addr, unsigned char *buff , unsigned short length)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

unsigned char writeMessageToFlash(unsigned long addr, unsigned char *buff , unsigned short length);

/**********************************************************************
* 程序 : unsigned short readPackedMessageFromFlash(unsigned long addr, unsigned char *buff , unsigned short length)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

unsigned short readPackedMessageFromFlash(unsigned long addr, unsigned char *buff , unsigned short length);

/**********************************************************************
* 程序 : void Testreset(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Testreset(void);

/**********************************************************************
* 程序 : void Parareset(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Parareset(void);


/**********************************************************************
* 程序 : void ParaRecovery(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void ParaRecovery(void);


/**********************************************************************
* 程序 : void ParaInit(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void ParaInit(void);

/**********************************************************************
* 程序 : void ParaRead(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void ParaRead(void);


/**********************************************************************
* 程序 : void ParaWrite(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void ParaWrite(void);



#endif
