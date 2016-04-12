#include <stdio.h>

struct Bit8
{
	unsigned b1 : 1;
	unsigned b2 : 1;
	unsigned b3 : 1;
	unsigned b4 : 1;
	unsigned b5 : 1;
	unsigned b6 : 1;
	unsigned b7 : 1;
	unsigned b8 : 1;
};

void printBit8Struct(struct Bit8 u)
{
	unsigned int maska = 0b1;
	while (maska != 0b1 << 8)
	{
		printf(*(unsigned char*)&u & maska ? "1" : "0");
		maska <<= 1;
	}
}

int main()
{
	union bytebit
	{
		unsigned char byte;
		struct Bit8 bit;
	} u;
	printf("Enter a byte value: ");
	scanf("%d", &u.byte);
	printf("This value in bits: ");
	printBit8Struct(u.bit);
	return 0;
}

