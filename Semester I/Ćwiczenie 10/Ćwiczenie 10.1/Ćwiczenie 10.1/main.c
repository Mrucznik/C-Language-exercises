#include <stdio.h>
#include <stdlib.h>

#define TYP long double

TYP SilniaRekurencyjna(int a)
{
	if (a == 0) return 1;
	return a * SilniaRekurencyjna(a - 1);
}

TYP SilniaIteracyjna(int a)
{
	TYP wynik = 1;
	for (int i = 2; i <= a; i++)
	{
		wynik *= i;
	}
	return wynik;
}

int main(void)
{
	char c;
	int liczba;
	TYP silnia;
	printf("Wybierz metode wyznaczania silni (0-iteracyjna, 1-rekurencyjna): ");
	scanf("%c", &c);
	printf("Podaj liczbe dla ktorej obliczyc silnie: ");
	scanf("%d", &liczba);

	if (c == '0')
	{
		silnia = SilniaIteracyjna(liczba);
	}
	else
	{
		silnia = SilniaRekurencyjna(liczba);
	}
	printf("Wynik: %d! = %.0lf\n", liczba, silnia);

	return 0;
}

//Typy daych:
//signed char - 5
//unsigned char - 5
//short int - 7
//short unsigned int - 8
//int - 12
//unsigned int - 12
//long int - 12
//long unsigned int - 12
//long long int - 20
//long long unsigned int - 20

//float - 34
//double - 170
//long double - 170


