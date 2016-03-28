//main.c

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int czyPierwsza(int a)
{
	if (a <= 1) return 0;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void pierwszePrzedzial(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		if (czyPierwsza(i))
		{
			printf("Pierwsza: %d\n", i);
		}
	}
}

void blizniacze(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		if (czyPierwsza(i) && czyPierwsza(i + 2))
		{
			printf("Liczby blizniacze: %d i %d\n", i, i + 2);
		}
	}
}

void goldbach(int a, int b)
{
	int check[2] = {0, 0};
	if (a % 2 != 0) a++;
	for (int i = a; i <= b; i += 2)
	{
		for (int g = 2; g <= i; g++)
		{
			if (czyPierwsza(g))
			{
				for (int h = 2; h <= i; h++)
				{
					if (czyPierwsza(h))
					{
						if (g + h == i)
						{
							printf("Dla %d hipoteza Goldbacha poprawna.\n", i);
							check[1]++;
							goto etykieta;
						}
					}
				}
			}
		}
	etykieta:
		check[0]++;
	}
	if (check[0] == check[1])
		printf("Hipoteza Goldbacha prawdziwa!\n\n");
}

int main(void)
{
	int a, b;
	char c = 'x';
	do //Pobieranie danych:
	{
		printf("Podaj przedzial <a, b>: ");
		scanf("%d%d", &a, &b);
	}
	while (b <= a);

	fflush(stdin);

	do
	{
		printf("Wybierz opcje:\nA - liczby pierwsze\nB - Liczby blizniacze\nC - Hipoteza Goldbacha\n: ");
		scanf("%c", &c);
	}
	while (c < 'A' || c > 'C');

	switch (c)
	{
	case 'A':
		pierwszePrzedzial(a, b);
		break;
	case 'B':
		blizniacze(a, b);
		break;
	case 'C':
		if (a <= 2)
		{
			printf("Niepoprawny przedzial (Hipoteza goldbacha jest sformulowana tylko dla liczb > 2!");
			return 0;
		}
		goldbach(a, b);
		break;
	default:
		printf("Error");
		break;
	}

	return 0;
}

