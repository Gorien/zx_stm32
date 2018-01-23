/*
 *
 *	Author: Beloussov Yegor
 *	Created on: january 2018
 *
 *	The program emulating the work of the processor z80
 *	Attention! this part must be included in the main program code
 *
 */


/*LD B, RLC (IX+$)*/
static void op_DDCB_0x00(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RLC (IX+$)*/
static void op_DDCB_0x01(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RLC (IX+$)*/
static void op_DDCB_0x02(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RLC (IX+$)*/
static void op_DDCB_0x03(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RLC (IX+$)*/
static void op_DDCB_0x04(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RLC (IX+$)*/
static void op_DDCB_0x05(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RLC (IX+$)*/
static void op_DDCB_0x06(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RLC (IX+$)*/
static void op_DDCB_0x07(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RLC(temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RRC (IX+$)*/
static void op_DDCB_0x08(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RRC (IX+$)*/
static void op_DDCB_0x09(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RRC (IX+$)*/
static void op_DDCB_0x0a(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RRC (IX+$)*/
static void op_DDCB_0x0b(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RRC (IX+$)*/
static void op_DDCB_0x0c(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RRC (IX+$)*/
static void op_DDCB_0x0d(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RRC (IX+$)*/
static void op_DDCB_0x0e(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RRC (IX+$)*/
static void op_DDCB_0x0f(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RRC(temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RL (IX+$)*/
static void op_DDCB_0x10(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RL (IX+$)*/
static void op_DDCB_0x11(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RL (IX+$)*/
static void op_DDCB_0x12(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RL (IX+$)*/
static void op_DDCB_0x13(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RL (IX+$)*/
static void op_DDCB_0x14(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RL (IX+$)*/
static void op_DDCB_0x15(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RL (IX+$)*/
static void op_DDCB_0x16(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RL (IX+$)*/
static void op_DDCB_0x17(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RL(temp8);
	LD16(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RR (IX+$)*/
static void op_DDCB_0x18(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RR (IX+$)*/
static void op_DDCB_0x19(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RR (IX+$)*/
static void op_DDCB_0x1a(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RR (IX+$)*/
static void op_DDCB_0x1b(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RR (IX+$)*/
static void op_DDCB_0x1c(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RR (IX+$)*/
static void op_DDCB_0x1d(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RR (IX+$)*/
static void op_DDCB_0x1e(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RR (IX+$)*/
static void op_DDCB_0x1f(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RR(temp8);
	LD16(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SLA (IX+$)*/
static void op_DDCB_0x20(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SLA (IX+$)*/
static void op_DDCB_0x21(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SLA (IX+$)*/
static void op_DDCB_0x22(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SLA (IX+$)*/
static void op_DDCB_0x23(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SLA (IX+$)*/
static void op_DDCB_0x24(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SLA (IX+$)*/
static void op_DDCB_0x25(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SLA (IX+$)*/
static void op_DDCB_0x26(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SLA (IX+$)*/
static void op_DDCB_0x27(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLA(temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SRA (IX+$)*/
static void op_DDCB_0x28(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SRA (IX+$)*/
static void op_DDCB_0x29(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SRA (IX+$)*/
static void op_DDCB_0x2a(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SRA (IX+$)*/
static void op_DDCB_0x2b(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SRA (IX+$)*/
static void op_DDCB_0x2c(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SRA (IX+$)*/
static void op_DDCB_0x2d(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SRA (IX+$)*/
static void op_DDCB_0x2e(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SRA (IX+$)*/
static void op_DDCB_0x2f(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRA(temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SLL (IX+$)*/
static void op_DDCB_0x30(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SLL (IX+$)*/
static void op_DDCB_0x31(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SLL (IX+$)*/
static void op_DDCB_0x32(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SLL (IX+$)*/
static void op_DDCB_0x33(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SLL (IX+$)*/
static void op_DDCB_0x34(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SLL (IX+$)*/
static void op_DDCB_0x35(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SLL (IX+$)*/
static void op_DDCB_0x36(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SLL (IX+$)*/
static void op_DDCB_0x37(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SLL(temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SRL (IX+$)*/
static void op_DDCB_0x38(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SRL (IX+$)*/
static void op_DDCB_0x39(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SRL (IX+$)*/
static void op_DDCB_0x3a(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SRL (IX+$)*/
static void op_DDCB_0x3b(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SRL (IX+$)*/
static void op_DDCB_0x3c(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SRL (IX+$)*/
static void op_DDCB_0x3d(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SRL (IX+$)*/
static void op_DDCB_0x3e(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SRL (IX+$)*/
static void op_DDCB_0x3f(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SRL(temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*BIT 0, (IX+$)*/
static void op_DDCB_0x47(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(0, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 1, (IX+$)*/
static void op_DDCB_0x4f(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(1, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 2, (IX+$)*/
static void op_DDCB_0x57(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(2, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 3, (IX+$)*/
static void op_DDCB_0x5f(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(3, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 4, (IX+$)*/
static void op_DDCB_0x67(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(4, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 5, (IX+$)*/
static void op_DDCB_0x6f(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(5, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 6, (IX+$)*/
static void op_DDCB_0x77(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(6, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 7, (IX+$)*/
static void op_DDCB_0x7f(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	BIT_MPTR(7, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*LD B, RES 0, (IX+$)*/
static void op_DDCB_0x80(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 0, (IX+$)*/
static void op_DDCB_0x81(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 0, (IX+$)*/
static void op_DDCB_0x82(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 0, (IX+$)*/
static void op_DDCB_0x83(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 0, (IX+$)*/
static void op_DDCB_0x84(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 0, (IX+$)*/
static void op_DDCB_0x85(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 0, (IX+$)*/
static void op_DDCB_0x86(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 0, (IX+$)*/
static void op_DDCB_0x87(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(0, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 1, (IX+$)*/
static void op_DDCB_0x88(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 1, (IX+$)*/
static void op_DDCB_0x89(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 1, (IX+$)*/
static void op_DDCB_0x8a(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 1, (IX+$)*/
static void op_DDCB_0x8b(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 1, (IX+$)*/
static void op_DDCB_0x8c(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 1, (IX+$)*/
static void op_DDCB_0x8d(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 1, (IX+$)*/
static void op_DDCB_0x8e(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 1, (IX+$)*/
static void op_DDCB_0x8f(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(1, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 2, (IX+$)*/
static void op_DDCB_0x90(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 2, (IX+$)*/
static void op_DDCB_0x91(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 2, (IX+$)*/
static void op_DDCB_0x92(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 2, (IX+$)*/
static void op_DDCB_0x93(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 2, (IX+$)*/
static void op_DDCB_0x94(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 2, (IX+$)*/
static void op_DDCB_0x95(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 2, (IX+$)*/
static void op_DDCB_0x96(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 2, (IX+$)*/
static void op_DDCB_0x97(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(2, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 3, (IX+$)*/
static void op_DDCB_0x98(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 3, (IX+$)*/
static void op_DDCB_0x99(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 3, (IX+$)*/
static void op_DDCB_0x9a(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 3, (IX+$)*/
static void op_DDCB_0x9b(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 3, (IX+$)*/
static void op_DDCB_0x9c(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 3, (IX+$)*/
static void op_DDCB_0x9d(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 3, (IX+$)*/
static void op_DDCB_0x9e(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 3, (IX+$)*/
static void op_DDCB_0x9f(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(3, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 4, (IX+$)*/
static void op_DDCB_0xa0(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 4, (IX+$)*/
static void op_DDCB_0xa1(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 4, (IX+$)*/
static void op_DDCB_0xa2(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 4, (IX+$)*/
static void op_DDCB_0xa3(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 4, (IX+$)*/
static void op_DDCB_0xa4(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 4, (IX+$)*/
static void op_DDCB_0xa5(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 4, (IX+$)*/
static void op_DDCB_0xa6(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 4, (IX+$)*/
static void op_DDCB_0xa7(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(4, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 5, (IX+$)*/
static void op_DDCB_0xa8(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 5, (IX+$)*/
static void op_DDCB_0xa9(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 5, (IX+$)*/
static void op_DDCB_0xaa(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 5, (IX+$)*/
static void op_DDCB_0xab(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 5, (IX+$)*/
static void op_DDCB_0xac(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 5, (IX+$)*/
static void op_DDCB_0xad(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 5, (IX+$)*/
static void op_DDCB_0xae(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 5, (IX+$)*/
static void op_DDCB_0xaf(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(5, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 6, (IX+$)*/
static void op_DDCB_0xb0(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 6, (IX+$)*/
static void op_DDCB_0xb1(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 6, (IX+$)*/
static void op_DDCB_0xb2(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 6, (IX+$)*/
static void op_DDCB_0xb3(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 6, (IX+$)*/
static void op_DDCB_0xb4(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 6, (IX+$)*/
static void op_DDCB_0xb5(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 6, (IX+$)*/
static void op_DDCB_0xb6(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 6, (IX+$)*/
static void op_DDCB_0xb7(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(6, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 7, (IX+$)*/
static void op_DDCB_0xb8(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 7, (IX+$)*/
static void op_DDCB_0xb9(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 7, (IX+$)*/
static void op_DDCB_0xba(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 7, (IX+$)*/
static void op_DDCB_0xbb(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 7, (IX+$)*/
static void op_DDCB_0xbc(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 7, (IX+$)*/
static void op_DDCB_0xbd(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 7, (IX+$)*/
static void op_DDCB_0xbe(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 7, (IX+$)*/
static void op_DDCB_0xbf(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	RES(7, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 0, (IX+$)*/
static void op_DDCB_0xc0(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 0, (IX+$)*/
static void op_DDCB_0xc1(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 0, (IX+$)*/
static void op_DDCB_0xc2(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 0, (IX+$)*/
static void op_DDCB_0xc3(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 0, (IX+$)*/
static void op_DDCB_0xc4(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 0, (IX+$)*/
static void op_DDCB_0xc5(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 0, (IX+$)*/
static void op_DDCB_0xc6(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 0, (IX+$)*/
static void op_DDCB_0xc7(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(0, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 1, (IX+$)*/
static void op_DDCB_0xc8(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 1, (IX+$)*/
static void op_DDCB_0xc9(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 1, (IX+$)*/
static void op_DDCB_0xca(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 1, (IX+$)*/
static void op_DDCB_0xcb(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 1, (IX+$)*/
static void op_DDCB_0xcc(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 1, (IX+$)*/
static void op_DDCB_0xcd(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 1, (IX+$)*/
static void op_DDCB_0xce(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 1, (IX+$)*/
static void op_DDCB_0xcf(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(1, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 2, (IX+$)*/
static void op_DDCB_0xd0(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 2, (IX+$)*/
static void op_DDCB_0xd1(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 2, (IX+$)*/
static void op_DDCB_0xd2(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 2, (IX+$)*/
static void op_DDCB_0xd3(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 2, (IX+$)*/
static void op_DDCB_0xd4(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 2, (IX+$)*/
static void op_DDCB_0xd5(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 2, (IX+$)*/
static void op_DDCB_0xd6(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 2, (IX+$)*/
static void op_DDCB_0xd7(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(2, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 3, (IX+$)*/
static void op_DDCB_0xd8(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 3, (IX+$)*/
static void op_DDCB_0xd9(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 3, (IX+$)*/
static void op_DDCB_0xda(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 3, (IX+$)*/
static void op_DDCB_0xdb(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 3, (IX+$)*/
static void op_DDCB_0xdc(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 3, (IX+$)*/
static void op_DDCB_0xdd(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 3, (IX+$)*/
static void op_DDCB_0xde(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 3, (IX+$)*/
static void op_DDCB_0xdf(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(3, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 4, (IX+$)*/
static void op_DDCB_0xe0(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 4, (IX+$)*/
static void op_DDCB_0xe1(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 4, (IX+$)*/
static void op_DDCB_0xe2(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 4, (IX+$)*/
static void op_DDCB_0xe3(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 4, (IX+$)*/
static void op_DDCB_0xe4(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 4, (IX+$)*/
static void op_DDCB_0xe5(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 4, (IX+$)*/
static void op_DDCB_0xe6(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 4, (IX+$)*/
static void op_DDCB_0xe7(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(4, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 5, (IX+$)*/
static void op_DDCB_0xe8(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 5, (IX+$)*/
static void op_DDCB_0xe9(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 5, (IX+$)*/
static void op_DDCB_0xea(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 5, (IX+$)*/
static void op_DDCB_0xeb(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 5, (IX+$)*/
static void op_DDCB_0xec(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 5, (IX+$)*/
static void op_DDCB_0xed(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 5, (IX+$)*/
static void op_DDCB_0xee(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 5, (IX+$)*/
static void op_DDCB_0xef(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(5, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 6, (IX+$)*/
static void op_DDCB_0xf0(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 6, (IX+$)*/
static void op_DDCB_0xf1(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 6, (IX+$)*/
static void op_DDCB_0xf2(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 6, (IX+$)*/
static void op_DDCB_0xf3(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 6, (IX+$)*/
static void op_DDCB_0xf4(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 6, (IX+$)*/
static void op_DDCB_0xf5(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 6, (IX+$)*/
static void op_DDCB_0xf6(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 6, (IX+$)*/
static void op_DDCB_0xf7(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(6, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 7, (IX+$)*/
static void op_DDCB_0xf8(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(B, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 7, (IX+$)*/
static void op_DDCB_0xf9(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(C, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 7, (IX+$)*/
static void op_DDCB_0xfa(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(D, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 7, (IX+$)*/
static void op_DDCB_0xfb(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(E, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 7, (IX+$)*/
static void op_DDCB_0xfc(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(H, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 7, (IX+$)*/
static void op_DDCB_0xfd(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(L, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 7, (IX+$)*/
static void op_DDCB_0xfe(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 7, (IX+$)*/
static void op_DDCB_0xff(void)
{
	MEMPTR=(IX+d.s);
	temp8=READ_BYTE(IX+d.s);
	SET(7, temp8);
	LD(A, temp8);
	WRITE_BYTE(IX+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

static void (*opcode_ddcb[0x100])(void)={
	op_DDCB_0x00, op_DDCB_0x01, op_DDCB_0x02, op_DDCB_0x03, op_DDCB_0x04, op_DDCB_0x05, op_DDCB_0x06, op_DDCB_0x07, op_DDCB_0x08, op_DDCB_0x09, op_DDCB_0x0a, op_DDCB_0x0b, op_DDCB_0x0c, op_DDCB_0x0d, op_DDCB_0x0e, op_DDCB_0x0f,
	op_DDCB_0x10, op_DDCB_0x11, op_DDCB_0x12, op_DDCB_0x13, op_DDCB_0x14, op_DDCB_0x15, op_DDCB_0x16, op_DDCB_0x17, op_DDCB_0x18, op_DDCB_0x19, op_DDCB_0x1a, op_DDCB_0x1b, op_DDCB_0x1c, op_DDCB_0x1d, op_DDCB_0x1e, op_DDCB_0x1f,
	op_DDCB_0x20, op_DDCB_0x21, op_DDCB_0x22, op_DDCB_0x23, op_DDCB_0x24, op_DDCB_0x25, op_DDCB_0x26, op_DDCB_0x27, op_DDCB_0x28, op_DDCB_0x29, op_DDCB_0x2a, op_DDCB_0x2b, op_DDCB_0x2c, op_DDCB_0x2d, op_DDCB_0x2e, op_DDCB_0x2f,
	op_DDCB_0x30, op_DDCB_0x31, op_DDCB_0x32, op_DDCB_0x33, op_DDCB_0x34, op_DDCB_0x35, op_DDCB_0x36, op_DDCB_0x37, op_DDCB_0x38, op_DDCB_0x39, op_DDCB_0x3a, op_DDCB_0x3b, op_DDCB_0x3c, op_DDCB_0x3d, op_DDCB_0x3e, op_DDCB_0x3f,
	op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x47, op_DDCB_0x4f, op_DDCB_0x4f, op_DDCB_0x4f, op_DDCB_0x4f, op_DDCB_0x4f, op_DDCB_0x4f, op_DDCB_0x4f, op_DDCB_0x4f,
	op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x57, op_DDCB_0x5f, op_DDCB_0x5f, op_DDCB_0x5f, op_DDCB_0x5f, op_DDCB_0x5f, op_DDCB_0x5f, op_DDCB_0x5f, op_DDCB_0x5f,
	op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x67, op_DDCB_0x6f, op_DDCB_0x6f, op_DDCB_0x6f, op_DDCB_0x6f, op_DDCB_0x6f, op_DDCB_0x6f, op_DDCB_0x6f, op_DDCB_0x6f,
	op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x77, op_DDCB_0x7f, op_DDCB_0x7f, op_DDCB_0x7f, op_DDCB_0x7f, op_DDCB_0x7f, op_DDCB_0x7f, op_DDCB_0x7f, op_DDCB_0x7f,
	op_DDCB_0x80, op_DDCB_0x81, op_DDCB_0x82, op_DDCB_0x83, op_DDCB_0x84, op_DDCB_0x85, op_DDCB_0x86, op_DDCB_0x87, op_DDCB_0x88, op_DDCB_0x89, op_DDCB_0x8a, op_DDCB_0x8b, op_DDCB_0x8c, op_DDCB_0x8d, op_DDCB_0x8e, op_DDCB_0x8f,
	op_DDCB_0x90, op_DDCB_0x91, op_DDCB_0x92, op_DDCB_0x93, op_DDCB_0x94, op_DDCB_0x95, op_DDCB_0x96, op_DDCB_0x97, op_DDCB_0x98, op_DDCB_0x99, op_DDCB_0x9a, op_DDCB_0x9b, op_DDCB_0x9c, op_DDCB_0x9d, op_DDCB_0x9e, op_DDCB_0x9f,
	op_DDCB_0xa0, op_DDCB_0xa1, op_DDCB_0xa2, op_DDCB_0xa3, op_DDCB_0xa4, op_DDCB_0xa5, op_DDCB_0xa6, op_DDCB_0xa7, op_DDCB_0xa8, op_DDCB_0xa9, op_DDCB_0xaa, op_DDCB_0xab, op_DDCB_0xac, op_DDCB_0xad, op_DDCB_0xae, op_DDCB_0xaf,
	op_DDCB_0xb0, op_DDCB_0xb1, op_DDCB_0xb2, op_DDCB_0xb3, op_DDCB_0xb4, op_DDCB_0xb5, op_DDCB_0xb6, op_DDCB_0xb7, op_DDCB_0xb8, op_DDCB_0xb9, op_DDCB_0xba, op_DDCB_0xbb, op_DDCB_0xbc, op_DDCB_0xbd, op_DDCB_0xbe, op_DDCB_0xbf,
	op_DDCB_0xc0, op_DDCB_0xc1, op_DDCB_0xc2, op_DDCB_0xc3, op_DDCB_0xc4, op_DDCB_0xc5, op_DDCB_0xc6, op_DDCB_0xc7, op_DDCB_0xc8, op_DDCB_0xc9, op_DDCB_0xca, op_DDCB_0xcb, op_DDCB_0xcc, op_DDCB_0xcd, op_DDCB_0xce, op_DDCB_0xcf,
	op_DDCB_0xd0, op_DDCB_0xd1, op_DDCB_0xd2, op_DDCB_0xd3, op_DDCB_0xd4, op_DDCB_0xd5, op_DDCB_0xd6, op_DDCB_0xd7, op_DDCB_0xd8, op_DDCB_0xd9, op_DDCB_0xda, op_DDCB_0xdb, op_DDCB_0xdc, op_DDCB_0xdd, op_DDCB_0xde, op_DDCB_0xdf,
	op_DDCB_0xe0, op_DDCB_0xe1, op_DDCB_0xe2, op_DDCB_0xe3, op_DDCB_0xe4, op_DDCB_0xe5, op_DDCB_0xe6, op_DDCB_0xe7, op_DDCB_0xe8, op_DDCB_0xe9, op_DDCB_0xea, op_DDCB_0xeb, op_DDCB_0xec, op_DDCB_0xed, op_DDCB_0xee, op_DDCB_0xef,
	op_DDCB_0xf0, op_DDCB_0xf1, op_DDCB_0xf2, op_DDCB_0xf3, op_DDCB_0xf4, op_DDCB_0xf5, op_DDCB_0xf6, op_DDCB_0xf7, op_DDCB_0xf8, op_DDCB_0xf9, op_DDCB_0xfa, op_DDCB_0xfb, op_DDCB_0xfc, op_DDCB_0xfd, op_DDCB_0xfe, op_DDCB_0xff
};
