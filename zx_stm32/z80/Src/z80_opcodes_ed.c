/*
 * z80_opcodes_ed.c
 *
 *  Created on: 22 џэт. 2018 у.
 *      Author: Beloussov
 */


/*IN B, (C)*/
static void op_ED_0x40(void)
{
	IN(B, BC);
	T_WAIT_UNTIL(8);
	return;
}

/*OUT (C), B*/
static void op_ED_0x41(void)
{
	OUT(BC, B);
	T_WAIT_UNTIL(8);
	return;
}

/*SUBC HL, BC*/
static void op_ED_0x42(void)
{
	SUBC16(HL, BC);
	T_WAIT_UNTIL(11);
	return;
}

/*LD (@), BC*/
static void op_ED_0x43(void)
{
	nn=NEXT_WORD;
	LD_RP_TO_ADDR_MPTR_16(temp16, BC, nn);
	WRITE_WORD(nn, temp16);
	T_WAIT_UNTIL(16);
	return;
}

/*NEG*/
static void op_ED_0x44(void)
{
	NEG();
	T_WAIT_UNTIL(4);
	return;
}

/*RETN*/
static void op_ED_0x45(void)
{
	RETN();
	T_WAIT_UNTIL(10);
	return;
}

/*IM 0*/
static void op_ED_0x46(void)
{
	IM_MODE(0);
	T_WAIT_UNTIL(4);
	return;
}

/*LD I, A*/
static void op_ED_0x47(void)
{
	LD(I, A);
	T_WAIT_UNTIL(5);
	return;
}

/*IN C, (C)*/
static void op_ED_0x48(void)
{
	IN(C, BC);
	T_WAIT_UNTIL(8);
	return;
}

/*OUT (C), C*/
static void op_ED_0x49(void)
{
	OUT(BC, C);
	T_WAIT_UNTIL(8);
	return;
}

/*ADDC HL, BC*/
static void op_ED_0x4a(void)
{
	ADDC16(HL, BC);
	T_WAIT_UNTIL(11);
	return;
}

/*LD BC, (@)*/
static void op_ED_0x4b(void)
{
	nn=NEXT_WORD;
	temp16=READ_WORD(nn);
	LD_RP_FROM_ADDR_MPTR_16(BC, temp16, nn);
	T_WAIT_UNTIL(16);
	return;
}

/*NEG*/
static void op_ED_0x4c(void)
{
	NEG();
	T_WAIT_UNTIL(4);
	return;
}

/*RETI*/
static void op_ED_0x4d(void)
{
	RETI();
	T_WAIT_UNTIL(10);
	return;
}

/*IM 0*/
static void op_ED_0x4e(void)
{
	IM_MODE(0);
	T_WAIT_UNTIL(4);
	return;
}

/*LD R, A*/
static void op_ED_0x4f(void)
{
	LD_R_A();
	T_WAIT_UNTIL(5);
	return;
}

/*IN D, (C)*/
static void op_ED_0x50(void)
{
	IN(D, BC);
	T_WAIT_UNTIL(8);
	return;
}

/*OUT (C), D*/
static void op_ED_0x51(void)
{
	OUT(BC, D);
	T_WAIT_UNTIL(8);
	return;
}

/*SUBC HL, DE*/
static void op_ED_0x52(void)
{
	SUBC16(HL, DE);
	T_WAIT_UNTIL(11);
	return;
}

/*LD (@), DE*/
static void op_ED_0x53(void)
{
	nn=NEXT_WORD;
	LD_RP_TO_ADDR_MPTR_16(temp16, DE, nn);
	WRITE_WORD(nn, temp16);
	T_WAIT_UNTIL(16);
	return;
}

/*NEG*/
static void op_ED_0x54(void)
{
	NEG();
	T_WAIT_UNTIL(4);
	return;
}

/*RETN*/
static void op_ED_0x55(void)
{
	RETN();
	T_WAIT_UNTIL(10);
	return;
}

