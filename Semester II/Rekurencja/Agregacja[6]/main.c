#include <stdio.h>

double suma(double a, double b)
{
	return a + b;
}

double roznica(double a, double b)
{
	return a - b;
}

double iloczyn(double a, double b)
{
	return a * b;
}

double iloraz(double a, double b)
{
	return a / b;
}

double agregacja(double tab[], int n, double(*func)(double, double))
{
	if (n >= 1)
		return func(agregacja(tab, n - 1, func), tab[n]);
	return tab[0];
}

int main(void)
{
	double tab[] = { 8, 3, 2, 5, 4 };
	printf("Suma: %lf\n", agregacja(tab, 4, suma));
	printf("Roznica: %lf\n", agregacja(tab, 4, roznica));
	printf("Iloczyn: %lf\n", agregacja(tab, 4, iloczyn));
	printf("Iloraz: %lf\n", agregacja(tab, 4, iloraz));
	return 0;
}