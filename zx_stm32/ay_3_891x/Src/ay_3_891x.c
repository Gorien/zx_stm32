/*
 * ay_3_891x.c
 *
 *  Created on: 21 ����. 2018 �.
 *      Author: Beloussov
 */

#include "stm32f4xx_hal.h"
#include "ay_3_891x.h"

uint8_t ay_3_891x[16]={0, 0, 0, 0, 0, 0, 0, 0x3f, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t ay_3_891x_reg=0;
const uint16_t noise_color [32]={
	671, 691, 711, 731, 751, 771, 791, 811, 831, 851, 871, 891, 911, 931, 951, 971,
	991, 1011, 1031, 1051, 1071, 1091, 1111, 1131, 1151, 1171, 1191, 1211, 1231, 1251, 1271, 1291
};

const uint16_t volume [16]={
	0,2,4,6,8,10,15,20,25,32,43,64,85,128,220,335
};

static void ay_3_891x_reg_0x00(uint8_t value)
{
	TIM2->PSC=(ay_3_891x[1]<<8)|ay_3_891x[0];
}

static void ay_3_891x_reg_0x01(uint8_t value)
{
	TIM2->PSC=(ay_3_891x[1]<<8)|ay_3_891x[0];
}

static void ay_3_891x_reg_0x02(uint8_t value)
{
	TIM3->PSC=(ay_3_891x[3]<<8)|ay_3_891x[2];
}

static void ay_3_891x_reg_0x03(uint8_t value)
{
	TIM3->PSC=(ay_3_891x[3]<<8)|ay_3_891x[2];
}

static void ay_3_891x_reg_0x04(uint8_t value)
{
	TIM4->PSC=(ay_3_891x[5]<<8)|ay_3_891x[4];
}

static void ay_3_891x_reg_0x05(uint8_t value)
{
	TIM4->PSC=(ay_3_891x[5]<<8)|ay_3_891x[4];
}

static void ay_3_891x_reg_0x06(uint8_t value)
{
	TIM1->ARR=(uint32_t)noise_color[value];
}

static void ay_3_891x_reg_0x07(uint8_t value)
{
	if (value&1)
	{
		TIM2->CCER&=~(TIM_CCER_CC2E);
	}
	else
	{
		TIM2->CCER|=TIM_CCER_CC2E;
	}

	if (value&2)
	{
		TIM3->CCER&=~(TIM_CCER_CC2E);
	}
	else
	{
		TIM3->CCER|=TIM_CCER_CC2E;
	}

	if (value&4)
	{
		TIM4->CCER&=~(TIM_CCER_CC1E);
	}
	else
	{
		TIM4->CCER|=TIM_CCER_CC1E;
	}

	if (value&8)
	{
		TIM1->CCER&=~(TIM_CCER_CC1E);
	}
	else
	{
		TIM1->CCER|=TIM_CCER_CC1E;
	}
	if (value&16)
	{
		TIM1->CCER&=~(TIM_CCER_CC2E);
	}
	else
	{
		TIM1->CCER|=TIM_CCER_CC2E;
	}
	if (value&32)
	{
		TIM1->CCER&=~(TIM_CCER_CC3E);
	}
	else
	{
		TIM1->CCER|=TIM_CCER_CC3E;
	}
}

static void ay_3_891x_reg_0x08(uint8_t value)
{
	TIM1->CCR1=TIM2->CCR2=(uint32_t)volume[value&0xf];
}

static void ay_3_891x_reg_0x09(uint8_t value)
{
	TIM1->CCR2=TIM3->CCR2=(uint32_t)volume[value&0xf];
}

static void ay_3_891x_reg_0x0a(uint8_t value)
{
	TIM1->CCR3=TIM4->CCR1=(uint32_t)volume[value&0xf];
}

static void ay_3_891x_reg_0x0b(uint8_t value)
{

}

static void ay_3_891x_reg_0x0c(uint8_t value)
{

}

static void ay_3_891x_reg_0x0d(uint8_t value)
{

}

static void ay_3_891x_reg_0x0e(uint8_t value)
{

}

static void ay_3_891x_reg_0x0f(uint8_t value)
{

}

void (*const ay_3_891x_fc [0x16])(uint8_t value)={
		ay_3_891x_reg_0x00, ay_3_891x_reg_0x01, ay_3_891x_reg_0x02, ay_3_891x_reg_0x03,
		ay_3_891x_reg_0x04, ay_3_891x_reg_0x05, ay_3_891x_reg_0x06, ay_3_891x_reg_0x07,
		ay_3_891x_reg_0x08, ay_3_891x_reg_0x09, ay_3_891x_reg_0x0a, ay_3_891x_reg_0x0b,
		ay_3_891x_reg_0x0c, ay_3_891x_reg_0x0d, ay_3_891x_reg_0x0e, ay_3_891x_reg_0x0f,
};
