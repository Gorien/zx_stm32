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

#define LCD_reg *(volatile uint16_t*)0x60000000
#define LCD_data *(volatile uint16_t*)0x60020000

#define Reset_Pin_Active HAL_GPIO_WritePin(reset_LCD_GPIO_Port, reset_LCD_Pin, GPIO_PIN_RESET);
#define Reset_Pin_Idle HAL_GPIO_WritePin(reset_LCD_GPIO_Port, reset_LCD_Pin, GPIO_PIN_SET);

/*LCD цвета*/
#define Green          0x03E0
#define Red            0x7800
#define Blue           0x000F
#define Black          0x0000
#define White          0x7BEF
#define Magenta        0xF81F
#define Blue2          0x07FF
#define Yellow         0xFFE0


void LCD_Init(void);
void LCD_Clear(uint16_t Color);
void LCD_SetCursor(uint16_t x, uint16_t y);
void LCD_Write(uint16_t LCD_RegValue);

#endif /* INC_LCD_H_ */
