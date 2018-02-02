/*
 *
 *	Author: Beloussov Yegor
 *	Created on: january 2018
 *
 *	Header file with macros
 *
 */

#ifndef INC_Z80_MACROS_H_
#define INC_Z80_MACROS_H_


/*macros used for accessing the registers*/
#define A	reg.r[7]
#define F   reg.r[6]
#define AF  reg.rp[3]

#define B   reg.r[1]
#define C   reg.r[0]
#define BC  reg.rp[0]

#define D   reg.r[3]
#define E   reg.r[2]
#define DE  reg.rp[1]

#define H   reg.r[5]
#define L   reg.r[4]
#define HL  reg.rp[2]

#define IXH reg.r[9]
#define IXL reg.r[8]
#define IX  reg.rp[4]

#define IYH reg.r[11]
#define IYL reg.r[10]
#define IY  reg.rp[5]

#define SPH reg.r[13]
#define SPL reg.r[12]
#define SP  reg.rp[6]

#define PCH reg.r[15]
#define PCL reg.r[14]
#define PC  reg.rp[7]

#define MEMPTRH reg.r[17]
#define MEMPTRL reg.r[16]
#define MEMPTR reg.rp[8]

#define I  reg.r[18]
#define R  reg.r[19]
#define R7  reg.r[20]

#define A_  reg_.r[7]
#define F_  reg_.r[6]
#define AF_ reg_.rp[3]

#define B_  reg_.r[1]
#define C_  reg_.r[0]
#define BC_ reg_.rp[0]

#define D_  reg_.r[3]
#define E_  reg_.r[2]
#define DE_ reg_.rp[1]

#define H_  reg_.r[5]
#define L_  reg_.r[4]
#define HL_ reg_.rp[2]

/*the flags*/
#define FLAG_C	0x01
#define FLAG_N	0x02
#define FLAG_P	0x04
#define FLAG_V	FLAG_P
#define FLAG_3	0x08
#define FLAG_H	0x10
#define FLAG_5	0x20
#define FLAG_Z	0x40
#define FLAG_S	0x80

/*macros R/W memory*/
#define NEXT_WORD peek16(PC); PC=PC+2;
#define NEXT_BYTE peek(PC); PC++;

#define READ_WORD(addr) peek16(addr);
#define WRITE_WORD(addr, value) poke16(addr, value);
#define READ_BYTE(addr) peek(addr);
#define WRITE_BYTE(addr, value) poke(addr, value);




/*macros R/W port*/
#define READ_PORT(port) in(port);
#define WRITE_PORT(port, value) out(port, value);

/*macros timing*/
#define T_WAIT_UNTIL(value) m_cycle=value;




/*Instructions Table 8-Bit Load Group*/
#define LD_R_TO_R(dst, src) \
{ \
	dst=src; \
}

#define LD_n_TO_R(dst) \
{ \
	dst=memory[PC]; \
	PC+=1; \
}

#define LD_ADDR_HL_TO_R(dst) \
{ \
	dst=memory[HL]; \
}

#define LD_ADDR_HL_FROM_R(src) \
{ \
	if (HL>0x3fff) \
	{ \
		memory[HL]=src; \
	} \
}

#define LD_n_TO_ADDR_HL \
{ \
	if (HL>0x3fff) \
	{ \
		memory[HL]=memory[PC]; \
	} \
	PC+=1; \
}

#define LD_ADDR_RP_AND_OFFSET_TO_R(dst, src) \
{ \
	d.u=memory[PC]; \
	PC+=1; \
	MEMPTR=(src+d.s); \
	dst=memory[MEMPTR]; \
}

#define LD_ADDR_RP_AND_OFFSET_FROM_R(dst, src) \
{ \
	d.u=memory[PC]; \
	PC+=1; \
	MEMPTR=(IX+d.s); \
	if (MEMPTR>0x3fff) \
	{ \
		memory[MEMPTR]=src; \
	} \
}

#define LD_n_TO_ADDR_RP_AND_OFFSET(dst) \
{ \
	d.u=memory[PC]; \
	PC+=1; \
	MEMPTR=(dst+d.s); \
	if (MEMPTR>0x3fff) \
	{ \
		memory[MEMPTR]=memory[PC]; \
	} \
	PC+=1; \
}

/*LD A, (BC|DE)*/
#define LD_A_FROM_ADDR_RP_MPTR(src) \
{ \
	A=memory[src]; \
	MEMPTR=src+1; \
}

