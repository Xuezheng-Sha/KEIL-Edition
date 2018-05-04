#include "key.h"
#include "delay.h"
#include "OLED.h"
#include "stm32f10x.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK Mini STM32开发板
//按键输入 驱动代码		   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2014/3/06
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									   
//////////////////////////////////////////////////////////////////////////////////	 	    
//按键初始化函数 
void KEY_Init(void)
{
        GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);	//打开GPIOC、GPIOD的时钟
        //GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//关闭jtag，使能SWD，可以用SWD模式调试
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;//初始化Pin11、12、13
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//承载的最大频率
	GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIOC
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIOD
} 
/*
************************************************************
*	函数名称：	KeyScan
*
*	函数功能：	按键电平扫描
*
*	入口参数：	GPIOX：需要扫描的GPIO组	NUM：该GPIO组内的编号
*
*	返回参数：	IO电平状态
*
*	说明：		
************************************************************
*/
_Bool KeyScan(GPIO_TypeDef* GPIOX, unsigned int NUM)
{
	
	if(GPIOX == GPIOC)
	{
		if(!GPIO_ReadInputDataBit(GPIOC, NUM))	//按下  为低
		{
			return KEYDOWN;
		}
		else									//弹起  为高
		{
			return KEYUP;
		}
	}
	else if(GPIOX == GPIOD)
	{
		if(!GPIO_ReadInputDataBit(GPIOD, NUM))	//按下  为低
		{
			return KEYDOWN;
		}
		else									//弹起  为高
		{
			return KEYUP;
		}
	}
	
	return KEYUP;								//默认返回按键释放
	
}

/*
************************************************************
*	函数名称：	Keyboard
*
*	函数功能：	按键功能检测
*
*	入口参数：	
*
*	返回参数：	IO电平状态
*
*	说明：		
************************************************************
*/
unsigned char Keyboard(void)
{
	
	if(KeyScan(GPIOC, KEY0) == KEYDOWN)
	{
		while(KeyScan(GPIOC, KEY0) != KEYUP);		//等待释放
		return KEY0DOWN;
	}
	
	if(KeyScan(GPIOC, KEY1) == KEYDOWN)
	{
		while(KeyScan(GPIOC, KEY1) != KEYUP);		//等待释放
		return KEY1DOWN;
	}
	
	if(KeyScan(GPIOC, KEY2) == KEYDOWN)
	{
		while(KeyScan(GPIOC, KEY2) != KEYUP);		//等待释放
		return KEY2DOWN;
	}
	
	if(KeyScan(GPIOD, KEY3) == KEYDOWN)
	{
		while(KeyScan(GPIOD, KEY3) != KEYUP);		//等待释放
		return KEY3DOWN;
	}
	
	return KEYNONE;
	
}
/*
************************************************************
*	函数名称：	Keyboard
*
*	函数功能：	按键菜单控制
*
*	入口参数：	
*
*	返回参数：	显示界面变化
*
*	说明：		
************************************************************
*/
u8 menu=0,menu1=0;
extern bool GO_1;
void KEY_red(void)
{
 switch(Keyboard())
  {
  case KEY0DOWN:{
       GO_1=false;      
       menu-=1;
       if(menu<1) menu=1;
       else if(menu>9) menu=10;
       OLED_Interface(menu);

      }break;
   case KEY1DOWN:{
            GO_1=false;
            menu+=1;
            if(menu>10)  menu=1;
            else if(menu<1) menu=10;
            OLED_Interface(menu);
        }break;
    case KEY2DOWN:{
                 GO_1=true;
	      }break;
case KEY3DOWN:{
  
                    
     }break;			
  default:
   break;	
 }
}


