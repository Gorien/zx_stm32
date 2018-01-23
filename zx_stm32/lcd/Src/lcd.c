/*
 *
 *	Author: Beloussov Yegor
 *	Created on: january 2018
 *
 *	 LCD display initialization program.The display is connected to the
 *	 module FSMC.
 *
 */



#include "lcd.h"
#include "stm32f4xx_hal.h"

uint8_t screen_IRQ;
uint8_t flash;
uint16_t baitRAM=0x0;

uint8_t pixel;
uint8_t atribut;
uint16_t bytecount;
uint8_t count;
uint8_t t=0;

void init_screen(void)
{
	LCD_Initializtion();
	LCD_Clear(White);
	LCD_SetCursor(32, 216);
	LCD_WriteRAM_Prepare();
}

//обработчик прерываний от TIM6
void TIM6_DAC_IRQHandler (void)
{
	TIM6->SR=0;

	if (bytecount==9600)
	{
		LCD_SetCursor(32, 216);
		LCD_WriteRAM_Prepare();
		screen_IRQ=1;
		bytecount=0;
		baitRAM=0;
		flash++;
	}

		if (bytecount==10)
		{
			screen_IRQ=0;
		}

	DMA2->LIFCR=~(0);

	if (bytecount<1920)
	{
		DMA2_Stream0->CR|=DMA_SxCR_EN;//пересылаем
	}
  else
	{
		if (count==40)
		{
			count=0;
		}

		if (count<32)
		{
			//pixel=screen_RAM[baitRAM];
			//atribut=attribute_RAM[((baitRAM&0x1F00)>>3)|(baitRAM&0x1F)];//перевод адреса пикселей в адрес атрибутов

			if (atribut&0x80)
			{
				if (flash&0x20)
				{
					pixel=~pixel;
				}
			}
			//DMA2_Stream1->PAR=(uint32_t)&byte_color[pixel][atribut&0x7F][0];//указатель на начало буфера "откуда"
			//DMA2_Stream1->CR|=DMA_SxCR_EN;//пересылаем
			baitRAM++;
		}
		else
		{
			//DMA2_Stream0->CR|=DMA_SxCR_EN;//пересылаем
		}
		count++;
	}
	bytecount++;
}

//Запись данных в регистр LCD
void LCD_WriteReg(uint16_t LCD_Reg,uint16_t LCD_RegValue)
{
	LCD_reg=LCD_Reg;
	LCD_data=LCD_RegValue;
}

//Чтение из регистра LCD
uint16_t LCD_ReadReg(uint8_t LCD_Reg)
{
	uint16_t data;
	LCD_reg=LCD_Reg;
	data=LCD_data;
	return data;
}

//Выбрать регистр
void LCD_WriteCommand(uint16_t LCD_Reg)
{
	LCD_reg=LCD_Reg;
}

//Записать данные в регистр
void LCD_WriteRAM(uint16_t LCD_RegValue)
{
	LCD_data=LCD_RegValue;
}

//Выбрать регистр 0х22 (запись в видеопамять)
void LCD_WriteRAM_Prepare(void)
{
	LCD_reg=(0x22);
}

//Задержка
void Delay(uint32_t nCount)
{
  uint32_t TimingDelay;
  while(nCount--)
  {
		for(TimingDelay=0;TimingDelay<1000;TimingDelay++);
  }
}