/*LD A, (nnnn)*/
#define LD_A_FROM_ADDR_MPTR \
{ \
	MEMPTRL=memory[PC]; \
	MEMPTRH=memory[PC+1]; \
	PC+=2; \
	A=memory[MEMPTR]; \
	MEMPTR+=1; \
}

/*LD (BC|DE), A*/
#define LD_A_TO_ADDR_RP_MPTR(dst) \
{ \
	if (dst>0x3fff) \
	{ \
		memory[dst]=A; \
	} \
	MEMPTR=dst+1; \
	MEMPTRH=A; \
}

/*LD (nnnn), A*/
#define LD_A_TO_ADDR_MPTR \
{ \
	MEMPTRL=memory[PC]; \
	MEMPTRH=memory[PC+1]; \
	PC+=2; \
	if (MEMPTR>0x3fff) \
	{ \
		memory[MEMPTR]=A; \
	} \
	MEMPTR+=1; \
	MEMPTRH=A; \
}

#define LD_A_I() \
{ \
	A=I; \
	F=(F&FLAG_C)|sz53_table[A]|(IFF2?FLAG_V:0); \
}

#define LD_A_R() \
{ \
	A=(R&0x7f)|(R7&0x80); \
	F=(F&FLAG_C)|sz53_table[A]|(IFF2?FLAG_V:0); \
}

#define LD_R_A() \
{ \
	R=R7=A; \
}














#define LD(dst, src) \
{ \
	dst=src; \
}





























/*Instructions Table 16-Bit Load Group*/
#define LD_RP_TO_RP(dst, src) \
{ \
	dst=src; \
}

#define LD_nn_TO_RP(dst) \
{ \
	dst=(memory[PC+1]<<8)|memory[PC]; \
	PC+=2; \
}

#define LD_ADDR_nn_TO_RP(dst) \
{ \
	MEMPTRL=memory[PC]; \
	MEMPTRH=memory[PC+1]; \
	PC+=2; \
	dst=(memory[MEMPTR+1]<<8)|memory[MEMPTR]; \
	MEMPTR+=1; \
}

#define LD_ADDR_nn_FROM_RP(src) \
{ \
	MEMPTRL=memory[PC]; \
	MEMPTRH=memory[PC+1]; \
	PC+=2; \
	if (MEMPTR>0x3fff) \
	{ \
		memory[MEMPTR]=src&0xff; \
	} \
	MEMPTR+=1; \
	if (MEMPTR>0x3fff) \
	{ \
		memory[MEMPTR]=src>>8; \
	} \
}

#define PUSH(rp) \
{ \
	SP-=2; \
	if (SP>0x3fff) \
	{ \
		memory[SP]=rp&0xff; \
	} \
	if (SP>0x3fff) \
	{ \
		memory[SP+1]=rp>>8; \
	} \
}

#define POP(rp) \
{ \
	rp=(memory[SP+1]<<8)|memory[SP]; \
	SP+=2; \
}
























#define LD16(dst, src) \
{ \
	dst=src; \
}
































/*Instructions Table Exchange, Block Transfer, Search Group*/
#define EXX() \
{ \
	exx_temp=BC; BC=BC_; BC_=exx_temp; \
	exx_temp=DE; DE=DE_; DE_=exx_temp; \
	exx_temp=HL; HL=HL_; HL_=exx_temp; \
}

#define EX(rp1, rp2) \
{ \
	exx_temp=rp1; rp1=rp2; rp2=exx_temp; \
}

/*EX (SP), HL|IX|IY*/
#define EX_MPTR(rp) \
{ \
	MEMPTRL=memory[SP]; \
	MEMPTRH=memory[SP+1]; \
	exx_temp=MEMPTR; MEMPTR=rp; \
	if (SP>0x3fff) \
	{ \
		memory[SP]=MEMPTRL; \
	} \
	if (SP+1>0x3fff) \
	{ \
		memory[SP+1]=MEMPTRH; \
	} \
	rp=exx_temp; \
	MEMPTR=exx_temp; \
}

#define LDI() \
{ \
	bo_temp=READ_BYTE(HL); \
	WRITE_BYTE(DE, bo_temp); \
	BC--; \
	DE++; \
	HL++; \
	bo_temp+=A; \
	F=(F&(FLAG_C|FLAG_Z|FLAG_S))|(BC?FLAG_V:0)|(bo_temp&FLAG_3)|((bo_temp&0x02)?FLAG_5:0); \
}

