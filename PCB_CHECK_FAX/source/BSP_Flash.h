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
//105 ������ѹ5V
//�������ֵ�ĳ�ʼֵ
#define CURRENT_MIN_105    (((0.040 * 4096) / 3.3) * 0.2 * 100)
//������С����Ϊ(3.3 * CURRENT_MIN_0 / 4096 / 0.2 / 100)*1000=40mA
//��ѹ��Ŵ�100��(pcb_check_info[i][j].Current&0xFFF)*3.3/4096)/0.2/100

#define CURRENT_MAX_105    (((0.060 * 4096) / 3.3) * 0.2 * 100)
//����������Ϊ(3.3 * CURRENT_MAX_0 / 4096 / 0.2 / 100)*1000=60mA

#define CURRENT_SHORT_105  (((0.090 * 4096) / 3.3) * 0.2 * 100)
//��·��������Ϊ(3.3 * CURRENT_SHORT_0 / 4096 / 0.2 / 100)*1000=90mA

#define V1V_MIN_105    ((1.10 * 4096) / 3.3)
//����1.2V��С��ѹΪ3.3 * V1V_MAX_0 / 4096 = 1.15V

#define V1V_MAX_105    ((1.30 * 4096) / 3.3)
//����1.2V����ѹΪ3.3 * V1V_MAX_0 / 4096 = 1.25V

#define V3V_MIN_105    ((0.12 * 4096) / 3.3)
//����3V��С��ѹΪ3.3 * V3V_MIN_0 / 4096 = 0.12V

#define V3V_MAX_105    ((0.45 * 4096) / 3.3)
//����3V����ѹΪ3.3 * V3V_MAX_0 / 4096 = 0.45V

#define SUM_SUB		400000
//�˶�������ȥ���˶������Ĳ�ֵ���������ֵ��ʾģ������

//201 ������ѹ12V
//�������ֵ�ĳ�ʼֵ
#define CURRENT_MIN_201    (((0.014 * 4096) / 3.3) * 0.2 * 100)
//������С����Ϊ(3.3 * CURRENT_MIN_0 / 4096 / 0.2 / 100)*1000=14mA
//��ѹ��Ŵ�100��(pcb_check_info[i][j].Current&0xFFF)*3.3/4096)/0.2/100

#define CURRENT_MAX_201    (((0.017 * 4096) / 3.3) * 0.2 * 100)
//����������Ϊ(3.3 * CURRENT_MAX_0 / 4096 / 0.2 / 100)*1000=17mA

#define CURRENT_SHORT_201  (((0.025 * 4096) / 3.3) * 0.2 * 100)
//��·��������Ϊ(3.3 * CURRENT_SHORT_0 / 4096 / 0.2 / 100)*1000=25mA

#define V1V_MIN_201    ((1.10 * 4096) / 3.3)
//����1.2V��С��ѹΪ3.3 * V1V_MAX_0 / 4096 = 1.15V

#define V1V_MAX_201    ((1.30 * 4096) / 3.3)
//����1.2V����ѹΪ3.3 * V1V_MAX_0 / 4096 = 1.25V

#define V3V_MIN_201    ((1.45 * 4096) / 3.3)
//����3V��С��ѹΪ3.3 * V3V_MIN_0 / 4096 = 1.45V ��ѹΪ1.45V * 2

#define V3V_MAX_201    ((1.60 * 4096) / 3.3)
//����3V����ѹΪ3.3 * V3V_MAX_0 / 4096 = 1.60V ��ѹΪ1.60V * 2


#define TH_MIN_0			150
//�������ģʽ�µƿذ���С����ֵ

#define TH_MAX_0			150
//�������ģʽ�µƿذ��������ֵ

#define LIGHT_AD_MIN_0  30
//30
//������Թ�װ��·��й�ADֵ��Сֵ--��������ǿ����Сֵ

#define LIGHT_AD_MAX_0  190
//180
//������Թ�װ��·��й�ADֵ��Сֵ--��������ǿ����Сֵ

#define LIGHT_AD_MAX_DELTA_PERCENT_0  30
//����ƿذ�й�ADֵ����Թ�װ��·��й�ADֵ���ƫ��İٷֱ�

#define AVERAGE_MIN_0  41
//����ֱ����ѹ��СֵΪ2.0*41/256=0.32V

