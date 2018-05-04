#ifndef __KEY_H
#define __KEY_H	 
#include "stm32f10x.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK miniSTM32开发板
//按键驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/3
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 


//#define KEY0 PCin(5)   	
//#define KEY1 PAin(15)	 
//#define WK_UP  PAin(0)	 
 

//#define KEY0    GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)//读取按键0
//#define KEY1    GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_11)//读取按键1
//#define KEY2    GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12)//读取按键2
//#define WK_UP   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2)//读取确认建
 

#define KEY0_PRES	1		//KEY0  
#define KEY1_PRES	2		//KEY1 
#define KEY2_PRES	3		//KEY1 
#define WKUP_PRES	4		//WK_UP 


#define KEY0			GPIO_Pin_13

#define KEY1			GPIO_Pin_11

#define KEY2			GPIO_Pin_12

#define KEY3			GPIO_Pin_2


/*******************************************
			按键按下与弹起
*******************************************/
#define KEYDOWN			1
#define KEYUP			0

#define KEY0DOWN		0

#define KEY1DOWN		3

#define KEY2DOWN		6

#define KEY3DOWN		9

#define KEYNONE			255



void KEY_Init(void);//IO初始化

_Bool KeyScan(GPIO_TypeDef* GPIOX, unsigned int NUM);
unsigned char Keyboard(void);
/*********************************************************/
u8 KEY_Scan(u8 mode);  	//按键扫描函数	
void KEY_red(void);
#endif



