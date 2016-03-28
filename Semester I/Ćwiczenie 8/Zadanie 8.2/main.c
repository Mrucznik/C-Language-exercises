//main.c

#include <stdio.h>
#include <stdlib.h>

#define MAX_PRZEDZIAL 101

double funkcja(int n)
{
	if (n % 2 == 0) //parzysta
	{
		return n / 2 + n * n;
	}
	else //nieparzysta
	{
		return (double)(n - 5) / n;
	}
}


int main(void)
{
	int a, b;
	double W[MAX_PRZEDZIAL];

	do //Pobieranie danych:
	{
		printf("Podaj przedzial <a, b> (maksymalna rozpietsoc przedzialu to %d): ", MAX_PRZEDZIAL - 1);
		scanf("%d%d", &a, &b);
	}
	while (b <= a || b - a >= MAX_PRZEDZIAL || a <= 0);

	//Obliczanie funkcji:
	for (int i = 0; i <= b - a; i++)
	{
		W[i] = funkcja(i + a);
	}

	//Wyœwietlanie wyników
	int lines = 0;
	for (int i = 0; i <= b - a; i++)
	{
		printf("W(%d)=\t %.3lf\n", i + a, W[i]);
		lines++;
		if (lines % 24 == 0)
			system("pause");
	}
	return 0;
}