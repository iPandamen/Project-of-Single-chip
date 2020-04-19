/*******************************************
*	@file 		lcd1602.c
*	@author 	Panda	
*	@version	V0.0.1
*	@date		2019.12
*	@brief		lcd1602 driver source files
********************************************/

#include "lcd1602.h"


/*******************************************
*	@brief	lcd1602写数据/ 写指令
*	@param	w_data:数据
*	@param 	data_type
*		@arg	1: 写数据
*		@arg	0: 写指令
*	@retval	None
********************************************/
void lcd1602_write(uchar w_data,uchar data_type)
{	
	lcd1602_E = 0; 			// 使能
	lcd1602_RS = data_type;	// 选择 写入数据/指令
	lcd1602_RW = 0;			// 选择写入
	
	lcd1602_data = w_data;	 // 
	lcd1602_delay1ms(1);
	
	lcd1602_E = 1;			// 写入时序
	lcd1602_delay1ms(5);	// 保持时间	
	lcd1602_E = 0;	
}

/*******************************************
*	@brief	lcd1602写数据/ 写指令
*	@param	r_data: 读取的数据
*	@param 	data_type：
*		@arg	1：读数据
*		@arg	0：读状态
*	@retval	None
********************************************/
//void lcd1602_read(uchar* r_data,uchar data_type)
//{
//	uchar i = 0;
//	
//	lcd1602_E = 0;
//	lcd1602_RS = data_type;
//	lcd1602_RW = 1;
//	
//	lcd1602_E = 1;
//	
//	*r_data = lcd1602_data;
//	lcd1602_delay1ms(1);
//	
//	lcd1602_E = 0;
//}


///*******************************************
//*	@brief	lcd1602 忙状态检测
//*	@param	None
//*	@retval	1: 忙碌中
//*			0：空闲
//********************************************/
//uchar lcd1602_get_busy(void)
//{
//	uchar status=0;
//	lcd1602_read(&status,LCD1602_CMD);
//	if(status&0x80)
//		return 1;
//	else 
//		return 0;
//}

/*******************************************
*	@brief	lcd1602 set cursor position
*	@param	x: x 坐标
*			y: y 坐标
*	@retval	None
********************************************/
void lcd1602_set_pos(uchar x,uchar y)
{
	lcd1602_write(0x80+(0x40*y)+x,LCD1602_CMD); //0xC0
}

/*******************************************
*	@brief	lcd1602 clear 
*	@param	None
*	@retval	None
********************************************/
void lcd1602_clear(void)
{
	lcd1602_write(0x01,LCD1602_CMD);
}

/*******************************************
*	@brief	lcd1602 show num
*	@param	num: 显示的整数
*	@retval	None
********************************************/
void lcd1602_show_num(uchar x,uchar y,uint num)
{
	uchar i=0;
	uint temp=num;
	while(temp != 0)
	{
		temp /= 10;
		i++;
	}
	while(num != 0)
	{
		lcd1602_set_pos(x+i,y);
		lcd1602_write('0'+num%10,LCD1602_DATA);
		num /= 10;
		i--;
	}
}	


/*******************************************
*	@brief	lcd1602 show string
*	@param	x: x 坐标
*			y: y 坐标
*			str: 显示字符串的地址
*			mode: 
*		@arg  1: 居中显示
*			  0: 
*	@retval	None
********************************************/
void lcd1602_show_string(uchar x,uchar y,const char* str,uchar mode)
{
	uchar i=0;
	if(mode == 1)
	{
		lcd1602_set_pos((16-strlen(str))/2,y);
	}
	else
	{
		lcd1602_set_pos(x,y);
	}
	for(i=0;i<strlen(str);i++)
	{
		lcd1602_write(*(str+i),LCD1602_DATA);
	}
}	

/*******************************************
*	@brief	lcd1602 初始化
*	@param	None
*	@retval	None
********************************************/
void lcd1602_init(void)
{
	lcd1602_write(0x38,LCD1602_CMD);	// 功能设置	 8位数据接口 16*2 两行显示 5*7点阵字符
	
	lcd1602_write(0x0C,LCD1602_CMD);	//开显示  光标不显示 不闪烁
	
//	lcd1602_write(0x0F,LCD1602_CMD);	//开显示 显示光标  
	
	lcd1602_write(0x06,LCD1602_CMD);	//数据读写操作 后地址指针自动增1  画面不动
	
	lcd1602_write(0x01,LCD1602_CMD);	//清屏
	
	lcd1602_write(0x80,LCD1602_CMD);	//初始化数据地址指针
}



/******************************** END OF FILE **********************************/


