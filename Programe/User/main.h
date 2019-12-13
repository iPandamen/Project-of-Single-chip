
/*******************************************
*	@file 		main.h
*	@author 	Panda	
*	@version	V0.0.1
*	@date		2019.12
*	@brief		main header files
********************************************/

#ifndef _MAIN_H
#define _MAIN_H


#include "reg51.h"

#include "stdio.h"
#include "math.h"

#include "lcd1602.h"
#include "keyboard.h"


#ifndef uchar
	#define uchar unsigned char 
#endif /* uchar */
	
#ifndef uint	
	#define uint unsigned int 
#endif /* uint */

// lcd1602 引脚

sbit lcd1602_RS = P2^0; // RS 引脚  1:读/写数据 0：读状态/写指令
sbit lcd1602_RW = P2^1;	// RW 引脚	1:读	0: 写 
sbit lcd1602_E = P2^2;	// E 引脚	使能信号

#define lcd1602_data P0
	
#define LCD1602_DATA 1
#define LCD1602_CMD  0

	
// keyboard
	
sbit C4 = P2^7;	
	
	
void delay_ms(uint nms);
	
#endif /* _MAIN_H */

/******************************** END OF FILE **********************************/
