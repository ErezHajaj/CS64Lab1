#include "stdio.h"
#include "stdlib.h"

int multiplyBy8(int v) {
   return v << 3;
}

int setBit6to1(int v)
{
  //set bit 6 to 1
  return v | (1 << 6);
}

int setBit3to0(int v)
{
	// TODO: set bit 3 to 0
  return v & ~(1 << 3);
}
	
int flipBit5(int v)
{
	// TODO: flip bit 5 (if it is 0, make it 1.  If 0, make 1)
  return v ^ ( 1<<5 );
}
	
int ifBit7is0(int v)
{
	// TODO: check to see if bit 7 is a 0 - return 1 if true, 0 if false
  if (1 & (v >> 7)) {
    return 0;
  } else {
    return 1;
  }
}

int ifBit3is1(int v)
{
	// check to see if bit 3 is a 1 - return 1 if true, 0 if false
  if (1 & (v >> 3)) {
    return 1;
  }
  else {return 0;}
}

int unsignedBits0through5(int v)
{
	// return the unsigned value in bits 0 through 5
	return v & 0x3F;
}

int unsignedBits6through9(int v)
{
	// return the unsigned value in bits 6 through 9
  return (v & 0x3C0) >> 6;
}

int signedBits0through5(int v)
{
	// return the signed value in bits 0 through 5
  v &= 0x3F;
  if (v & 0x20) return v | ~(0x3F);
  else return v;
}

int signedBits6through9(int v)
{
	// return the signed value in bits 6 through 9
  v &= 0x3C0;
  if (v & 0x200) return (v | ~(0x3C0)) >> 6;
  else return v >> 6;
}

int setBits4through9(int v, int setValue)
{
	// set bits 4 through 9 in v to become setValue
  v &= 0xFFFFFC0F;
  v |= ((0x3F & setValue) << 4);
  return v;
}
