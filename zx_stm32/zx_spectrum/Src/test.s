#include "zx.h"


	.syntax unified
	.cpu cortex-m4
	.thumb



.equ RNG_BASE, 0x50060800
.equ RNG_DR, 0x08


.global nois_f

.extern nois

nois_f:
			movw r3, #0
			ldr r0, =RNG_BASE+RNG_DR
			ldr r1, =nois
loop:
			ldr r2, [r0]
			strb r2, [r1]

			add r3, #1
			cmp r3, #9600
			bne loop
			movw r3, #0
			B loop

