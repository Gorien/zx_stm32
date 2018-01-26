/*
 *
 *	Author: Beloussov Yegor
 *	Created on: january 2018
 *
 *	The main interface header file of the processor emulator is z80. In writing
 *	the emulator code, different Internet resources were used. Most of the code
 *	is borrowed from https://sourceforge.net/projects/z80ex/. Creation of the
 *	famous Pigmaker57 aka Boo-boo.
 *
 */

#ifndef INC_Z80_H_
#define INC_Z80_H_

extern uint8_t screen_RAM [6144];
extern uint8_t memory[0x10000];
extern uint8_t const ROM[16384];

void z80_reset(void);
uint8_t z80_run(void);

void poke(uint16_t addr, uint8_t value);
uint8_t peek(uint16_t addr);
void poke16(uint16_t addr, uint16_t value);
uint16_t peek16(uint16_t addr);

uint8_t in(uint16_t port);
void out(uint16_t port, uint8_t value);


#endif /* INC_Z80_H_ */