#define LDD() \
{ \
	bo_temp=READ_BYTE(HL); \
	WRITE_BYTE(DE, bo_temp); \
	BC--; \
	DE--; \
	HL--; \
	bo_temp+=A; \
	F=(F&(FLAG_C|FLAG_Z|FLAG_S))|(BC?FLAG_V:0)|(bo_temp&FLAG_3)|((bo_temp&0x02)?FLAG_5:0); \
}

#define LDIR() \
{ \
	bo_temp=READ_BYTE(HL); \
	WRITE_BYTE(DE, bo_temp); \
	BC--; \
	DE++; \
	HL++; \
	bo_temp+=A; \
	F=(F&(FLAG_C|FLAG_Z|FLAG_S))|(BC?FLAG_V:0)|(bo_temp&FLAG_3)|((bo_temp&0x02)?FLAG_5:0); \
	if(BC) \
	{ \
		PC-=2; \
		T_WAIT_UNTIL(17); \
		MEMPTR=PC+1; \
	} \
	else \
	{ \
		T_WAIT_UNTIL(12); \
	} \
}

#define LDDR() \
{ \
	bo_temp=READ_BYTE(HL); \
	WRITE_BYTE(DE, bo_temp); \
	BC--; \
	DE--; \
	HL--; \
	bo_temp+=A; \
	F=(F&(FLAG_C|FLAG_Z|FLAG_S))|(BC?FLAG_V:0)|(bo_temp&FLAG_3)|((bo_temp&0x02)?FLAG_5:0); \
	if(BC) \
	{ \
		PC-=2; \
		T_WAIT_UNTIL(17); \
		MEMPTR=PC+1; \
	} \
	else \
	{ \
		T_WAIT_UNTIL(12); \
	} \
}

#define CPI(rd) \
{ \
	bo_temp=READ_BYTE(HL); \
	cp_temp=A-bo_temp; \
	lookup=((A&0x08)>>3)|((bo_temp&0x08 )>>2)|((cp_temp&0x08)>>1); \
	HL++; \
	BC--; \
	F=(F&FLAG_C)|(BC?(FLAG_V|FLAG_N):FLAG_N)|halfcarry_sub_table[lookup]|(cp_temp?0:FLAG_Z)|(cp_temp&FLAG_S ); \
	if(F&FLAG_H) \
	{ \
		cp_temp--; \
	} \
	F|=(cp_temp&FLAG_3)|((cp_temp&0x02)?FLAG_5:0); \
	MEMPTR=MEMPTR+1; \
}

#define CPD(rd) \
{ \
	bo_temp=READ_BYTE(HL); \
	cp_temp=A-bo_temp; \
	lookup=((A&0x08)>>3)|((bo_temp&0x08 )>>2)|((cp_temp&0x08)>>1); \
	HL--; \
	BC--; \
	F=(F&FLAG_C)|(BC?(FLAG_V|FLAG_N):FLAG_N)|halfcarry_sub_table[lookup]|(cp_temp?0:FLAG_Z)|(cp_temp&FLAG_S ); \
	if(F&FLAG_H) \
	{ \
		cp_temp--; \
	} \
	F|=(cp_temp&FLAG_3)|((cp_temp&0x02)?FLAG_5:0); \
	MEMPTR=MEMPTR-1; \
}

#define CPIR() \
{ \
	bo_temp=READ_BYTE(HL); \
	cp_temp=A-bo_temp; \
	lookup=((A&0x08)>>3)|((bo_temp&0x08 )>>2)|((cp_temp&0x08)>>1); \
	HL++; \
	BC--; \
	F=(F&FLAG_C)|(BC?(FLAG_V|FLAG_N):FLAG_N)|halfcarry_sub_table[lookup]|(cp_temp?0:FLAG_Z)|(cp_temp&FLAG_S ); \
	if(F&FLAG_H) \
	{ \
		cp_temp--; \
	} \
	F|=(cp_temp&FLAG_3)|((cp_temp&0x02)?FLAG_5:0); \
	if((F&(FLAG_V|FLAG_Z))==FLAG_V) \
	{ \
		PC-=2; \
		MEMPTR=PC+1; \
		T_WAIT_UNTIL(17); \
	} \
	else \
	{ \
		MEMPTR=MEMPTR+1; \
		T_WAIT_UNTIL(12); \
	} \
}