#define AVERAGE_MAX_0  112
//����ֱ����ѹ���ֵΪ2.0*112/256=0.875V



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
	//XBR105ģ��
	unsigned int 		Current_AdMin_105;//ģ����С����
	unsigned int 		Current_AdMax_105;//ģ��������
	unsigned int 		Current_Short_105;//��·���޵���
	//1.2V��ѹ
	unsigned int 		V_1V_AdMin_105;//ģ����С������ѹ
	unsigned int 		V_1V_AdMax_105;//ģ���������ѹ
	//��ֹ״̬ƽ��ֵ
	unsigned int 		V_3V_AdMin_105;//ģ���״��ź���Сֵ
	unsigned int 		V_3V_AdMax_105;//ģ���״��ź����ֵ

	//////////////////////////////////////////////////////////////
	//XBR201ģ��
	unsigned int 		Current_AdMin_201;//ģ����С����
	unsigned int 		Current_AdMax_201;//ģ��������
	unsigned int 		Current_Short_201;//��·���޵���
	//1.2V��ѹ
	unsigned int 		V_1V_AdMin_201;//ģ����С������ѹ
	unsigned int 		V_1V_AdMax_201;//ģ���������ѹ
	//��ֹ״̬ƽ��ֵ
	unsigned int 		V_3V_AdMin_201;//ģ��3V��ѹ��Сֵ
	unsigned int 		V_3V_AdMax_201;//ģ��3V��ѹ���ֵ

	//////////////////////////////////////////////////////////////
	//��������
	//�����˶�״̬
	unsigned int 		V_3V_AdMin0;//��Сֵ
	unsigned int 		V_3V_AdMax0;//���ֵ
	//�����˶�״̬
	unsigned int 		V_3V_AdMin1;//��Сֵ
	unsigned int 		V_3V_AdMax1;//���ֵ
	//���˶�ʱ��������Χ
	unsigned int 		SUM0_Min;//��Сֵ
	unsigned int		SUM0_Max;//���ֵ
	//�˶�ʱ��������Χ
	unsigned int 		SUM1_Min;//��Сֵ
	unsigned int		SUM1_Max;//���ֵ
	//�˶�ʱ������-���˶�ʱ������
	unsigned int 		SUM_Sub;
	//�����
	unsigned int 		LIGHT_AdMin;
	unsigned int 		LIGHT_AdMax;
	unsigned int 		LIGHT_AdMax_Delta_Percent;
	//����
	unsigned int 		TH_Min;
	unsigned int 		TH_Max;
	//��ֵ
	unsigned int		Average_Min;
	unsigned int 		Average_Max;
	
	//////////////////////////////////////////////////////////////
	//���Բ���
	unsigned int XBR_TH;
	unsigned int XBR_LIGHT_TH;
	unsigned int XBR_DELAY_NUM;
	unsigned int XBR_ID;
	unsigned char XBR_STATUS;
	
	//////////////////////////////////////////////////////////////
	//���ܲ���
	unsigned int		XBR_PE;
	//���ܲ���
	unsigned int 		XBR_FUN;
	//��¼����
	unsigned int		XBR_DL;
	//LED
	unsigned int 		led_data;
	//ģ�鲨����
	unsigned int		BaudRate; 
	//ģ������
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
* ���� : void writeFlashTest(void)
* ���� : FLASHд���?
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void writeFlashTest(void);

/**********************************************************************
* ���� : void printFlashTest(void)
* ���� : FLASH��ȡ��ӡ��?
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void printFlashTest(void);


/**********************************************************************
* ���� : void fmc_erase_and_program(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void fmc_erase_and_program(void);

/**********************************************************************
* ���� : unsigned char writeMessageToFlash(unsigned long addr, unsigned char *buff , unsigned short length)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

unsigned char writeMessageToFlash(unsigned long addr, unsigned char *buff , unsigned short length);

/**********************************************************************
* ���� : unsigned short readPackedMessageFromFlash(unsigned long addr, unsigned char *buff , unsigned short length)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

unsigned short readPackedMessageFromFlash(unsigned long addr, unsigned char *buff , unsigned short length);

/**********************************************************************
* ���� : void Testreset(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Testreset(void);

/**********************************************************************
* ���� : void Parareset(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void Parareset(void);


/**********************************************************************
* ���� : void ParaRecovery(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void ParaRecovery(void);


/**********************************************************************
* ���� : void ParaInit(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void ParaInit(void);

/**********************************************************************
* ���� : void ParaRead(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void ParaRead(void);


/**********************************************************************
* ���� : void ParaWrite(void)
* ���� : ��
* ���� : ��
* ��� : ��
* ���� : Steven.Hu ���ڣ�2020��3��23��
***********************************************************************/

void ParaWrite(void);



#endif
