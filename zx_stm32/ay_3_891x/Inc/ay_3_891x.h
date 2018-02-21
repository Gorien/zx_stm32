/*
 * ay_3_891x.h
 *
 *  Created on: 21 ����. 2018 �.
 *      Author: Beloussov
 */

#ifndef INC_AY_3_891X_H_
#define INC_AY_3_891X_H_

extern uint8_t ay_3_891x[16];
extern uint8_t ay_3_891x_reg;

void (*const ay_3_891x_fc [0x16])(uint8_t value);

#endif /* INC_AY_3_891X_H_ */
