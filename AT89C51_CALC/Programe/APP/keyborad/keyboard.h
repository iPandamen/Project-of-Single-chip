/*******************************************
*	@file 		keyborad.h
*	@author 	Panda	
*	@version	V0.0.1
*	@date		2019.12
*	@brief		matrix keyboard driver header files
********************************************/

#ifndef _KEYBOARD_H
#define _KEYBOARD_H


#include "main.h"
#include "string.h"

#ifndef uchar
	#define uchar unsigned char 
#endif /* uchar */
	
#ifndef uint	
	#define uint unsigned int 
#endif /* uint */

#define KEYBOARD_PORT P1
	
#define KEY_0_VALUE "0"
#define KEY_1_VALUE "1"
#define KEY_2_VALUE "2"
#define KEY_3_VALUE "3"
#define KEY_4_VALUE "4"
#define KEY_5_VALUE "5"
#define KEY_6_VALUE "6"
#define KEY_7_VALUE "7"
#define KEY_8_VALUE "8"
#define KEY_9_VALUE "9"
	
#define KEY_CLEAR_VALUE "clear"
#define KEY_CALC_VALUE 	"="

#define KEY_PLUS_VALUE 	"+"
#define KEY_MINUS_VALUE "-"
#define KEY_MULTI_VALUE "*"
#define KEY_SQRT_VALUE 	"sqrt"
#define KEY_LOG10_VALUE "log10"
#define KEY_SIN_VALUE 	"sin"
#define KEY_COS_VALUE 	"cos"
#define KEY_TAN_VALUE 	"tan"
	
	
	
typedef enum 
{
	KEY_7 = 0x11,
	KEY_8 = 0x12,
	KEY_9 = 0x14,
	KEY_PLUS = 0x18,
	KEY_LOG10 = 0x15,
	KEY_4 = 0x21,
	KEY_5 = 0x22,
	KEY_6 = 0x24,
	KEY_MINUS = 0x28,
	KEY_SIN = 0x25,
	KEY_1 = 0x41,
	KEY_2 = 0x42,
	KEY_3 = 0x44,
	KEY_MULTI = 0x48,
	KEY_COS = 0x45,
	KEY_CLEAR = 0x81,
	KEY_0 = 0x82,
	KEY_CALC = 0x84,
	KEY_SQRT = 0x88,
	KEY_TAN = 0x85
}KEY_FLAG;

uchar key_scan(void);
uchar* key_getvalue(void);

#endif /* _KEYBOARD_H */

/******************************** END OF FILE **********************************/

