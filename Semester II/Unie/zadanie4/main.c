#include <stdio.h>

struct Bit32
{
	unsigned b1 : 1;
	unsigned b2 : 1;
	unsigned b3 : 1;
	unsigned b4 : 1;
	unsigned b5 : 1;
	unsigned b6 : 1;
	unsigned b7 : 1;
	unsigned b8 : 1;
	unsigned b9 : 1;
	unsigned b10 : 1;
	unsigned b11 : 1;
	unsigned b12 : 1;
	unsigned b13 : 1;
	unsigned b14 : 1;
	unsigned b15 : 1;
	unsigned b16 : 1;
	unsigned b17 : 1;
	unsigned b18 : 1;
	unsigned b19 : 1;
	unsigned b20 : 1;
	unsigned b21 : 1;
	unsigned b22 : 1;
	unsigned b23 : 1;
	unsigned b24 : 1;
	unsigned b25 : 1;
	unsigned b26 : 1;
	unsigned b27 : 1;
	unsigned b28 : 1;
	unsigned b29 : 1;
	unsigned b30 : 1;
	unsigned b31 : 1;
	unsigned b32 : 1;
};

void printBit32Struct(struct Bit32 u)
{
	unsigned int maska = 0b1;
	while (maska != 0b1 << 32)
	{
		printf(*(unsigned int*)&u & maska ? "1" : "0");
		maska <<= 1;
	}
}

struct Bit8
{
	unsigned char b1 : 1;
	unsigned char b2 : 1;
	unsigned char b3 : 1;
	unsigned char b4 : 1;
	unsigned char b5 : 1;
	unsigned char b6 : 1;
	unsigned char b7 : 1;
	unsigned char b8 : 1;
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
	union intwordbytebit
	{
		unsigned int integer;
		unsigned short word[2];
		unsigned char byte[4];
		struct Bit8 bit8[4];
		struct Bit32 bit32;
	} u;

	printf("Enter an unsigned integer value: ");
	scanf("%d", &u.integer);
	printf("This value in unsinged int type looks like: %u\n", u.integer);
	printf("This value in two words looks like: %d %d\n", u.word[0], u.word[1]);
	printf("This value in 4 bytes looks like: %d %d %d %d\n", u.byte[0], u.byte[1], u.byte[2], u.byte[3]);
	printf("This value in 4x 8 bit looks like: ");
	printBit8Struct(u.bit8[0]);
	printf(" ");
	printBit8Struct(u.bit8[1]);
	printf(" ");
	printBit8Struct(u.bit8[2]);
	printf(" ");
	printBit8Struct(u.bit8[3]);
	printf("\nThis value in bits looks like: ");
	printBit32Struct(u.bit32);
	printf("\n");
	return 0;
}

