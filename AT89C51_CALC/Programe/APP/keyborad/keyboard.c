/*******************************************
*	@file 		keyborad.h
*	@author 	Panda	
*	@version	V0.0.1
*	@date		2019.12
*	@brief		matrix keyboard driver header files
********************************************/

#include "keyboard.h"


/******************************************
*	@brief 		按键扫描
*	@param		None
*	@retval		返回键的位置
*******************************************/
uchar key_scan(void)
{
	uchar temp=0;
	uchar t=0;
	
	KEYBOARD_PORT = 0xF0;
	C4 = 0;
	if(KEYBOARD_PORT != 0xF0)
	{
		delay_ms(10);  // 防止抖动
		if(KEYBOARD_PORT != 0xF0)
		{
			temp = (~KEYBOARD_PORT)&0xF0;				
			/*
			1111 0000
			1110 0000
			0001 1111 & 1111 0000
			0001 0000
			*/
			// 获取列位置
			KEYBOARD_PORT = 0x0F;
			C4 = 1;
			if(KEYBOARD_PORT == 0x0F && C4 == 0)
			{
				temp |= 0x05;
			}
			else
			{		
				temp |= (~KEYBOARD_PORT)&0x0F;
				/*
				0000 1110
				1111 0001 & 0000 1111
				0000 0001
				*/
			}
			while(t<50 && (KEYBOARD_PORT != 0x0F || C4 != 1))  // 等待按键松开
			{
				delay_ms(100);
				t++;
			}
			return temp;
		}
	}
	return 0;
}

/******************************************
*	@brief 		获取按键的值
*	@param		None
*	@retval		返回键的值
*******************************************/
uchar* key_getvalue(void)
{
	uchar temp = 0;
	
	temp = key_scan();
	
	switch(temp)
	{
		case KEY_0:
			return KEY_0_VALUE;
			break;
		case KEY_1:
			return KEY_1_VALUE;
			break;
		case KEY_2:
			return KEY_2_VALUE;
			break;
		case KEY_3:
			return KEY_3_VALUE;
			break;
		case KEY_4:
			return KEY_4_VALUE;
			break;
		case KEY_5:
			return KEY_5_VALUE;
			break;
		case KEY_6:
			return KEY_6_VALUE;
			break;
		case KEY_7:
			return KEY_7_VALUE;
			break;
		case KEY_8:
			return KEY_8_VALUE;
			break;
		case KEY_9:
			return KEY_9_VALUE;
			break;
		case KEY_CLEAR:
			return KEY_CLEAR_VALUE;
			break;
		case KEY_CALC:
			return KEY_CALC_VALUE;
			break;
		case KEY_PLUS:
			return KEY_PLUS_VALUE;
			break;
		case KEY_MINUS:
			return KEY_MINUS_VALUE;
			break;
		case KEY_MULTI:
			return KEY_MULTI_VALUE;
			break;
		case KEY_SQRT:
			return KEY_SQRT_VALUE;
			break;
		case KEY_LOG10:
			return KEY_LOG10_VALUE;
			break;
		case KEY_SIN:
			return KEY_SIN_VALUE;
			break;
		case KEY_COS:
			return KEY_COS_VALUE;
			break;
		case KEY_TAN:
			return KEY_TAN_VALUE;
			break;
		default:
			// no input
			return 0;
			break;
	}
}

/******************************** END OF FILE **********************************/


