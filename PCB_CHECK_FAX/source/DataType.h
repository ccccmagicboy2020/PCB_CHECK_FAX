//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：DataType.c
//功能概要：DataType驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
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
