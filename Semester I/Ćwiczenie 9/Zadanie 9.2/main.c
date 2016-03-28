//main.c

#include <stdio.h>
#include <math.h>

#define ILOSC_PARZYSTYCH 40

int czyPierwsza(int a)
{
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int tablicowanieLiczbPierwszych(int array[])
{
	int ilosc_pierwszych = 0;
	for (int i = 2; i <= ILOSC_PARZYSTYCH + 2; i++)
	{
		if (czyPierwsza(i))
		{
			array[ilosc_pierwszych] = i;
			ilosc_pierwszych++;
		}
	}
	return ilosc_pierwszych;
}

int main(void)
{
	int pierwsze[ILOSC_PARZYSTYCH / 2];
	int ilosc_pierwszych;
	int check = 0;

	ilosc_pierwszych = tablicowanieLiczbPierwszych(pierwsze);

	for (int i = 4; i <= ILOSC_PARZYSTYCH + 2; i += 2)
	{
		for (int g = 0; g < ilosc_pierwszych; g++)
		{
			for (int h = 0; h < ilosc_pierwszych; h++)
			{
				if (pierwsze[g] + pierwsze[h] == i)
				{
					printf("Dla %d hipoteza Goldbacha poprawna.\n", i);
					check++;
					goto etykieta;
				}
			}
		}
	etykieta:;
	}

	if (check == 20)
		printf("Hipoteza prawdziwa!\n\n");

	return 0;
}

