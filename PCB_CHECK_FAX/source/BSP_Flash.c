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

#include "stm32f1xx_hal.h"
#include "systick.h"
#include <stdio.h>
#include <math.h>
#include "BSP_Flash.h"

//讲解：本程序是512K大小的Flash，使用的是最后一个扇区的第一页（每个扇区有四页）
//如果使用Flash大小为256K的芯片addr请设为0x0803E000
//如果使用Flash大小为128K的芯片addr请设为0x0801F000
//如果使用Flash大小为64K的芯片addr请设为0x08007000
uint32_t WriteFlashData = 0x12345678;
//uint32_t addr = 0x0800F400;
uint32_t addr = FLASH_PAGE_STARTADDR;

PARA_MANAGE  Para;
DATA_MANAGE  datmag;
PARA_test    Test;


/**********************************************************************
* 程序 : void writeFlashTest(void)
* 功能 : FLASH写入程?
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/


void writeFlashTest(void)
{
	// 1/4解锁FLASH
	HAL_FLASH_Unlock();

	// 2/4擦除FLASH
	//初始化FLASH_EraseInitTypeDef
	//擦除方式页擦除FLASH_TYPEERASE_PAGES，块擦除FLASH_TYPEERASE_MASSERASE
	//擦除页数
	//擦除地址
	FLASH_EraseInitTypeDef FlashSet;
	FlashSet.TypeErase = FLASH_TYPEERASE_PAGES;
	FlashSet.PageAddress = addr;
	FlashSet.NbPages = 1;
	
	//设置PageError，调用擦除函数
	uint32_t PageError = 0;
	HAL_FLASHEx_Erase(&FlashSet, &PageError);

	// 3/4对FLASH烧写
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addr, WriteFlashData);

	// 4/4锁住FLASH
	HAL_FLASH_Lock();
}

/**********************************************************************
* 程序 : void printFlashTest(void)
* 功能 : FLASH读取打印程?
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void printFlashTest(void)
{
	
	uint32_t temp = *(__IO uint32_t*)(addr);

	printf("addr is:0x%x, data is:0x%x\r\n", addr, temp);
}

 
/**********************************************************************
* 程序 : void fmc_erase_and_program(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void fmc_erase_and_program(void)
{
    uint32_t *ptr = (uint32_t *)ERASE_PAGE_START_ADDR;

    // unlock the flash program/erase controller
    HAL_FLASH_Unlock();

    // erase target page 
	FLASH_EraseInitTypeDef FlashSet;
	FlashSet.TypeErase = FLASH_TYPEERASE_PAGES;
	FlashSet.PageAddress = ERASE_PAGE_START_ADDR;
	FlashSet.NbPages = 1;
	
	//设置PageError，调用擦除函数
	uint32_t PageError = 0;
	HAL_FLASHEx_Erase(&FlashSet, &PageError);
	
    // check the erase result, light the LED2 if the result is failed 
    if(0xFFFFFFFF != (*ptr))
	{
     	printf("erase err\r\n");
        return;
    }

    // program target address 
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, ERASE_PAGE_START_ADDR, WriteFlashData);
		
    // check the program result, light the LED2 if the result is failed 
    if(WriteFlashData != (*ptr))
	{
    	printf("program err\r\n");
       return;
    }

    // lock the main FMC after the operation 
    HAL_FLASH_Lock();

}

/**********************************************************************
* 程序 : unsigned char writeMessageToFlash(unsigned long addr, unsigned char *buff , unsigned short length)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

unsigned char writeMessageToFlash(unsigned long addr, unsigned char *buff , unsigned short length)
{
	unsigned char *p, t;
	unsigned short i;
	unsigned long  temp,addre = addr;
	// 1/4解锁FLASH
	HAL_FLASH_Unlock();

	// 2/4擦除FLASH
	//初始化FLASH_EraseInitTypeDef
	//擦除方式页擦除FLASH_TYPEERASE_PAGES，块擦除FLASH_TYPEERASE_MASSERASE
	//擦除页数
	//擦除地址
	FLASH_EraseInitTypeDef FlashSet;
	FlashSet.TypeErase = FLASH_TYPEERASE_PAGES;
	FlashSet.PageAddress = addre;
	FlashSet.NbPages = 1;

	//设置PageError，调用擦除函数
	uint32_t PageError = 0;
	HAL_FLASHEx_Erase(&FlashSet, &PageError);

	// 3/4对FLASH烧写
	p = buff;
	for(i = 0; i < (length >> 2); i++)
	{
		for(temp = 0, t = 0; t < 4; t++)
		temp = (temp << 8) | (*((p)++));

		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addre, temp);
		addre += 4;
	}

	if(length & 0x03)
	{
		for(temp = 0, t = 0; t < 4; t++)
		temp = (temp << 8) | (*((p)++));

		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addre, temp);
	}

	// 4/4锁住FLASH
	HAL_FLASH_Lock(); 

	return 0;
}

/**********************************************************************
* 程序 : unsigned short readPackedMessageFromFlash(unsigned long addr, unsigned char *buff , unsigned short length)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

unsigned short readPackedMessageFromFlash(unsigned long addr, unsigned char *buff , unsigned short length)
{
	unsigned char *p, t;
	unsigned short i;
	unsigned long temp,addre = addr;

	p = buff;
	for(i = 0; i < (length >> 2); i++)
	{
		temp = *(unsigned long *)addre;
		for(t = 0 ; t < 4; t++)
			*((p)++) = (unsigned char)(temp >> ((3 - t) * 8));
		addre += 4;
	}

	if(length & 0x03)
	{
		temp = *(unsigned long *)addre;
		for(t = 0; t < (length & 0x03); t++)
			*((p)++) = (unsigned char)(temp >> ((3 - t) * 8));
	}

	return i;
}

/**********************************************************************
* 程序 : void Testreset(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Testreset(void)
{
	for(int i = 0; i < (sizeof(PARA_test)); i++)
	Test.runflag = 0xAA;
	Test.runendflag = 0xAA;  
}

/**********************************************************************
* 程序 : void Parareset(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void Parareset(void)
{
	//for(int i = 0; i < (sizeof(PARA_MANAGE)); i++)

	Para.runflag = 0xAA;
	Para.runendflag = 0xAA;
	//////////////////////////////////////////////////////////////
	//105
	Para.Current_AdMin_105 = (unsigned int)CURRENT_MIN_105;
	Para.Current_AdMax_105 = (unsigned int)CURRENT_MAX_105;
	Para.Current_Short_105 = (unsigned int)CURRENT_SHORT_105;

	Para.V_1V_AdMin_105 = (unsigned int)V1V_MIN_105;
	Para.V_1V_AdMax_105 = (unsigned int)V1V_MAX_105;

	Para.V_3V_AdMin_105 = (unsigned int)V3V_MIN_105;
	Para.V_3V_AdMax_105 = (unsigned int)V3V_MAX_105;


	
	//////////////////////////////////////////////////////////////
	//201
	Para.Current_AdMin_201 = (unsigned int)CURRENT_MIN_201;
	Para.Current_AdMax_201 = (unsigned int)CURRENT_MAX_201;
	Para.Current_Short_201 = (unsigned int)CURRENT_SHORT_201;

	Para.V_1V_AdMin_201 = (unsigned int)V1V_MIN_201;
	Para.V_1V_AdMax_201 = (unsigned int)V1V_MAX_201;

	Para.V_3V_AdMin_201 = (unsigned int)V3V_MIN_201;
	Para.V_3V_AdMax_201 = (unsigned int)V3V_MAX_201;

	//////////////////////////////////////////////////////////////
	//公共参数
	Para.V_3V_AdMin0 = 0;
	Para.V_3V_AdMax0 = 0;

	Para.V_3V_AdMin1 = 0;
	Para.V_3V_AdMax1 = 0;
	
	Para.SUM0_Min = 0;
	Para.SUM0_Max = 0;

	Para.SUM1_Min = 0;
	Para.SUM1_Max = 0;

	//运动时积分量-无运动时积分量
	Para.SUM_Sub = (unsigned int)SUM_SUB;

	Para.LIGHT_AdMin = (unsigned int)LIGHT_AD_MIN_0;
	Para.LIGHT_AdMax = (unsigned int)LIGHT_AD_MAX_0;
	Para.LIGHT_AdMin = (unsigned int)LIGHT_AD_MAX_DELTA_PERCENT_0;

	Para.TH_Min = (unsigned int)TH_MIN_0;
	Para.TH_Max = (unsigned int)TH_MAX_0;

	Para.Average_Min = (unsigned int)AVERAGE_MIN_0;
	Para.Average_Max = (unsigned int)AVERAGE_MAX_0;

	//////////////////////////////////////////////////////////////
	//测试参数
	Para.XBR_TH = 60000;
	Para.XBR_LIGHT_TH = 255;
	Para.XBR_DELAY_NUM = 5;
	Para.XBR_ID = 0;
	Para.XBR_STATUS = 0;

	//////////////////////////////////////////////////////////////
	//性能测试
	Para.XBR_PE = 1;
	//201功能测试
	Para.XBR_FUN = 1;
	//烧录功能
	Para.XBR_DL=0;

	Para.led_data = 0;
	Para.BaudRate = 9600;
	Para.MODE_Select = 0;//0为105，1为201，2为402，3为202
}

/**********************************************************************
* 程序 : void ParaRecovery(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void ParaRecovery(void)
{
    Parareset();
    writeMessageToFlash(FLASH_PAGE_STARTADDR, (unsigned char *)&Para , sizeof(PARA_MANAGE));
}



/**********************************************************************
* 程序 : void ParaInit(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void ParaInit(void)
{
  #if (0)
    Testreset();
   	writeMessageToFlash(FLASH_PAGE_STARTADDR, (unsigned char *)&Test , sizeof(PARA_test));
    Test.runflag = 0;
    Test.runendflag = 0;
    readPackedMessageFromFlash(FLASH_PAGE_STARTADDR,(unsigned char *)&Test, sizeof(PARA_test));
    return;
  #endif
  
  readPackedMessageFromFlash(FLASH_PAGE_STARTADDR, (unsigned char *)&Para, sizeof(PARA_MANAGE));
  
  if((Para.runflag != 0xAA)||(Para.runendflag != 0xAA))
  {
    Parareset();
    writeMessageToFlash(FLASH_PAGE_STARTADDR, (unsigned char *)&Para , sizeof(PARA_MANAGE));
  }
  
}


/**********************************************************************
* 程序 : void ParaRead(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void ParaRead(void)
{
	readPackedMessageFromFlash(FLASH_PAGE_STARTADDR, (unsigned char *)&Para, sizeof(PARA_MANAGE));
	//test
	/*
	unsigned int i = 0;
	unsigned char buff[11] = {0};
	unsigned char len = 0;
	len = sizeof(buff);
	readPackedMessageFromFlash(FLASH_PAGE_STARTADDR, buff, len);
	printf("\r\n################### ParaRead ###################\r\n");
	printf("DATA:");
	for( i = 0; i < len; i++)
	{
		printf("0x%02X ", buff[i]);
	}*/

}


/**********************************************************************
* 程序 : void ParaWrite(void)
* 功能 : 无
* 输入 : 无
* 输出 : 无
* 作者 : Steven.Hu 日期：2020年3月23日
***********************************************************************/

void ParaWrite(void)
{
  if(datmag.flashwrite == 0xAA)
  {
    datmag.flashwrite = 0x00;
    writeMessageToFlash(FLASH_PAGE_STARTADDR, (unsigned char *)&Para , sizeof(PARA_MANAGE));
  }
  	/*
	static unsigned char off = 0;
	unsigned int i = 0;
	unsigned char buff[11] = {0};
	unsigned char len = 0;
	len = sizeof(buff);

	off = off + 10;
	for(i=0;i<len;i++)
	{
		buff[i] = i + off;
	}

	printf("\r\n################### ParaWrite ###################\r\n");
	printf("DATA:");
	for( i = 0; i < len; i++)
	{
		printf("0x%02X ", buff[i]);
	}

	writeMessageToFlash(FLASH_PAGE_STARTADDR, buff, len);
*/
}