/*IM 1*/
static void op_ED_0x56(void)
{
	IM_MODE(1);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, I*/
static void op_ED_0x57(void)
{
	LD_A_I();
	T_WAIT_UNTIL(5);
	return;
}

/*IN E, (C)*/
static void op_ED_0x58(void)
{
	IN(E, BC);
	T_WAIT_UNTIL(8);
	return;
}

/*OUT (C), E*/
static void op_ED_0x59(void)
{
	OUT(BC, E);
	T_WAIT_UNTIL(8);
	return;
}

/*ADDC HL, DE*/
static void op_ED_0x5a(void)
{
	ADDC16(HL, DE);
	T_WAIT_UNTIL(11);
	return;
}

/*LD DE, (@)*/
static void op_ED_0x5b(void)
{
	nn=NEXT_WORD;
	temp16=READ_WORD(nn);
	LD_RP_FROM_ADDR_MPTR_16(DE, temp16, nn);
	T_WAIT_UNTIL(16);
	return;
}

/*NEG*/
static void op_ED_0x5c(void)
{
	NEG();
	T_WAIT_UNTIL(4);
	return;
}

/*RETI*/
static void op_ED_0x5d(void)
{
	RETI();
	T_WAIT_UNTIL(10);
	return;
}

/*IM 2*/
static void op_ED_0x5e(void)
{
	IM_MODE(2);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, R*/
static void op_ED_0x5f(void)
{
	LD_A_R();
	T_WAIT_UNTIL(5);
	return;
}

/*IN H, (C)*/
static void op_ED_0x60(void)
{
	IN(H, BC);
	T_WAIT_UNTIL(8);
	return;
}

/*OUT (C), H*/
static void op_ED_0x61(void)
{
	OUT(BC, H);
	T_WAIT_UNTIL(8);
	return;
}

/*SUBC HL, HL*/
static void op_ED_0x62(void)
{
	SUBC16(HL, HL);
	T_WAIT_UNTIL(11);
	return;
}

/*LD (@), HL*/
static void op_ED_0x63(void)
{
	nn=NEXT_WORD;
	LD_RP_TO_ADDR_MPTR_16(temp16, HL, nn);
	WRITE_WORD(nn, temp16);
	T_WAIT_UNTIL(16);
	return;
}

/*NEG*/
static void op_ED_0x64(void)
{
	NEG();
	T_WAIT_UNTIL(4);
	return;
}

/*RETN*/
static void op_ED_0x65(void)
{
	RETN();
	T_WAIT_UNTIL(10);
	return;
}

/*IM 0*/
static void op_ED_0x66(void)
{
	IM_MODE(0);
	T_WAIT_UNTIL(4);
	return;
}

/*RRD*/
static void op_ED_0x67(void)
{
	RRD();
	T_WAIT_UNTIL(14);
	return;
}

/*IN L, (C)*/
static void op_ED_0x68(void)
{
	IN(L, BC);
	T_WAIT_UNTIL(8);
	return;
}

/*OUT (C), L*/
static void op_ED_0x69(void)
{
	OUT(BC, L);
	T_WAIT_UNTIL(8);
	return;
}

/*ADDC HL, HL*/
static void op_ED_0x6a(void)
{
	ADDC16(HL, HL);
	T_WAIT_UNTIL(11);
	return;
}

/*LD HL, (@)*/
static void op_ED_0x6b(void)
{
	nn=NEXT_WORD;
	temp16=READ_WORD(nn);
	LD_RP_FROM_ADDR_MPTR_16(HL, temp16, nn);
	T_WAIT_UNTIL(16);
	return;
}

/*NEG*/
static void op_ED_0x6c(void)
{
	NEG();
	T_WAIT_UNTIL(4);
	return;
}

/*RETI*/
static void op_ED_0x6d(void)
{
	RETI();
	T_WAIT_UNTIL(10);
	return;
}

/*IM 0*/
static void op_ED_0x6e(void)
{
	IM_MODE(0);
	T_WAIT_UNTIL(4);
	return;
}

/*RLD*/
static void op_ED_0x6f(void)
{
	RLD();
	T_WAIT_UNTIL(14);
	return;
}

/*IN_F (C)*/
static void op_ED_0x70(void)
{
	IN_F(BC);
	T_WAIT_UNTIL(8);
	return;
}

/*OUT (C), 0*/
static void op_ED_0x71(void)
{
	OUT(BC, 0);
	T_WAIT_UNTIL(8);
	return;
}

/*SUBC HL, SP*/
static void op_ED_0x72(void)
{
	SUBC16(HL, SP);
	T_WAIT_UNTIL(11);
	return;
}

/*LD (@), SP*/
static void op_ED_0x73(void)
{
	nn=NEXT_WORD;
	LD_RP_TO_ADDR_MPTR_16(temp16, SP, nn);
	WRITE_WORD(nn, temp16);
	T_WAIT_UNTIL(16);
	return;
}

/*NEG*/
static void op_ED_0x74(void)
{
	NEG();
	T_WAIT_UNTIL(4);
	return;
}

/*RETN*/
static void op_ED_0x75(void)
{
	RETN();
	T_WAIT_UNTIL(10);
	return;
}

/*IM 1*/
static void op_ED_0x76(void)
{
	IM_MODE(1);
	T_WAIT_UNTIL(4);
	return;
}

/*IN A, (C)*/
static void op_ED_0x78(void)
{
	IN(A, BC);
	T_WAIT_UNTIL(8);
	return;
}

/*OUT (C), A*/
static void op_ED_0x79(void)
{
	OUT(BC, A);
	T_WAIT_UNTIL(8);
	return;
}

/*ADDC HL, SP*/
static void op_ED_0x7a(void)
{
	ADDC16(HL, SP);
	T_WAIT_UNTIL(11);
	return;
}

/*LD SP, (@)*/
static void op_ED_0x7b(void)
{
	nn=NEXT_WORD;
	temp16=READ_WORD(nn);
	LD_RP_FROM_ADDR_MPTR_16(SP, temp16, nn);
	T_WAIT_UNTIL(16);
	return;
}

/*NEG*/
static void op_ED_0x7c(void)
{
	NEG();
	T_WAIT_UNTIL(4);
	return;
}

/*RETI*/
static void op_ED_0x7d(void)
{
	RETI();
	T_WAIT_UNTIL(10);
	return;
}

/*IM 2*/
static void op_ED_0x7e(void)
{
	IM_MODE(2);
	T_WAIT_UNTIL(4);
	return;
}

/*LDI*/
static void op_ED_0xa0(void)
{
	LDI();
	T_WAIT_UNTIL(12);
	return;
}

/*CPI*/
static void op_ED_0xa1(void)
{
	CPI();
	T_WAIT_UNTIL(12);
	return;
}

/*INI*/
static void op_ED_0xa2(void)
{
	INI();
	T_WAIT_UNTIL(12);
	return;
}

/*OUTI*/
static void op_ED_0xa3(void)
{
	OUTI();
	T_WAIT_UNTIL(12);
	return;
}

/*LDD*/
static void op_ED_0xa8(void)
{
	LDD();
	T_WAIT_UNTIL(12);
	return;
}

/*CPD*/
static void op_ED_0xa9(void)
{
	CPD();
	T_WAIT_UNTIL(12);
	return;
}

/*IND*/
static void op_ED_0xaa(void)
{
	IND();
	T_WAIT_UNTIL(12);
	return;
}

/*OUTD*/
static void op_ED_0xab(void)
{
	OUTD();
	T_WAIT_UNTIL(12);
	return;
}

/*LDIR*/
static void op_ED_0xb0(void)
{
	LDIR();
	return;
}

/*CPIR*/
static void op_ED_0xb1(void)
{
	CPIR();
	return;
}

/*INIR*/
static void op_ED_0xb2(void)
{
	INIR();
	return;
}

/*OTIR*/
static void op_ED_0xb3(void)
{
	OTIR();
	return;
}

/*LDDR*/
static void op_ED_0xb8(void)
{
	LDDR();
	return;
}

/*CPDR*/
static void op_ED_0xb9(void)
{
	CPDR();
	return;
}

/*INDR*/
static void op_ED_0xba(void)
{
	INDR();
	return;
}

/*OTDR*/
static void op_ED_0xbb(void)
{
	OTDR();
	return;
}

/*NONI*/
static void noni_ED(void)
{
	T_WAIT_UNTIL(4);
	return;
}

static void (*opcode_ed [0x100])(void)={
	noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   ,
	noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   ,
	noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   ,
	noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   ,
	op_ED_0x40, op_ED_0x41, op_ED_0x42, op_ED_0x43, op_ED_0x44, op_ED_0x45, op_ED_0x46, op_ED_0x47, op_ED_0x48, op_ED_0x49, op_ED_0x4a, op_ED_0x4b, op_ED_0x4c, op_ED_0x4d, op_ED_0x4e, op_ED_0x4f,
	op_ED_0x50, op_ED_0x51, op_ED_0x52, op_ED_0x53, op_ED_0x54, op_ED_0x55, op_ED_0x56, op_ED_0x57, op_ED_0x58, op_ED_0x59, op_ED_0x5a, op_ED_0x5b, op_ED_0x5c, op_ED_0x5d, op_ED_0x5e, op_ED_0x5f,
	op_ED_0x60, op_ED_0x61, op_ED_0x62, op_ED_0x63, op_ED_0x64, op_ED_0x65, op_ED_0x66, op_ED_0x67, op_ED_0x68, op_ED_0x69, op_ED_0x6a, op_ED_0x6b, op_ED_0x6c, op_ED_0x6d, op_ED_0x6e, op_ED_0x6f,
	op_ED_0x70, op_ED_0x71, op_ED_0x72, op_ED_0x73, op_ED_0x74, op_ED_0x75, op_ED_0x76, noni_ED   , op_ED_0x78, op_ED_0x79, op_ED_0x7a, op_ED_0x7b, op_ED_0x7c, op_ED_0x7d, op_ED_0x7e, noni_ED   ,
	noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   ,
	noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   ,
	op_ED_0xa0, op_ED_0xa1, op_ED_0xa2, op_ED_0xa3, noni_ED   , noni_ED   , noni_ED   , noni_ED   , op_ED_0xa8, op_ED_0xa9, op_ED_0xaa, op_ED_0xab, noni_ED   , noni_ED   , noni_ED   , noni_ED   ,
	op_ED_0xb0, op_ED_0xb1, op_ED_0xb2, op_ED_0xb3, noni_ED   , noni_ED   , noni_ED   , noni_ED   , op_ED_0xb8, op_ED_0xb9, op_ED_0xba, op_ED_0xbb, noni_ED   , noni_ED   , noni_ED   , noni_ED   ,
	noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   ,
	noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   ,
	noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   ,
	noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED   , noni_ED
};
