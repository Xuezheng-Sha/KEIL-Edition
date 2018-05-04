#include "delay.h"

void Delay_Init(void)
{

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//STM32F10x单片机定时器的BUG，需要先启动一次，然后清除标志，以跳过这个BUG
	TIM3->CR1 = 1;
	while(!(TIM3->SR & 1));							//等待产生中断事件
	TIM3->SR &= ~(1UL << 0);						//清除标志
	TIM3->CR1 = 0;
	
	TIM3->CR1 |= 1UL << 3;							//单脉冲模式
	
	TIM3->EGR |= 1;									//更新生成
	
	TIM3->DIER = 0;									//禁止所有中断
	
	TIM3->CR1 &= (unsigned short)~TIM_CR1_CEN;		//停止计时
	
	TIM3->PSC = 71;

}


void delay_ms(u16 nms)
{
	u16 i=0;
  for(i=0;i<nms;i++)
  {
    vTaskDelay(1);
  }
} 

/*
************************************************************
*	函数名称：	DelayUs
*
*	函数功能：	微秒级延时
*
*	入口参数：	us：延时的时长
*
*	返回参数：	无
*
*	说明：		此时钟(21MHz)最大延时798915us
************************************************************
*/
void DelayUs(unsigned short us)
{

	TIM3->ARR = us;
	
	TIM3->PSC = 71;									//timer4为72MHz，设置为71+1分频，1MHz，1us计数一次
	
	TIM3->CR1 |= (unsigned short)TIM_CR1_CEN;		//开始计时
	
	while(!(TIM3->SR & 1));							//等待产生中断事件
	
	TIM3->SR &= ~(1UL << 0);						//清除标志

}

/*
************************************************************
*	函数名称：	DelayXms
*
*	函数功能：	毫秒级延时
*
*	入口参数：	ms：延时的时长
*
*	返回参数：	无
*
*	说明：		
************************************************************
*/
void DelayXms(unsigned short ms)
{

	while(ms--)
		DelayUs(1000);

}

/*
************************************************************
*	函数名称：	DelayMs
*
*	函数功能：	微秒级长延时
*
*	入口参数：	ms：延时的时长
*
*	返回参数：	无
*
*	说明：		多次调用DelayXms，做到长延时
************************************************************
*/
void DelayMs(unsigned short ms)
{

	unsigned char repeat = 0;
	unsigned short remain = 0;
	
	repeat = ms / 500;
	remain = ms % 500;
	
	while(repeat)
	{
		DelayXms(500);
		repeat--;
	}
	
	if(remain)
		DelayXms(remain);

}
