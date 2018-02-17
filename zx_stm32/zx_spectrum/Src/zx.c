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
#include "adc.h"


uint16_t count;
uint16_t pi_x_count=0;
uint16_t pi_y_count=0;
uint16_t pix=0;
uint16_t addr;
uint16_t border;
uint16_t pix_count=0;
uint16_t line_count=0;
uint16_t byte_count=0;
uint8_t flash;
uint8_t flash_count;

#include "scr_table.c"
#include "scr_routine.c"




void zx_run(void)
{
	LCD_Init();
	LCD_Clear(Red);

	for(count=0; count<16384; count++)
	{
		memory[count]=ROM[count];
	}

	z80_reset();

	LCD_SetCursor(31, 23);

	ADC1->CR2=0;
	ADC1->CR2|=ADC_CR2_CONT;
	ADC1->CR2|=ADC_CR2_ADON;
	ADC1->CR2|=ADC_CR2_SWSTART;


	//DMA2->LIFCR=~(0);
	DMA2_Stream0->PAR=(uint32_t)&border;
	DMA2_Stream0->M0AR=(uint32_t)&LCD_data;
	DMA2_Stream0->NDTR=0x0008;
	//DMA2_Stream0->CR|=DMA_SxCR_EN;

	//DMA2_Stream1->PAR=(uint32_t)&screen_data[pixel][attribute][0];
	DMA2_Stream1->M0AR=(uint32_t)&LCD_data;
	DMA2_Stream1->NDTR=0x0008;
	//DMA2_Stream1->CR|=DMA_SxCR_EN;

	HAL_SuspendTick();//Disable SysTick Interrupt

	//HAL_TIM_Base_Start_IT(&htim11);
	HAL_TIM_Base_Start(&htim11);

	HAL_TIM_OC_Start_IT(&htim10, TIM_CHANNEL_1);
	HAL_TIM_Base_Start(&htim10);

	while (1)
	{
		while ((TIM11->SR&TIM_SR_UIF)==0)
		{

		}

		(*scr_out[byte_count>>3])(byte_count&0x7);

		TIM11->SR=0;
		byte_count++;
		if (byte_count==9600)
		{
			byte_count=0;
		}
		while ((DMA2->LISR&(DMA_LISR_TCIF0|DMA_LISR_TCIF1))==0)
		{

		}
		DMA2->LIFCR=~(0);
	}
}


void zx(void)
{
	DMA2->LIFCR=~(0);
	(*scr_out[byte_count&0xfff8])(byte_count&0x7);
	byte_count++;
	if (byte_count==9600)
	{
		byte_count=0;
	}
}



/*void zx(void)
{
	HAL_GPIO_TogglePin(green_LED_GPIO_Port, green_LED_Pin);
	DMA2->LIFCR=~(0);
	if (pix_count<7680)
	{
		if(line_count<32)
		{
			DMA2_Stream1->PAR=(uint32_t)&screen_data[memory[((byte_count&0xF81F)|((byte_count&0xE0)<<3)|((byte_count&0x700)>>3))]][(memory[((byte_count&0x1F00)>>3)|(byte_count&0x1F)|0x5800])&0x7f][0];
			//DMA2_Stream1->PAR=(uint32_t)&screen_data[0xff][0x38][0];
			DMA2_Stream1->CR|=DMA_SxCR_EN;
			byte_count++;
		}
		else
		{
			DMA2_Stream0->CR|=DMA_SxCR_EN;

			if(line_count==39)
			{
				line_count=0xffff;
			}
		}
		line_count++;
	}
	else
	{
		if (pix_count==9500)
		{
			INT=1;
		}
		DMA2_Stream0->CR|=DMA_SxCR_EN;
		if(pix_count==9599)
		{
			INT=0;
			pix_count=0xffff;
			byte_count=0x4000;
		}
	}
	pix_count++;
}/*










/*
 		if ((pi_x_count<256)&&(pi_y_count<192))
		{
			addr=(pix>>3)+16384;
			if((memory[((addr&0xF81F)|((addr&0xE0)<<3)|((addr&0x700)>>3))])&(128>>(pix&7)))
			{
				LCD_Write(Black);
			}
			else
			{
				LCD_Write(White);
			}

			pix++;
		}
		else
		{
			LCD_Write(border);
			if((pi_y_count==191)||(pi_y_count==70))
			{
				INT=1;
			}
			else
			{
				INT=0;
			}
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
			}
		}
 */































