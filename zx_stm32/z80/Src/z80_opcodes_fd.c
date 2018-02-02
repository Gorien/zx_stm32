/*
 *
 *	Author: Beloussov Yegor
 *	Created on: january 2018
 *
 *	The program emulating the work of the processor z80
 *	Attention! this part must be included in the main program code
 *
 */


/*ADD IY, BC*/
static void op_FD_0x09(void)
{
	ADD16(IY, BC);
	T_WAIT_UNTIL(11);
	return;
}

/*ADD IY, DE*/
static void op_FD_0x19(void)
{
	ADD16(IY, DE);
	T_WAIT_UNTIL(11);
	return;
}

/*LD IY, @*/
static void op_FD_0x21(void)
{
	LD_nn_TO_RP(IY);
	T_WAIT_UNTIL(10);
	return;
}

/*LD (@), IY*/
static void op_FD_0x22(void)
{
	LD_ADDR_nn_FROM_RP(IY);
	T_WAIT_UNTIL(16);
	return;
}

/*INC IY*/
static void op_FD_0x23(void)
{
	INC16(IY);
	T_WAIT_UNTIL(6);
	return;
}

/*INC IYH*/
static void op_FD_0x24(void)
{
	INC_R(IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*DEC IYH*/
static void op_FD_0x25(void)
{
	DEC_R(IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYH, #*/
static void op_FD_0x26(void)
{
	LD_n_TO_R(IYH);
	T_WAIT_UNTIL(7);
	return;
}

/*ADD IY, IY*/
static void op_FD_0x29(void)
{
	ADD16(IY, IY);
	T_WAIT_UNTIL(11);
	return;
}

/*LD IY, (@)*/
static void op_FD_0x2a(void)
{
	LD_ADDR_nn_TO_RP(IY);
	T_WAIT_UNTIL(16);
	return;
}

/*DEC IY*/
static void op_FD_0x2b(void)
{
	DEC16(IY);
	T_WAIT_UNTIL(6);
	return;
}

/*INC IYL*/
static void op_FD_0x2c(void)
{
	INC_R(IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*DEC IYL*/
static void op_FD_0x2d(void)
{
	DEC_R(IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYL, #*/
static void op_FD_0x2e(void)
{
	LD_n_TO_R(IYL);
	T_WAIT_UNTIL(7);
	return;
}

/*INC (IY+$)*/
static void op_FD_0x34(void)
{
	INC_ADDR_RP_AND_OFSET(IY);
	T_WAIT_UNTIL(19);
	return;
}

/*DEC (IY+$)*/
static void op_FD_0x35(void)
{
	DEC_ADDR_RP_AND_OFSET(IY);
	T_WAIT_UNTIL(19);
	return;
}

/*LD (IY+$), #*/
static void op_FD_0x36(void)
{
	LD_n_TO_ADDR_RP_AND_OFFSET(IY);
	T_WAIT_UNTIL(15);
	return;
}

/*ADD IY, SP*/
static void op_FD_0x39(void)
{
	ADD16(IY, SP);
	T_WAIT_UNTIL(11);
	return;
}

/*LD B, IYH*/
static void op_FD_0x44(void)
{
	LD_R_TO_R(B, IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD B, IYL*/
static void op_FD_0x45(void)
{
	LD_R_TO_R(B, IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD B, (IY+$)*/
static void op_FD_0x46(void)
{
	LD_ADDR_RP_AND_OFFSET_TO_R(B, IY);
	T_WAIT_UNTIL(15);
	return;
}

/*LD C, IYH*/
static void op_FD_0x4c(void)
{
	LD_R_TO_R(C, IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD C, IYL*/
static void op_FD_0x4d(void)
{
	LD_R_TO_R(C, IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD C, (IY+$)*/
static void op_FD_0x4e(void)
{
	LD_ADDR_RP_AND_OFFSET_TO_R(C, IY);
	T_WAIT_UNTIL(15);
	return;
}

/*LD D, IYH*/
static void op_FD_0x54(void)
{
	LD_R_TO_R(D, IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD D, IYL*/
static void op_FD_0x55(void)
{
	LD_R_TO_R(D, IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD D, (IY+$)*/
static void op_FD_0x56(void)
{
	LD_ADDR_RP_AND_OFFSET_TO_R(D, IY);
	T_WAIT_UNTIL(15);
	return;
}

/*LD E, IYH*/
static void op_FD_0x5c(void)
{
	LD_R_TO_R(E, IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD E, IYL*/
static void op_FD_0x5d(void)
{
	LD_R_TO_R(E, IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD E, (IY+$)*/
static void op_FD_0x5e(void)
{
	LD_ADDR_RP_AND_OFFSET_TO_R(E, IY);
	T_WAIT_UNTIL(15);
	return;
}

/*LD IYH, B*/
static void op_FD_0x60(void)
{
	LD_R_TO_R(IYH, B);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYH, C*/
static void op_FD_0x61(void)
{
	LD_R_TO_R(IYH, C);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYH, D*/
static void op_FD_0x62(void)
{
	LD_R_TO_R(IYH, D);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYH, E*/
static void op_FD_0x63(void)
{
	LD_R_TO_R(IYH, E);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYH, IYH*/
static void op_FD_0x64(void)
{
	LD_R_TO_R(IYH, IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYH, IYL*/
static void op_FD_0x65(void)
{
	LD_R_TO_R(IYH, IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD H, (IY+$)*/
static void op_FD_0x66(void)
{
	LD_ADDR_RP_AND_OFFSET_TO_R(H, IY);
	T_WAIT_UNTIL(15);
	return;
}

/*LD IYH, A*/
static void op_FD_0x67(void)
{
	LD_R_TO_R(IYH, A);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYL, B*/
static void op_FD_0x68(void)
{
	LD_R_TO_R(IYL, B);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYL, C*/
static void op_FD_0x69(void)
{
	LD_R_TO_R(IYL, C);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYL, D*/
static void op_FD_0x6a(void)
{
	LD_R_TO_R(IYL, D);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYL, E*/
static void op_FD_0x6b(void)
{
	LD_R_TO_R(IYL, E);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYL, IYH*/
static void op_FD_0x6c(void)
{
	LD_R_TO_R(IYL, IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD IYL, IYL*/
static void op_FD_0x6d(void)
{
	LD_R_TO_R(IYL, IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD L, (IY+$)*/
static void op_FD_0x6e(void)
{
	LD_ADDR_RP_AND_OFFSET_TO_R(L, IY);
	T_WAIT_UNTIL(15);
	return;
}

/*LD IYL, A*/
static void op_FD_0x6f(void)
{
	LD_R_TO_R(IYL, A);
	T_WAIT_UNTIL(4);
	return;
}

/*LD (IY+$), B*/
static void op_FD_0x70(void)
{
	LD_ADDR_RP_AND_OFFSET_FROM_R(IY, B);
	T_WAIT_UNTIL(15);
	return;
}

/*LD (IY+$), C*/
static void op_FD_0x71(void)
{
	LD_ADDR_RP_AND_OFFSET_FROM_R(IY, C);
	T_WAIT_UNTIL(15);
	return;
}

/*LD (IY+$), D*/
static void op_FD_0x72(void)
{
	LD_ADDR_RP_AND_OFFSET_FROM_R(IY, D);
	T_WAIT_UNTIL(15);
	return;
}

/*LD (IY+$), E*/
static void op_FD_0x73(void)
{
	LD_ADDR_RP_AND_OFFSET_FROM_R(IY, E);
	T_WAIT_UNTIL(15);
	return;
}

/*LD (IY+$), H*/
static void op_FD_0x74(void)
{
	LD_ADDR_RP_AND_OFFSET_FROM_R(IY, H);
	T_WAIT_UNTIL(15);
	return;
}

/*LD (IY+$), L*/
static void op_FD_0x75(void)
{
	LD_ADDR_RP_AND_OFFSET_FROM_R(IY, L);
	T_WAIT_UNTIL(15);
	return;
}

/*LD (IY+$), A*/
static void op_FD_0x77(void)
{
	LD_ADDR_RP_AND_OFFSET_FROM_R(IY, A);
	T_WAIT_UNTIL(15);
	return;
}

/*LD A, IYH*/
static void op_FD_0x7c(void)
{
	LD_R_TO_R(A, IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, IYL*/
static void op_FD_0x7d(void)
{
	LD_R_TO_R(A, IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, (IY+$)*/
static void op_FD_0x7e(void)
{
	LD_ADDR_RP_AND_OFFSET_TO_R(A, IY);
	T_WAIT_UNTIL(15);
	return;
}

/*ADD A, IYH*/
static void op_FD_0x84(void)
{
	ADD_A_AND_R(IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*ADD A, IYL*/
static void op_FD_0x85(void)
{
	ADD_A_AND_R(IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*ADD A, (IY+$)*/
static void op_FD_0x86(void)
{
	ADD_A_AND_RP_AND_OFFSET(IY);
	T_WAIT_UNTIL(15);
	return;
}

/*ADDC A, IYH*/
static void op_FD_0x8c(void)
{
	ADDC(A, IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*ADDC A, IYL*/
static void op_FD_0x8d(void)
{
	ADDC(A, IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*ADDC A, (IY+$)*/
static void op_FD_0x8e(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	ADDC(A, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*SUB IYH*/
static void op_FD_0x94(void)
{
	SUB_A_AND_R(IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*SUB IYL*/
static void op_FD_0x95(void)
{
	SUB_A_AND_R(IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*SUB (IY+$)*/
static void op_FD_0x96(void)
{
	SUB_A_AND_RP_AND_OFFSET(IY);
	T_WAIT_UNTIL(15);
	return;
}

/*SUBC A, IYH*/
static void op_FD_0x9c(void)
{
	SUBC(A, IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*SUBC A, IYL*/
static void op_FD_0x9d(void)
{
	SUBC(A, IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*SUBC A, (IY+$)*/
static void op_FD_0x9e(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SUBC(A, temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*AND IYH*/
static void op_FD_0xa4(void)
{
	AND(IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*AND IYL*/
static void op_FD_0xa5(void)
{
	AND(IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*AND (IY+$)*/
static void op_FD_0xa6(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	AND(temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*XOR IYH*/
static void op_FD_0xac(void)
{
	XOR(IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*XOR IYL*/
static void op_FD_0xad(void)
{
	XOR(IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*XOR (IY+$)*/
static void op_FD_0xae(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	XOR(temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*OR IYH*/
static void op_FD_0xb4(void)
{
	OR(IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*OR IYL*/
static void op_FD_0xb5(void)
{
	OR(IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*OR (IY+$)*/
static void op_FD_0xb6(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	OR(temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*CP IYH*/
static void op_FD_0xbc(void)
{
	CP(IYH);
	T_WAIT_UNTIL(4);
	return;
}

/*CP IYL*/
static void op_FD_0xbd(void)
{
	CP(IYL);
	T_WAIT_UNTIL(4);
	return;
}

/*CP (IY+$)*/
static void op_FD_0xbe(void)
{
	d.u=NEXT_BYTE
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	CP(temp8);
	T_WAIT_UNTIL(15);
	return;
}

/*prefix FDCB*/
static void op_FD_0xcb(void)
{
	return;
}

/*POP IY*/
static void op_FD_0xe1(void)
{
	POP(IY);
	T_WAIT_UNTIL(10);
	return;
}

/*EX (SP), IY*/
static void op_FD_0xe3(void)
{
	EX_MPTR(IY);
	T_WAIT_UNTIL(19);
	return;
}

/*PUSH IY*/
static void op_FD_0xe5(void)
{
	PUSH(IY);
	T_WAIT_UNTIL(11);
	return;
}

/*JP IY*/
static void op_FD_0xe9(void)
{
	JP_NO_MPTR(IY);
	T_WAIT_UNTIL(4);
	return;
}

/*LD SP, IY*/
static void op_FD_0xf9(void)
{
	LD_RP_TO_RP(SP, IY);
	T_WAIT_UNTIL(6);
	return;
}

/*NONI*/
static void non_FD (void)
{
	return;
}

static void (*opcode_fd[0x100])(void)={
	non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0x09, non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    ,
	non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0x19, non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    ,
	non_FD    , op_FD_0x21, op_FD_0x22, op_FD_0x23, op_FD_0x24, op_FD_0x25, op_FD_0x26, non_FD    , non_FD    , op_FD_0x29, op_FD_0x2a, op_FD_0x2b, op_FD_0x2c, op_FD_0x2d, op_FD_0x2e, non_FD    ,
	non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0x34, op_FD_0x35, op_FD_0x36, non_FD    , non_FD    , op_FD_0x39, non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    ,
	non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0x44, op_FD_0x45, op_FD_0x46, non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0x4c, op_FD_0x4d, op_FD_0x4e, non_FD    ,
	non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0x54, op_FD_0x55, op_FD_0x56, non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0x5c, op_FD_0x5d, op_FD_0x5e, non_FD    ,
	op_FD_0x60, op_FD_0x61, op_FD_0x62, op_FD_0x63, op_FD_0x64, op_FD_0x65, op_FD_0x66, op_FD_0x67, op_FD_0x68, op_FD_0x69, op_FD_0x6a, op_FD_0x6b, op_FD_0x6c, op_FD_0x6d, op_FD_0x6e, op_FD_0x6f,
	op_FD_0x70, op_FD_0x71, op_FD_0x72, op_FD_0x73, op_FD_0x74, op_FD_0x75, non_FD    , op_FD_0x77, non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0x7c, op_FD_0x7d, op_FD_0x7e, non_FD    ,
	non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0x84, op_FD_0x85, op_FD_0x86, non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0x8c, op_FD_0x8d, op_FD_0x8e, non_FD    ,
	non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0x94, op_FD_0x95, op_FD_0x96, non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0x9c, op_FD_0x9d, op_FD_0x9e, non_FD    ,
	non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0xa4, op_FD_0xa5, op_FD_0xa6, non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0xac, op_FD_0xad, op_FD_0xae, non_FD    ,
	non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0xb4, op_FD_0xb5, op_FD_0xb6, non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0xbc, op_FD_0xbd, op_FD_0xbe, non_FD    ,
	non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0xcb, non_FD    , non_FD    , non_FD    , non_FD    ,
	non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    ,
	non_FD    , op_FD_0xe1, non_FD    , op_FD_0xe3, non_FD    , op_FD_0xe5, non_FD    , non_FD    , non_FD    , op_FD_0xe9, non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    ,
	non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , op_FD_0xf9, non_FD    , non_FD    , non_FD    , non_FD    , non_FD    , non_FD
};
