#ifndef _UNICORN_DRIVE_H_
#define _UNICORN_DRIVE_H_
#include "includes.h"


typedef struct
{

	float voltag;

} LIGHT_INFO;

extern LIGHT_INFO light_info;


void LIGHT_Init(void);

void LIGHT_GetVoltag(void);


#endif

