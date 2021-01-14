//=============================================================================
//��˾���ƣ�������
//�ļ����ƣ�MODE_XBR.h
//���ܸ�Ҫ��MODE_XBR����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================


#ifndef MODE_XBR_H
#define MODE_XBR_H

#include <stdint.h>

//ͨ������Э�鲿��
#define PACKET_HEADER_BYTE1	0x3C
#define PACKET_HEADER_BYTE2	0x3A
#define PACKET_TAIL_BYTE1	0x3A
#define PACKET_TAIL_BYTE2	0x3E
#define PACKET_CMD_REASTAT	0xF0
#define PACKET_CMD_SETPARA	0xF1
#define PACKET_CMD_GETPARA	0xF2
#define PACKET_CMD_RECOVERYPARA	0xF3
#define PACKET_CMD_TRESULT		0xF4
#define PACKET_CMD_DRESULT		0xF5
#define PACKET_CMD_GET		0xFA
#define PACKET_CMD_SET		0xFD
#define PACKET_CMD_SELECT	0xFB
#define PACKET_CMD_START	0xFC
#define PACKET_CMD_LIGHTON	0xFE
#define PACKET_CMD_LIGHTOFF	0xFF
#define PACKET_CMD_MODETEST	0x42

typedef struct
{  
	unsigned char XBR_VERSION;
	unsigned int XBR_TH;
	unsigned int XBR_LIGHT_TH;
	unsigned int XBR_DELAY_NUM;
	unsigned char XBR_LIGHT_AD;
	unsigned int XBR_AVERAGE;
	unsigned int XBR_SUM0;
	unsigned int XBR_SUM2;
	unsigned int XBR_ID;
	unsigned char XBR_STATUS;
	unsigned char XBR_CHECKSUM; 
	
}XBR_PARA;

extern unsigned char XBR_WR;//д���ݳɹ���־��д����ǰ���
extern XBR_PARA  Xbr_Para;

//=============================================================================
//�ļ����ƣ�void MODE_XBR_Send(unsigned char Cmd)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void MODE_XBR_Send(unsigned char Cmd);

//=============================================================================
//�ļ����ƣ�void MODE_XBR201_Poll(void)
//���ܸ�Ҫ����
//����˵������
//�������أ���
//����    �����Ի�
//��ϵ��ʽ: Steven.Hu ���ڣ�2020��3��23�� 738275730@qq.com
//=============================================================================

void MODE_XBR_Poll(void);




#endif /* MODE_XBR_H */

