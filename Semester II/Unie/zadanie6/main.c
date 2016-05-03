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
	printf(u.b1 ? "1" : "0");
	printf(u.b2 ? "1" : "0");
	printf(u.b3 ? "1" : "0");
	printf(u.b4 ? "1" : "0");
	printf(u.b5 ? "1" : "0");
	printf(u.b6 ? "1" : "0");
	printf(u.b7 ? "1" : "0");
	printf(u.b8 ? "1" : "0");
	printf(u.b9 ? "1" : "0");
	printf(u.b10 ? "1" : "0");
	printf(u.b11 ? "1" : "0");
	printf(u.b12 ? "1" : "0");
	printf(u.b13 ? "1" : "0");
	printf(u.b14 ? "1" : "0");
	printf(u.b15 ? "1" : "0");
	printf(u.b16 ? "1" : "0");
	printf(u.b17 ? "1" : "0");
	printf(u.b18 ? "1" : "0");
	printf(u.b19 ? "1" : "0");
	printf(u.b20 ? "1" : "0");
	printf(u.b21 ? "1" : "0");
	printf(u.b22 ? "1" : "0");
	printf(u.b23 ? "1" : "0");
	printf(u.b24 ? "1" : "0");
	printf(u.b25 ? "1" : "0");
	printf(u.b26 ? "1" : "0");
	printf(u.b27 ? "1" : "0");
	printf(u.b28 ? "1" : "0");
	printf(u.b29 ? "1" : "0");
	printf(u.b30 ? "1" : "0");
	printf(u.b31 ? "1" : "0");
	printf(u.b32 ? "1" : "0");
}

struct Bit16
{
	unsigned char b1 : 1;
	unsigned char b2 : 1;
	unsigned char b3 : 1;
	unsigned char b4 : 1;
	unsigned char b5 : 1;
	unsigned char b6 : 1;
	unsigned char b7 : 1;
	unsigned char b8 : 1;
	unsigned char b9 : 1;
	unsigned char b10 : 1;
	unsigned char b11 : 1;
	unsigned char b12 : 1;
	unsigned char b13 : 1;
	unsigned char b14 : 1;
	unsigned char b15 : 1;
	unsigned char b16 : 1;
};

void printBit16Struct(struct Bit16 u)
{
	printf(u.b1 ? "1" : "0");
	printf(u.b2 ? "1" : "0");
	printf(u.b3 ? "1" : "0");
	printf(u.b4 ? "1" : "0");
	printf(u.b5 ? "1" : "0");
	printf(u.b6 ? "1" : "0");
	printf(u.b7 ? "1" : "0");
	printf(u.b8 ? "1" : "0");
	printf(u.b9 ? "1" : "0");
	printf(u.b10 ? "1" : "0");
	printf(u.b11 ? "1" : "0");
	printf(u.b12 ? "1" : "0");
	printf(u.b13 ? "1" : "0");
	printf(u.b14 ? "1" : "0");
	printf(u.b15 ? "1" : "0");
	printf(u.b16 ? "1" : "0");
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
	printf(u.b1 ? "1" : "0");
	printf(u.b2 ? "1" : "0");
	printf(u.b3 ? "1" : "0");
	printf(u.b4 ? "1" : "0");
	printf(u.b5 ? "1" : "0");
	printf(u.b6 ? "1" : "0");
	printf(u.b7 ? "1" : "0");
	printf(u.b8 ? "1" : "0");
}

union Liczba
{
	int integer;
	struct Bit32 bit32;
	struct Bit16 bit16[2];
	struct Bit8 bit8[4];
};

int main(void)
{
	union Liczba liczba;
	printf("Podaj liczbe calkowita: ");
	scanf("%d", &liczba.integer);
	printf("\nTa liczba w postaci 1 liczby 32 bitowej: ");
	printBit32Struct(liczba.bit32);
	printf("\nTa liczba w postaci 2 liczb 16 bitowych: ");
	for (int i = 0; i < 2; i++)
	{
		printBit16Struct(liczba.bit16[i]);
		putchar(' ');
	}
	printf("\nTa liczba w postaci 4 liczb 8 bitowych: ");
	for (int i = 0; i < 4; i++)
	{
		printBit8Struct(liczba.bit8[i]);
		putchar(' ');
	}
	printf("\nTa liczba w postaci 8 liczb 4 bitowych: ");
	for (int i = 0; i < 4; i++)
	{
		printf(liczba.bit8[i].b1 ? "1" : "0");
		printf(liczba.bit8[i].b2 ? "1" : "0");
		printf(liczba.bit8[i].b3 ? "1" : "0");
		printf(liczba.bit8[i].b4 ? "1" : "0");
		putchar(' ');
		printf(liczba.bit8[i].b5 ? "1" : "0");
		printf(liczba.bit8[i].b6 ? "1" : "0");
		printf(liczba.bit8[i].b7 ? "1" : "0");
		printf(liczba.bit8[i].b8 ? "1" : "0");
		putchar(' ');
	}
	printf("\nTa liczba w postaci 16 liczb 2 bitowych: ");
	for (int i = 0; i < 4; i++)
	{
		printf(liczba.bit8[i].b1 ? "1" : "0");
		printf(liczba.bit8[i].b2 ? "1" : "0");
		putchar(' ');
		printf(liczba.bit8[i].b3 ? "1" : "0");
		printf(liczba.bit8[i].b4 ? "1" : "0");
		putchar(' ');
		printf(liczba.bit8[i].b5 ? "1" : "0");
		printf(liczba.bit8[i].b6 ? "1" : "0");
		putchar(' ');
		printf(liczba.bit8[i].b7 ? "1" : "0");
		printf(liczba.bit8[i].b8 ? "1" : "0");
		putchar(' ');
	}
	printf("\nTa liczba w postaci 32 liczb 1 bitowych: ");
	for (int i = 0; i < 4; i++)
	{
		printf(liczba.bit8[i].b1 ? "1" : "0");
		putchar(' ');
		printf(liczba.bit8[i].b2 ? "1" : "0");
		putchar(' ');
		printf(liczba.bit8[i].b3 ? "1" : "0");
		putchar(' ');
		printf(liczba.bit8[i].b4 ? "1" : "0");
		putchar(' ');
		printf(liczba.bit8[i].b5 ? "1" : "0");
		putchar(' ');
		printf(liczba.bit8[i].b6 ? "1" : "0");
		putchar(' ');
		printf(liczba.bit8[i].b7 ? "1" : "0");
		putchar(' ');
		printf(liczba.bit8[i].b8 ? "1" : "0");
		putchar(' ');
	}
	return 0;
}