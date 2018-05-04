#ifndef __Executable_H
#define __Executable_H
/* Private macro -------------------------------------------------------------*/
//拨码开关控制
#define BUTTON1_READ()      GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_8)
#define BUTTON2_READ()      GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_9)
#define BUTTON3_READ()      GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_10)
#define BUTTON4_READ()      GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_11)
#define BUTTON5_READ()      GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_12)
#define BUTTON6_READ()      GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_13)
#define BUTTON7_READ()      GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_14)
#define BUTTON8_READ()      GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_15)

//继电器控制
#define Relay1_ON()         GPIO_SetBits(GPIOC,GPIO_Pin_0)
#define Relay1_OFF()        GPIO_ResetBits(GPIOC,GPIO_Pin_0)

#define Relay2_ON()         GPIO_SetBits(GPIOC,GPIO_Pin_1)
#define Relay2_OFF()        GPIO_ResetBits(GPIOC,GPIO_Pin_1)

#define Relay3_ON()         GPIO_SetBits(GPIOC,GPIO_Pin_2)
#define Relay3_OFF()        GPIO_ResetBits(GPIOC,GPIO_Pin_2)

#define Relay4_ON()         GPIO_SetBits(GPIOC,GPIO_Pin_3)
#define Relay4_OFF()        GPIO_ResetBits(GPIOC,GPIO_Pin_3)

/* Private function prototypes -----------------------------------------------*/
void RCC_Config(void);
void LED_Config(void);
void LED_Poll(void);
void Button_Config(void);
void Button_Poll(void);
void Relay_Config(void);
void Relay_Poll(void);
/* Private functions ---------------------------------------------------------*/



#endif

