/*NOP*/
static void op_0x00(void)
{
	T_WAIT_UNTIL(4);
	return;
}

/*LD BC,@*/
static void op_0x01(void)
{
	nn=NEXT_WORD;
	LD16(BC, nn);
	T_WAIT_UNTIL(10);
	return;
}

/*LD (BC), A*/
static void op_0x02(void)
{
	LD_A_TO_ADDR_MPTR(temp8, A, (BC));
	WRITE_BYTE((BC), temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*INC BC*/
static void op_0x03(void)
{
	INC16(BC);
	T_WAIT_UNTIL(6);
	return;
}

/*INC B*/
static void op_0x04(void)
{
	INC(B);
	T_WAIT_UNTIL(4);
	return;
}

/*DEC B*/
static void op_0x05(void)
{
	DEC(B);
	T_WAIT_UNTIL(4);
	return;
}

/*LD B, #*/
static void op_0x06(void)
{
	n=NEXT_BYTE;
	LD(B, n);
	T_WAIT_UNTIL(7);
	return;
}

/*RLCA*/
static void op_0x07(void)
{
	RLCA();
	T_WAIT_UNTIL(4);
	return;
}

/*EX AF, AF'*/
static void op_0x08(void)
{
	EX(AF, AF_);
	T_WAIT_UNTIL(4);
	return;
}

/*ADD HL, BC*/
static void op_0x09(void)
{
	ADD16(HL, BC);
	T_WAIT_UNTIL(11);
	return;
}

/*LD A, (BC)*/
static void op_0x0a(void)
{
	temp8=READ_BYTE(BC);
	LD_A_FROM_ADDR_MPTR(A, temp8, BC);
	T_WAIT_UNTIL(7);
	return;
}

/*DEC BC*/
static void op_0x0b(void)
{
	DEC16(BC);
	T_WAIT_UNTIL(6);
	return;
}

/*INC C*/
static void op_0x0c(void)
{
	INC(C);
	T_WAIT_UNTIL(4);
	return;
}

/*DEC C*/
static void op_0x0d(void)
{
	DEC(C);
	T_WAIT_UNTIL(4);
	return;
}

/*LD C, #*/
static void op_0x0e(void)
{
	n=NEXT_BYTE;
	LD(C, n);
	T_WAIT_UNTIL(7);
	return;
}

/*RRCA*/
static void op_0x0f(void)
{
	RRCA();
	T_WAIT_UNTIL(4);
	return;
}

/*DJNZ %*/
static void op_0x10(void)
{
	d.u=NEXT_BYTE;
	B--;
	if(B)
	{
		JR(d.s);
		T_WAIT_UNTIL(13);
	}
	else
	{
		T_WAIT_UNTIL(8);
	}
	return;
}

/*LD DE, @*/
static void op_0x11(void)
{
	nn=NEXT_WORD;
	LD16(DE, nn);
	T_WAIT_UNTIL(10);
	return;
}

/*LD (DE), A*/
static void op_0x12(void)
{
	LD_A_TO_ADDR_MPTR(temp8, A, DE);
	WRITE_BYTE(DE, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*INC DE*/
static void op_0x13(void)
{
	INC16(DE);
	T_WAIT_UNTIL(6);
	return;
}

/*INC D*/
static void op_0x14(void)
{
	INC(D);
	T_WAIT_UNTIL(4);
	return;
}

/*DEC D*/
static void op_0x15(void)
{
	DEC(D);
	T_WAIT_UNTIL(4);
	return;
}

/*LD D, #*/
static void op_0x16(void)
{
	n=NEXT_BYTE;
	LD(D, n);
	T_WAIT_UNTIL(7);
	return;
}

/*RLA*/
static void op_0x17(void)
{
	RLA();
	T_WAIT_UNTIL(4);
	return;
}

/*JR %*/
static void op_0x18(void)
{
	d.u=NEXT_BYTE;
	JR(d.s);
	T_WAIT_UNTIL(12);
	return;
}

/*ADD HL, DE*/
static void op_0x19(void)
{
	ADD16(HL, DE);
	T_WAIT_UNTIL(11);
	return;
}

/*LD A,(DE)*/
static void op_0x1a(void)
{
	temp8=READ_BYTE(DE);
	LD_A_FROM_ADDR_MPTR(A, temp8, DE);
	T_WAIT_UNTIL(7);
	return;
}

/*DEC DE*/
static void op_0x1b(void)
{
	DEC16(DE);
	T_WAIT_UNTIL(6);
	return;
}

/*INC E*/
static void op_0x1c(void)
{
	INC(E);
	T_WAIT_UNTIL(4);
	return;
}

/*DEC E*/
static void op_0x1d(void)
{
	DEC(E);
	T_WAIT_UNTIL(4);
	return;
}

/*LD E, #*/
static void op_0x1e(void)
{
	n=NEXT_BYTE;
	LD(E, n);
	T_WAIT_UNTIL(7);
	return;
}

/*RRA*/
static void op_0x1f(void)
{
	RRA();
	T_WAIT_UNTIL(4);
	return;
}

/*JR NZ, %*/
static void op_0x20(void)
{
	d.u=NEXT_BYTE;
	if(!(F&FLAG_Z))
	{
		JR(d.s);
		T_WAIT_UNTIL(12);
	}
	else
	{
		T_WAIT_UNTIL(7);
	}
	return;
}

/*LD HL, @*/
static void op_0x21(void)
{
	nn=NEXT_WORD;
	LD16(HL, nn);
	T_WAIT_UNTIL(10);
	return;
}

/*LD (@), HL*/
static void op_0x22(void)
{
	nn=NEXT_WORD;
	LD_RP_TO_ADDR_MPTR_16(temp16, HL, nn);
	WRITE_WORD(nn, temp16);
	T_WAIT_UNTIL(16);
	return;
}

/*INC HL*/
static void op_0x23(void)
{
	INC16(HL);
	T_WAIT_UNTIL(6);
	return;
}

/*INC H*/
static void op_0x24(void)
{
	INC(H);
	T_WAIT_UNTIL(4);
	return;
}

/*DEC H*/
static void op_0x25(void)
{
	DEC(H);
	T_WAIT_UNTIL(4);
	return;
}

/*LD H, #*/
static void op_0x26(void)
{
	n=NEXT_BYTE;
	LD(H, n);
	T_WAIT_UNTIL(7);
	return;
}

/*DAA*/
static void op_0x27(void)
{
	DAA();
	T_WAIT_UNTIL(4);
	return;
}

/*JR Z, %*/
static void op_0x28(void)
{
	d.u=NEXT_BYTE;
	if(F&FLAG_Z)
	{
		JR(d.s);
		T_WAIT_UNTIL(12);
	}
	else
	{
		T_WAIT_UNTIL(7);
	}
	return;
}

/*ADD HL, HL*/
static void op_0x29(void)
{
	ADD16(HL, HL);
	T_WAIT_UNTIL(11);
	return;
}

/*LD HL, (@)*/
static void op_0x2a(void)
{
	nn=NEXT_WORD;
	temp16=READ_WORD(nn);
	LD_RP_FROM_ADDR_MPTR_16(HL, temp16, nn);
	T_WAIT_UNTIL(16);
	return;
}

/*DEC HL*/
static void op_0x2b(void)
{
	DEC16(HL);
	T_WAIT_UNTIL(6);
	return;
}

/*INC L*/
static void op_0x2c(void)
{
	INC(L);
	T_WAIT_UNTIL(4);
	return;
}

/*DEC L*/
static void op_0x2d(void)
{
	DEC(L);
	T_WAIT_UNTIL(4);
	return;
}

/*LD L, #*/
static void op_0x2e(void)
{
	n=NEXT_BYTE;
	LD(L, n);
	T_WAIT_UNTIL(7);
	return;
}

/*CPL*/
static void op_0x2f(void)
{
	CPL();
	T_WAIT_UNTIL(4);
	return;
}

/*JR NC, %*/
static void op_0x30(void)
{
	d.u=NEXT_BYTE;
	if(!(F&FLAG_C))
	{
		JR(d.s);
		T_WAIT_UNTIL(12);
	}
	else
	{
		T_WAIT_UNTIL(7);
	}
	return;
}

/*LD SP, @*/
static void op_0x31(void)
{
	nn=NEXT_WORD;
	LD16(SP, nn);
	T_WAIT_UNTIL(10);
	return;
}

/*LD (@), A*/
static void op_0x32(void)
{
	nn=NEXT_WORD;
	LD_A_TO_ADDR_MPTR(temp8, A, nn);
	WRITE_BYTE(nn, temp8);
	T_WAIT_UNTIL(13);
	return;
}

/*INC SP*/
static void op_0x33(void)
{
	INC16(SP);
	T_WAIT_UNTIL(6);
	return;
}

/*INC (HL)*/
static void op_0x34(void)
{
	temp8=READ_BYTE(HL);
	INC(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
	return;
}

/*DEC (HL)*/
static void op_0x35(void)
{
	temp8=READ_BYTE(HL);
	DEC(temp8);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(11);
	return;
}

/*LD (HL), #*/
static void op_0x36(void)
{
	n=NEXT_BYTE;
	LD(n, n);
	WRITE_BYTE(HL, n);
	T_WAIT_UNTIL(10);
	return;
}

/*SCF*/
static void op_0x37(void)
{
	SCF();
	T_WAIT_UNTIL(4);
	return;
}

/*JR C, %*/
static void op_0x38(void)
{
	d.u=NEXT_BYTE;
	if(F&FLAG_C)
	{
		JR(d.s);
		T_WAIT_UNTIL(12);
	}
	else
	{
		T_WAIT_UNTIL(7);
	}
	return;
}

/*ADD HL, SP*/
static void op_0x39(void)
{
	ADD16(HL, SP);
	T_WAIT_UNTIL(11);
	return;
}

/*LD A, (@)*/
static void op_0x3a(void)
{
	nn=NEXT_WORD;
	temp8=READ_BYTE(nn);
	LD_A_FROM_ADDR_MPTR(A, temp8, nn);
	T_WAIT_UNTIL(13);
	return;
}

/*DEC SP*/
static void op_0x3b(void)
{
	DEC16(SP);
	T_WAIT_UNTIL(6);
	return;
}

/*INC A*/
static void op_0x3c(void)
{
	INC(A);
	T_WAIT_UNTIL(4);
	return;
}

/*DEC A*/
static void op_0x3d(void)
{
	DEC(A);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, #*/
static void op_0x3e(void)
{
	n=NEXT_BYTE;
	LD(A, n);
	T_WAIT_UNTIL(7);
	return;
}

/*CCF*/
static void op_0x3f(void)
{
	CCF();
	T_WAIT_UNTIL(4);
	return;
}

/*LD B, B*/
static void op_0x40(void)
{
	LD(B, B);
	T_WAIT_UNTIL(4);
	return;
}

/*LD B, C*/
static void op_0x41(void)
{
	LD(B, C);
	T_WAIT_UNTIL(4);
	return;
}

/*LD B, D*/
static void op_0x42(void)
{
	LD(B, D);
	T_WAIT_UNTIL(4);
	return;
}

/*LD B, E*/
static void op_0x43(void)
{
	LD(B, E);
	T_WAIT_UNTIL(4);
	return;
}

/*LD B, H*/
static void op_0x44(void)
{
	LD(B, H);
	T_WAIT_UNTIL(4);
	return;
}

/*LD B, L*/
static void op_0x45(void)
{
	LD(B, L);
	T_WAIT_UNTIL(4);
	return;
}

/*LD B, (HL)*/
static void op_0x46(void)
{
	temp8=READ_BYTE(HL);
	LD(B, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD B, A*/
static void op_0x47(void)
{
	LD(B, A);
	T_WAIT_UNTIL(4);
	return;
}

/*LD C, B*/
static void op_0x48(void)
{
	LD(C, B);
	T_WAIT_UNTIL(4);
	return;
}

/*LD C, C*/
static void op_0x49(void)
{
	LD(C, C);
	T_WAIT_UNTIL(4);
	return;
}

/*LD C, D*/
static void op_0x4a(void)
{
	LD(C, D);
	T_WAIT_UNTIL(4);
	return;
}

/*LD C, E*/
static void op_0x4b(void)
{
	LD(C, E);
	T_WAIT_UNTIL(4);
	return;
}

/*LD C, H*/
static void op_0x4c(void)
{
	LD(C, H);
	T_WAIT_UNTIL(4);
	return;
}

/*LD C, L*/
static void op_0x4d(void)
{
	LD(C, L);
	T_WAIT_UNTIL(4);
	return;
}

/*LD C, (HL)*/
static void op_0x4e(void)
{
	temp8=READ_BYTE(HL);
	LD(C, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD C, A*/
static void op_0x4f(void)
{
	LD(C, A);
	T_WAIT_UNTIL(4);
	return;
}

/*LD D, B*/
static void op_0x50(void)
{
	LD(D, B);
	T_WAIT_UNTIL(4);
	return;
}

/*LD D, C*/
static void op_0x51(void)
{
	LD(D, C);
	T_WAIT_UNTIL(4);
	return;
}

/*LD D, D*/
static void op_0x52(void)
{
	LD(D, D);
	T_WAIT_UNTIL(4);
	return;
}

/*LD D, E*/
static void op_0x53(void)
{
	LD(D, E);
	T_WAIT_UNTIL(4);
	return;
}

/*LD D, H*/
static void op_0x54(void)
{
	LD(D, H);
	T_WAIT_UNTIL(4);
	return;
}

/*LD D, L*/
static void op_0x55(void)
{
	LD(D, L);
	T_WAIT_UNTIL(4);
	return;
}

/*LD D, (HL)*/
static void op_0x56(void)
{
	temp8=READ_BYTE(HL);
	LD(D, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD D, A*/
static void op_0x57(void)
{
	LD(D, A);
	T_WAIT_UNTIL(4);
	return;
}

/*LD E, B*/
static void op_0x58(void)
{
	LD(E, B);
	T_WAIT_UNTIL(4);
	return;
}

/*LD E, C*/
static void op_0x59(void)
{
	LD(E, C);
	T_WAIT_UNTIL(4);
	return;
}

/*LD E, D*/
static void op_0x5a(void)
{
	LD(E, D);
	T_WAIT_UNTIL(4);
	return;
}

/*LD E, E*/
static void op_0x5b(void)
{
	LD(E, E);
	T_WAIT_UNTIL(4);
	return;
}

/*LD E, H*/
static void op_0x5c(void)
{
	LD(E, H);
	T_WAIT_UNTIL(4);
	return;
}

/*LD E, L*/
static void op_0x5d(void)
{
	LD(E, L);
	T_WAIT_UNTIL(4);
	return;
}

/*LD E, (HL)*/
static void op_0x5e(void)
{
	temp8=READ_BYTE(HL);
	LD(E, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD E, A*/
static void op_0x5f(void)
{
	LD(E, A);
	T_WAIT_UNTIL(4);
	return;
}

/*LD H, B*/
static void op_0x60(void)
{
	LD(H, B);
	T_WAIT_UNTIL(4);
	return;
}

/*LD H, C*/
static void op_0x61(void)
{
	LD(H, C);
	T_WAIT_UNTIL(4);
	return;
}

/*LD H, D*/
static void op_0x62(void)
{
	LD(H, D);
	T_WAIT_UNTIL(4);
	return;
}

/*LD H, E*/
static void op_0x63(void)
{
	LD(H, E);
	T_WAIT_UNTIL(4);
	return;
}

/*LD H, H*/
static void op_0x64(void)
{
	LD(H, H);
	T_WAIT_UNTIL(4);
	return;
}

/*LD H, L*/
static void op_0x65(void)
{
	LD(H, L);
	T_WAIT_UNTIL(4);
	return;
}

/*LD H, (HL)*/
static void op_0x66(void)
{
	temp8=READ_BYTE(HL);
	LD(H, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD H, A*/
static void op_0x67(void)
{
	LD(H, A);
	T_WAIT_UNTIL(4);
	return;
}

/*LD L, B*/
static void op_0x68(void)
{
	LD(L, B);
	T_WAIT_UNTIL(4);
	return;
}

/*LD L, C*/
static void op_0x69(void)
{
	LD(L, C);
	T_WAIT_UNTIL(4);
	return;
}

/*LD L, D*/
static void op_0x6a(void)
{
	LD(L, D);
	T_WAIT_UNTIL(4);
	return;
}

/*LD L, E*/
static void op_0x6b(void)
{
	LD(L, E);
	T_WAIT_UNTIL(4);
	return;
}

/*LD L, H*/
static void op_0x6c(void)
{
	LD(L, H);
	T_WAIT_UNTIL(4);
	return;
}

/*LD L, L*/
static void op_0x6d(void)
{
	LD(L, L);
	T_WAIT_UNTIL(4);
	return;
}

/*LD L, (HL)*/
static void op_0x6e(void)
{
	temp8=READ_BYTE(HL);
	LD(L, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD L, A*/
static void op_0x6f(void)
{
	LD(L, A);
	T_WAIT_UNTIL(4);
	return;
}

/*LD (HL), B*/
static void op_0x70(void)
{
	LD(temp8, B);
	WRITE_BYTE((HL), temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD (HL), C*/
static void op_0x71(void)
{
	LD(temp8, C);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD (HL), D*/
static void op_0x72(void)
{
	LD(temp8, D);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD (HL), E*/
static void op_0x73(void)
{
	LD(temp8, E);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD (HL), H*/
static void op_0x74(void)
{
	LD(temp8, H);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD (HL), L*/
static void op_0x75(void)
{
	LD(temp8, L);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*HALT*/
static void op_0x76(void)
{
	HALT();
	T_WAIT_UNTIL(4);
	return;
}

/*LD (HL), A*/
static void op_0x77(void)
{
	LD(temp8, A);
	WRITE_BYTE(HL, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD A, B*/
static void op_0x78(void)
{
	LD(A, B);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, C*/
static void op_0x79(void)
{
	LD(A, C);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, D*/
static void op_0x7a(void)
{
	LD(A, D);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, E*/
static void op_0x7b(void)
{
	LD(A, E);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, H*/
static void op_0x7c(void)
{
	LD(A, H);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, L*/
static void op_0x7d(void)
{
	LD(A, L);
	T_WAIT_UNTIL(4);
	return;
}

/*LD A, (HL)*/
static void op_0x7e(void)
{
	temp8=READ_BYTE(HL);
	LD(A, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*LD A, A*/
static void op_0x7f(void)
{
	LD(A, A);
	T_WAIT_UNTIL(4);
	return;
}

/*ADD A, B*/
static void op_0x80(void)
{
	ADD(A, B);
	T_WAIT_UNTIL(4);
	return;
}

/*ADD A, C*/
static void op_0x81(void)
{
	ADD(A, C);
	T_WAIT_UNTIL(4);
	return;
}

/*ADD A, D*/
static void op_0x82(void)
{
	ADD(A, D);
	T_WAIT_UNTIL(4);
	return;
}

/*ADD A, E*/
static void op_0x83(void)
{
	ADD(A, E);
	T_WAIT_UNTIL(4);
	return;
}

/*ADD A, H*/
static void op_0x84(void)
{
	ADD(A, H);
	T_WAIT_UNTIL(4);
	return;
}

/*ADD A, L*/
static void op_0x85(void)
{
	ADD(A, L);
	T_WAIT_UNTIL(4);
	return;
}

/*ADD A, (HL)*/
static void op_0x86(void)
{
	temp8=READ_BYTE(HL);
	ADD(A, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*ADD A, A*/
static void op_0x87(void)
{
	ADD(A, A);
	T_WAIT_UNTIL(4);
	return;
}

/*ADDC A, B*/
static void op_0x88(void)
{
	ADDC(A, B);
	T_WAIT_UNTIL(4);
	return;
}

/*ADDC A, C*/
static void op_0x89(void)
{
	ADDC(A, C);
	T_WAIT_UNTIL(4);
	return;
}

/*ADDC A, D*/
static void op_0x8a(void)
{
	ADDC(A, D);
	T_WAIT_UNTIL(4);
	return;
}

/*ADDC A, E*/
static void op_0x8b(void)
{
	ADDC(A, E);
	T_WAIT_UNTIL(4);
	return;
}

/*ADDC A, H*/
static void op_0x8c(void)
{
	ADDC(A, H);
	T_WAIT_UNTIL(4);
	return;
}

/*ADDC A, L*/
static void op_0x8d(void)
{
	ADDC(A, L);
	T_WAIT_UNTIL(4);
	return;
}

/*ADDC A, (HL)*/
static void op_0x8e(void)
{
	temp8=READ_BYTE(HL);
	ADDC(A, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*ADDC A, A*/
static void op_0x8f(void)
{
	ADDC(A, A);
	T_WAIT_UNTIL(4);
	return;
}

/*SUB B*/
static void op_0x90(void)
{
	SUB(B);
	T_WAIT_UNTIL(4);
	return;
}

/*SUB C*/
static void op_0x91(void)
{
	SUB(C);
	T_WAIT_UNTIL(4);
	return;
}

/*SUB D*/
static void op_0x92(void)
{
	SUB(D);
	T_WAIT_UNTIL(4);
	return;
}

/*SUB E*/
static void op_0x93(void)
{
	SUB(E);
	T_WAIT_UNTIL(4);
	return;
}

/*SUB H*/
static void op_0x94(void)
{
	SUB(H);
	T_WAIT_UNTIL(4);
	return;
}

/*SUB L*/
static void op_0x95(void)
{
	SUB(L);
	T_WAIT_UNTIL(4);
	return;
}

/*SUB (HL)*/
static void op_0x96(void)
{
	temp8=READ_BYTE(HL);
	SUB(temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*SUB A*/
static void op_0x97(void)
{
	SUB(A);
	T_WAIT_UNTIL(4);
	return;
}

/*SUBC A, B*/
static void op_0x98(void)
{
	SUBC(A, B);
	T_WAIT_UNTIL(4);
	return;
}

/*SUBC A, C*/
static void op_0x99(void)
{
	SUBC(A, C);
	T_WAIT_UNTIL(4);
	return;
}

/*SUBC A, D*/
static void op_0x9a(void)
{
	SUBC(A, D);
	T_WAIT_UNTIL(4);
	return;
}

/*SUBC A, E*/
static void op_0x9b(void)
{
	SUBC(A, E);
	T_WAIT_UNTIL(4);
	return;
}

/*SUBC A, H*/
static void op_0x9c(void)
{
	SUBC(A, H);
	T_WAIT_UNTIL(4);
	return;
}

/*SUBC A, L*/
static void op_0x9d(void)
{
	SUBC(A, L);
	T_WAIT_UNTIL(4);
	return;
}

/*SUBC A, (HL)*/
static void op_0x9e(void)
{
	temp8=READ_BYTE(HL);
	SUBC(A, temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*SUBC A, A*/
static void op_0x9f(void)
{
	SUBC(A, A);
	T_WAIT_UNTIL(4);
	return;
}

/*AND B*/
static void op_0xa0(void)
{
	AND(B);
	T_WAIT_UNTIL(4);
	return;
}

/*AND C*/
static void op_0xa1(void)
{
	AND(C);
	T_WAIT_UNTIL(4);
	return;
}

/*AND D*/
static void op_0xa2(void)
{
	AND(D);
	T_WAIT_UNTIL(4);
	return;
}

/*AND E*/
static void op_0xa3(void)
{
	AND(E);
	T_WAIT_UNTIL(4);
	return;
}

/*AND H*/
static void op_0xa4(void)
{
	AND(H);
	T_WAIT_UNTIL(4);
	return;
}

/*AND L*/
static void op_0xa5(void)
{
	AND(L);
	T_WAIT_UNTIL(4);
	return;
}

/*AND (HL)*/
static void op_0xa6(void)
{
	temp8=READ_BYTE(HL);
	AND(temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*AND A*/
static void op_0xa7(void)
{
	AND(A);
	T_WAIT_UNTIL(4);
	return;
}

/*XOR B*/
static void op_0xa8(void)
{
	XOR(B);
	T_WAIT_UNTIL(4);
	return;
}

/*XOR C*/
static void op_0xa9(void)
{
	XOR(C);
	T_WAIT_UNTIL(4);
	return;
}

/*XOR D*/
static void op_0xaa(void)
{
	XOR(D);
	T_WAIT_UNTIL(4);
	return;
}

/*XOR E*/
static void op_0xab(void)
{
	XOR(E);
	T_WAIT_UNTIL(4);
	return;
}

/*XOR H*/
static void op_0xac(void)
{
	XOR(H);
	T_WAIT_UNTIL(4);
	return;
}

/*XOR L*/
static void op_0xad(void)
{
	XOR(L);
	T_WAIT_UNTIL(4);
	return;
}

/*XOR (HL)*/
static void op_0xae(void)
{
	temp8=READ_BYTE(HL);
	XOR(temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*XOR A*/
static void op_0xaf(void)
{
	XOR(A);
	T_WAIT_UNTIL(4);
	return;
}

/*OR B*/
static void op_0xb0(void)
{
	OR(B);
	T_WAIT_UNTIL(4);
	return;
}

/*OR C*/
static void op_0xb1(void)
{
	OR(C);
	T_WAIT_UNTIL(4);
	return;
}

/*OR D*/
static void op_0xb2(void)
{
	OR(D);
	T_WAIT_UNTIL(4);
	return;
}

/*OR E*/
static void op_0xb3(void)
{
	OR(E);
	T_WAIT_UNTIL(4);
	return;
}

/*OR H*/
static void op_0xb4(void)
{
	OR(H);
	T_WAIT_UNTIL(4);
	return;
}

/*OR L*/
static void op_0xb5(void)
{
	OR(L);
	T_WAIT_UNTIL(4);
	return;
}

/*OR (HL)*/
static void op_0xb6(void)
{
	temp8=READ_BYTE(HL);
	OR(temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*OR A*/
static void op_0xb7(void)
{
	OR(A);
	T_WAIT_UNTIL(4);
	return;
}

/*CP B*/
static void op_0xb8(void)
{
	CP(B);
	T_WAIT_UNTIL(4);
	return;
}

/*CP C*/
static void op_0xb9(void)
{
	CP(C);
	T_WAIT_UNTIL(4);
	return;
}

/*CP D*/
static void op_0xba(void)
{
	CP(D);
	T_WAIT_UNTIL(4);
	return;
}

/*CP E*/
static void op_0xbb(void)
{
	CP(E);
	T_WAIT_UNTIL(4);
	return;
}

/*CP H*/
static void op_0xbc(void)
{
	CP(H);
	T_WAIT_UNTIL(4);
	return;
}

/*CP L*/
static void op_0xbd(void)
{
	CP(L);
	T_WAIT_UNTIL(4);
	return;
}

/*CP (HL)*/
static void op_0xbe(void)
{
	temp8=READ_BYTE(HL);
	CP(temp8);
	T_WAIT_UNTIL(7);
	return;
}

/*CP A*/
static void op_0xbf(void)
{
	CP(A);
	T_WAIT_UNTIL(4);
	return;
}

/*RET NZ*/
static void op_0xc0(void)
{
	if(!(F&FLAG_Z))
	{
		RET();
		T_WAIT_UNTIL(11);
	}
	else
	{
		T_WAIT_UNTIL(5);
	}
	return;
}

/*POP BC*/
static void op_0xc1(void)
{
	POP(BC);
	T_WAIT_UNTIL(10);
	return;
}

/*JP NZ, @*/
static void op_0xc2(void)
{
	nn=NEXT_WORD;
	if(!(F&FLAG_Z))
	{
		JP(nn);
		T_WAIT_UNTIL(10);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

/*JP @*/
static void op_0xc3(void)
{
	nn=NEXT_WORD;
	JP(nn);
	T_WAIT_UNTIL(10);
	return;
}

/*CALL NZ, @*/
static void op_0xc4(void)
{
	nn=NEXT_WORD;
	if(!(F&FLAG_Z))
	{
		CALL(nn);
		T_WAIT_UNTIL(17);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

/*PUSH BC*/
static void op_0xc5(void)
{
	PUSH(BC);
	T_WAIT_UNTIL(11);
	return;
}

/*ADD A, #*/
static void op_0xc6(void)
{
	n=NEXT_BYTE;
	ADD(A, n);
	T_WAIT_UNTIL(7);
	return;
}

/*RST 0x00*/
static void op_0xc7(void)
{
	RST(0x00);
	T_WAIT_UNTIL(11);
	return;
}

/*RET Z*/
static void op_0xc8(void)
{
	if(F&FLAG_Z)
	{
		RET();
		T_WAIT_UNTIL(11);
	}
	else
	{
		T_WAIT_UNTIL(5);
	}
	return;
}

/*RET*/
static void op_0xc9(void)
{
	RET();
	T_WAIT_UNTIL(10);
	return;
}

/*JP Z, @*/
static void op_0xca(void)
{
	nn=NEXT_WORD;
	if(F&FLAG_Z)
	{
		JP(nn);
		T_WAIT_UNTIL(10);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

static void op_0xcb(void)
{
	prefix=0xCB;
	no_int=1;
	return;
}

/*CALL Z, @*/
static void op_0xcc(void)
{
	nn=NEXT_WORD;
	if(F&FLAG_Z)
	{
		CALL(nn);
		T_WAIT_UNTIL(17);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

/*CALL @*/
static void op_0xcd(void)
{
	nn=NEXT_WORD;
	CALL(nn);
	T_WAIT_UNTIL(17);
	return;
}

/*ADDC A, #*/
static void op_0xce(void)
{
	n=NEXT_BYTE;
	ADDC(A, n);
	T_WAIT_UNTIL(7);
	return;
}

/*RST 0x08*/
static void op_0xcf(void)
{
	RST(0x08);
	T_WAIT_UNTIL(11);
	return;
}

/*RET NC*/
static void op_0xd0(void)
{
	if(!(F&FLAG_C))
	{
		RET();
		T_WAIT_UNTIL(11);
	}
	else
	{
		T_WAIT_UNTIL(5);
	}
	return;
}

/*POP DE*/
static void op_0xd1(void)
{
	POP(DE);
	T_WAIT_UNTIL(10);
	return;
}

/*JP NC, @*/
static void op_0xd2(void)
{
	nn=NEXT_WORD;
	if(!(F&FLAG_C))
	{
		JP(nn);
		T_WAIT_UNTIL(10);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

/*OUT (#), A*/
static void op_0xd3(void)
{
	n=NEXT_BYTE;
	temp16=(n+(A<<8));
	OUT_A(temp16, A);
	T_WAIT_UNTIL(11);
	return;
}

/*CALL NC, @*/
static void op_0xd4(void)
{
	nn=NEXT_WORD;
	if(!(F&FLAG_C))
	{
		CALL(nn);
		T_WAIT_UNTIL(17);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

/*PUSH DE*/
static void op_0xd5(void)
{
	PUSH(DE);
	T_WAIT_UNTIL(11);
	return;
}

/*SUB #*/
static void op_0xd6(void)
{
	n=NEXT_BYTE;
	SUB(n);
	T_WAIT_UNTIL(7);
	return;
}

/*RST 0x10*/
static void op_0xd7(void)
{
	RST(0x10);
	T_WAIT_UNTIL(11);
	return;
}

/*RET C*/
static void op_0xd8(void)
{
	if(F&FLAG_C)
	{
		RET();
		T_WAIT_UNTIL(11);
	}
	else
	{
		T_WAIT_UNTIL(5);
	}
	return;
}

/*EXX*/
static void op_0xd9(void)
{
	EXX();
	T_WAIT_UNTIL(4);
	return;
}

/*JP C, @*/
static void op_0xda(void)
{
	nn=NEXT_WORD;
	if(F&FLAG_C)
	{
		JP(nn);
		T_WAIT_UNTIL(10);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

/*IN A,(#)*/
static void op_0xdb(void)
{
	n=NEXT_BYTE;
	temp16=(n+(A<<8));
	IN_A(A, temp16);
	T_WAIT_UNTIL(11);
	return;
}

/*CALL C, @*/
static void op_0xdc(void)
{
	nn=NEXT_WORD;
	if(F&FLAG_C)
	{
		CALL(nn);
		T_WAIT_UNTIL(17);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

static void op_0xdd(void)
{
	prefix=0xDD;
	no_int=1;
	return;
}

/*SUBC A, #*/
static void op_0xde(void)
{
	n=NEXT_BYTE;
	SUBC(A, n);
	T_WAIT_UNTIL(7);
	return;
}

/*RST 0x18*/
static void op_0xdf(void)
{
	RST(0x18);
	T_WAIT_UNTIL(11);
	return;
}

/*RET PO*/
static void op_0xe0(void)
{
	if(!(F&FLAG_P))
	{
		RET();
		T_WAIT_UNTIL(11);
	}
	else
	{
		T_WAIT_UNTIL(5);
	}
	return;
}

/*POP HL*/
static void op_0xe1(void)
{
	POP(HL);
	T_WAIT_UNTIL(10);
	return;
}

/*JP PO, @*/
static void op_0xe2(void)
{
	nn=NEXT_WORD;
	if(!(F&FLAG_P))
	{
		JP(nn);
		T_WAIT_UNTIL(10);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

/*EX (SP), HL*/
static void op_0xe3(void)
{
	temp16=READ_WORD(SP);
	EX_MPTR(temp16, HL);
	WRITE_WORD((SP), temp16);
	T_WAIT_UNTIL(19);
	return;
}

/*CALL PO, @*/
static void op_0xe4(void)
{
	nn=NEXT_WORD;
	if(!(F&FLAG_P))
	{
		CALL(nn);
		T_WAIT_UNTIL(17);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

/*PUSH HL*/
static void op_0xe5(void)
{
	PUSH(HL);
	T_WAIT_UNTIL(11);
	return;
}

/*AND #*/
static void op_0xe6(void)
{
	n=NEXT_BYTE;
	AND(n);
	T_WAIT_UNTIL(7);
	return;
}

/*RST 0x20*/
static void op_0xe7(void)
{
	RST(0x20);
	T_WAIT_UNTIL(11);
	return;
}

/*RET PE*/
static void op_0xe8(void)
{
	if(F&FLAG_P)
	{
		RET();
		T_WAIT_UNTIL(11);
	}
	else
	{
		T_WAIT_UNTIL(5);
	}
	return;
}

/*JP HL*/
static void op_0xe9(void)
{
	JP_NO_MPTR(HL);
	T_WAIT_UNTIL(4);
	return;
}

/*JP PE, @*/
static void op_0xea(void)
{
	nn=NEXT_WORD;
	if(F&FLAG_P)
	{
		JP(nn);
		T_WAIT_UNTIL(10);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

/*EX DE, HL*/
static void op_0xeb(void)
{
	EX(DE, HL);
	T_WAIT_UNTIL(4);
	return;
}

/*CALL PE, @*/
static void op_0xec(void)
{
	nn=NEXT_WORD;
	if(F&FLAG_P)
	{
		CALL(nn);
		T_WAIT_UNTIL(17);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

static void op_0xed(void)
{
	prefix=0xED;
	no_int=1;
	return;
}

/*XOR #*/
static void op_0xee(void)
{
	n=NEXT_BYTE;
	XOR(n);
	T_WAIT_UNTIL(7);
	return;
}

/*RST 0x28*/
static void op_0xef(void)
{
	RST(0x28);
	T_WAIT_UNTIL(11);
	return;
}

/*RET P*/
static void op_0xf0(void)
{
	if(!(F&FLAG_S))
	{
		RET();
		T_WAIT_UNTIL(11);
	}
	else
	{
		T_WAIT_UNTIL(5);
	}
	return;
}

/*POP AF*/
static void op_0xf1(void)
{
	POP(AF);
	T_WAIT_UNTIL(10);
	return;
}

/*JP P, @*/
static void op_0xf2(void)
{
	nn=NEXT_WORD;
	if(!(F&FLAG_S))
	{
		JP(nn);
		T_WAIT_UNTIL(10);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

/*DI*/
static void op_0xf3(void)
{
	DI();
	T_WAIT_UNTIL(4);
	return;
}

/*CALL P, @*/
static void op_0xf4(void)
{
	nn=NEXT_WORD;
	if(!(F&FLAG_S))
	{
		CALL(nn);
		T_WAIT_UNTIL(17);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

/*PUSH AF*/
static void op_0xf5(void)
{
	PUSH(AF);
	T_WAIT_UNTIL(11);
	return;
}

/*OR #*/
static void op_0xf6(void)
{
	n=NEXT_BYTE;
	OR(n);
	T_WAIT_UNTIL(7);
	return;
}

/*RST 0x30*/
static void op_0xf7(void)
{
	RST(0x30);
	T_WAIT_UNTIL(11);
	return;
}

/*RET M*/
static void op_0xf8(void)
{
	if(F&FLAG_S)
	{
		RET();
		T_WAIT_UNTIL(11);
	}
	else
	{
		T_WAIT_UNTIL(5);
	}
	return;
}

/*LD SP, HL*/
static void op_0xf9(void)
{
	LD16(SP, HL);
	T_WAIT_UNTIL(6);
	return;
}

/*JP M, @*/
static void op_0xfa(void)
{
	nn=NEXT_WORD;
	if(F&FLAG_S)
	{
		JP(nn);
		T_WAIT_UNTIL(10);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

/*EI*/
static void op_0xfb(void)
{
	EI();
	T_WAIT_UNTIL(4);
	return;
}

/*CALL M, @*/
static void op_0xfc(void)
{
	nn=NEXT_WORD;
	if(F&FLAG_S)
	{
		CALL(nn);
		T_WAIT_UNTIL(17);
	}
	else
	{
		MEMPTR=nn;
		T_WAIT_UNTIL(10);
	}
	return;
}

static void op_0xfd(void)
{
	prefix=0xFD;
	no_int=1;
	return;
}

/*CP #*/
static void op_0xfe(void)
{
	n=NEXT_BYTE;
	CP(n);
	T_WAIT_UNTIL(7);
	return;
}

/*RST 0x38*/
static void op_0xff(void)
{
	RST(0x38);
	T_WAIT_UNTIL(11);
	return;
}

static void (*opcode_base [0x100])(void)={
	op_0x00, op_0x01, op_0x02, op_0x03, op_0x04, op_0x05, op_0x06, op_0x07, op_0x08, op_0x09, op_0x0a, op_0x0b, op_0x0c, op_0x0d, op_0x0e, op_0x0f,
	op_0x10, op_0x11, op_0x12, op_0x13, op_0x14, op_0x15, op_0x16, op_0x17, op_0x18, op_0x19, op_0x1a, op_0x1b, op_0x1c, op_0x1d, op_0x1e, op_0x1f,
	op_0x20, op_0x21, op_0x22, op_0x23, op_0x24, op_0x25, op_0x26, op_0x27, op_0x28, op_0x29, op_0x2a, op_0x2b, op_0x2c, op_0x2d, op_0x2e, op_0x2f,
	op_0x30, op_0x31, op_0x32, op_0x33, op_0x34, op_0x35, op_0x36, op_0x37, op_0x38, op_0x39, op_0x3a, op_0x3b, op_0x3c, op_0x3d, op_0x3e, op_0x3f,
	op_0x40, op_0x41, op_0x42, op_0x43, op_0x44, op_0x45, op_0x46, op_0x47, op_0x48, op_0x49, op_0x4a, op_0x4b, op_0x4c, op_0x4d, op_0x4e, op_0x4f,
	op_0x50, op_0x51, op_0x52, op_0x53, op_0x54, op_0x55, op_0x56, op_0x57, op_0x58, op_0x59, op_0x5a, op_0x5b, op_0x5c, op_0x5d, op_0x5e, op_0x5f,
	op_0x60, op_0x61, op_0x62, op_0x63, op_0x64, op_0x65, op_0x66, op_0x67, op_0x68, op_0x69, op_0x6a, op_0x6b, op_0x6c, op_0x6d, op_0x6e, op_0x6f,
	op_0x70, op_0x71, op_0x72, op_0x73, op_0x74, op_0x75, op_0x76, op_0x77, op_0x78, op_0x79, op_0x7a, op_0x7b, op_0x7c, op_0x7d, op_0x7e, op_0x7f,
	op_0x80, op_0x81, op_0x82, op_0x83, op_0x84, op_0x85, op_0x86, op_0x87, op_0x88, op_0x89, op_0x8a, op_0x8b, op_0x8c, op_0x8d, op_0x8e, op_0x8f,
	op_0x90, op_0x91, op_0x92, op_0x93, op_0x94, op_0x95, op_0x96, op_0x97, op_0x98, op_0x99, op_0x9a, op_0x9b, op_0x9c, op_0x9d, op_0x9e, op_0x9f,
	op_0xa0, op_0xa1, op_0xa2, op_0xa3, op_0xa4, op_0xa5, op_0xa6, op_0xa7,	op_0xa8, op_0xa9, op_0xaa, op_0xab, op_0xac, op_0xad, op_0xae, op_0xaf,
	op_0xb0, op_0xb1, op_0xb2, op_0xb3, op_0xb4, op_0xb5, op_0xb6, op_0xb7, op_0xb8, op_0xb9, op_0xba, op_0xbb, op_0xbc, op_0xbd, op_0xbe, op_0xbf,
	op_0xc0, op_0xc1, op_0xc2, op_0xc3, op_0xc4, op_0xc5, op_0xc6, op_0xc7, op_0xc8, op_0xc9, op_0xca, op_0xcb, op_0xcc, op_0xcd, op_0xce, op_0xcf,
	op_0xd0, op_0xd1, op_0xd2, op_0xd3, op_0xd4, op_0xd5, op_0xd6, op_0xd7, op_0xd8, op_0xd9, op_0xda, op_0xdb, op_0xdc, op_0xdd, op_0xde, op_0xdf,
	op_0xe0, op_0xe1, op_0xe2, op_0xe3, op_0xe4, op_0xe5, op_0xe6, op_0xe7, op_0xe8, op_0xe9, op_0xea, op_0xeb, op_0xec, op_0xed, op_0xee, op_0xef,
	op_0xf0, op_0xf1, op_0xf2, op_0xf3, op_0xf4, op_0xf5, op_0xf6, op_0xf7, op_0xf8, op_0xf9, op_0xfa, op_0xfb, op_0xfc, op_0xfd, op_0xfe, op_0xff
};
