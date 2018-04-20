#include "DecodeCode.h"


mipsinstruction decode(int value)
{
	mipsinstruction instr;

	// TODO: fill in the fields
	instr.funct = 15;
	instr.immediate = -10;
	instr.rd = 0;
	instr.rt = 5;
	instr.rs = 3;
	instr.opcode = 25;

	return instr;
}