#define CPDR() \
{ \
	bo_temp=READ_BYTE(HL); \
	cp_temp=A-bo_temp; \
	lookup=((A&0x08)>>3)|((bo_temp&0x08 )>>2)|((cp_temp&0x08)>>1); \
	HL--; \
	BC--; \
	F=(F&FLAG_C)|(BC?(FLAG_V|FLAG_N):FLAG_N)|halfcarry_sub_table[lookup]|(cp_temp?0:FLAG_Z)|(cp_temp&FLAG_S ); \
	if(F&FLAG_H) \
	{ \
		cp_temp--; \
	} \
	F|=(cp_temp&FLAG_3)|((cp_temp&0x02)?FLAG_5:0); \
	if((F&(FLAG_V|FLAG_Z))==FLAG_V) \
	{ \
		PC-=2; \
		MEMPTR=PC+1; \
		T_WAIT_UNTIL(17); \
	} \
	else \
	{ \
		MEMPTR=MEMPTR-1; \
		T_WAIT_UNTIL(12); \
	} \
}

/*Instructions Table 8-Bit Arithmetic and Logical Group*/
#define ADD_A_AND_R(src) \
{ \
	add_temp=A+(src); \
	lookup=((A&0x88 )>>3 )|(((src)&0x88)>>2)|((add_temp&0x88)>>1); \
	A=add_temp; \
	F=(add_temp&0x100?FLAG_C:0)|halfcarry_add_table[lookup&0x07]|overflow_add_table[lookup>>4]|sz53_table[A]; \
}

#define ADD_A_AND_n \
{ \
	temp8=memory[PC]; \
	PC+=1; \
	add_temp=A+(temp8); \
	lookup=((A&0x88 )>>3 )|(((temp8)&0x88)>>2)|((add_temp&0x88)>>1); \
	A=add_temp; \
	F=(add_temp&0x100?FLAG_C:0)|halfcarry_add_table[lookup&0x07]|overflow_add_table[lookup>>4]|sz53_table[A]; \
}

#define ADD_A_AND_HL \
{ \
	temp8=memory[HL]; \
	add_temp=A+(temp8); \
	lookup=((A&0x88 )>>3 )|(((temp8)&0x88)>>2)|((add_temp&0x88)>>1); \
	A=add_temp; \
	F=(add_temp&0x100?FLAG_C:0)|halfcarry_add_table[lookup&0x07]|overflow_add_table[lookup>>4]|sz53_table[A]; \
}

#define ADD_A_AND_RP_AND_OFFSET(src) \
{ \
	d.u=memory[PC]; \
	PC+=1; \
	MEMPTR=(src+d.s); \
	temp8=memory[MEMPTR]; \
	add_temp=A+(temp8); \
	lookup=((A&0x88 )>>3 )|(((temp8)&0x88)>>2)|((add_temp&0x88)>>1); \
	A=add_temp; \
	F=(add_temp&0x100?FLAG_C:0)|halfcarry_add_table[lookup&0x07]|overflow_add_table[lookup>>4]|sz53_table[A]; \
}


#define SUB_A_AND_R(src) \
{ \
	sub_temp=A-(src); \
	lookup=((A&0x88)>>3)|(((src)&0x88)>>2)|((sub_temp&0x88)>>1); \
	A=sub_temp; \
	F=(sub_temp&0x100?FLAG_C:0)|FLAG_N|halfcarry_sub_table[lookup&0x07]|overflow_sub_table[lookup>>4]|sz53_table[A]; \
}

#define SUB_A_AND_n \
{ \
	temp8=memory[PC]; \
	PC+=1; \
	sub_temp=A-(temp8); \
	lookup=((A&0x88)>>3)|(((temp8)&0x88)>>2)|((sub_temp&0x88)>>1); \
	A=sub_temp; \
	F=(sub_temp&0x100?FLAG_C:0)|FLAG_N|halfcarry_sub_table[lookup&0x07]|overflow_sub_table[lookup>>4]|sz53_table[A]; \
}

#define SUB_A_AND_HL \
{ \
	temp8=memory[HL]; \
	sub_temp=A-(temp8); \
	lookup=((A&0x88)>>3)|(((temp8)&0x88)>>2)|((sub_temp&0x88)>>1); \
	A=sub_temp; \
	F=(sub_temp&0x100?FLAG_C:0)|FLAG_N|halfcarry_sub_table[lookup&0x07]|overflow_sub_table[lookup>>4]|sz53_table[A]; \
}

