/*
 * z80.h
 *
 *  Created on: 22 џэт. 2018 у.
 *      Author: Beloussov
 */

#ifndef INC_Z80_H_
#define INC_Z80_H_

void z80_reset(void);
void z80_run(void);

void poke(uint16_t addr, uint8_t value);
uint8_t peek(uint16_t addr);
void poke16(uint16_t addr, uint16_t value);
uint16_t peek16(uint16_t addr);

uint8_t in(uint16_t port);
void out(uint16_t port, uint8_t value);


#endif /* INC_Z80_H_ */
