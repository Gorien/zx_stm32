/*
 * zx.c
 *
 *  Created on: 24 џэт. 2018 у.
 *      Author: Beloussov
 */
#include "stm32f4xx_hal.h"
#include "z80.h"
#include "lcd.h"
#include "dma.h"


	uint8_t m_c;
	uint16_t pi_x_count=0;
	uint16_t pi_y_count=0;
	uint16_t pix=0;
	uint16_t buf[100];

void zx_run(void)
{
	LCD_Init();
	LCD_Clear(Green);

	uint16_t count;
	for(count=0; count<16384; count++)
	{
		memory[count]=ROM[count];
	}

	z80_reset();

	LCD_SetCursor(31, 23);



	while (1)
	{
		m_c = z80_run();

		uint8_t s_c;

		//for (s_c=0; s_c<(m_c*2); s_c++)
			for (s_c=0; s_c<(m_c); s_c++)
		{
			if ((pi_x_count<256)&&(pi_y_count<192))
			{

				if((memory[(pix>>3)+16384])&(128>>(pix&7)))
				{
					//LCD_Write(Black);
					buf[s_c]=Black;
				}
				else
				{
					//LCD_Write(White);
					buf[s_c]=White;
				}

				pix++;
			}
			else
			{
				//LCD_Write(White);
				buf[s_c]=Red;
			}


			pi_x_count++;
			if (pi_x_count==320)
			{
				pi_x_count=0;
				pi_y_count++;
				if (pi_y_count==240)
				{
					pi_y_count=0;
					pix=0;
					HAL_GPIO_TogglePin(green_LED_GPIO_Port, green_LED_Pin);
				}
			}




		}

		HAL_DMA_Abort(&hdma_memtomem_dma2_stream0),
		HAL_DMA_Start(&hdma_memtomem_dma2_stream0, (uint32_t)&buf, (uint32_t)&LCD_data, (uint32_t)s_c);


	}
}