#define SUB_A_AND_RP_AND_OFFSET(temp8) \
{ \
	d.u=memory[PC]; \
	PC+=1; \
	MEMPTR=(temp8+d.s); \
	temp8=memory[MEMPTR]; \
	sub_temp=A-(temp8); \
	lookup=((A&0x88)>>3)|(((temp8)&0x88)>>2)|((sub_temp&0x88)>>1); \
	A=sub_temp; \
	F=(sub_temp&0x100?FLAG_C:0)|FLAG_N|halfcarry_sub_table[lookup&0x07]|overflow_sub_table[lookup>>4]|sz53_table[A]; \
}

#define INC_R(value) \
{ \
	(value)++; \
	F=(F&FLAG_C)|((value)==0x80?FLAG_V:0)|((value)&0x0f?0:FLAG_H)|sz53_table[(value)]; \
}

#define INC_ADDR_HL \
{ \
	temp8=memory[HL]; \
	temp8++; \
	F=(F&FLAG_C)|((temp8)==0x80?FLAG_V:0)|((temp8)&0x0f?0:FLAG_H)|sz53_table[(temp8)]; \
	if (HL>0x3fff) \
	{ \
		memory[HL]=temp8; \
	} \
}

#define INC_ADDR_RP_AND_OFSET(temp16) \
{ \
	d.u=memory[PC]; \
	PC+=1; \
	MEMPTR=(temp16+d.s); \
	temp8=memory[MEMPTR]; \
	temp8++; \
	F=(F&FLAG_C)|((temp8)==0x80?FLAG_V:0)|((temp8)&0x0f?0:FLAG_H)|sz53_table[(temp8)]; \
	if (MEMPTR>0x3fff) \
	{ \
		memory[MEMPTR]=temp8; \
	} \
}

#define DEC_R(value) \
{ \
	F=(F&FLAG_C)|((value)&0x0f?0:FLAG_H)|FLAG_N; \
	(value)--; \
	F|=((value)==0x7f?FLAG_V:0)|sz53_table[(value)]; \
}

#define DEC_ADDR_HL \
{ \
	temp8=memory[HL]; \
	F=(F&FLAG_C)|((temp8)&0x0f?0:FLAG_H)|FLAG_N; \
	temp8--; \
	F|=((temp8)==0x7f?FLAG_V:0)|sz53_table[(temp8)]; \
	if (HL>0x3fff) \
	{ \
		memory[HL]=temp8; \
	} \
}

#define DEC_ADDR_RP_AND_OFSET(temp16) \
{ \
	d.u=memory[PC]; \
	PC+=1; \
	MEMPTR=(temp16+d.s); \
	temp8=memory[MEMPTR]; \
	F=(F&FLAG_C)|((temp8)&0x0f?0:FLAG_H)|FLAG_N; \
	temp8--; \
	F|=((temp8)==0x7f?FLAG_V:0)|sz53_table[(temp8)]; \
	if (MEMPTR>0x3fff) \
	{ \
		memory[MEMPTR]=temp8; \
	} \
}

























#define ADDC(a, value) \
{ \
	add_temp=A+(value)+(F&FLAG_C); \
	lookup=((A&0x88)>>3)|(((value)&0x88)>>2 )|((add_temp&0x88)>>1); \
	A=add_temp; \
	F=(add_temp&0x100?FLAG_C:0)|halfcarry_add_table[lookup & 0x07]|overflow_add_table[lookup>>4]|sz53_table[A]; \
}

#define SUBC(a, value) \
{ \
	sub_temp=A-(value)-(F&FLAG_C); \
	lookup=((A&0x88)>>3)|(((value)&0x88)>>2)|((sub_temp&0x88)>>1); \
	A=sub_temp;\
	F=(sub_temp&0x100?FLAG_C:0)|FLAG_N|halfcarry_sub_table[lookup&0x07]|overflow_sub_table[lookup>>4]|sz53_table[A]; \
}

#define CP(value) \
{ \
	cp_temp=A-(value); \
	lookup=((A&0x88)>>3)|(((value)&0x88)>>2)|((cp_temp&0x88)>>1); \
	F=(cp_temp&0x100?FLAG_C:(cp_temp?0:FLAG_Z))|FLAG_N|halfcarry_sub_table[lookup&0x07]|overflow_sub_table[lookup>>4]|((value)&(FLAG_3|FLAG_5))|(cp_temp&FLAG_S); \
}

