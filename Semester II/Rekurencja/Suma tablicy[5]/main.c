#include <stdio.h>

double suma(double tab[], int n)
{
	if (n >= 1)
		return suma(tab, n - 1) + tab[n];
	return tab[0];
}

double roznica(double tab[], int n)
{
	if (n >= 1)
		return roznica(tab, n - 1) - tab[n];
	return tab[0];
}

double iloczyn(double tab[], int n)
{
	if (n >= 1)
		return iloczyn(tab, n - 1) * tab[n];
	return tab[0];
}

double iloraz(double tab[], int n)
{
	if (n >= 1)
		return iloraz(tab, n - 1) / tab[n];
	return tab[0];
}

int main(void)
{
	double tab[] = { 8, 3, 2, 5, 4 };
	printf("Suma: %lf\n", suma(tab, 4));
	printf("Roznica: %lf\n", roznica(tab, 4));
	printf("Iloczyn: %lf\n", iloczyn(tab, 4));
	printf("Iloraz: %lf\n", iloraz(tab, 4));
	return 0;
}