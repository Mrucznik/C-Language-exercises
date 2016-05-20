#include <stdio.h>
#include <stdlib.h>

typedef (*OP)(int, int);

typedef enum TYPY
{
	Suma, Roznica, Iloczyn, Iloraz
} TYP;

int sumuj(int a, int b)
{
	return a + b;
}

int odejmij(int a, int b)
{
	return a - b;
}

int pomnoz(int a, int b)
{
	return a * b;
}

int podziel(int a, int b)
{
	if (b == 0)
	{
		puts("Nie mozna podzielic przez 0!");
		exit(1);
	}
	return a / b;
}

OP operacja(TYP operator)
{
	switch (operator)
	{
	case Suma:
		return sumuj;
	case Roznica:
		return odejmij;
	case Iloczyn:
		return pomnoz;
	case Iloraz:
		return podziel;
	default:
		puts("NULL ERROR w funkcji operacja");
		exit(1);
	}
}

int main(void)
{
	int liczby[2];
	TYP operator;
	puts("Podaj 2 liczby: ");
	scanf("%d%d", &liczby[0], &liczby[1]);
	puts("Podaj jaka operacje wykonac [0-suma, 1-roznica, 2-iloczyn, 3-iloraz]: ");
	scanf("%d", &operator);
	printf("Wynik: %d\n", operacja(operator)(liczby[0], liczby[1]));
	return 0;
}