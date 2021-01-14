//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�BSP_Flash.c
//���ܸ�Ҫ��BSP_Flash����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================

#include "stm32f1xx_hal.h"
#include "systick.h"
#include <stdio.h>
#include <math.h>
#include "BSP_Flash.h"

//���⣺��������512K��С��Flash��ʹ�õ������һ�������ĵ�һҳ��ÿ����������ҳ��
//���ʹ��Flash��СΪ256K��оƬaddr����Ϊ0x0803E000
//���ʹ��Flash��СΪ128K��оƬaddr����Ϊ0x0801F000
//���ʹ��Flash��СΪ64K��оƬaddr����Ϊ0x08007000
uint32_t WriteFlashData = 0x12345678;
//uint32_t addr = 0x0800F400;
uint32_t addr = FLASH_PAGE_STARTADDR;

PARA_MANAGE  Para;
DATA_MANAGE  datmag;
PARA_test    Test;


/**********************************************************************
* ���� : void writeFlashTest(void)
* ���� : FLASHд���?
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/


void writeFlashTest(void)
{
	// 1/4����FLASH
	HAL_FLASH_Unlock();

	// 2/4����FLASH
	//��ʼ��FLASH_EraseInitTypeDef
	//������ʽҳ����FLASH_TYPEERASE_PAGES�������FLASH_TYPEERASE_MASSERASE
	//����ҳ��
	//������ַ
	FLASH_EraseInitTypeDef FlashSet;
	FlashSet.TypeErase = FLASH_TYPEERASE_PAGES;
	FlashSet.PageAddress = addr;
	FlashSet.NbPages = 1;
	
	//����PageError�����ò�������
	uint32_t PageError = 0;
	HAL_FLASHEx_Erase(&FlashSet, &PageError);

	// 3/4��FLASH��д
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addr, WriteFlashData);

	// 4/4��סFLASH
	HAL_FLASH_Lock();
}

/**********************************************************************
* ���� : void printFlashTest(void)
* ���� : FLASH��ȡ��ӡ��?
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void printFlashTest(void)
{
	
	uint32_t temp = *(__IO uint32_t*)(addr);

	printf("addr is:0x%x, data is:0x%x\r\n", addr, temp);
}

 
/**********************************************************************
* ���� : void fmc_erase_and_program(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
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
	
	//����PageError�����ò�������
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
* ���� : unsigned char writeMessageToFlash(unsigned long addr, unsigned char *buff , unsigned short length)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

unsigned char writeMessageToFlash(unsigned long addr, unsigned char *buff , unsigned short length)
{
	unsigned char *p, t;
	unsigned short i;
	unsigned long  temp,addre = addr;
	// 1/4����FLASH
	HAL_FLASH_Unlock();

	// 2/4����FLASH
	//��ʼ��FLASH_EraseInitTypeDef
	//������ʽҳ����FLASH_TYPEERASE_PAGES�������FLASH_TYPEERASE_MASSERASE
	//����ҳ��
	//������ַ
	FLASH_EraseInitTypeDef FlashSet;
	FlashSet.TypeErase = FLASH_TYPEERASE_PAGES;
	FlashSet.PageAddress = addre;
	FlashSet.NbPages = 1;

	//����PageError�����ò�������
	uint32_t PageError = 0;
	HAL_FLASHEx_Erase(&FlashSet, &PageError);

	// 3/4��FLASH��д
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

	// 4/4��סFLASH
	HAL_FLASH_Lock(); 

	return 0;
}

/**********************************************************************
* ���� : unsigned short readPackedMessageFromFlash(unsigned long addr, unsigned char *buff , unsigned short length)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
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
* ���� : void Testreset(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Testreset(void)
{
	for(int i = 0; i < (sizeof(PARA_test)); i++)
	Test.runflag = 0xAA;
	Test.runendflag = 0xAA;  
}

/**********************************************************************
* ���� : void Parareset(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
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
	//��������
	Para.V_3V_AdMin0 = 0;
	Para.V_3V_AdMax0 = 0;

	Para.V_3V_AdMin1 = 0;
	Para.V_3V_AdMax1 = 0;
	
	Para.SUM0_Min = 0;
	Para.SUM0_Max = 0;

	Para.SUM1_Min = 0;
	Para.SUM1_Max = 0;

	//�˶�ʱ������-���˶�ʱ������
	Para.SUM_Sub = (unsigned int)SUM_SUB;

	Para.LIGHT_AdMin = (unsigned int)LIGHT_AD_MIN_0;
	Para.LIGHT_AdMax = (unsigned int)LIGHT_AD_MAX_0;
	Para.LIGHT_AdMin = (unsigned int)LIGHT_AD_MAX_DELTA_PERCENT_0;

	Para.TH_Min = (unsigned int)TH_MIN_0;
	Para.TH_Max = (unsigned int)TH_MAX_0;

	Para.Average_Min = (unsigned int)AVERAGE_MIN_0;
	Para.Average_Max = (unsigned int)AVERAGE_MAX_0;

	//////////////////////////////////////////////////////////////
	//���Բ���
	Para.XBR_TH = 60000;
	Para.XBR_LIGHT_TH = 255;
	Para.XBR_DELAY_NUM = 5;
	Para.XBR_ID = 0;
	Para.XBR_STATUS = 0;

	//////////////////////////////////////////////////////////////
	//���ܲ���
	Para.XBR_PE = 1;
	//201���ܲ���
	Para.XBR_FUN = 1;
	//��¼����
	Para.XBR_DL=0;

	Para.led_data = 0;
	Para.BaudRate = 9600;
	Para.MODE_Select = 0;//0Ϊ105��1Ϊ201��2Ϊ402��3Ϊ202
}

/**********************************************************************
* ���� : void ParaRecovery(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void ParaRecovery(void)
{
    Parareset();
    writeMessageToFlash(FLASH_PAGE_STARTADDR, (unsigned char *)&Para , sizeof(PARA_MANAGE));
}



/**********************************************************************
* ���� : void ParaInit(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
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
* ���� : void ParaRead(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
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
* ���� : void ParaWrite(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
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




