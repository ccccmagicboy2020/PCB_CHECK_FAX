//=================(C) COPYRIGHT  ������XXXXX�������޹�˾ =====================
//��˾���ƣ�������
//�ļ����ƣ�DataType.c
//���ܸ�Ҫ��DataType����ͷ�ļ�
//ʵ��ƽ̨��
//�Ĵ����汾 ��V1.0.0
//����       �����Ի�
//�ʼ���QQ   ��738275730@qq.com
//�޸�ʱ��   ��2017-12-1
//=============================================================================


#ifndef DATATYPE_H_
#define DATATYPE_H_

#ifndef BOOL
#define BOOL u8
#endif

#ifndef TRUE
#define TRUE (BOOL)SET
#endif

#ifndef FALSE
#define FALSE (BOOL)RESET
#endif

//typedef enum _BOOL { FALSE = 0, TRUE } BOOL;

#define INFINITE 0xFFFFFFFF

#define MAX_( a, b) ( (a) > (b) ? (a) : (b))
#define MIN_( a, b) ( (a) < (b) ? (a) : (b))



#endif