#define AND(value) \
{ \
	A&=(value); \
	F=FLAG_H|sz53p_table[A]; \
}

#define OR(value) \
{ \
	A|=(value); \
	F=sz53p_table[A]; \
}

#define XOR(value) \
{ \
	A^=(value); \
	F=sz53p_table[A]; \
}

/*Instructions Table General-Purpose Arithmetic and CPU Control Group*/
#define DI() \
{ \
	IFF1=IFF2=0; \
}

#define EI() \
{ \
	IFF1=IFF2=1; \
}

#define IM_MODE(value) \
{ \
	IM=(value); \
}

#define CPL() \
{ \
	A^= 0xff; \
	F=(F&(FLAG_C|FLAG_P|FLAG_Z|FLAG_S))|(A&(FLAG_3|FLAG_5))|(FLAG_N|FLAG_H); \
}

#define NEG() \
{ \
	neg_temp=A; \
	A=0; \
	SUB_A_AND_R(neg_temp); \
}

#define SCF() \
{ \
	F=(F&(FLAG_P|FLAG_Z|FLAG_S))|(A&(FLAG_3|FLAG_5))|FLAG_C; \
}

#define CCF() \
{ \
	F=(F&(FLAG_P|FLAG_Z|FLAG_S))|((F&FLAG_C)?FLAG_H:FLAG_C)|(A&(FLAG_3|FLAG_5)); \
}

#define HALT() \
{ \
	halt=1; \
}

#define DAA() \
{ \
	daa_temp=((A+0x100*((F&3)+((F>>2)&4)))*2); \
	F=daatab[daa_temp]; \
	A=daatab[daa_temp+1]; \
}

/*Instructions Table 16-Bit Arithmetic Group*/
#define ADD16(value1, value2) \
{ \
	add_temp=(value1)+(value2); \
	lookup=(((value1)&0x0800)>>11)|(((value2)&0x0800)>>10)|((add_temp&0x0800)>>9 );  \
	MEMPTR=value1+1; \
	(value1)=add_temp; \
	F=(F&(FLAG_V|FLAG_Z|FLAG_S))|(add_temp&0x10000?FLAG_C:0)|((add_temp>>8)&(FLAG_3|FLAG_5))|halfcarry_add_table[lookup]; \
}

#define INC16(value) \
{ \
	(value)++; \
}

#define DEC16(value) \
{ \
	(value)--; \
}

#define ADDC16(hl, value) \
{ \
	add_temp=HL+(value)+(F&FLAG_C); \
	lookup=((HL&0x8800)>>11)|(((value)&0x8800)>>10)|((add_temp&0x8800)>>9); \
	MEMPTR=hl+1; \
	HL=add_temp; \
	F=(add_temp&0x10000?FLAG_C:0)|overflow_add_table[lookup>>4]|(H&(FLAG_3|FLAG_5|FLAG_S))|halfcarry_add_table[lookup&0x07]|(HL?0:FLAG_Z); \
}

#define SUBC16(hl, value) \
{ \
	sub_temp=HL-(value)-(F&FLAG_C); \
	lookup=((HL&0x8800)>>11)|(((value)&0x8800)>>10)|((sub_temp&0x8800)>>9); \
	MEMPTR=hl+1; \
	HL=sub_temp; \
	F=(sub_temp&0x10000?FLAG_C:0)|FLAG_N|overflow_sub_table[lookup>>4]|(H&(FLAG_3|FLAG_5|FLAG_S))|halfcarry_sub_table[lookup&0x07]|(HL?0:FLAG_Z); \
}

/*Instructions Rotate and Shift Group*/
#define SRL(value) \
{ \
	F=(value)&FLAG_C; \
	(value)>>=1; \
	F|=sz53p_table[(value)]; \
}

#define SRA(value) \
{ \
	F=(value)&FLAG_C; \
	(value)=((value)&0x80)|((value)>>1); \
	F|=sz53p_table[(value)]; \
}

#define SLA(value) \
{ \
	F=(value)>>7; \
	(value)<<=1; \
	F|=sz53p_table[(value)]; \
}

#define SLL(value) \
{ \
	F=(value)>>7; \
	(value)=((value)<<1)|0x01; \
	F|=sz53p_table[(value)]; \
}

#define RL(value) \
{ \
	rot_temp=(value); \
	(value)=((value)<<1)|( F & FLAG_C ); \
	F=(rot_temp>>7)|sz53p_table[(value)]; \
}

