#ifndef _OLED_H
#define _OLED_H
#include "stm32f10x_rcc.h"

#define   byte        u8
#define   word        u16
/*-----------------OLED¶Ë¿Ú¶¨Òå----------------*/					   
/*
#define LCD_SCL_CLR()	GPIO_ResetBits(GPIOB,GPIO_Pin_9)
#define LCD_SCL_SET()	GPIO_SetBits(GPIOB,GPIO_Pin_9)

#define LCD_SDA_CLR()	GPIO_ResetBits(GPIOB,GPIO_Pin_8)
#define LCD_SDA_SET()	GPIO_SetBits(GPIOB,GPIO_Pin_8)

#define LCD_RST_CLR()	GPIO_ResetBits(GPIOB,GPIO_Pin_7)
#define LCD_RST_SET()	GPIO_SetBits(GPIOB,GPIO_Pin_7)

#define LCD_DC_CLR()	GPIO_ResetBits(GPIOB,GPIO_Pin_6)
#define LCD_DC_SET()	GPIO_SetBits(GPIOB,GPIO_Pin_6)
*/
#define LCD_SCL_CLR()	GPIO_ResetBits(GPIOC,GPIO_Pin_2)
#define LCD_SCL_SET()	GPIO_SetBits(GPIOC,GPIO_Pin_2)

#define LCD_SDA_CLR()	GPIO_ResetBits(GPIOC,GPIO_Pin_1)
#define LCD_SDA_SET()	GPIO_SetBits(GPIOC,GPIO_Pin_1)

#define LCD_RST_CLR()	GPIO_ResetBits(GPIOC,GPIO_Pin_0)
#define LCD_RST_SET()	GPIO_SetBits(GPIOC,GPIO_Pin_0)

#define LCD_DC_CLR()	GPIO_ResetBits(GPIOB,GPIO_Pin_9)
#define LCD_DC_SET()	GPIO_SetBits(GPIOB,GPIO_Pin_9)



extern const unsigned char bmp_rssi[6][72];
extern void LCD_WrDat(unsigned char data);
extern void LCD_Init(void);
extern void LCD_CLS(void);
extern void LCD_CLS_y(char y);
extern void LCD_CLS_line_area(u8 start_x,u8 start_y,u8 width);
extern void LCD_P6x8Str(u8 x,u8 y,u8 *ch,const u8 *F6x8);
extern void LCD_P16x16Str(u8 x,u8 y,u8 *ch,const u8 *F16x16_Idx,const u8 *F16x16);
extern void LCD_Set_Pos(unsigned char x, unsigned char y);
extern void LCD_PutPixel(u8 x,u8 y);
extern void LCD_Rectangle(u8 x1,u8 y1,u8 x2,u8 y2,u8 gif);
extern void LCD_Fill(u8 dat);
extern void Dis_num(u8 x,u8 y,int asc);
extern void LCD_PrintFloat(unsigned char x,unsigned char y,float num);
extern void Draw_BMP(byte x0,byte y0,byte x1,byte y1,byte bmp[]);
extern void Draw_LQLogo(void);
extern void Draw_LibLogo(void);
extern void plotC(unsigned int x,unsigned int y,unsigned int xc,unsigned int yc); 
extern void GUIcircle(byte xc,byte yc,byte r); 
extern void gui_circle(byte x0 , byte y0 , byte r);
extern void oled_showPicture(u8 x,u8 y,const u8 *p,u8 p_w,u8 p_h);
extern void LCD_PXXxYYCHtoBMP(unsigned char xx,unsigned char yy,
unsigned char FXXxYY[],unsigned char x,unsigned char y,
unsigned char N,unsigned char p);
extern	void gundong(void);
extern  void AT24C02(void);
extern	void OLED_Interface(u8 num);
extern  void OLED_function(u8  num);
extern  void VIEW_CCD_dongtai(u8 x[]);//
extern  void OLED_write_8X16String(unsigned char x,unsigned char y, char ch[],unsigned char z);
extern  void VIEW_DCXH_dongtai(void);
extern  void parameter(void);
extern  void OLED_Print(byte x, byte y, byte ch[]);
extern  void LCD_P14x16Str(byte x,byte y,byte ch[]);
extern  void LCD_P8x16Str(byte x,byte y,byte ch[]);
extern  void OLED_P6x8Str(byte x,byte y,byte ch[]);
extern  void LCD_Print(byte x, byte y, byte ch[]);
extern  void Dis_float(u8 x,u8 y,double real);
#endif








