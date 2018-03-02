/*
 *
 *	Author: Beloussov Yegor
 *	Created on: january 2018
 *
 *	The program emulating the work ZX Spectrum
 *
 */


#include "stm32f4xx_hal.h"
#include "z80.h"
#include "lcd.h"
#include "dma.h"
#include "tim.h"
#include "ay_3_891x.h"
#include "scr_table.c"

void zx_run(void)
{


	LCD_Init();
	LCD_Clear(Black);
	LCD_Set_Region();
	LCD_SetCursor(23, 31);
	ay_3_891x_Init();
	z80_reset();

	uint16_t count; //copy ROM
	for(count=0; count<16384; count++)
	{
		memory[count]=ROM[count];
	}

	DMA2_Stream0->PAR=(uint32_t)&border;
	DMA2_Stream0->M0AR=(uint32_t)&LCD_data;
	DMA2_Stream0->NDTR=0x0008;
	//DMA2_Stream0->CR|=DMA_SxCR_EN;

	//DMA2_Stream1->PAR=(uint32_t)&screen_data[0][0][0];
	DMA2_Stream1->M0AR=(uint32_t)&LCD_data;
	DMA2_Stream1->NDTR=0x0008;
	//DMA2_Stream1->CR|=DMA_SxCR_EN;

	HAL_SuspendTick();//Disable SysTick Interrupt

	HAL_TIM_Base_Start(&htim11);

	HAL_TIM_OC_Start_IT(&htim10, TIM_CHANNEL_1);
	HAL_TIM_Base_Start(&htim10);

	while (1)
	{
		z80_screen();
	}
}
