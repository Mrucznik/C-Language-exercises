#include <stdio.h>

union intbajt
{
	int integer;
	unsigned char bajt[4];
};

struct sBit8
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

struct sBit32
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

union Bit
{
	unsigned char bajt;
	struct sBit8 bit;
};


union manyForms
{
	unsigned int integer;
	unsigned short slowo[2];
	unsigned char bajt[4];
	struct sBit32 bit32;
	struct sBit8 bit8[4];
};

void print8BitUnion(union Bit u)
{
	unsigned int maska = 0b1;
	while (maska != (0b1 << 8))
	{
		printf(u.bajt & maska ? "1" : "0");
		maska <<= 1;
	}
}

void print32BitUnion(union manyForms u)
{
	unsigned int maska = 0b1;
	while (maska != (0b1 << 32))
	{
		printf(u.integer & maska ? "1" : "0");
		maska <<= 1;
	}
}

int main()
{
	//Zadanie 1-2
	union intbajt u;
	u.integer = 122443244;
	printf("%d %d\n", u.bajt[0], u.bajt[3]);

	//Zadanie 3.
	union Bit bitunion;
	printf("Podaj wartosc bajta : ");
	scanf("%d", &bitunion.bajt);
	printf("\n");
	print8BitUnion(bitunion);

	//Zadanie 4.
	union manyForms many;
	many.integer = 122443244;
	printf("%u", many.integer);
	printf("%u%u", many.slowo[0], many.slowo[2]);
	print32BitUnion(many);

	return 0;
}