#define RR(value) \
{ \
	rot_temp=(value); \
	(value)=((value)>>1)|(F<<7); \
	F=(rot_temp&FLAG_C)|sz53p_table[(value)]; \
}

#define RLC(value) \
{ \
	(value)=((value)<<1)|((value)>>7); \
	F=((value)&FLAG_C)|sz53p_table[(value)]; \
}

#define RRC(value) \
{ \
	F=(value)&FLAG_C; \
	(value)=((value)>>1)|((value)<<7); \
	F|=sz53p_table[(value)]; \
}

#define RLA() \
{ \
	rot_temp=A; \
	A=(A<<1)|(F&FLAG_C); \
	F=(F&(FLAG_P|FLAG_Z|FLAG_S))|(A&(FLAG_3|FLAG_5))|(rot_temp>>7); \
}

#define RRA() \
{ \
	rot_temp=A; \
	A=(A>>1)|(F<<7); \
	F=(F&(FLAG_P|FLAG_Z|FLAG_S))|(A&(FLAG_3|FLAG_5))|(rot_temp&FLAG_C); \
}

#define RLCA() \
{ \
	A=(A<<1)|(A>>7); \
	F=(F&(FLAG_P|FLAG_Z|FLAG_S))|(A&(FLAG_C|FLAG_3|FLAG_5)); \
}

#define RRCA() \
{ \
	F=(F&(FLAG_P|FLAG_Z|FLAG_S))|(A&FLAG_C); \
	A=(A>>1)|(A<<7); \
	F|=(A&(FLAG_3|FLAG_5)); \
}

#define RRD() \
{ \
	rot_temp=READ_BYTE(HL); \
	WRITE_BYTE(HL, (A<<4)|(rot_temp>>4)); \
	A=(A&0xf0)|(rot_temp&0x0f); \
	F=(F&FLAG_C)|sz53p_table[A]; \
	MEMPTR=HL+1; \
}

#define RLD() \
{ \
	rot_temp=READ_BYTE(HL); \
	WRITE_BYTE(HL, (rot_temp<<4)|(A&0x0f)); \
	A=(A&0xf0)|(rot_temp>>4); \
	F=(F&FLAG_C)|sz53p_table[A]; \
	MEMPTR=HL+1; \
}

/*Instructions Bit Set, Reset and Test Group*/
#define BIT(bit, value) \
{ \
	F=(F&FLAG_C)|FLAG_H|sz53p_table[(value)&(0x01<<(bit))]|((value)&0x28); \
}

/*BIT n,(IX+d/IY+d) and BIT n,(HL)*/
#define BIT_MPTR(bit, value) \
{ \
	F=(F&FLAG_C)|FLAG_H|(sz53p_table[(value)&(0x01<<(bit))]&0xD7)|((MEMPTRH)&0x28); \
}

#define SET(bit, value) \
{ \
	value|=(1<<bit); \
}

#define RES(bit, value) \
{ \
	value&=~(1<<bit); \
}

/*Instructions Table Jump Group*/
#define JP(addr) \
{ \
	PC=addr; \
	MEMPTR=addr; \
}

#define JP_NO_MPTR(addr) \
{ \
	PC=addr; \
}

#define JR(offset) \
{ \
	PC+=offset; \
	MEMPTR=PC; \
}

/*Instructions Table Call and Return Group*/
#define RST(addr) \
{ \
	PUSH(PC); \
	PC=addr; \
	MEMPTR=PC; \
}

#define CALL(addr) \
{ \
	PUSH(PC); \
	PC=addr; \
	MEMPTR=addr; \
}

#define RET() \
{ \
	POP(PC); \
	MEMPTR=PC; \
}

/*same as RETI, only opcode is different*/
#define RETN() \
{ \
	IFF1=IFF2; \
	RET(); \
}

#define RETI() \
{ \
	IFF1=IFF2; \
	RET(); \
}
/*Instructions Input and Output Group*/
#define IN_A(reg, port) \
{ \
	reg=READ_PORT(port); \
	MEMPTR=port+1; \
}

#define IN(reg, port) \
{ \
	reg=READ_PORT(port); \
	F=(F&FLAG_C)|sz53p_table[(reg)]; \
	MEMPTR=port+1; \
}

#define IN_F(port) \
{ \
	in_temp=READ_PORT(port); \
	F=(F& FLAG_C)|sz53p_table[in_temp]; \
	MEMPTR=port+1; \
}

