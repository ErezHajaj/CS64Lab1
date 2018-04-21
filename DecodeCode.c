#include "DecodeCode.h"


mipsinstruction decode(int value)
{
	mipsinstruction instr;

	// TODO: fill in the fields
	instr.funct = (value & 0x3F);

	int im = value & 0xFFFF;
        if(im & 0x8000) {
          instr.immediate = ((im & 0xFFFF) << 28) >> 28;
        } else {
          instr.immediate = im;
	}

	instr.rd = (value >> 11) & 0x1F;
	instr.rt = (value >> 16) & 0x1F;
	instr.rs = (value >> 21) & 0x1F;
	instr.opcode = (value >> 26) & 0x3F;

	return instr;
}


