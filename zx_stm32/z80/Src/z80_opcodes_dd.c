/*
 * z80_opcodes_dd.c
 *
 *  Created on: 22 џэт. 2018 у.
 *      Author: Beloussov
 */



/*ADD IX, BC*/
static void op_DD_0x09(void)
{
	ADD16(IX, BC);
	T_WAIT_UNTIL(11);
	return;
}

/*ADD IX, DE*/
static void op_DD_0x19(void)
{
	ADD16(IX, DE);
	T_WAIT_UNTIL(11);
	return;
}

/*LD IX, @*/
static void op_DD_0x21(void)
{
	nn=NEXT_WORD;
	LD16(IX, nn);
	T_WAIT_UNTIL(10);
	return;
}

/*LD (@), IX*/
static void op_DD_0x22(void)
{
	nn=NEXT_WORD;
	LD_RP_TO_ADDR_MPTR_16(temp16, IX, nn);
	WRITE_WORD(nn, temp16);
	T_WAIT_UNTIL(16);
	return;
}

/*INC IX*/
static void op_DD_0x23(void)
{
	INC16(IX);
	T_WAIT_UNTIL(6);
	return;
}

/*INC IXH*/
static void op_DD_0x24(void)
{
	INC(IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*DEC IXH*/
static void op_DD_0x25(void)
{
	DEC(IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXH, #*/
static void op_DD_0x26(void)
{
	n=NEXT_BYTE;
	LD(IXH, n);
	T_WAIT_UNTIL(7);
	return;
}

/*ADD IX, IX*/
static void op_DD_0x29(void)
{
	ADD16(IX, IX);
	T_WAIT_UNTIL(11);
	return;
}

/*LD IX, (@)*/
static void op_DD_0x2a(void)
{
	nn=NEXT_WORD;
	temp16=READ_WORD(nn);
	LD_RP_FROM_ADDR_MPTR_16(IX, temp16, nn);
	T_WAIT_UNTIL(16);
	return;
}

/*DEC IX*/
static void op_DD_0x2b(void)
{
	DEC16(IX);
	T_WAIT_UNTIL(6);
	return;
}

/*INC IXL*/
static void op_DD_0x2c(void)
{
	INC(IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*DEC IXL*/
static void op_DD_0x2d(void)
{
	DEC(IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXL, #*/
static void op_DD_0x2e(void)
{
	n=NEXT_BYTE;
	LD(IXL, n);
	T_WAIT_UNTIL(7);
	return;
}

/*INC (IX+$)*/
static void op_DD_0x34(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	INC(temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*DEC (IX+$)*/
static void op_DD_0x35(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	DEC(temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD (IX+$), #*/
static void op_DD_0x36(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	n=NEXT_BYTE;
	LD(n, n);
	WRITE_BYTE(IX+d.s, n);
	T_WAIT_UNTIL(15);
	return;
}

/*ADD IX, SP*/
static void op_DD_0x39(void)
{
	ADD16(IX, SP);
	T_WAIT_UNTIL(11);
	return;
}

/*LD B, IXH*/
static void op_DD_0x44(void)
{
	LD(B, IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD B, IXL*/
static void op_DD_0x45(void)
{
	LD(B, IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD B, (IX+$)*/
static void op_DD_0x46(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(B, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD C, IXH*/
static void op_DD_0x4c(void)
{
	LD(C, IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD C, IXL*/
static void op_DD_0x4d(void)
{
	LD(C, IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD C, (IX+$)*/
static void op_DD_0x4e(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(C, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD D, IXH*/
static void op_DD_0x54(void)
{
	LD(D, IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD D, IXL*/
static void op_DD_0x55(void)
{
	LD(D, IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD D, (IX+$)*/
static void op_DD_0x56(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(D, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD E, IXH*/
static void op_DD_0x5c(void)
{
	LD(E, IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD E, IXL*/
static void op_DD_0x5d(void)
{
	LD(E, IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD E, (IX+$)*/
static void op_DD_0x5e(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(E, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD IXH, B*/
static void op_DD_0x60(void)
{
	LD(IXH, B);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXH, C*/
static void op_DD_0x61(void)
{
	LD(IXH, C);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXH, D*/
static void op_DD_0x62(void)
{
	LD(IXH, D);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXH, E*/
static void op_DD_0x63(void)
{
	LD(IXH, E);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXH, IXH*/
static void op_DD_0x64(void)
{
	LD(IXH, IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXH, IXL*/
static void op_DD_0x65(void)
{
	LD(IXH, IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD H, (IX+$)*/
static void op_DD_0x66(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(H, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD IXH, A*/
static void op_DD_0x67(void)
{
	LD(IXH, A);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXL, B*/
static void op_DD_0x68(void)
{
	LD(IXL, B);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXL, C*/
static void op_DD_0x69(void)
{
	LD(IXL, C);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXL, D*/
static void op_DD_0x6a(void)
{
	LD(IXL, D);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXL, E*/
static void op_DD_0x6b(void)
{
	LD(IXL, E);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXL, IXH*/
static void op_DD_0x6c(void)
{
	LD(IXL, IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IXL, IXL*/
static void op_DD_0x6d(void)
{
	LD(IXL, IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD L, (IX+$)*/
static void op_DD_0x6e(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(L, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD IXL, A*/
static void op_DD_0x6f(void)
{
	LD(IXL, A);
	T_WAIT_UNTIL(4);
	return;
}

/*LD (IX+$), B*/
static void op_DD_0x70(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, B);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD (IX+$), C*/
static void op_DD_0x71(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, C);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD (IX+$), D*/
static void op_DD_0x72(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, D);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD (IX+$), E*/
static void op_DD_0x73(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, E);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD (IX+$), H*/
static void op_DD_0x74(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, H);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD (IX+$), L*/
static void op_DD_0x75(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, L);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD (IX+$), A*/
static void op_DD_0x77(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	LD(temp8, A);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*LD A, IXH*/
static void op_DD_0x7c(void)
{
	LD(A, IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, IXL*/
static void op_DD_0x7d(void)
{
	LD(A, IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, (IX+$)*/
static void op_DD_0x7e(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	LD(A, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*ADD A, IXH*/
static void op_DD_0x84(void)
{
	ADD(A, IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*ADD A, IXL*/
static void op_DD_0x85(void)
{
	ADD(A, IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*ADD A, (IX+$)*/
static void op_DD_0x86(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	ADD(A, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*ADDC A, IXH*/
static void op_DD_0x8c(void)
{
	ADDC(A, IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*ADDC A, IXL*/
static void op_DD_0x8d(void)
{
	ADDC(A, IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*ADDC A, (IX+$)*/
static void op_DD_0x8e(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	ADDC(A, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*SUB IXH*/
static void op_DD_0x94(void)
{
	SUB(IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*SUB IXL*/
static void op_DD_0x95(void)
{
	SUB(IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*SUB (IX+$)*/
static void op_DD_0x96(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SUB(temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*SUBC A, IXH*/
static void op_DD_0x9c(void)
{
	SUBC(A, IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*SUBC A, IXL*/
static void op_DD_0x9d(void)
{
	SUBC(A, IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*SUBC A, (IX+$)*/
static void op_DD_0x9e(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SUBC(A, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*AND IXH*/
static void op_DD_0xa4(void)
{
	AND(IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*AND IXL*/
static void op_DD_0xa5(void)
{
	AND(IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*AND (IX+$)*/
static void op_DD_0xa6(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	AND(temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*XOR IXH*/
static void op_DD_0xac(void)
{
	XOR(IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*XOR IXL*/
static void op_DD_0xad(void)
{
	XOR(IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*XOR (IX+$)*/
static void op_DD_0xae(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	XOR(temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*OR IXH*/
static void op_DD_0xb4(void)
{
	OR(IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*OR IXL*/
static void op_DD_0xb5(void)
{
	OR(IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*OR (IX+$)*/
static void op_DD_0xb6(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	OR(temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*CP IXH*/
static void op_DD_0xbc(void)
{
	CP(IXH);
	T_WAIT_UNTIL(4);
	return;
}

/*CP IXL*/
static void op_DD_0xbd(void)
{
	CP(IXL);
	T_WAIT_UNTIL(4);
	return;
}

/*CP (IX+$)*/
static void op_DD_0xbe(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	CP(temp8);
	T_WAIT_UNTIL(15);
	return;
}


/*POP IX*/
static void op_DD_0xe1(void)
{
	POP(IX);
	T_WAIT_UNTIL(10);
	return;
}

/*EX (SP), IX*/
static void op_DD_0xe3(void)
{
	temp16=READ_WORD(SP);
	EX_MPTR(temp16, IX);
	WRITE_WORD(SP, temp16);
	T_WAIT_UNTIL(19);
	return;
}

/*PUSH IX*/
static void op_DD_0xe5(void)
{
	PUSH(IX);
	T_WAIT_UNTIL(11);
	return;
}

/*JP IX*/
static void op_DD_0xe9(void)
{
	JP_NO_MPTR(IX);
	T_WAIT_UNTIL(4);
	return;
}

/*LD SP, IX*/
static void op_DD_0xf9(void)
{
	LD16(SP, IX);
	T_WAIT_UNTIL(6);
	return;
}

/*NONI*/
static void non_DD (void)
{
	(*opcode_base[opcode])();
	return;
}

static void (*opcode_dd[0x100])(void)={
	non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0x09, non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    ,
	non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0x19, non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    ,
	non_DD    , op_DD_0x21, op_DD_0x22, op_DD_0x23, op_DD_0x24, op_DD_0x25, op_DD_0x26, non_DD    , non_DD    , op_DD_0x29, op_DD_0x2a, op_DD_0x2b, op_DD_0x2c, op_DD_0x2d, op_DD_0x2e, non_DD    ,
	non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0x34, op_DD_0x35, op_DD_0x36, non_DD    , non_DD    , op_DD_0x39, non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    ,
	non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0x44, op_DD_0x45, op_DD_0x46, non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0x4c, op_DD_0x4d, op_DD_0x4e, non_DD    ,
	non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0x54, op_DD_0x55, op_DD_0x56, non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0x5c, op_DD_0x5d, op_DD_0x5e, non_DD    ,
	op_DD_0x60, op_DD_0x61, op_DD_0x62, op_DD_0x63, op_DD_0x64, op_DD_0x65, op_DD_0x66, op_DD_0x67, op_DD_0x68, op_DD_0x69, op_DD_0x6a, op_DD_0x6b, op_DD_0x6c, op_DD_0x6d, op_DD_0x6e, op_DD_0x6f,
	op_DD_0x70, op_DD_0x71, op_DD_0x72, op_DD_0x73, op_DD_0x74, op_DD_0x75, non_DD    , op_DD_0x77, non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0x7c, op_DD_0x7d, op_DD_0x7e, non_DD    ,
	non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0x84, op_DD_0x85, op_DD_0x86, non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0x8c, op_DD_0x8d, op_DD_0x8e, non_DD    ,
	non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0x94, op_DD_0x95, op_DD_0x96, non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0x9c, op_DD_0x9d, op_DD_0x9e, non_DD    ,
	non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0xa4, op_DD_0xa5, op_DD_0xa6, non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0xac, op_DD_0xad, op_DD_0xae, non_DD    ,
	non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0xb4, op_DD_0xb5, op_DD_0xb6, non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0xbc, op_DD_0xbd, op_DD_0xbe, non_DD    ,
	non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    ,
	non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    ,
	non_DD    , op_DD_0xe1, non_DD    , op_DD_0xe3, non_DD    , op_DD_0xe5, non_DD    , non_DD    , non_DD    , op_DD_0xe9, non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    ,
	non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , op_DD_0xf9, non_DD    , non_DD    , non_DD    , non_DD    , non_DD    , non_DD
};