//Инициализация дисплея
void LCD_Initializtion(void)
{
	uint16_t DeviceIdCode;
	//GPIOE->BSRRL|=GPIO_BSRR_BS_1;//Reset LCD
  //Delay (100);
	//GPIOE->BSRRL|=GPIO_BSRR_BR_1;
  //Delay (100);
  //GPIOE->BSRRL|=GPIO_BSRR_BS_1;
  //Delay (100);

	DeviceIdCode=LCD_ReadReg(0x0000);
	Delay(1);
	if(DeviceIdCode == 0x4532)//This LCD is LGDP4532
	{
		//power on
    LCD_WriteReg(0x15, 0x0030);//Regulator Control (R15h)
    LCD_WriteReg(0x11, 0x0040);//Power Control 2 (R11h) set dc1,dc0,vc2
    LCD_WriteReg(0x10, 0x1628);//Power Control 1 (R10h) set bt,sap,ap:1628
    LCD_WriteReg(0x12, 0x0000);//Power Control 3 (R12h) set vrh
    LCD_WriteReg(0x13, 0x104D);//Power Control 4 (R13h) set vdv,vcm
    Delay(60);
    LCD_WriteReg(0x12, 0x0010);//Power Control 3 (R12h) set vrh:0012
    Delay(60);
    LCD_WriteReg(0x10, 0x2620);//Power Control 1 (R10h) set bt,sap,ap:2620
    LCD_WriteReg(0x13, 0x304D);//Power Control 4 (R13h set vdv,vcm
    Delay(60);
		//end power on

		//set gamma
    LCD_WriteReg(0x30, 0x0000);//Red Gamma Control
    LCD_WriteReg(0x31, 0x0603);//Red Gamma Control
    LCD_WriteReg(0x32, 0x0307);//Red Gamma Control
    LCD_WriteReg(0x33, 0x0303);//Red Gamma Control
    LCD_WriteReg(0x34, 0x0004);//Red Gamma Control
    LCD_WriteReg(0x35, 0x0401);//Red Gamma Control
    LCD_WriteReg(0x36, 0x0707);//Red Gamma Control
    LCD_WriteReg(0x37, 0x0303);//Red Gamma Control
    LCD_WriteReg(0x38, 0x1505);//Red Gamma Control
    LCD_WriteReg(0x39, 0x1505);//Red Gamma Control
		//end gamma set

    LCD_WriteReg(0x01, 0x0100);//Driver output control (R01h) set sm,ss
    LCD_WriteReg(0x02, 0x0300);//LCD Driving Wave Control (R02h) set line/frame inversion ,BC0,EOR,NW5-0
    LCD_WriteReg(0x03, 0x1038);//Entry Mode (R03h) SET BGR,ID1-0,AM
    LCD_WriteReg(0x08, 0x0604);//Display Control 2 (R08h) set fp,bp,0604
    LCD_WriteReg(0x09, 0x0000);//Display Control 3 (R09h)
    LCD_WriteReg(0x0A, 0x0008);//Display Control 4 (R0Ah)
    LCD_WriteReg(0x40, 0x2000);//EPROM Control Register 1 (R40h) add from LG
    LCD_WriteReg(0x40, 0x0000);//EPROM Control Register 1 (R40h) add from LG

    LCD_WriteReg(0x41, 0x0002);//EPROM Control Register 2 (R41h)
    LCD_WriteReg(0x60, 0xA700);//Driver Output Control (R60h) set GS bit
    LCD_WriteReg(0x61, 0x0001);//Base Image Display Control (R61h)
    LCD_WriteReg(0x90, 0x0182);//Panel Interface Control 1 (R90h) set DIV1-0,RTN4-0 ,0199
    LCD_WriteReg(0x93, 0x0001);//Panel Interface Control 3 (R93h)
    LCD_WriteReg(0xA3, 0x0010);//Test Register 4 (RA3h)

    LCD_WriteReg(0x50, 0x0000);//window horizontial start address
    LCD_WriteReg(0x51, 0x00EF);//window horizontial end address
    LCD_WriteReg(0x52, 0x0000);//window vertical  start address
    LCD_WriteReg(0x53, 0x013F);//window vertical end  address

    LCD_WriteReg(0x07,0x0001);//Display Control 1 (R07h)
    LCD_WriteReg(0x07,0x0021);
    LCD_WriteReg(0x07,0x0023);
    LCD_WriteReg(0x07,0x0033);
    Delay(10);
		LCD_WriteReg(0x07,0x0133);
	}
  else//Err: Unknow DeviceIdCode
  {
		while(1);
  }
}

//Переместить курсор
void LCD_SetCursor(uint16_t x,uint16_t y)
{
	LCD_WriteReg(0x0020,y);
  LCD_WriteReg(0x0021,x);
}


//Отчистка всего экрана
void LCD_Clear(uint16_t Color)
{
  uint32_t index=0;
	LCD_WriteReg(0x0050,0x0000);
	LCD_WriteReg(0x0051,0x00EF);
	LCD_WriteReg(0x0052,0x0000);
	LCD_WriteReg(0x0053,0x013F);
  LCD_SetCursor(0x00,0x00);
  LCD_WriteRAM_Prepare();
  for(index=0;index<76800;index++)
	{
		LCD_WriteRAM(Color);
	}
}
