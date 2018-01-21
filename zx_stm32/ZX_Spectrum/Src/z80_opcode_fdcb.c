/*LD B, RLC (IY+$)*/
static void op_FDCB_0x00(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RLC(temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RLC (IY+$)*/
static void op_FDCB_0x01(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RLC(temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RLC (IY+$)*/
static void op_FDCB_0x02(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RLC(temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RLC (IY+$)*/
static void op_FDCB_0x03(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RLC(temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RLC (IY+$)*/
static void op_FDCB_0x04(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RLC(temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RLC (IY+$)*/
static void op_FDCB_0x05(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RLC(temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RLC (IY+$)*/
static void op_FDCB_0x06(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RLC(temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RLC (IY+$)*/
static void op_FDCB_0x07(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RLC(temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RRC (IY+$)*/
static void op_FDCB_0x08(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RRC(temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RRC (IY+$)*/
static void op_FDCB_0x09(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RRC(temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RRC (IY+$)*/
static void op_FDCB_0x0a(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RRC(temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RRC (IY+$)*/
static void op_FDCB_0x0b(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RRC(temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RRC (IY+$)*/
static void op_FDCB_0x0c(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RRC(temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RRC (IY+$)*/
static void op_FDCB_0x0d(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RRC(temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RRC (IY+$)*/
static void op_FDCB_0x0e(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RRC(temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RRC (IY+$)*/
static void op_FDCB_0x0f(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RRC(temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RL (IY+$)*/
static void op_FDCB_0x10(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RL(temp8);
	LD16(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RL (IY+$)*/
static void op_FDCB_0x11(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RL(temp8);
	LD16(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RL (IY+$)*/
static void op_FDCB_0x12(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RL(temp8);
	LD16(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RL (IY+$)*/
static void op_FDCB_0x13(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RL(temp8);
	LD16(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RL (IY+$)*/
static void op_FDCB_0x14(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RL(temp8);
	LD16(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RL (IY+$)*/
static void op_FDCB_0x15(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RL(temp8);
	LD16(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RL (IY+$)*/
static void op_FDCB_0x16(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RL(temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RL (IY+$)*/
static void op_FDCB_0x17(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RL(temp8);
	LD16(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RR (IY+$)*/
static void op_FDCB_0x18(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RR(temp8);
	LD16(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RR (IY+$)*/
static void op_FDCB_0x19(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RR(temp8);
	LD16(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RR (IY+$)*/
static void op_FDCB_0x1a(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RR(temp8);
	LD16(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RR (IY+$)*/
static void op_FDCB_0x1b(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RR(temp8);
	LD16(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RR (IY+$)*/
static void op_FDCB_0x1c(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RR(temp8);
	LD16(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RR (IY+$)*/
static void op_FDCB_0x1d(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RR(temp8);
	LD16(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RR (IY+$)*/
static void op_FDCB_0x1e(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RR(temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RR (IY+$)*/
static void op_FDCB_0x1f(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RR(temp8);
	LD16(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SLA (IY+$)*/
static void op_FDCB_0x20(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLA(temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SLA (IY+$)*/
static void op_FDCB_0x21(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLA(temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SLA (IY+$)*/
static void op_FDCB_0x22(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLA(temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SLA (IY+$)*/
static void op_FDCB_0x23(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLA(temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SLA (IY+$)*/
static void op_FDCB_0x24(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLA(temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SLA (IY+$)*/
static void op_FDCB_0x25(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLA(temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SLA (IY+$)*/
static void op_FDCB_0x26(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLA(temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SLA (IY+$)*/
static void op_FDCB_0x27(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLA(temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SRA (IY+$)*/
static void op_FDCB_0x28(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRA(temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SRA (IY+$)*/
static void op_FDCB_0x29(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRA(temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SRA (IY+$)*/
static void op_FDCB_0x2a(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRA(temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SRA (IY+$)*/
static void op_FDCB_0x2b(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRA(temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SRA (IY+$)*/
static void op_FDCB_0x2c(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRA(temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SRA (IY+$)*/
static void op_FDCB_0x2d(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRA(temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SRA (IY+$)*/
static void op_FDCB_0x2e(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRA(temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SRA (IY+$)*/
static void op_FDCB_0x2f(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRA(temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SLL (IY+$)*/
static void op_FDCB_0x30(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLL(temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SLL (IY+$)*/
static void op_FDCB_0x31(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLL(temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SLL (IY+$)*/
static void op_FDCB_0x32(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLL(temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SLL (IY+$)*/
static void op_FDCB_0x33(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLL(temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SLL (IY+$)*/
static void op_FDCB_0x34(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLL(temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SLL (IY+$)*/
static void op_FDCB_0x35(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLL(temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SLL (IY+$)*/
static void op_FDCB_0x36(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLL(temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SLL (IY+$)*/
static void op_FDCB_0x37(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SLL(temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SRL (IY+$)*/
static void op_FDCB_0x38(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRL(temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SRL (IY+$)*/
static void op_FDCB_0x39(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRL(temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SRL (IY+$)*/
static void op_FDCB_0x3a(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRL(temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SRL (IY+$)*/
static void op_FDCB_0x3b(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRL(temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SRL (IY+$)*/
static void op_FDCB_0x3c(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRL(temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SRL (IY+$)*/
static void op_FDCB_0x3d(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRL(temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SRL (IY+$)*/
static void op_FDCB_0x3e(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRL(temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SRL (IY+$)*/
static void op_FDCB_0x3f(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SRL(temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*BIT 0, (IY+$)*/
static void op_FDCB_0x47(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	BIT_MPTR(0, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 1, (IY+$)*/
static void op_FDCB_0x4f(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	BIT_MPTR(1, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 2, (IY+$)*/
static void op_FDCB_0x57(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	BIT_MPTR(2, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 3, (IY+$)*/
static void op_FDCB_0x5f(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	BIT_MPTR(3, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 4, (IY+$)*/
static void op_FDCB_0x67(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	BIT_MPTR(4, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 5, (IY+$)*/
static void op_FDCB_0x6f(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	BIT_MPTR(5, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 6, (IY+$)*/
static void op_FDCB_0x77(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	BIT_MPTR(6, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*BIT 7, (IY+$)*/
static void op_FDCB_0x7f(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	BIT_MPTR(7, temp8);
	T_WAIT_UNTIL(16);
	return;
}

/*LD B, RES 0, (IY+$)*/
static void op_FDCB_0x80(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(0, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 0, (IY+$)*/
static void op_FDCB_0x81(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(0, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 0, (IY+$)*/
static void op_FDCB_0x82(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(0, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 0, (IY+$)*/
static void op_FDCB_0x83(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(0, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 0, (IY+$)*/
static void op_FDCB_0x84(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(0, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 0, (IY+$)*/
static void op_FDCB_0x85(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(0, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 0, (IY+$)*/
static void op_FDCB_0x86(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(0, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 0, (IY+$)*/
static void op_FDCB_0x87(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(0, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 1, (IY+$)*/
static void op_FDCB_0x88(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(1, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 1, (IY+$)*/
static void op_FDCB_0x89(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(1, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 1, (IY+$)*/
static void op_FDCB_0x8a(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(1, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 1, (IY+$)*/
static void op_FDCB_0x8b(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(1, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 1, (IY+$)*/
static void op_FDCB_0x8c(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(1, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 1, (IY+$)*/
static void op_FDCB_0x8d(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(1, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 1, (IY+$)*/
static void op_FDCB_0x8e(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(1, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 1, (IY+$)*/
static void op_FDCB_0x8f(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(1, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 2, (IY+$)*/
static void op_FDCB_0x90(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(2, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 2, (IY+$)*/
static void op_FDCB_0x91(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(2, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 2, (IY+$)*/
static void op_FDCB_0x92(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(2, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 2, (IY+$)*/
static void op_FDCB_0x93(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(2, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 2, (IY+$)*/
static void op_FDCB_0x94(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(2, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 2, (IY+$)*/
static void op_FDCB_0x95(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(2, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 2, (IY+$)*/
static void op_FDCB_0x96(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(2, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 2, (IY+$)*/
static void op_FDCB_0x97(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(2, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 3, (IY+$)*/
static void op_FDCB_0x98(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(3, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 3, (IY+$)*/
static void op_FDCB_0x99(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(3, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 3, (IY+$)*/
static void op_FDCB_0x9a(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(3, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 3, (IY+$)*/
static void op_FDCB_0x9b(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(3, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 3, (IY+$)*/
static void op_FDCB_0x9c(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(3, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 3, (IY+$)*/
static void op_FDCB_0x9d(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(3, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 3, (IY+$)*/
static void op_FDCB_0x9e(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(3, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 3, (IY+$)*/
static void op_FDCB_0x9f(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(3, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 4, (IY+$)*/
static void op_FDCB_0xa0(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(4, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 4, (IY+$)*/
static void op_FDCB_0xa1(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(4, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 4, (IY+$)*/
static void op_FDCB_0xa2(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(4, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 4, (IY+$)*/
static void op_FDCB_0xa3(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(4, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 4, (IY+$)*/
static void op_FDCB_0xa4(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(4, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 4, (IY+$)*/
static void op_FDCB_0xa5(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(4, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 4, (IY+$)*/
static void op_FDCB_0xa6(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(4, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 4, (IY+$)*/
static void op_FDCB_0xa7(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(4, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 5, (IY+$)*/
static void op_FDCB_0xa8(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(5, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 5, (IY+$)*/
static void op_FDCB_0xa9(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(5, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 5, (IY+$)*/
static void op_FDCB_0xaa(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(5, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 5, (IY+$)*/
static void op_FDCB_0xab(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(5, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 5, (IY+$)*/
static void op_FDCB_0xac(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(5, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 5, (IY+$)*/
static void op_FDCB_0xad(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(5, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 5, (IY+$)*/
static void op_FDCB_0xae(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(5, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 5, (IY+$)*/
static void op_FDCB_0xaf(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(5, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 6, (IY+$)*/
static void op_FDCB_0xb0(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(6, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 6, (IY+$)*/
static void op_FDCB_0xb1(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(6, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 6, (IY+$)*/
static void op_FDCB_0xb2(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(6, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 6, (IY+$)*/
static void op_FDCB_0xb3(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(6, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 6, (IY+$)*/
static void op_FDCB_0xb4(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(6, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 6, (IY+$)*/
static void op_FDCB_0xb5(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(6, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 6, (IY+$)*/
static void op_FDCB_0xb6(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(6, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 6, (IY+$)*/
static void op_FDCB_0xb7(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(6, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, RES 7, (IY+$)*/
static void op_FDCB_0xb8(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(7, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, RES 7, (IY+$)*/
static void op_FDCB_0xb9(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(7, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, RES 7, (IY+$)*/
static void op_FDCB_0xba(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(7, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, RES 7, (IY+$)*/
static void op_FDCB_0xbb(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(7, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, RES 7, (IY+$)*/
static void op_FDCB_0xbc(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(7, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, RES 7, (IY+$)*/
static void op_FDCB_0xbd(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(7, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*RES 7, (IY+$)*/
static void op_FDCB_0xbe(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(7, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, RES 7, (IY+$)*/
static void op_FDCB_0xbf(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	RES(7, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 0, (IY+$)*/
static void op_FDCB_0xc0(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(0, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 0, (IY+$)*/
static void op_FDCB_0xc1(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(0, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 0, (IY+$)*/
static void op_FDCB_0xc2(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(0, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 0, (IY+$)*/
static void op_FDCB_0xc3(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(0, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 0, (IY+$)*/
static void op_FDCB_0xc4(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(0, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 0, (IY+$)*/
static void op_FDCB_0xc5(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(0, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 0, (IY+$)*/
static void op_FDCB_0xc6(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(0, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 0, (IY+$)*/
static void op_FDCB_0xc7(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(0, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 1, (IY+$)*/
static void op_FDCB_0xc8(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(1, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 1, (IY+$)*/
static void op_FDCB_0xc9(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(1, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 1, (IY+$)*/
static void op_FDCB_0xca(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(1, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 1, (IY+$)*/
static void op_FDCB_0xcb(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(1, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 1, (IY+$)*/
static void op_FDCB_0xcc(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(1, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 1, (IY+$)*/
static void op_FDCB_0xcd(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(1, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 1, (IY+$)*/
static void op_FDCB_0xce(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(1, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 1, (IY+$)*/
static void op_FDCB_0xcf(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(1, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 2, (IY+$)*/
static void op_FDCB_0xd0(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(2, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 2, (IY+$)*/
static void op_FDCB_0xd1(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(2, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 2, (IY+$)*/
static void op_FDCB_0xd2(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(2, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 2, (IY+$)*/
static void op_FDCB_0xd3(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(2, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 2, (IY+$)*/
static void op_FDCB_0xd4(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(2, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 2, (IY+$)*/
static void op_FDCB_0xd5(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(2, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 2, (IY+$)*/
static void op_FDCB_0xd6(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(2, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 2, (IY+$)*/
static void op_FDCB_0xd7(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(2, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 3, (IY+$)*/
static void op_FDCB_0xd8(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(3, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 3, (IY+$)*/
static void op_FDCB_0xd9(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(3, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 3, (IY+$)*/
static void op_FDCB_0xda(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(3, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 3, (IY+$)*/
static void op_FDCB_0xdb(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(3, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 3, (IY+$)*/
static void op_FDCB_0xdc(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(3, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 3, (IY+$)*/
static void op_FDCB_0xdd(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(3, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 3, (IY+$)*/
static void op_FDCB_0xde(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(3, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 3, (IY+$)*/
static void op_FDCB_0xdf(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(3, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 4, (IY+$)*/
static void op_FDCB_0xe0(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(4, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 4, (IY+$)*/
static void op_FDCB_0xe1(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(4, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 4, (IY+$)*/
static void op_FDCB_0xe2(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(4, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 4, (IY+$)*/
static void op_FDCB_0xe3(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(4, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 4, (IY+$)*/
static void op_FDCB_0xe4(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(4, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 4, (IY+$)*/
static void op_FDCB_0xe5(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(4, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 4, (IY+$)*/
static void op_FDCB_0xe6(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(4, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 4, (IY+$)*/
static void op_FDCB_0xe7(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(4, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 5, (IY+$)*/
static void op_FDCB_0xe8(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(5, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 5, (IY+$)*/
static void op_FDCB_0xe9(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(5, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 5, (IY+$)*/
static void op_FDCB_0xea(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(5, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 5, (IY+$)*/
static void op_FDCB_0xeb(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(5, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 5, (IY+$)*/
static void op_FDCB_0xec(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(5, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 5, (IY+$)*/
static void op_FDCB_0xed(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(5, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 5, (IY+$)*/
static void op_FDCB_0xee(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(5, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 5, (IY+$)*/
static void op_FDCB_0xef(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(5, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 6, (IY+$)*/
static void op_FDCB_0xf0(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(6, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 6, (IY+$)*/
static void op_FDCB_0xf1(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(6, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 6, (IY+$)*/
static void op_FDCB_0xf2(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(6, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 6, (IY+$)*/
static void op_FDCB_0xf3(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(6, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 6, (IY+$)*/
static void op_FDCB_0xf4(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(6, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 6, (IY+$)*/
static void op_FDCB_0xf5(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(6, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 6, (IY+$)*/
static void op_FDCB_0xf6(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(6, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 6, (IY+$)*/
static void op_FDCB_0xf7(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(6, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD B, SET 7, (IY+$)*/
static void op_FDCB_0xf8(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(7, temp8);
	LD(B, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD C, SET 7, (IY+$)*/
static void op_FDCB_0xf9(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(7, temp8);
	LD(C, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD D, SET 7, (IY+$)*/
static void op_FDCB_0xfa(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(7, temp8);
	LD(D, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD E, SET 7, (IY+$)*/
static void op_FDCB_0xfb(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(7, temp8);
	LD(E, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD H, SET 7, (IY+$)*/
static void op_FDCB_0xfc(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(7, temp8);
	LD(H, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD L, SET 7, (IY+$)*/
static void op_FDCB_0xfd(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(7, temp8);
	LD(L, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*SET 7, (IY+$)*/
static void op_FDCB_0xfe(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(7, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

/*LD A, SET 7, (IY+$)*/
static void op_FDCB_0xff(void)
{
	MEMPTR=(IY+d.s);
	temp8=READ_BYTE(IY+d.s);
	SET(7, temp8);
	LD(A, temp8);
	WRITE_BYTE(IY+d.s, temp8);
	T_WAIT_UNTIL(19);
	return;
}

static void (*opcode_fdcb[0x100])(void)={
	op_FDCB_0x00, op_FDCB_0x01, op_FDCB_0x02, op_FDCB_0x03, op_FDCB_0x04, op_FDCB_0x05, op_FDCB_0x06, op_FDCB_0x07, op_FDCB_0x08, op_FDCB_0x09, op_FDCB_0x0a, op_FDCB_0x0b, op_FDCB_0x0c, op_FDCB_0x0d, op_FDCB_0x0e, op_FDCB_0x0f,
	op_FDCB_0x10, op_FDCB_0x11, op_FDCB_0x12, op_FDCB_0x13, op_FDCB_0x14, op_FDCB_0x15, op_FDCB_0x16, op_FDCB_0x17, op_FDCB_0x18, op_FDCB_0x19, op_FDCB_0x1a, op_FDCB_0x1b, op_FDCB_0x1c, op_FDCB_0x1d, op_FDCB_0x1e, op_FDCB_0x1f,
	op_FDCB_0x20, op_FDCB_0x21, op_FDCB_0x22, op_FDCB_0x23, op_FDCB_0x24, op_FDCB_0x25, op_FDCB_0x26, op_FDCB_0x27, op_FDCB_0x28, op_FDCB_0x29, op_FDCB_0x2a, op_FDCB_0x2b, op_FDCB_0x2c, op_FDCB_0x2d, op_FDCB_0x2e, op_FDCB_0x2f,
	op_FDCB_0x30, op_FDCB_0x31, op_FDCB_0x32, op_FDCB_0x33, op_FDCB_0x34, op_FDCB_0x35, op_FDCB_0x36, op_FDCB_0x37, op_FDCB_0x38, op_FDCB_0x39, op_FDCB_0x3a, op_FDCB_0x3b, op_FDCB_0x3c, op_FDCB_0x3d, op_FDCB_0x3e, op_FDCB_0x3f,
	op_FDCB_0x47, op_FDCB_0x47, op_FDCB_0x47, op_FDCB_0x47, op_FDCB_0x47, op_FDCB_0x47, op_FDCB_0x47, op_FDCB_0x47, op_FDCB_0x4f, op_FDCB_0x4f, op_FDCB_0x4f, op_FDCB_0x4f, op_FDCB_0x4f, op_FDCB_0x4f, op_FDCB_0x4f, op_FDCB_0x4f,
	op_FDCB_0x57, op_FDCB_0x57, op_FDCB_0x57, op_FDCB_0x57, op_FDCB_0x57, op_FDCB_0x57, op_FDCB_0x57, op_FDCB_0x57, op_FDCB_0x5f, op_FDCB_0x5f, op_FDCB_0x5f, op_FDCB_0x5f, op_FDCB_0x5f, op_FDCB_0x5f, op_FDCB_0x5f, op_FDCB_0x5f,
	op_FDCB_0x67, op_FDCB_0x67, op_FDCB_0x67, op_FDCB_0x67, op_FDCB_0x67, op_FDCB_0x67, op_FDCB_0x67, op_FDCB_0x67, op_FDCB_0x6f, op_FDCB_0x6f, op_FDCB_0x6f, op_FDCB_0x6f, op_FDCB_0x6f, op_FDCB_0x6f, op_FDCB_0x6f, op_FDCB_0x6f,
	op_FDCB_0x77, op_FDCB_0x77, op_FDCB_0x77, op_FDCB_0x77, op_FDCB_0x77, op_FDCB_0x77, op_FDCB_0x77, op_FDCB_0x77, op_FDCB_0x7f, op_FDCB_0x7f, op_FDCB_0x7f, op_FDCB_0x7f, op_FDCB_0x7f, op_FDCB_0x7f, op_FDCB_0x7f, op_FDCB_0x7f,
	op_FDCB_0x80, op_FDCB_0x81, op_FDCB_0x82, op_FDCB_0x83, op_FDCB_0x84, op_FDCB_0x85, op_FDCB_0x86, op_FDCB_0x87, op_FDCB_0x88, op_FDCB_0x89, op_FDCB_0x8a, op_FDCB_0x8b, op_FDCB_0x8c, op_FDCB_0x8d, op_FDCB_0x8e, op_FDCB_0x8f,
	op_FDCB_0x90, op_FDCB_0x91, op_FDCB_0x92, op_FDCB_0x93, op_FDCB_0x94, op_FDCB_0x95, op_FDCB_0x96, op_FDCB_0x97, op_FDCB_0x98, op_FDCB_0x99, op_FDCB_0x9a, op_FDCB_0x9b, op_FDCB_0x9c, op_FDCB_0x9d, op_FDCB_0x9e, op_FDCB_0x9f,
	op_FDCB_0xa0, op_FDCB_0xa1, op_FDCB_0xa2, op_FDCB_0xa3, op_FDCB_0xa4, op_FDCB_0xa5, op_FDCB_0xa6, op_FDCB_0xa7, op_FDCB_0xa8, op_FDCB_0xa9, op_FDCB_0xaa, op_FDCB_0xab, op_FDCB_0xac, op_FDCB_0xad, op_FDCB_0xae, op_FDCB_0xaf,
	op_FDCB_0xb0, op_FDCB_0xb1, op_FDCB_0xb2, op_FDCB_0xb3, op_FDCB_0xb4, op_FDCB_0xb5, op_FDCB_0xb6, op_FDCB_0xb7, op_FDCB_0xb8, op_FDCB_0xb9, op_FDCB_0xba, op_FDCB_0xbb, op_FDCB_0xbc, op_FDCB_0xbd, op_FDCB_0xbe, op_FDCB_0xbf,
	op_FDCB_0xc0, op_FDCB_0xc1, op_FDCB_0xc2, op_FDCB_0xc3, op_FDCB_0xc4, op_FDCB_0xc5, op_FDCB_0xc6, op_FDCB_0xc7, op_FDCB_0xc8, op_FDCB_0xc9, op_FDCB_0xca, op_FDCB_0xcb, op_FDCB_0xcc, op_FDCB_0xcd, op_FDCB_0xce, op_FDCB_0xcf,
	op_FDCB_0xd0, op_FDCB_0xd1, op_FDCB_0xd2, op_FDCB_0xd3, op_FDCB_0xd4, op_FDCB_0xd5, op_FDCB_0xd6, op_FDCB_0xd7, op_FDCB_0xd8, op_FDCB_0xd9, op_FDCB_0xda, op_FDCB_0xdb, op_FDCB_0xdc, op_FDCB_0xdd, op_FDCB_0xde, op_FDCB_0xdf,
	op_FDCB_0xe0, op_FDCB_0xe1, op_FDCB_0xe2, op_FDCB_0xe3, op_FDCB_0xe4, op_FDCB_0xe5, op_FDCB_0xe6, op_FDCB_0xe7, op_FDCB_0xe8, op_FDCB_0xe9, op_FDCB_0xea, op_FDCB_0xeb, op_FDCB_0xec, op_FDCB_0xed, op_FDCB_0xee, op_FDCB_0xef,
	op_FDCB_0xf0, op_FDCB_0xf1, op_FDCB_0xf2, op_FDCB_0xf3, op_FDCB_0xf4, op_FDCB_0xf5, op_FDCB_0xf6, op_FDCB_0xf7, op_FDCB_0xf8, op_FDCB_0xf9, op_FDCB_0xfa, op_FDCB_0xfb, op_FDCB_0xfc, op_FDCB_0xfd, op_FDCB_0xfe, op_FDCB_0xff
};
