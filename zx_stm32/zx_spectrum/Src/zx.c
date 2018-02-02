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
#include "tim.h"

	uint8_t m_c;
	uint16_t pi_x_count=0;
	uint16_t pi_y_count=0;
	uint16_t pix=0;
	uint16_t buf[100];
	uint16_t addr;



	uint16_t pix_count=0;
	uint8_t screen_task=0;
	uint16_t scr_task_count=256;
	uint16_t scr_line_count=192;

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

	//HAL_TIM_Base_Start(&htim10);
	//HAL_TIM_OC_Start_IT(&htim10, TIM_CHANNEL_1);



	while (1)
	{

		m_c = z80_run();

		uint8_t s_c;
		TIM10->CCR1+=m_c;

		//for (s_c=0; s_c<(m_c*2); s_c++)
		for (s_c=0; s_c<(m_c); s_c++)
		{
			switch (screen_task)
			{
			case (0):

					addr=(pix>>3)+16384;
					if((memory[((addr&0xF81F)|((addr&0xE0)<<3)|((addr&0x700)>>3))])&(128>>(pix&7)))
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

					scr_task_count--;
					if (!scr_task_count)
					{
						screen_task=1;
						scr_task_count=64;
					}
					break;

			case (1):
					buf[s_c]=Red;

					scr_task_count--;
					if (!scr_task_count)
					{
						screen_task=0;
						scr_task_count=256;
						scr_line_count--;
						if (!scr_line_count)
						{
							screen_task=2;
							scr_task_count=320;
							scr_line_count=48;
						}
					}
					break;

			case (2):
					buf[s_c]=Red;
					scr_task_count--;
					if (!scr_task_count)
					{
						scr_task_count=320;
						scr_line_count--;
						if (!scr_line_count)
						{
							screen_task=0;
							pix=0;
							scr_task_count=256;
							scr_line_count=192;
							HAL_GPIO_TogglePin(green_LED_GPIO_Port, green_LED_Pin);
						}
					}

					break;



			default:
				break;
			}
		}

		/*for (s_c=0; s_c<(m_c*2); s_c++)
		//for (s_c=0; s_c<(m_c); s_c++)
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
				buf[s_c]=White;
			}


			pi_x_count++;
			if (pi_x_count==320)
			{
				pi_x_count=0;
				pi_y_count++;
				screen_IRQ=0;
				if (pi_y_count==240)
				{
					pi_y_count=0;
					pix=0;
					HAL_GPIO_TogglePin(green_LED_GPIO_Port, green_LED_Pin);
					screen_IRQ=1;
				}
			}




		}*/

		HAL_DMA_Abort(&hdma_memtomem_dma2_stream0),
		HAL_DMA_Start(&hdma_memtomem_dma2_stream0, (uint32_t)&buf, (uint32_t)&LCD_data, (uint32_t)s_c);



	}
}


void zx(void)
{
	m_c = z80_run();

	uint8_t s_c;
	TIM10->CCR1+=m_c;

	//for (s_c=0; s_c<(m_c*2); s_c++)
	for (s_c=0; s_c<(m_c); s_c++)
	{
		switch (screen_task)
		{
		case (0):
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

				scr_task_count--;
				if (!scr_task_count)
				{
					screen_task=1;
					scr_task_count=64;
				}
				break;

		case (1):
				buf[s_c]=Red;

				scr_task_count--;
				if (!scr_task_count)
				{
					screen_task=0;
					scr_task_count=256;
					scr_line_count--;
					if (!scr_line_count)
					{
						screen_task=2;
						scr_task_count=320;
						scr_line_count=48;
					}
				}
				break;

		case (2):
				buf[s_c]=Red;
				scr_task_count--;
				if (!scr_task_count)
				{
					scr_task_count=320;
					scr_line_count--;
					if (!scr_line_count)
					{
						screen_task=0;
						pix=0;
						scr_task_count=256;
						scr_line_count=192;
						HAL_GPIO_TogglePin(green_LED_GPIO_Port, green_LED_Pin);
					}
				}

				break;



		default:
			break;
		}
	}

	/*for (s_c=0; s_c<(m_c*2); s_c++)
	//for (s_c=0; s_c<(m_c); s_c++)
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
			buf[s_c]=White;
		}


		pi_x_count++;
		if (pi_x_count==320)
		{
			pi_x_count=0;
			pi_y_count++;
			screen_IRQ=0;
			if (pi_y_count==240)
			{
				pi_y_count=0;
				pix=0;
				HAL_GPIO_TogglePin(green_LED_GPIO_Port, green_LED_Pin);
				screen_IRQ=1;
			}
		}




	}*/

	HAL_DMA_Abort(&hdma_memtomem_dma2_stream0),
	HAL_DMA_Start(&hdma_memtomem_dma2_stream0, (uint32_t)&buf, (uint32_t)&LCD_data, (uint32_t)s_c);
}