#define INI() \
{ \
	MEMPTR=BC+1; \
	bo_temp=READ_PORT(BC); \
	WRITE_BYTE(HL, bo_temp); \
	B--; \
	HL++; \
	F=(bo_temp&0x80?FLAG_N:0)|sz53_table[B]; \
	IN_BL(bo_temp, 1); \
}

#define IND() \
{ \
	MEMPTR=BC-1; \
	bo_temp=READ_PORT(BC); \
	WRITE_BYTE(HL, bo_temp); \
	B--; \
	HL--; \
	F=(bo_temp&0x80?FLAG_N:0 )|sz53_table[B]; \
	IN_BL(bo_temp, -1); \
}

#define INIR() \
{ \
	bo_temp=READ_PORT(BC); \
	WRITE_BYTE(HL, bo_temp); \
	MEMPTR=BC+1; \
	B--; \
	HL++; \
	F=(bo_temp&0x80?FLAG_N:0)|sz53_table[B]; \
	if(B) \
	{ \
		PC -= 2; \
		T_WAIT_UNTIL(17); \
	} \
	else \
	{ \
		T_WAIT_UNTIL(12); \
	} \
	IN_BL(bo_temp, 1); \
}

#define INDR() \
{ \
	bo_temp=READ_PORT(BC); \
	WRITE_BYTE(HL, bo_temp); \
	MEMPTR=BC-1;\
	B--; \
	HL--; \
	F=(bo_temp&0x80?FLAG_N:0)|sz53_table[B]; \
	if(B) \
	{ \
		PC -= 2; \
		T_WAIT_UNTIL(17); \
	} \
	else \
	{ \
		T_WAIT_UNTIL(12); \
	} \
	IN_BL(bo_temp, -1); \
}

/*undocumented flag effects for block input operations*/
#define IN_BL(pbyte, c_add) \
{ \
	if((pbyte+((C+(c_add))&0xff))>255) F|=(FLAG_C|FLAG_H); \
	F|=parity_table[(((pbyte+((C+(c_add))&0xff))&7)^B)]; \
}

#define OUT_A(port, reg) \
{ \
	WRITE_PORT(port, reg); \
	MEMPTRL=((port+1)&0xFF); \
	MEMPTRH=A; \
}

#define OUT(port, reg) \
{ \
	WRITE_PORT(port, reg); \
	MEMPTR=port+1; \
}

#define OUTI() \
{ \
	bo_temp=READ_BYTE(HL); \
	B--; \
	MEMPTR=BC+1; \
	WRITE_PORT(BC, bo_temp); \
	HL++; \
	F=(bo_temp&0x80?FLAG_N:0)|sz53_table[B]; \
	OUT_BL(bo_temp); \
}

#define OUTD() \
{ \
	bo_temp=READ_BYTE(HL); \
	B--; \
	MEMPTR=BC-1; \
	WRITE_PORT(BC, bo_temp); \
	HL--; \
	F= (bo_temp&0x80?FLAG_N:0 )|sz53_table[B]; \
	OUT_BL(bo_temp); \
}

#define OTIR() \
{ \
	bo_temp=READ_BYTE(HL); \
	B--; \
	MEMPTR=BC+1; \
	WRITE_PORT(BC, bo_temp); \
	HL++; \
	F=(bo_temp&0x80?FLAG_N:0)|sz53_table[B]; \
	if(B) \
	{ \
		PC-= 2; \
		T_WAIT_UNTIL(17); \
	} \
	else \
	{ \
		T_WAIT_UNTIL(12);\
	} \
	OUT_BL(bo_temp); \
}

#define OTDR() \
{ \
	bo_temp=READ_BYTE(HL); \
	B--; \
	MEMPTR=BC-1; \
	WRITE_PORT(BC, bo_temp); \
	HL--; \
	F=(bo_temp&0x80?FLAG_N:0)|sz53_table[B]; \
	if(B) \
	{ \
		PC-= 2; \
		T_WAIT_UNTIL(17); \
	} \
	else \
	{ \
		T_WAIT_UNTIL(12); \
	} \
	OUT_BL(bo_temp); \
}

/*undocumented flag effects for block output operations*/
#define OUT_BL(pbyte) \
{ \
	if((pbyte+L)>255) F|=(FLAG_C|FLAG_H); \
	F|=parity_table[(((pbyte+L)&7)^B)]; \
}

#endif /* INC_Z80_MACROS_H_ */
