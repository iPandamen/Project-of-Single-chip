/*******************************************
*	@file 		lcd1602.h
*	@author 	Panda	
*	@version	V0.0.1
*	@date		2019.12
*	@brief		lcd1602 driver header files
********************************************/

#ifndef _LCD1602_H
#define _LCD1602_H

#include "main.h"

#ifndef uchar
	#define uchar unsigned char 
#endif /* uchar */
	
#ifndef uint	
	#define uint unsigned int 
#endif /* uint */

#define lcd1602_delay1ms delay_ms

void lcd1602_write(uchar w_data,uchar data_type);
	
void lcd1602_read(uchar* r_data,uchar data_type);
	
uchar lcd1602_get_busy(void);

void lcd1602_set_pos(uchar x,uchar y);
	
void lcd1602_show_num(uchar x,uchar y,uint num);
	
void lcd1602_show_float(uchar x,uchar y,float num);
	
void lcd1602_show_string(uchar x,uchar y,const char* str,uchar mode);

void lcd1602_init(void);


#endif  /* _LCD1602_H */

/******************************** END OF FILE **********************************/


