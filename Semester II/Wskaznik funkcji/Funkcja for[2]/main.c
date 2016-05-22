#include <stdio.h>

void myfor(double poczatek, double krok, double koniec, void (*func)(double))
{
	double i = poczatek;
	while((krok > 0) ? (i <= koniec) : (i >= koniec))
	{
		func(i);
		i+=krok;
	}
}

void wyswietl(double a)
{
	printf("%.02lf ", a);
}

int main(void)
{
	myfor(0, 10, 40, wyswietl); putchar('\n');
	myfor(3, 10, 45, wyswietl); putchar('\n');
	myfor(-20, 1.1, 10, wyswietl); putchar('\n');
	myfor(-50, -3.14, -60, wyswietl); putchar('\n');
	return 0;
}