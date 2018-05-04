#ifndef __LED_H
#define __LED_H	 
#include "stm32f10x_rcc.h"			  
////////////////////////////////////////////////////////////////////////////////// 

typedef struct
{

	_Bool Led1Sta;
	_Bool Led2Sta;
	_Bool Led3Sta;
	_Bool Led4Sta;

} LED_STATUS;

extern LED_STATUS led_status;


typedef enum
{

	LED_OFF = 0,
	LED_ON

} LED_ENUM;

void LED_Init(void);//≥ı ºªØ

void Led1_Set(LED_ENUM status);

void Led2_Set(LED_ENUM status);

void Led3_Set(LED_ENUM status);

void Led4_Set(LED_ENUM status);		


#endif