/*DMA2_Stream0->PAR=(uint32_t)&buf;//��������� �� ������ ������ "������"
DMA2_Stream0->M0AR=(uint32_t)&LCD_data;//��������� �� ����� "����" (� ����� ������ �� �������� ������������ FSMC � �������� ��������� LCD)
DMA2_Stream0->NDTR=0x0008;//������� ��� ����������
//DMA2_Stream0->CR|=DMA_SxCR_EN;//����������

DMA2_Stream1->PAR=(uint32_t)&buf1;//��������� �� ������ ������ "������"
DMA2_Stream1->M0AR=(uint32_t)&LCD_data;//��������� �� ����� "����" (� ����� ������ �� �������� ������������ FSMC � �������� ��������� LCD)
DMA2_Stream1->NDTR=0x0008;//������� ��� ����������
//DMA2_Stream0->CR|=DMA_SxCR_EN;//����������

DMA2_Stream2->PAR=(uint32_t)&buf;//��������� �� ������ ������ "������"
DMA2_Stream2->M0AR=(uint32_t)&LCD_data;//��������� �� ����� "����" (� ����� ������ �� �������� ������������ FSMC � �������� ��������� LCD)
DMA2_Stream2->NDTR=0x0008;//������� ��� ����������
//DMA2_Stream0->CR|=DMA_SxCR_EN;//����������

DMA2_Stream3->PAR=(uint32_t)&buf1;//��������� �� ������ ������ "������"
DMA2_Stream3->M0AR=(uint32_t)&LCD_data;//��������� �� ����� "����" (� ����� ������ �� �������� ������������ FSMC � �������� ��������� LCD)
DMA2_Stream3->NDTR=0x0008;//������� ��� ����������
//DMA2_Stream0->CR|=DMA_SxCR_EN;//����������

DMA2_Stream4->PAR=(uint32_t)&buf;//��������� �� ������ ������ "������"
DMA2_Stream4->M0AR=(uint32_t)&LCD_data;//��������� �� ����� "����" (� ����� ������ �� �������� ������������ FSMC � �������� ��������� LCD)
DMA2_Stream4->NDTR=0x0008;//������� ��� ����������
//DMA2_Stream0->CR|=DMA_SxCR_EN;//����������

DMA2_Stream5->PAR=(uint32_t)&buf1;//��������� �� ������ ������ "������"
DMA2_Stream5->M0AR=(uint32_t)&LCD_data;//��������� �� ����� "����" (� ����� ������ �� �������� ������������ FSMC � �������� ��������� LCD)
DMA2_Stream5->NDTR=0x0008;//������� ��� ����������
//DMA2_Stream0->CR|=DMA_SxCR_EN;//����������

DMA2_Stream6->PAR=(uint32_t)&buf;//��������� �� ������ ������ "������"
DMA2_Stream6->M0AR=(uint32_t)&LCD_data;//��������� �� ����� "����" (� ����� ������ �� �������� ������������ FSMC � �������� ��������� LCD)
DMA2_Stream6->NDTR=0x0008;//������� ��� ����������
//DMA2_Stream0->CR|=DMA_SxCR_EN;//����������

DMA2_Stream7->PAR=(uint32_t)&buf1;//��������� �� ������ ������ "������"
DMA2_Stream7->M0AR=(uint32_t)&LCD_data;//��������� �� ����� "����" (� ����� ������ �� �������� ������������ FSMC � �������� ��������� LCD)
DMA2_Stream7->NDTR=0x0008;//������� ��� ����������
//DMA2_Stream0->CR|=DMA_SxCR_EN;//����������*/


		//TIM10->CCR1+=m_c;

		//for (s_c=0; s_c<(m_c*2); s_c++)
		/*for (s_c=0; s_c<(m_c); s_c++)
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
		}*/

		/*for (s_c=0; s_c<(m_c*2); s_c++)
		//for (s_c=0; s_c<(m_c); s_c++)
		{
			if ((pi_x_count<256)&&(pi_y_count<192))
			{
				addr=(pix>>3)+16384;
				//if((memory[((addr&0xF81F)|((addr&0xE0)<<3)|((addr&0x700)>>3))])&(128>>(pix&7)))
				if((memory[addr])&(128>>(pix&7)))
				{
					//LCD_Write(Black);
					//buf[s_c]=Black;
					LCD_Write(Black);
				}
				else
				{
					//LCD_Write(White);
					//buf[s_c]=White;
					LCD_Write(White);
				}

				pix++;
			}
			else
			{
				//LCD_Write(White);
				//buf[s_c]=Red;
				LCD_Write(Red);
			}


			pi_x_count++;
			if (pi_x_count==320)
			{
				pi_x_count=0;
				pi_y_count++;
				INT=0;
				if (pi_y_count==240)
				{
					pi_y_count=0;
					pix=0;
					HAL_GPIO_TogglePin(green_LED_GPIO_Port, green_LED_Pin);
					INT=1;
				}
			}




		}*/

		//HAL_DMA_Abort(&hdma_memtomem_dma2_stream0);

		//HAL_DMA_Start(&hdma_memtomem_dma2_stream0, (uint32_t)&buf, (uint32_t)&LCD_data, (uint32_t)s_c);





/*void zx(void)
{
	m_c = z80_run();

	TIM10->CCR1+=m_c;

	m_c=m_c*2+ost;

	ost=m_c%8;

	m_c=m_c/8;

	for (s_c=0; s_c<m_c; s_c++)
	{
		if ((pi_x_count<32)&&(pi_y_count<192))
		{
			if(stream_c<4)
			{
				DMA2->LIFCR=cl_flag[stream_c];
			}
			else
			{
				DMA2->HIFCR=cl_flag[stream_c];
			}
			*(uint32_t*)bufst[stream_c]=(uint32_t)&buf;
			*(uint32_t*)stream[stream_c]|=DMA_SxCR_EN;//����������
		}
		else
		{
			if(stream_c<4)
			{
				DMA2->LIFCR=cl_flag[stream_c];
			}
			else
			{
				DMA2->HIFCR=cl_flag[stream_c];
			}
			*(uint32_t*)bufst[stream_c]=(uint32_t)&buf1;
			*(uint32_t*)stream[stream_c]|=DMA_SxCR_EN;//����������
		}
		pi_x_count++;

		stream_c++;

		if (stream_c==8)
		{
			stream_c=0;
		}
		if(pi_x_count==40)
		{
			pi_x_count=0;
			pi_y_count++;
			if(pi_y_count==240)
			{
				pi_y_count=0;
				HAL_GPIO_TogglePin(green_LED_GPIO_Port, green_LED_Pin);
			}
		}
	}


}*/
