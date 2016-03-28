//main.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PRZEDZIAL 1001

int czyPierwsza(int a)
{
	if (a <= 1) return 0;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
			return 0;
	}
	return 1;
}

int main(void)
{
	int W[MAX_PRZEDZIAL];
	int a, b;
	int n = 0;

	do //Pobieranie danych:
	{
		printf("Podaj przedzial <a, b> (maksymalna rozpietsoc przedzialu to %d): ", MAX_PRZEDZIAL - 1);
		scanf("%d%d", &a, &b);
	}
	while (b <= a || b - a >= MAX_PRZEDZIAL);

	//Obliczanie i zapisywanie danych
	for (int i = a; i < b; i++)
	{
		if (czyPierwsza(i) || i % 23 == 0)
		{
			W[n] = i;
			n++;
		}
	}

	//Wyœwietlanie danych
	int lines = 0;
	for (int i = 0; i < n; i++)
	{
		printf("Liczba %d\n", W[i]);
		lines++;
		if (lines % 24 == 0)
			system("pause");
	}
	return 0;
}

