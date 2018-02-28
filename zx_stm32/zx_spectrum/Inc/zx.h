/*
 * zx.h
 *
 *  Created on: 24 ���. 2018 �.
 *      Author: Beloussov
 */

#ifndef INC_ZX_H_
#define INC_ZX_H_

extern uint16_t border;
extern uint16_t const screen_data [128][256][8];
extern uint16_t noise;

void zx_run(void);
void zx(void);

void z80_screen(void);

#endif /* INC_ZX_H_ */
