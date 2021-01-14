//=================(C) COPYRIGHT  深圳市XXXXX电子有限公司 =====================
//公司名称：深圳市
//文件名称：Typedef.h
//功能概要：Typedef驱动头文件
//实验平台：
//寄存器版本 ：V1.0.0
//作者       ：胡显辉
//邮件或QQ   ：738275730@qq.com
//修改时间   ：2017-12-1
//=============================================================================

#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdint.h>

typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32; 
typedef const int16_t sc16; 
typedef const int8_t sc8;  

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t   vs8;

typedef __I int32_t vsc32; 
typedef __I int16_t vsc16; 
typedef __I int8_t vsc8;  

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32; 
typedef const uint16_t uc16; 
typedef const uint8_t uc8;  

typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

typedef __I uint32_t vuc32; 
typedef __I uint16_t vuc16; 
typedef __I uint8_t vuc8;  

#if 0
#define      __I        volatile const          /*!< defines 'read only' permissions      */
#define      __O        volatile                  /*!< defines 'write only' permissions     */
#define     __IO        volatile                  /*!< defines 'read / write' permissions   */


//typedef unsigned int  uint32_t;
//typedef unsigned long  u32;
//typedef uint32_t  u32;

/* Exported types ------------------------------------------------------------*/

typedef signed long  s32;
typedef signed short s16;
typedef signed char  s8;
typedef signed long  const sc32;  /* Read Only */
typedef signed short const sc16;  /* Read Only */
typedef signed char  const sc8;   /* Read Only */
typedef volatile signed long  vs32;
typedef volatile signed short vs16;
typedef volatile signed char  vs8;
typedef volatile signed long  const vsc32;  /* Read Only */
typedef volatile signed short const vsc16;  /* Read Only */
typedef volatile signed char  const vsc8;   /* Read Only */
typedef unsigned long  u32;
typedef unsigned short u16;
typedef unsigned char  u8;
typedef unsigned long  const uc32;  /* Read Only */
typedef unsigned short const uc16;  /* Read Only */
typedef unsigned char  const uc8;   /* Read Only */
typedef volatile unsigned long  vu32;
typedef volatile unsigned short vu16;
typedef volatile unsigned char  vu8;
typedef volatile unsigned long  const vuc32;  /* Read Only */
typedef volatile unsigned short const vuc16;  /* Read Only */
typedef volatile unsigned char  const vuc8;   /* Read Only */

/*
类型定义 
typedef int32_t  s32 
typedef int16_t  s16 
typedef int8_t  s8 
typedef const int32_t  sc32 
typedef const int16_t  sc16 
typedef const int8_t  sc8 
typedef __IO int32_t  vs32 
typedef __IO int16_t  vs16 
typedef __IO int8_t  vs8 
typedef __I int32_t  vsc32 
typedef __I int16_t  vsc16 
typedef __I int8_t  vsc8 
typedef uint32_t  u32 
typedef uint16_t  u16 
typedef uint8_t  u8 
typedef const uint32_t  uc32 
typedef const uint16_t  uc16 
typedef const uint8_t  uc8 
typedef __IO uint32_t  vu32 
typedef __IO uint16_t  vu16 
typedef __IO uint8_t  vu8 
typedef __I uint32_t  vuc32 
typedef __I uint16_t  vuc16 
typedef __I uint8_t  vuc8
*/

#endif

/*
#define xdata
#define data
#define code const

#define NOP() __NOP()

#ifndef u8
#define u8  unsigned char
#endif

#ifndef u16
#define u16 unsigned short
#endif

#ifndef u32
#define u32 unsigned long
#endif

#ifndef U8
#define U8  unsigned char
#endif

#ifndef S8
#define S8  char
#endif

#ifndef U16
#define U16 unsigned short
#endif

#ifndef U32
#define U32 unsigned long
#endif
*/

#endif
