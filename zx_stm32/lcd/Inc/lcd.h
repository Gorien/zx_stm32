/*
 *
 *	Author: Beloussov Yegor
 *	Created on: january 2018
 *
 *	The main interface header file of the program for initializing and
 *	displaying information on the LCD. The display is connected to the
 *	module FSMC.
 *
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "stm32f4xx_hal.h"

#define LCD_reg (*((volatile uint16_t*)0x60000000))
#define LCD_data (*((volatile uint16_t*)0x60020000))

extern uint8_t screen_IRQ;

/*LCD цвета*/
#define Green          0x03E0
#define Red            0x7800
#define Blue           0x000F
#define Black          0x0000
#define White          0x7BEF
#define Magenta        0xF81F
#define Blue2          0x07FF
#define Yellow         0xFFE0

extern uint16_t border;
extern uint16_t color [8];
extern uint16_t const byte_color [256][128][8];


void Delay(uint32_t nCount);

void LCD_WriteReg(uint16_t LCD_Reg,uint16_t LCD_RegValue);
uint16_t LCD_ReadReg(uint8_t LCD_Reg);
void LCD_WriteCommand(uint16_t LCD_RegValue);
void LCD_WriteRAM(uint16_t RGB_Code);
void LCD_WriteRAM_Prepare(void);

void LCD_Initializtion(void);
void LCD_Set_Scr(void);
void LCD_Clear_Window(uint16_t Color);
void LCD_Clear(uint16_t Color);
void LCD_SetCursor(uint16_t x, uint16_t y);

void init_screen(void);
void TIM6_DAC_IRQHandler(void);

#endif /* INC_LCD_H_ */
