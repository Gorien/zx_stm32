/*
 *
 *	Author: Beloussov Yegor
 *	Created on: january 2018
 *
 *	The program emulating AY_3_891x
 *
 */

#ifndef INC_AY_3_891X_H_
#define INC_AY_3_891X_H_

extern uint8_t ay_3_891x[16];
extern uint8_t ay_3_891x_reg;
extern uint16_t noise;

void ay_3_891x_Init(void);
void (*const ay_3_891x_fc [0x16])(uint8_t value);

#endif /* INC_AY_3_891X_H_ */
