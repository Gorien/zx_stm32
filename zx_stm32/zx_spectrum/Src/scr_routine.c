/*
 *
 *	Author: Beloussov Yegor
 *	Created on: january 2018
 *
 *	The program emulating the work ZX Spectrum
 *
 */

#include "stm32f4xx_hal.h"

static void sc_0x4000 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4000|b])^flash][memory[0x5800|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4008 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4008|b])^flash][memory[0x5808|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4010 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4010|b])^flash][memory[0x5810|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4018 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4018|b])^flash][memory[0x5818|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4100 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4100|b])^flash][memory[0x5800|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4108 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4108|b])^flash][memory[0x5808|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4110 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4110|b])^flash][memory[0x5810|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4118 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4118|b])^flash][memory[0x5818|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4200 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4200|b])^flash][memory[0x5800|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4208 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4208|b])^flash][memory[0x5808|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4210 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4210|b])^flash][memory[0x5810|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4218 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4218|b])^flash][memory[0x5818|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4300 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4300|b])^flash][memory[0x5800|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4308 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4308|b])^flash][memory[0x5808|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4310 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4310|b])^flash][memory[0x5810|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4318 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4318|b])^flash][memory[0x5818|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4400 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4400|b])^flash][memory[0x5800|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4408 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4408|b])^flash][memory[0x5808|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4410 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4410|b])^flash][memory[0x5810|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4418 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4418|b])^flash][memory[0x5818|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4500 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4500|b])^flash][memory[0x5800|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4508 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4508|b])^flash][memory[0x5808|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4510 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4510|b])^flash][memory[0x5810|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4518 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4518|b])^flash][memory[0x5818|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4600 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4600|b])^flash][memory[0x5800|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4608 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4608|b])^flash][memory[0x5808|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4610 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4610|b])^flash][memory[0x5810|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4618 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4618|b])^flash][memory[0x5818|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4700 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4700|b])^flash][memory[0x5800|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4708 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4708|b])^flash][memory[0x5808|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4710 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4710|b])^flash][memory[0x5810|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4718 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4718|b])^flash][memory[0x5818|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4020 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4020|b])^flash][memory[0x5820|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4028 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4028|b])^flash][memory[0x5828|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4030 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4030|b])^flash][memory[0x5830|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4038 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4038|b])^flash][memory[0x5838|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4120 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4120|b])^flash][memory[0x5820|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4128 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4128|b])^flash][memory[0x5828|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4130 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4130|b])^flash][memory[0x5830|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4138 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4138|b])^flash][memory[0x5838|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4220 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4220|b])^flash][memory[0x5820|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4228 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4228|b])^flash][memory[0x5828|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4230 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4230|b])^flash][memory[0x5830|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4238 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4238|b])^flash][memory[0x5838|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4320 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4320|b])^flash][memory[0x5820|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4328 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4328|b])^flash][memory[0x5828|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4330 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4330|b])^flash][memory[0x5830|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4338 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4338|b])^flash][memory[0x5838|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4420 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4420|b])^flash][memory[0x5820|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4428 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4428|b])^flash][memory[0x5828|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4430 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4430|b])^flash][memory[0x5830|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4438 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4438|b])^flash][memory[0x5838|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4520 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4520|b])^flash][memory[0x5820|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4528 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4528|b])^flash][memory[0x5828|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4530 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4530|b])^flash][memory[0x5830|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4538 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4538|b])^flash][memory[0x5838|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4620 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4620|b])^flash][memory[0x5820|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4628 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4628|b])^flash][memory[0x5828|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4630 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4630|b])^flash][memory[0x5830|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4638 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4638|b])^flash][memory[0x5838|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4720 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4720|b])^flash][memory[0x5820|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4728 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4728|b])^flash][memory[0x5828|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4730 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4730|b])^flash][memory[0x5830|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4738 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4738|b])^flash][memory[0x5838|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4040 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4040|b])^flash][memory[0x5840|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4048 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4048|b])^flash][memory[0x5848|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4050 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4050|b])^flash][memory[0x5850|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4058 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4058|b])^flash][memory[0x5858|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4140 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4140|b])^flash][memory[0x5840|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4148 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4148|b])^flash][memory[0x5848|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4150 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4150|b])^flash][memory[0x5850|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4158 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4158|b])^flash][memory[0x5858|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4240 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4240|b])^flash][memory[0x5840|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4248 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4248|b])^flash][memory[0x5848|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4250 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4250|b])^flash][memory[0x5850|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4258 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4258|b])^flash][memory[0x5858|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4340 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4340|b])^flash][memory[0x5840|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4348 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4348|b])^flash][memory[0x5848|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4350 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4350|b])^flash][memory[0x5850|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4358 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4358|b])^flash][memory[0x5858|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4440 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4440|b])^flash][memory[0x5840|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4448 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4448|b])^flash][memory[0x5848|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4450 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4450|b])^flash][memory[0x5850|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4458 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4458|b])^flash][memory[0x5858|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4540 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4540|b])^flash][memory[0x5840|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4548 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4548|b])^flash][memory[0x5848|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4550 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4550|b])^flash][memory[0x5850|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4558 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4558|b])^flash][memory[0x5858|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4640 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4640|b])^flash][memory[0x5840|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4648 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4648|b])^flash][memory[0x5848|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4650 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4650|b])^flash][memory[0x5850|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4658 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4658|b])^flash][memory[0x5858|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4740 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4740|b])^flash][memory[0x5840|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4748 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4748|b])^flash][memory[0x5848|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4750 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4750|b])^flash][memory[0x5850|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4758 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4758|b])^flash][memory[0x5858|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4060 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4060|b])^flash][memory[0x5860|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4068 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4068|b])^flash][memory[0x5868|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4070 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4070|b])^flash][memory[0x5870|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4078 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4078|b])^flash][memory[0x5878|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4160 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4160|b])^flash][memory[0x5860|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4168 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4168|b])^flash][memory[0x5868|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4170 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4170|b])^flash][memory[0x5870|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4178 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4178|b])^flash][memory[0x5878|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4260 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4260|b])^flash][memory[0x5860|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4268 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4268|b])^flash][memory[0x5868|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4270 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4270|b])^flash][memory[0x5870|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4278 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4278|b])^flash][memory[0x5878|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4360 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4360|b])^flash][memory[0x5860|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4368 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4368|b])^flash][memory[0x5868|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4370 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4370|b])^flash][memory[0x5870|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4378 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4378|b])^flash][memory[0x5878|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4460 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4460|b])^flash][memory[0x5860|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4468 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4468|b])^flash][memory[0x5868|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4470 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4470|b])^flash][memory[0x5870|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4478 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4478|b])^flash][memory[0x5878|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4560 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4560|b])^flash][memory[0x5860|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4568 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4568|b])^flash][memory[0x5868|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4570 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4570|b])^flash][memory[0x5870|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4578 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4578|b])^flash][memory[0x5878|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4660 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4660|b])^flash][memory[0x5860|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4668 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4668|b])^flash][memory[0x5868|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4670 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4670|b])^flash][memory[0x5870|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4678 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4678|b])^flash][memory[0x5878|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4760 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4760|b])^flash][memory[0x5860|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4768 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4768|b])^flash][memory[0x5868|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4770 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4770|b])^flash][memory[0x5870|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4778 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4778|b])^flash][memory[0x5878|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4080 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4080|b])^flash][memory[0x5880|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4088 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4088|b])^flash][memory[0x5888|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4090 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4090|b])^flash][memory[0x5890|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4098 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4098|b])^flash][memory[0x5898|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4180 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4180|b])^flash][memory[0x5880|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4188 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4188|b])^flash][memory[0x5888|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4190 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4190|b])^flash][memory[0x5890|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4198 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4198|b])^flash][memory[0x5898|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4280 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4280|b])^flash][memory[0x5880|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4288 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4288|b])^flash][memory[0x5888|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4290 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4290|b])^flash][memory[0x5890|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4298 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4298|b])^flash][memory[0x5898|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4380 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4380|b])^flash][memory[0x5880|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4388 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4388|b])^flash][memory[0x5888|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4390 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4390|b])^flash][memory[0x5890|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4398 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4398|b])^flash][memory[0x5898|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4480 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4480|b])^flash][memory[0x5880|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4488 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4488|b])^flash][memory[0x5888|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4490 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4490|b])^flash][memory[0x5890|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4498 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4498|b])^flash][memory[0x5898|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4580 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4580|b])^flash][memory[0x5880|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4588 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4588|b])^flash][memory[0x5888|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4590 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4590|b])^flash][memory[0x5890|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4598 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4598|b])^flash][memory[0x5898|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4680 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4680|b])^flash][memory[0x5880|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4688 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4688|b])^flash][memory[0x5888|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4690 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4690|b])^flash][memory[0x5890|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4698 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4698|b])^flash][memory[0x5898|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4780 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4780|b])^flash][memory[0x5880|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4788 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4788|b])^flash][memory[0x5888|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4790 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4790|b])^flash][memory[0x5890|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4798 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4798|b])^flash][memory[0x5898|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x40A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x40A0|b])^flash][memory[0x58A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x40A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x40A8|b])^flash][memory[0x58A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x40B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x40B0|b])^flash][memory[0x58B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x40B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x40B8|b])^flash][memory[0x58B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x41A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x41A0|b])^flash][memory[0x58A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x41A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x41A8|b])^flash][memory[0x58A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x41B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x41B0|b])^flash][memory[0x58B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x41B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x41B8|b])^flash][memory[0x58B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x42A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x42A0|b])^flash][memory[0x58A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x42A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x42A8|b])^flash][memory[0x58A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x42B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x42B0|b])^flash][memory[0x58B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x42B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x42B8|b])^flash][memory[0x58B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x43A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x43A0|b])^flash][memory[0x58A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x43A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x43A8|b])^flash][memory[0x58A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x43B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x43B0|b])^flash][memory[0x58B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x43B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x43B8|b])^flash][memory[0x58B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x44A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x44A0|b])^flash][memory[0x58A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x44A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x44A8|b])^flash][memory[0x58A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x44B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x44B0|b])^flash][memory[0x58B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x44B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x44B8|b])^flash][memory[0x58B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x45A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x45A0|b])^flash][memory[0x58A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x45A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x45A8|b])^flash][memory[0x58A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x45B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x45B0|b])^flash][memory[0x58B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x45B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x45B8|b])^flash][memory[0x58B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x46A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x46A0|b])^flash][memory[0x58A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x46A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x46A8|b])^flash][memory[0x58A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x46B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x46B0|b])^flash][memory[0x58B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x46B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x46B8|b])^flash][memory[0x58B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x47A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x47A0|b])^flash][memory[0x58A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x47A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x47A8|b])^flash][memory[0x58A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x47B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x47B0|b])^flash][memory[0x58B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x47B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x47B8|b])^flash][memory[0x58B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x40C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x40C0|b])^flash][memory[0x58C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x40C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x40C8|b])^flash][memory[0x58C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x40D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x40D0|b])^flash][memory[0x58D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x40D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x40D8|b])^flash][memory[0x58D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x41C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x41C0|b])^flash][memory[0x58C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x41C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x41C8|b])^flash][memory[0x58C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x41D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x41D0|b])^flash][memory[0x58D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x41D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x41D8|b])^flash][memory[0x58D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x42C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x42C0|b])^flash][memory[0x58C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x42C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x42C8|b])^flash][memory[0x58C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x42D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x42D0|b])^flash][memory[0x58D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x42D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x42D8|b])^flash][memory[0x58D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x43C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x43C0|b])^flash][memory[0x58C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x43C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x43C8|b])^flash][memory[0x58C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x43D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x43D0|b])^flash][memory[0x58D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x43D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x43D8|b])^flash][memory[0x58D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x44C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x44C0|b])^flash][memory[0x58C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x44C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x44C8|b])^flash][memory[0x58C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x44D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x44D0|b])^flash][memory[0x58D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x44D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x44D8|b])^flash][memory[0x58D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x45C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x45C0|b])^flash][memory[0x58C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x45C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x45C8|b])^flash][memory[0x58C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x45D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x45D0|b])^flash][memory[0x58D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x45D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x45D8|b])^flash][memory[0x58D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x46C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x46C0|b])^flash][memory[0x58C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x46C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x46C8|b])^flash][memory[0x58C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x46D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x46D0|b])^flash][memory[0x58D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x46D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x46D8|b])^flash][memory[0x58D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x47C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x47C0|b])^flash][memory[0x58C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x47C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x47C8|b])^flash][memory[0x58C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x47D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x47D0|b])^flash][memory[0x58D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x47D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x47D8|b])^flash][memory[0x58D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x40E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x40E0|b])^flash][memory[0x58E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x40E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x40E8|b])^flash][memory[0x58E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x40F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x40F0|b])^flash][memory[0x58F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x40F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x40F8|b])^flash][memory[0x58F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x41E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x41E0|b])^flash][memory[0x58E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x41E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x41E8|b])^flash][memory[0x58E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x41F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x41F0|b])^flash][memory[0x58F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x41F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x41F8|b])^flash][memory[0x58F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x42E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x42E0|b])^flash][memory[0x58E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x42E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x42E8|b])^flash][memory[0x58E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x42F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x42F0|b])^flash][memory[0x58F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x42F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x42F8|b])^flash][memory[0x58F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x43E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x43E0|b])^flash][memory[0x58E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x43E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x43E8|b])^flash][memory[0x58E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x43F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x43F0|b])^flash][memory[0x58F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x43F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x43F8|b])^flash][memory[0x58F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x44E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x44E0|b])^flash][memory[0x58E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x44E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x44E8|b])^flash][memory[0x58E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x44F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x44F0|b])^flash][memory[0x58F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x44F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x44F8|b])^flash][memory[0x58F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x45E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x45E0|b])^flash][memory[0x58E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x45E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x45E8|b])^flash][memory[0x58E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x45F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x45F0|b])^flash][memory[0x58F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x45F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x45F8|b])^flash][memory[0x58F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x46E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x46E0|b])^flash][memory[0x58E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x46E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x46E8|b])^flash][memory[0x58E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x46F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x46F0|b])^flash][memory[0x58F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x46F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x46F8|b])^flash][memory[0x58F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x47E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x47E0|b])^flash][memory[0x58E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x47E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x47E8|b])^flash][memory[0x58E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x47F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x47F0|b])^flash][memory[0x58F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x47F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x47F8|b])^flash][memory[0x58F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4800 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4800|b])^flash][memory[0x5900|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4808 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4808|b])^flash][memory[0x5908|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4810 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4810|b])^flash][memory[0x5910|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4818 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4818|b])^flash][memory[0x5918|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4900 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4900|b])^flash][memory[0x5900|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4908 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4908|b])^flash][memory[0x5908|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4910 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4910|b])^flash][memory[0x5910|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4918 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4918|b])^flash][memory[0x5918|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A00 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A00|b])^flash][memory[0x5900|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A08 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A08|b])^flash][memory[0x5908|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A10 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A10|b])^flash][memory[0x5910|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A18 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A18|b])^flash][memory[0x5918|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B00 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B00|b])^flash][memory[0x5900|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B08 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B08|b])^flash][memory[0x5908|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B10 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B10|b])^flash][memory[0x5910|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B18 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B18|b])^flash][memory[0x5918|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C00 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C00|b])^flash][memory[0x5900|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C08 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C08|b])^flash][memory[0x5908|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C10 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C10|b])^flash][memory[0x5910|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C18 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C18|b])^flash][memory[0x5918|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D00 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D00|b])^flash][memory[0x5900|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D08 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D08|b])^flash][memory[0x5908|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D10 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D10|b])^flash][memory[0x5910|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D18 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D18|b])^flash][memory[0x5918|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E00 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E00|b])^flash][memory[0x5900|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E08 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E08|b])^flash][memory[0x5908|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E10 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E10|b])^flash][memory[0x5910|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E18 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E18|b])^flash][memory[0x5918|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F00 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F00|b])^flash][memory[0x5900|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F08 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F08|b])^flash][memory[0x5908|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F10 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F10|b])^flash][memory[0x5910|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F18 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F18|b])^flash][memory[0x5918|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4820 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4820|b])^flash][memory[0x5920|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4828 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4828|b])^flash][memory[0x5928|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4830 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4830|b])^flash][memory[0x5930|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4838 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4838|b])^flash][memory[0x5938|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4920 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4920|b])^flash][memory[0x5920|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4928 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4928|b])^flash][memory[0x5928|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4930 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4930|b])^flash][memory[0x5930|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4938 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4938|b])^flash][memory[0x5938|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A20 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A20|b])^flash][memory[0x5920|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A28 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A28|b])^flash][memory[0x5928|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A30 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A30|b])^flash][memory[0x5930|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A38 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A38|b])^flash][memory[0x5938|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B20 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B20|b])^flash][memory[0x5920|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B28 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B28|b])^flash][memory[0x5928|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B30 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B30|b])^flash][memory[0x5930|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B38 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B38|b])^flash][memory[0x5938|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C20 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C20|b])^flash][memory[0x5920|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C28 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C28|b])^flash][memory[0x5928|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C30 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C30|b])^flash][memory[0x5930|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C38 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C38|b])^flash][memory[0x5938|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D20 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D20|b])^flash][memory[0x5920|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D28 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D28|b])^flash][memory[0x5928|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D30 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D30|b])^flash][memory[0x5930|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D38 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D38|b])^flash][memory[0x5938|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E20 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E20|b])^flash][memory[0x5920|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E28 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E28|b])^flash][memory[0x5928|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E30 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E30|b])^flash][memory[0x5930|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E38 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E38|b])^flash][memory[0x5938|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F20 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F20|b])^flash][memory[0x5920|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F28 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F28|b])^flash][memory[0x5928|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F30 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F30|b])^flash][memory[0x5930|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F38 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F38|b])^flash][memory[0x5938|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4840 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4840|b])^flash][memory[0x5940|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4848 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4848|b])^flash][memory[0x5948|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4850 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4850|b])^flash][memory[0x5950|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4858 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4858|b])^flash][memory[0x5958|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4940 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4940|b])^flash][memory[0x5940|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4948 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4948|b])^flash][memory[0x5948|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4950 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4950|b])^flash][memory[0x5950|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4958 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4958|b])^flash][memory[0x5958|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A40 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A40|b])^flash][memory[0x5940|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A48 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A48|b])^flash][memory[0x5948|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A50 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A50|b])^flash][memory[0x5950|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A58 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A58|b])^flash][memory[0x5958|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B40 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B40|b])^flash][memory[0x5940|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B48 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B48|b])^flash][memory[0x5948|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B50 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B50|b])^flash][memory[0x5950|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B58 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B58|b])^flash][memory[0x5958|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C40 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C40|b])^flash][memory[0x5940|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C48 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C48|b])^flash][memory[0x5948|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C50 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C50|b])^flash][memory[0x5950|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C58 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C58|b])^flash][memory[0x5958|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D40 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D40|b])^flash][memory[0x5940|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D48 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D48|b])^flash][memory[0x5948|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D50 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D50|b])^flash][memory[0x5950|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D58 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D58|b])^flash][memory[0x5958|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E40 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E40|b])^flash][memory[0x5940|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E48 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E48|b])^flash][memory[0x5948|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E50 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E50|b])^flash][memory[0x5950|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E58 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E58|b])^flash][memory[0x5958|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F40 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F40|b])^flash][memory[0x5940|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F48 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F48|b])^flash][memory[0x5948|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F50 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F50|b])^flash][memory[0x5950|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F58 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F58|b])^flash][memory[0x5958|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4860 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4860|b])^flash][memory[0x5960|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4868 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4868|b])^flash][memory[0x5968|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4870 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4870|b])^flash][memory[0x5970|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4878 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4878|b])^flash][memory[0x5978|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4960 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4960|b])^flash][memory[0x5960|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4968 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4968|b])^flash][memory[0x5968|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4970 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4970|b])^flash][memory[0x5970|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4978 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4978|b])^flash][memory[0x5978|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A60 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A60|b])^flash][memory[0x5960|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A68 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A68|b])^flash][memory[0x5968|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A70 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A70|b])^flash][memory[0x5970|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A78 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A78|b])^flash][memory[0x5978|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B60 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B60|b])^flash][memory[0x5960|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B68 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B68|b])^flash][memory[0x5968|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B70 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B70|b])^flash][memory[0x5970|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B78 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B78|b])^flash][memory[0x5978|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C60 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C60|b])^flash][memory[0x5960|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C68 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C68|b])^flash][memory[0x5968|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C70 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C70|b])^flash][memory[0x5970|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C78 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C78|b])^flash][memory[0x5978|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D60 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D60|b])^flash][memory[0x5960|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D68 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D68|b])^flash][memory[0x5968|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D70 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D70|b])^flash][memory[0x5970|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D78 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D78|b])^flash][memory[0x5978|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E60 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E60|b])^flash][memory[0x5960|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E68 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E68|b])^flash][memory[0x5968|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E70 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E70|b])^flash][memory[0x5970|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E78 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E78|b])^flash][memory[0x5978|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F60 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F60|b])^flash][memory[0x5960|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F68 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F68|b])^flash][memory[0x5968|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F70 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F70|b])^flash][memory[0x5970|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F78 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F78|b])^flash][memory[0x5978|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4880 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4880|b])^flash][memory[0x5980|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4888 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4888|b])^flash][memory[0x5988|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4890 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4890|b])^flash][memory[0x5990|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4898 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4898|b])^flash][memory[0x5998|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4980 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4980|b])^flash][memory[0x5980|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4988 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4988|b])^flash][memory[0x5988|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4990 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4990|b])^flash][memory[0x5990|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4998 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4998|b])^flash][memory[0x5998|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A80 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A80|b])^flash][memory[0x5980|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A88 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A88|b])^flash][memory[0x5988|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A90 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A90|b])^flash][memory[0x5990|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4A98 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4A98|b])^flash][memory[0x5998|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B80 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B80|b])^flash][memory[0x5980|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B88 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B88|b])^flash][memory[0x5988|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B90 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B90|b])^flash][memory[0x5990|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4B98 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4B98|b])^flash][memory[0x5998|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C80 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C80|b])^flash][memory[0x5980|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C88 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C88|b])^flash][memory[0x5988|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C90 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C90|b])^flash][memory[0x5990|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4C98 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4C98|b])^flash][memory[0x5998|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D80 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D80|b])^flash][memory[0x5980|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D88 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D88|b])^flash][memory[0x5988|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D90 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D90|b])^flash][memory[0x5990|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4D98 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4D98|b])^flash][memory[0x5998|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E80 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E80|b])^flash][memory[0x5980|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E88 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E88|b])^flash][memory[0x5988|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E90 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E90|b])^flash][memory[0x5990|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4E98 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4E98|b])^flash][memory[0x5998|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F80 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F80|b])^flash][memory[0x5980|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F88 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F88|b])^flash][memory[0x5988|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F90 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F90|b])^flash][memory[0x5990|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4F98 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4F98|b])^flash][memory[0x5998|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x48A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x48A0|b])^flash][memory[0x59A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x48A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x48A8|b])^flash][memory[0x59A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x48B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x48B0|b])^flash][memory[0x59B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x48B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x48B8|b])^flash][memory[0x59B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x49A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x49A0|b])^flash][memory[0x59A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x49A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x49A8|b])^flash][memory[0x59A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x49B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x49B0|b])^flash][memory[0x59B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x49B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x49B8|b])^flash][memory[0x59B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4AA0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4AA0|b])^flash][memory[0x59A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4AA8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4AA8|b])^flash][memory[0x59A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4AB0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4AB0|b])^flash][memory[0x59B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4AB8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4AB8|b])^flash][memory[0x59B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4BA0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4BA0|b])^flash][memory[0x59A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4BA8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4BA8|b])^flash][memory[0x59A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4BB0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4BB0|b])^flash][memory[0x59B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4BB8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4BB8|b])^flash][memory[0x59B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4CA0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4CA0|b])^flash][memory[0x59A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4CA8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4CA8|b])^flash][memory[0x59A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4CB0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4CB0|b])^flash][memory[0x59B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4CB8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4CB8|b])^flash][memory[0x59B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4DA0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4DA0|b])^flash][memory[0x59A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4DA8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4DA8|b])^flash][memory[0x59A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4DB0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4DB0|b])^flash][memory[0x59B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4DB8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4DB8|b])^flash][memory[0x59B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4EA0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4EA0|b])^flash][memory[0x59A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4EA8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4EA8|b])^flash][memory[0x59A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4EB0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4EB0|b])^flash][memory[0x59B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4EB8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4EB8|b])^flash][memory[0x59B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4FA0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4FA0|b])^flash][memory[0x59A0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4FA8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4FA8|b])^flash][memory[0x59A8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4FB0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4FB0|b])^flash][memory[0x59B0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4FB8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4FB8|b])^flash][memory[0x59B8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x48C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x48C0|b])^flash][memory[0x59C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x48C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x48C8|b])^flash][memory[0x59C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x48D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x48D0|b])^flash][memory[0x59D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x48D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x48D8|b])^flash][memory[0x59D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x49C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x49C0|b])^flash][memory[0x59C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x49C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x49C8|b])^flash][memory[0x59C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x49D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x49D0|b])^flash][memory[0x59D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x49D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x49D8|b])^flash][memory[0x59D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4AC0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4AC0|b])^flash][memory[0x59C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4AC8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4AC8|b])^flash][memory[0x59C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4AD0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4AD0|b])^flash][memory[0x59D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4AD8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4AD8|b])^flash][memory[0x59D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4BC0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4BC0|b])^flash][memory[0x59C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4BC8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4BC8|b])^flash][memory[0x59C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4BD0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4BD0|b])^flash][memory[0x59D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4BD8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4BD8|b])^flash][memory[0x59D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4CC0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4CC0|b])^flash][memory[0x59C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4CC8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4CC8|b])^flash][memory[0x59C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4CD0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4CD0|b])^flash][memory[0x59D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4CD8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4CD8|b])^flash][memory[0x59D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4DC0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4DC0|b])^flash][memory[0x59C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4DC8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4DC8|b])^flash][memory[0x59C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4DD0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4DD0|b])^flash][memory[0x59D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4DD8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4DD8|b])^flash][memory[0x59D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4EC0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4EC0|b])^flash][memory[0x59C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4EC8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4EC8|b])^flash][memory[0x59C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4ED0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4ED0|b])^flash][memory[0x59D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4ED8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4ED8|b])^flash][memory[0x59D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4FC0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4FC0|b])^flash][memory[0x59C0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4FC8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4FC8|b])^flash][memory[0x59C8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4FD0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4FD0|b])^flash][memory[0x59D0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4FD8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4FD8|b])^flash][memory[0x59D8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x48E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x48E0|b])^flash][memory[0x59E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x48E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x48E8|b])^flash][memory[0x59E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x48F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x48F0|b])^flash][memory[0x59F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x48F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x48F8|b])^flash][memory[0x59F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x49E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x49E0|b])^flash][memory[0x59E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x49E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x49E8|b])^flash][memory[0x59E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x49F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x49F0|b])^flash][memory[0x59F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x49F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x49F8|b])^flash][memory[0x59F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4AE0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4AE0|b])^flash][memory[0x59E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4AE8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4AE8|b])^flash][memory[0x59E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4AF0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4AF0|b])^flash][memory[0x59F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4AF8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4AF8|b])^flash][memory[0x59F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4BE0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4BE0|b])^flash][memory[0x59E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4BE8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4BE8|b])^flash][memory[0x59E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4BF0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4BF0|b])^flash][memory[0x59F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4BF8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4BF8|b])^flash][memory[0x59F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4CE0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4CE0|b])^flash][memory[0x59E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4CE8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4CE8|b])^flash][memory[0x59E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4CF0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4CF0|b])^flash][memory[0x59F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4CF8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4CF8|b])^flash][memory[0x59F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4DE0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4DE0|b])^flash][memory[0x59E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4DE8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4DE8|b])^flash][memory[0x59E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4DF0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4DF0|b])^flash][memory[0x59F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4DF8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4DF8|b])^flash][memory[0x59F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4EE0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4EE0|b])^flash][memory[0x59E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4EE8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4EE8|b])^flash][memory[0x59E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4EF0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4EF0|b])^flash][memory[0x59F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4EF8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4EF8|b])^flash][memory[0x59F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4FE0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4FE0|b])^flash][memory[0x59E0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4FE8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4FE8|b])^flash][memory[0x59E8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4FF0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4FF0|b])^flash][memory[0x59F0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x4FF8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x4FF8|b])^flash][memory[0x59F8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5000 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5000|b])^flash][memory[0x5A00|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5008 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5008|b])^flash][memory[0x5A08|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5010 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5010|b])^flash][memory[0x5A10|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5018 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5018|b])^flash][memory[0x5A18|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5100 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5100|b])^flash][memory[0x5A00|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5108 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5108|b])^flash][memory[0x5A08|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5110 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5110|b])^flash][memory[0x5A10|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5118 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5118|b])^flash][memory[0x5A18|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5200 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5200|b])^flash][memory[0x5A00|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5208 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5208|b])^flash][memory[0x5A08|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5210 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5210|b])^flash][memory[0x5A10|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5218 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5218|b])^flash][memory[0x5A18|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5300 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5300|b])^flash][memory[0x5A00|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5308 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5308|b])^flash][memory[0x5A08|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5310 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5310|b])^flash][memory[0x5A10|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5318 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5318|b])^flash][memory[0x5A18|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5400 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5400|b])^flash][memory[0x5A00|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5408 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5408|b])^flash][memory[0x5A08|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5410 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5410|b])^flash][memory[0x5A10|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5418 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5418|b])^flash][memory[0x5A18|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5500 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5500|b])^flash][memory[0x5A00|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5508 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5508|b])^flash][memory[0x5A08|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5510 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5510|b])^flash][memory[0x5A10|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5518 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5518|b])^flash][memory[0x5A18|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5600 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5600|b])^flash][memory[0x5A00|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5608 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5608|b])^flash][memory[0x5A08|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5610 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5610|b])^flash][memory[0x5A10|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5618 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5618|b])^flash][memory[0x5A18|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5700 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5700|b])^flash][memory[0x5A00|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5708 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5708|b])^flash][memory[0x5A08|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5710 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5710|b])^flash][memory[0x5A10|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5718 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5718|b])^flash][memory[0x5A18|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5020 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5020|b])^flash][memory[0x5A20|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5028 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5028|b])^flash][memory[0x5A28|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5030 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5030|b])^flash][memory[0x5A30|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5038 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5038|b])^flash][memory[0x5A38|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5120 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5120|b])^flash][memory[0x5A20|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5128 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5128|b])^flash][memory[0x5A28|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5130 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5130|b])^flash][memory[0x5A30|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5138 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5138|b])^flash][memory[0x5A38|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5220 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5220|b])^flash][memory[0x5A20|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5228 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5228|b])^flash][memory[0x5A28|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5230 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5230|b])^flash][memory[0x5A30|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5238 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5238|b])^flash][memory[0x5A38|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5320 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5320|b])^flash][memory[0x5A20|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5328 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5328|b])^flash][memory[0x5A28|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5330 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5330|b])^flash][memory[0x5A30|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5338 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5338|b])^flash][memory[0x5A38|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5420 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5420|b])^flash][memory[0x5A20|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5428 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5428|b])^flash][memory[0x5A28|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5430 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5430|b])^flash][memory[0x5A30|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5438 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5438|b])^flash][memory[0x5A38|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5520 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5520|b])^flash][memory[0x5A20|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5528 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5528|b])^flash][memory[0x5A28|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5530 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5530|b])^flash][memory[0x5A30|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5538 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5538|b])^flash][memory[0x5A38|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5620 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5620|b])^flash][memory[0x5A20|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5628 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5628|b])^flash][memory[0x5A28|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5630 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5630|b])^flash][memory[0x5A30|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5638 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5638|b])^flash][memory[0x5A38|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5720 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5720|b])^flash][memory[0x5A20|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5728 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5728|b])^flash][memory[0x5A28|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5730 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5730|b])^flash][memory[0x5A30|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5738 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5738|b])^flash][memory[0x5A38|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5040 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5040|b])^flash][memory[0x5A40|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5048 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5048|b])^flash][memory[0x5A48|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5050 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5050|b])^flash][memory[0x5A50|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5058 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5058|b])^flash][memory[0x5A58|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5140 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5140|b])^flash][memory[0x5A40|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5148 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5148|b])^flash][memory[0x5A48|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5150 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5150|b])^flash][memory[0x5A50|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5158 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5158|b])^flash][memory[0x5A58|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5240 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5240|b])^flash][memory[0x5A40|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5248 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5248|b])^flash][memory[0x5A48|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5250 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5250|b])^flash][memory[0x5A50|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5258 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5258|b])^flash][memory[0x5A58|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5340 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5340|b])^flash][memory[0x5A40|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5348 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5348|b])^flash][memory[0x5A48|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5350 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5350|b])^flash][memory[0x5A50|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5358 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5358|b])^flash][memory[0x5A58|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5440 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5440|b])^flash][memory[0x5A40|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5448 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5448|b])^flash][memory[0x5A48|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5450 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5450|b])^flash][memory[0x5A50|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5458 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5458|b])^flash][memory[0x5A58|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5540 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5540|b])^flash][memory[0x5A40|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5548 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5548|b])^flash][memory[0x5A48|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5550 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5550|b])^flash][memory[0x5A50|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5558 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5558|b])^flash][memory[0x5A58|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5640 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5640|b])^flash][memory[0x5A40|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5648 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5648|b])^flash][memory[0x5A48|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5650 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5650|b])^flash][memory[0x5A50|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5658 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5658|b])^flash][memory[0x5A58|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5740 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5740|b])^flash][memory[0x5A40|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5748 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5748|b])^flash][memory[0x5A48|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5750 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5750|b])^flash][memory[0x5A50|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5758 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5758|b])^flash][memory[0x5A58|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5060 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5060|b])^flash][memory[0x5A60|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5068 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5068|b])^flash][memory[0x5A68|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5070 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5070|b])^flash][memory[0x5A70|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5078 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5078|b])^flash][memory[0x5A78|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5160 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5160|b])^flash][memory[0x5A60|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5168 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5168|b])^flash][memory[0x5A68|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5170 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5170|b])^flash][memory[0x5A70|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5178 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5178|b])^flash][memory[0x5A78|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5260 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5260|b])^flash][memory[0x5A60|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5268 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5268|b])^flash][memory[0x5A68|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5270 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5270|b])^flash][memory[0x5A70|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5278 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5278|b])^flash][memory[0x5A78|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5360 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5360|b])^flash][memory[0x5A60|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5368 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5368|b])^flash][memory[0x5A68|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5370 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5370|b])^flash][memory[0x5A70|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5378 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5378|b])^flash][memory[0x5A78|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5460 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5460|b])^flash][memory[0x5A60|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5468 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5468|b])^flash][memory[0x5A68|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5470 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5470|b])^flash][memory[0x5A70|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5478 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5478|b])^flash][memory[0x5A78|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5560 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5560|b])^flash][memory[0x5A60|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5568 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5568|b])^flash][memory[0x5A68|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5570 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5570|b])^flash][memory[0x5A70|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5578 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5578|b])^flash][memory[0x5A78|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5660 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5660|b])^flash][memory[0x5A60|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5668 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5668|b])^flash][memory[0x5A68|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5670 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5670|b])^flash][memory[0x5A70|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5678 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5678|b])^flash][memory[0x5A78|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5760 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5760|b])^flash][memory[0x5A60|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5768 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5768|b])^flash][memory[0x5A68|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5770 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5770|b])^flash][memory[0x5A70|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5778 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5778|b])^flash][memory[0x5A78|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5080 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5080|b])^flash][memory[0x5A80|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5088 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5088|b])^flash][memory[0x5A88|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5090 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5090|b])^flash][memory[0x5A90|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5098 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5098|b])^flash][memory[0x5A98|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5180 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5180|b])^flash][memory[0x5A80|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5188 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5188|b])^flash][memory[0x5A88|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5190 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5190|b])^flash][memory[0x5A90|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5198 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5198|b])^flash][memory[0x5A98|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5280 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5280|b])^flash][memory[0x5A80|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5288 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5288|b])^flash][memory[0x5A88|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5290 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5290|b])^flash][memory[0x5A90|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5298 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5298|b])^flash][memory[0x5A98|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5380 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5380|b])^flash][memory[0x5A80|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5388 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5388|b])^flash][memory[0x5A88|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5390 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5390|b])^flash][memory[0x5A90|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5398 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5398|b])^flash][memory[0x5A98|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5480 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5480|b])^flash][memory[0x5A80|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5488 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5488|b])^flash][memory[0x5A88|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5490 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5490|b])^flash][memory[0x5A90|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5498 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5498|b])^flash][memory[0x5A98|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5580 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5580|b])^flash][memory[0x5A80|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5588 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5588|b])^flash][memory[0x5A88|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5590 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5590|b])^flash][memory[0x5A90|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5598 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5598|b])^flash][memory[0x5A98|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5680 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5680|b])^flash][memory[0x5A80|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5688 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5688|b])^flash][memory[0x5A88|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5690 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5690|b])^flash][memory[0x5A90|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5698 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5698|b])^flash][memory[0x5A98|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5780 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5780|b])^flash][memory[0x5A80|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5788 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5788|b])^flash][memory[0x5A88|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5790 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5790|b])^flash][memory[0x5A90|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x5798 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x5798|b])^flash][memory[0x5A98|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x50A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x50A0|b])^flash][memory[0x5AA0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x50A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x50A8|b])^flash][memory[0x5AA8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x50B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x50B0|b])^flash][memory[0x5AB0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x50B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x50B8|b])^flash][memory[0x5AB8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x51A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x51A0|b])^flash][memory[0x5AA0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x51A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x51A8|b])^flash][memory[0x5AA8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x51B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x51B0|b])^flash][memory[0x5AB0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x51B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x51B8|b])^flash][memory[0x5AB8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x52A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x52A0|b])^flash][memory[0x5AA0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x52A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x52A8|b])^flash][memory[0x5AA8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x52B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x52B0|b])^flash][memory[0x5AB0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x52B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x52B8|b])^flash][memory[0x5AB8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x53A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x53A0|b])^flash][memory[0x5AA0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x53A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x53A8|b])^flash][memory[0x5AA8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x53B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x53B0|b])^flash][memory[0x5AB0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x53B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x53B8|b])^flash][memory[0x5AB8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x54A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x54A0|b])^flash][memory[0x5AA0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x54A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x54A8|b])^flash][memory[0x5AA8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x54B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x54B0|b])^flash][memory[0x5AB0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x54B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x54B8|b])^flash][memory[0x5AB8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x55A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x55A0|b])^flash][memory[0x5AA0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x55A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x55A8|b])^flash][memory[0x5AA8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x55B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x55B0|b])^flash][memory[0x5AB0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x55B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x55B8|b])^flash][memory[0x5AB8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x56A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x56A0|b])^flash][memory[0x5AA0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x56A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x56A8|b])^flash][memory[0x5AA8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x56B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x56B0|b])^flash][memory[0x5AB0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x56B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x56B8|b])^flash][memory[0x5AB8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x57A0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x57A0|b])^flash][memory[0x5AA0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x57A8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x57A8|b])^flash][memory[0x5AA8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x57B0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x57B0|b])^flash][memory[0x5AB0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x57B8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x57B8|b])^flash][memory[0x5AB8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x50C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x50C0|b])^flash][memory[0x5AC0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x50C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x50C8|b])^flash][memory[0x5AC8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x50D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x50D0|b])^flash][memory[0x5AD0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x50D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x50D8|b])^flash][memory[0x5AD8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x51C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x51C0|b])^flash][memory[0x5AC0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x51C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x51C8|b])^flash][memory[0x5AC8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x51D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x51D0|b])^flash][memory[0x5AD0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x51D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x51D8|b])^flash][memory[0x5AD8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x52C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x52C0|b])^flash][memory[0x5AC0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x52C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x52C8|b])^flash][memory[0x5AC8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x52D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x52D0|b])^flash][memory[0x5AD0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x52D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x52D8|b])^flash][memory[0x5AD8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x53C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x53C0|b])^flash][memory[0x5AC0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x53C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x53C8|b])^flash][memory[0x5AC8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x53D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x53D0|b])^flash][memory[0x5AD0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x53D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x53D8|b])^flash][memory[0x5AD8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x54C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x54C0|b])^flash][memory[0x5AC0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x54C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x54C8|b])^flash][memory[0x5AC8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x54D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x54D0|b])^flash][memory[0x5AD0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x54D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x54D8|b])^flash][memory[0x5AD8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x55C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x55C0|b])^flash][memory[0x5AC0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x55C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x55C8|b])^flash][memory[0x5AC8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x55D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x55D0|b])^flash][memory[0x5AD0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x55D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x55D8|b])^flash][memory[0x5AD8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x56C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x56C0|b])^flash][memory[0x5AC0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x56C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x56C8|b])^flash][memory[0x5AC8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x56D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x56D0|b])^flash][memory[0x5AD0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x56D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x56D8|b])^flash][memory[0x5AD8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x57C0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x57C0|b])^flash][memory[0x5AC0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x57C8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x57C8|b])^flash][memory[0x5AC8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x57D0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x57D0|b])^flash][memory[0x5AD0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x57D8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x57D8|b])^flash][memory[0x5AD8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x50E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x50E0|b])^flash][memory[0x5AE0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x50E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x50E8|b])^flash][memory[0x5AE8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x50F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x50F0|b])^flash][memory[0x5AF0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x50F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x50F8|b])^flash][memory[0x5AF8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x51E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x51E0|b])^flash][memory[0x5AE0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x51E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x51E8|b])^flash][memory[0x5AE8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x51F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x51F0|b])^flash][memory[0x5AF0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x51F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x51F8|b])^flash][memory[0x5AF8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x52E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x52E0|b])^flash][memory[0x5AE0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x52E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x52E8|b])^flash][memory[0x5AE8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x52F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x52F0|b])^flash][memory[0x5AF0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x52F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x52F8|b])^flash][memory[0x5AF8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x53E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x53E0|b])^flash][memory[0x5AE0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x53E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x53E8|b])^flash][memory[0x5AE8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x53F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x53F0|b])^flash][memory[0x5AF0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x53F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x53F8|b])^flash][memory[0x5AF8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x54E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x54E0|b])^flash][memory[0x5AE0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x54E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x54E8|b])^flash][memory[0x5AE8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x54F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x54F0|b])^flash][memory[0x5AF0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x54F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x54F8|b])^flash][memory[0x5AF8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x55E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x55E0|b])^flash][memory[0x5AE0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x55E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x55E8|b])^flash][memory[0x5AE8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x55F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x55F0|b])^flash][memory[0x5AF0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x55F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x55F8|b])^flash][memory[0x5AF8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x56E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x56E0|b])^flash][memory[0x5AE0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x56E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x56E8|b])^flash][memory[0x5AE8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x56F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x56F0|b])^flash][memory[0x5AF0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x56F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x56F8|b])^flash][memory[0x5AF8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x57E0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x57E0|b])^flash][memory[0x5AE0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x57E8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x57E8|b])^flash][memory[0x5AE8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x57F0 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x57F0|b])^flash][memory[0x5AF0|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}
static void sc_0x57F8 (uint8_t b) {DMA2_Stream1->PAR=(uint32_t)&screen_data[(memory[0x57F8|b])^flash][memory[0x5AF8|b]&0x7f][0]; DMA2_Stream1->CR|=DMA_SxCR_EN;}

static void sc_BORDER (uint8_t b)
{
	DMA2_Stream0->CR|=DMA_SxCR_EN;
}

static void sc_BRINTH (uint8_t b)
{
	DMA2_Stream0->CR|=DMA_SxCR_EN;
	INT=1;
	flash_count++;
	if (flash_count==0)
	{
		flash^=0xff;
	}
}

static void sc_BRINTL (uint8_t b)
{
	DMA2_Stream0->CR|=DMA_SxCR_EN;
	INT=0;
}

static void (*scr_out [0x1200])(uint8_t b)={
sc_0x4000, sc_0x4008, sc_0x4010, sc_0x4018, sc_BORDER,
sc_0x4100, sc_0x4108, sc_0x4110, sc_0x4118, sc_BORDER,
sc_0x4200, sc_0x4208, sc_0x4210, sc_0x4218, sc_BORDER,
sc_0x4300, sc_0x4308, sc_0x4310, sc_0x4318, sc_BORDER,
sc_0x4400, sc_0x4408, sc_0x4410, sc_0x4418, sc_BORDER,
sc_0x4500, sc_0x4508, sc_0x4510, sc_0x4518, sc_BORDER,
sc_0x4600, sc_0x4608, sc_0x4610, sc_0x4618, sc_BORDER,
sc_0x4700, sc_0x4708, sc_0x4710, sc_0x4718, sc_BORDER,
sc_0x4020, sc_0x4028, sc_0x4030, sc_0x4038, sc_BORDER,
sc_0x4120, sc_0x4128, sc_0x4130, sc_0x4138, sc_BORDER,
sc_0x4220, sc_0x4228, sc_0x4230, sc_0x4238, sc_BORDER,
sc_0x4320, sc_0x4328, sc_0x4330, sc_0x4338, sc_BORDER,
sc_0x4420, sc_0x4428, sc_0x4430, sc_0x4438, sc_BORDER,
sc_0x4520, sc_0x4528, sc_0x4530, sc_0x4538, sc_BORDER,
sc_0x4620, sc_0x4628, sc_0x4630, sc_0x4638, sc_BORDER,
sc_0x4720, sc_0x4728, sc_0x4730, sc_0x4738, sc_BORDER,
sc_0x4040, sc_0x4048, sc_0x4050, sc_0x4058, sc_BORDER,
sc_0x4140, sc_0x4148, sc_0x4150, sc_0x4158, sc_BORDER,
sc_0x4240, sc_0x4248, sc_0x4250, sc_0x4258, sc_BORDER,
sc_0x4340, sc_0x4348, sc_0x4350, sc_0x4358, sc_BORDER,
sc_0x4440, sc_0x4448, sc_0x4450, sc_0x4458, sc_BORDER,
sc_0x4540, sc_0x4548, sc_0x4550, sc_0x4558, sc_BORDER,
sc_0x4640, sc_0x4648, sc_0x4650, sc_0x4658, sc_BORDER,
sc_0x4740, sc_0x4748, sc_0x4750, sc_0x4758, sc_BORDER,
sc_0x4060, sc_0x4068, sc_0x4070, sc_0x4078, sc_BORDER,
sc_0x4160, sc_0x4168, sc_0x4170, sc_0x4178, sc_BORDER,
sc_0x4260, sc_0x4268, sc_0x4270, sc_0x4278, sc_BORDER,
sc_0x4360, sc_0x4368, sc_0x4370, sc_0x4378, sc_BORDER,
sc_0x4460, sc_0x4468, sc_0x4470, sc_0x4478, sc_BORDER,
sc_0x4560, sc_0x4568, sc_0x4570, sc_0x4578, sc_BORDER,
sc_0x4660, sc_0x4668, sc_0x4670, sc_0x4678, sc_BORDER,
sc_0x4760, sc_0x4768, sc_0x4770, sc_0x4778, sc_BORDER,
sc_0x4080, sc_0x4088, sc_0x4090, sc_0x4098, sc_BORDER,
sc_0x4180, sc_0x4188, sc_0x4190, sc_0x4198, sc_BORDER,
sc_0x4280, sc_0x4288, sc_0x4290, sc_0x4298, sc_BORDER,
sc_0x4380, sc_0x4388, sc_0x4390, sc_0x4398, sc_BORDER,
sc_0x4480, sc_0x4488, sc_0x4490, sc_0x4498, sc_BORDER,
sc_0x4580, sc_0x4588, sc_0x4590, sc_0x4598, sc_BORDER,
sc_0x4680, sc_0x4688, sc_0x4690, sc_0x4698, sc_BORDER,
sc_0x4780, sc_0x4788, sc_0x4790, sc_0x4798, sc_BORDER,
sc_0x40A0, sc_0x40A8, sc_0x40B0, sc_0x40B8, sc_BORDER,
sc_0x41A0, sc_0x41A8, sc_0x41B0, sc_0x41B8, sc_BORDER,
sc_0x42A0, sc_0x42A8, sc_0x42B0, sc_0x42B8, sc_BORDER,
sc_0x43A0, sc_0x43A8, sc_0x43B0, sc_0x43B8, sc_BORDER,
sc_0x44A0, sc_0x44A8, sc_0x44B0, sc_0x44B8, sc_BORDER,
sc_0x45A0, sc_0x45A8, sc_0x45B0, sc_0x45B8, sc_BORDER,
sc_0x46A0, sc_0x46A8, sc_0x46B0, sc_0x46B8, sc_BORDER,
sc_0x47A0, sc_0x47A8, sc_0x47B0, sc_0x47B8, sc_BORDER,
sc_0x40C0, sc_0x40C8, sc_0x40D0, sc_0x40D8, sc_BORDER,
sc_0x41C0, sc_0x41C8, sc_0x41D0, sc_0x41D8, sc_BORDER,
sc_0x42C0, sc_0x42C8, sc_0x42D0, sc_0x42D8, sc_BORDER,
sc_0x43C0, sc_0x43C8, sc_0x43D0, sc_0x43D8, sc_BORDER,
sc_0x44C0, sc_0x44C8, sc_0x44D0, sc_0x44D8, sc_BORDER,
sc_0x45C0, sc_0x45C8, sc_0x45D0, sc_0x45D8, sc_BORDER,
sc_0x46C0, sc_0x46C8, sc_0x46D0, sc_0x46D8, sc_BORDER,
sc_0x47C0, sc_0x47C8, sc_0x47D0, sc_0x47D8, sc_BORDER,
sc_0x40E0, sc_0x40E8, sc_0x40F0, sc_0x40F8, sc_BORDER,
sc_0x41E0, sc_0x41E8, sc_0x41F0, sc_0x41F8, sc_BORDER,
sc_0x42E0, sc_0x42E8, sc_0x42F0, sc_0x42F8, sc_BORDER,
sc_0x43E0, sc_0x43E8, sc_0x43F0, sc_0x43F8, sc_BORDER,
sc_0x44E0, sc_0x44E8, sc_0x44F0, sc_0x44F8, sc_BORDER,
sc_0x45E0, sc_0x45E8, sc_0x45F0, sc_0x45F8, sc_BORDER,
sc_0x46E0, sc_0x46E8, sc_0x46F0, sc_0x46F8, sc_BORDER,
sc_0x47E0, sc_0x47E8, sc_0x47F0, sc_0x47F8, sc_BORDER,
sc_0x4800, sc_0x4808, sc_0x4810, sc_0x4818, sc_BORDER,
sc_0x4900, sc_0x4908, sc_0x4910, sc_0x4918, sc_BORDER,
sc_0x4A00, sc_0x4A08, sc_0x4A10, sc_0x4A18, sc_BORDER,
sc_0x4B00, sc_0x4B08, sc_0x4B10, sc_0x4B18, sc_BORDER,
sc_0x4C00, sc_0x4C08, sc_0x4C10, sc_0x4C18, sc_BORDER,
sc_0x4D00, sc_0x4D08, sc_0x4D10, sc_0x4D18, sc_BORDER,
sc_0x4E00, sc_0x4E08, sc_0x4E10, sc_0x4E18, sc_BORDER,
sc_0x4F00, sc_0x4F08, sc_0x4F10, sc_0x4F18, sc_BORDER,
sc_0x4820, sc_0x4828, sc_0x4830, sc_0x4838, sc_BORDER,
sc_0x4920, sc_0x4928, sc_0x4930, sc_0x4938, sc_BORDER,
sc_0x4A20, sc_0x4A28, sc_0x4A30, sc_0x4A38, sc_BORDER,
sc_0x4B20, sc_0x4B28, sc_0x4B30, sc_0x4B38, sc_BORDER,
sc_0x4C20, sc_0x4C28, sc_0x4C30, sc_0x4C38, sc_BORDER,
sc_0x4D20, sc_0x4D28, sc_0x4D30, sc_0x4D38, sc_BORDER,
sc_0x4E20, sc_0x4E28, sc_0x4E30, sc_0x4E38, sc_BORDER,
sc_0x4F20, sc_0x4F28, sc_0x4F30, sc_0x4F38, sc_BORDER,
sc_0x4840, sc_0x4848, sc_0x4850, sc_0x4858, sc_BORDER,
sc_0x4940, sc_0x4948, sc_0x4950, sc_0x4958, sc_BORDER,
sc_0x4A40, sc_0x4A48, sc_0x4A50, sc_0x4A58, sc_BORDER,
sc_0x4B40, sc_0x4B48, sc_0x4B50, sc_0x4B58, sc_BORDER,
sc_0x4C40, sc_0x4C48, sc_0x4C50, sc_0x4C58, sc_BORDER,
sc_0x4D40, sc_0x4D48, sc_0x4D50, sc_0x4D58, sc_BORDER,
sc_0x4E40, sc_0x4E48, sc_0x4E50, sc_0x4E58, sc_BORDER,
sc_0x4F40, sc_0x4F48, sc_0x4F50, sc_0x4F58, sc_BORDER,
sc_0x4860, sc_0x4868, sc_0x4870, sc_0x4878, sc_BORDER,
sc_0x4960, sc_0x4968, sc_0x4970, sc_0x4978, sc_BORDER,
sc_0x4A60, sc_0x4A68, sc_0x4A70, sc_0x4A78, sc_BORDER,
sc_0x4B60, sc_0x4B68, sc_0x4B70, sc_0x4B78, sc_BORDER,
sc_0x4C60, sc_0x4C68, sc_0x4C70, sc_0x4C78, sc_BORDER,
sc_0x4D60, sc_0x4D68, sc_0x4D70, sc_0x4D78, sc_BORDER,
sc_0x4E60, sc_0x4E68, sc_0x4E70, sc_0x4E78, sc_BORDER,
sc_0x4F60, sc_0x4F68, sc_0x4F70, sc_0x4F78, sc_BORDER,
sc_0x4880, sc_0x4888, sc_0x4890, sc_0x4898, sc_BORDER,
sc_0x4980, sc_0x4988, sc_0x4990, sc_0x4998, sc_BORDER,
sc_0x4A80, sc_0x4A88, sc_0x4A90, sc_0x4A98, sc_BORDER,
sc_0x4B80, sc_0x4B88, sc_0x4B90, sc_0x4B98, sc_BORDER,
sc_0x4C80, sc_0x4C88, sc_0x4C90, sc_0x4C98, sc_BORDER,
sc_0x4D80, sc_0x4D88, sc_0x4D90, sc_0x4D98, sc_BORDER,
sc_0x4E80, sc_0x4E88, sc_0x4E90, sc_0x4E98, sc_BORDER,
sc_0x4F80, sc_0x4F88, sc_0x4F90, sc_0x4F98, sc_BORDER,
sc_0x48A0, sc_0x48A8, sc_0x48B0, sc_0x48B8, sc_BORDER,
sc_0x49A0, sc_0x49A8, sc_0x49B0, sc_0x49B8, sc_BORDER,
sc_0x4AA0, sc_0x4AA8, sc_0x4AB0, sc_0x4AB8, sc_BORDER,
sc_0x4BA0, sc_0x4BA8, sc_0x4BB0, sc_0x4BB8, sc_BORDER,
sc_0x4CA0, sc_0x4CA8, sc_0x4CB0, sc_0x4CB8, sc_BORDER,
sc_0x4DA0, sc_0x4DA8, sc_0x4DB0, sc_0x4DB8, sc_BORDER,
sc_0x4EA0, sc_0x4EA8, sc_0x4EB0, sc_0x4EB8, sc_BORDER,
sc_0x4FA0, sc_0x4FA8, sc_0x4FB0, sc_0x4FB8, sc_BORDER,
sc_0x48C0, sc_0x48C8, sc_0x48D0, sc_0x48D8, sc_BORDER,
sc_0x49C0, sc_0x49C8, sc_0x49D0, sc_0x49D8, sc_BORDER,
sc_0x4AC0, sc_0x4AC8, sc_0x4AD0, sc_0x4AD8, sc_BORDER,
sc_0x4BC0, sc_0x4BC8, sc_0x4BD0, sc_0x4BD8, sc_BORDER,
sc_0x4CC0, sc_0x4CC8, sc_0x4CD0, sc_0x4CD8, sc_BORDER,
sc_0x4DC0, sc_0x4DC8, sc_0x4DD0, sc_0x4DD8, sc_BORDER,
sc_0x4EC0, sc_0x4EC8, sc_0x4ED0, sc_0x4ED8, sc_BORDER,
sc_0x4FC0, sc_0x4FC8, sc_0x4FD0, sc_0x4FD8, sc_BORDER,
sc_0x48E0, sc_0x48E8, sc_0x48F0, sc_0x48F8, sc_BORDER,
sc_0x49E0, sc_0x49E8, sc_0x49F0, sc_0x49F8, sc_BORDER,
sc_0x4AE0, sc_0x4AE8, sc_0x4AF0, sc_0x4AF8, sc_BORDER,
sc_0x4BE0, sc_0x4BE8, sc_0x4BF0, sc_0x4BF8, sc_BORDER,
sc_0x4CE0, sc_0x4CE8, sc_0x4CF0, sc_0x4CF8, sc_BORDER,
sc_0x4DE0, sc_0x4DE8, sc_0x4DF0, sc_0x4DF8, sc_BORDER,
sc_0x4EE0, sc_0x4EE8, sc_0x4EF0, sc_0x4EF8, sc_BORDER,
sc_0x4FE0, sc_0x4FE8, sc_0x4FF0, sc_0x4FF8, sc_BORDER,
sc_0x5000, sc_0x5008, sc_0x5010, sc_0x5018, sc_BORDER,
sc_0x5100, sc_0x5108, sc_0x5110, sc_0x5118, sc_BORDER,
sc_0x5200, sc_0x5208, sc_0x5210, sc_0x5218, sc_BORDER,
sc_0x5300, sc_0x5308, sc_0x5310, sc_0x5318, sc_BORDER,
sc_0x5400, sc_0x5408, sc_0x5410, sc_0x5418, sc_BORDER,
sc_0x5500, sc_0x5508, sc_0x5510, sc_0x5518, sc_BORDER,
sc_0x5600, sc_0x5608, sc_0x5610, sc_0x5618, sc_BORDER,
sc_0x5700, sc_0x5708, sc_0x5710, sc_0x5718, sc_BORDER,
sc_0x5020, sc_0x5028, sc_0x5030, sc_0x5038, sc_BORDER,
sc_0x5120, sc_0x5128, sc_0x5130, sc_0x5138, sc_BORDER,
sc_0x5220, sc_0x5228, sc_0x5230, sc_0x5238, sc_BORDER,
sc_0x5320, sc_0x5328, sc_0x5330, sc_0x5338, sc_BORDER,
sc_0x5420, sc_0x5428, sc_0x5430, sc_0x5438, sc_BORDER,
sc_0x5520, sc_0x5528, sc_0x5530, sc_0x5538, sc_BORDER,
sc_0x5620, sc_0x5628, sc_0x5630, sc_0x5638, sc_BORDER,
sc_0x5720, sc_0x5728, sc_0x5730, sc_0x5738, sc_BORDER,
sc_0x5040, sc_0x5048, sc_0x5050, sc_0x5058, sc_BORDER,
sc_0x5140, sc_0x5148, sc_0x5150, sc_0x5158, sc_BORDER,
sc_0x5240, sc_0x5248, sc_0x5250, sc_0x5258, sc_BORDER,
sc_0x5340, sc_0x5348, sc_0x5350, sc_0x5358, sc_BORDER,
sc_0x5440, sc_0x5448, sc_0x5450, sc_0x5458, sc_BORDER,
sc_0x5540, sc_0x5548, sc_0x5550, sc_0x5558, sc_BORDER,
sc_0x5640, sc_0x5648, sc_0x5650, sc_0x5658, sc_BORDER,
sc_0x5740, sc_0x5748, sc_0x5750, sc_0x5758, sc_BORDER,
sc_0x5060, sc_0x5068, sc_0x5070, sc_0x5078, sc_BORDER,
sc_0x5160, sc_0x5168, sc_0x5170, sc_0x5178, sc_BORDER,
sc_0x5260, sc_0x5268, sc_0x5270, sc_0x5278, sc_BORDER,
sc_0x5360, sc_0x5368, sc_0x5370, sc_0x5378, sc_BORDER,
sc_0x5460, sc_0x5468, sc_0x5470, sc_0x5478, sc_BORDER,
sc_0x5560, sc_0x5568, sc_0x5570, sc_0x5578, sc_BORDER,
sc_0x5660, sc_0x5668, sc_0x5670, sc_0x5678, sc_BORDER,
sc_0x5760, sc_0x5768, sc_0x5770, sc_0x5778, sc_BORDER,
sc_0x5080, sc_0x5088, sc_0x5090, sc_0x5098, sc_BORDER,
sc_0x5180, sc_0x5188, sc_0x5190, sc_0x5198, sc_BORDER,
sc_0x5280, sc_0x5288, sc_0x5290, sc_0x5298, sc_BORDER,
sc_0x5380, sc_0x5388, sc_0x5390, sc_0x5398, sc_BORDER,
sc_0x5480, sc_0x5488, sc_0x5490, sc_0x5498, sc_BORDER,
sc_0x5580, sc_0x5588, sc_0x5590, sc_0x5598, sc_BORDER,
sc_0x5680, sc_0x5688, sc_0x5690, sc_0x5698, sc_BORDER,
sc_0x5780, sc_0x5788, sc_0x5790, sc_0x5798, sc_BORDER,
sc_0x50A0, sc_0x50A8, sc_0x50B0, sc_0x50B8, sc_BORDER,
sc_0x51A0, sc_0x51A8, sc_0x51B0, sc_0x51B8, sc_BORDER,
sc_0x52A0, sc_0x52A8, sc_0x52B0, sc_0x52B8, sc_BORDER,
sc_0x53A0, sc_0x53A8, sc_0x53B0, sc_0x53B8, sc_BORDER,
sc_0x54A0, sc_0x54A8, sc_0x54B0, sc_0x54B8, sc_BORDER,
sc_0x55A0, sc_0x55A8, sc_0x55B0, sc_0x55B8, sc_BORDER,
sc_0x56A0, sc_0x56A8, sc_0x56B0, sc_0x56B8, sc_BORDER,
sc_0x57A0, sc_0x57A8, sc_0x57B0, sc_0x57B8, sc_BORDER,
sc_0x50C0, sc_0x50C8, sc_0x50D0, sc_0x50D8, sc_BORDER,
sc_0x51C0, sc_0x51C8, sc_0x51D0, sc_0x51D8, sc_BORDER,
sc_0x52C0, sc_0x52C8, sc_0x52D0, sc_0x52D8, sc_BORDER,
sc_0x53C0, sc_0x53C8, sc_0x53D0, sc_0x53D8, sc_BORDER,
sc_0x54C0, sc_0x54C8, sc_0x54D0, sc_0x54D8, sc_BORDER,
sc_0x55C0, sc_0x55C8, sc_0x55D0, sc_0x55D8, sc_BORDER,
sc_0x56C0, sc_0x56C8, sc_0x56D0, sc_0x56D8, sc_BORDER,
sc_0x57C0, sc_0x57C8, sc_0x57D0, sc_0x57D8, sc_BORDER,
sc_0x50E0, sc_0x50E8, sc_0x50F0, sc_0x50F8, sc_BORDER,
sc_0x51E0, sc_0x51E8, sc_0x51F0, sc_0x51F8, sc_BORDER,
sc_0x52E0, sc_0x52E8, sc_0x52F0, sc_0x52F8, sc_BORDER,
sc_0x53E0, sc_0x53E8, sc_0x53F0, sc_0x53F8, sc_BORDER,
sc_0x54E0, sc_0x54E8, sc_0x54F0, sc_0x54F8, sc_BORDER,
sc_0x55E0, sc_0x55E8, sc_0x55F0, sc_0x55F8, sc_BORDER,
sc_0x56E0, sc_0x56E8, sc_0x56F0, sc_0x56F8, sc_BORDER,
sc_0x57E0, sc_0x57E8, sc_0x57F0, sc_0x57F8, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BRINTH,
sc_BRINTL, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER,
sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER, sc_BORDER
};
