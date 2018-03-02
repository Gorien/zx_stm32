/*
 *
 *	Author: Beloussov Yegor
 *	Created on: january 2018
 *
 *	The program emulating the work ZX Spectrum
 *
 */

#ifndef INC_ZX_H_
#define INC_ZX_H_

extern uint16_t const screen_data [128][256][8];

void zx_run(void);
void zx(void);

void z80_screen(void);

#endif /* INC_ZX_H_ */
