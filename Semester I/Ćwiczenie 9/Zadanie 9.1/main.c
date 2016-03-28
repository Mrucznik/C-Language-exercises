//main.c

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int getIntegerFromRange(const char* statement, int min, int max)
{
	int number;
	do
	{
		char tmp[4];
		printf("%s [od %d do %d]:", statement, min, max);
		scanf("%s", &tmp);
		number = atoi(tmp);
	}
	while (number < min || number > max);
	return number;
}

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

int main(void)
{
	int a, i = 0;

	a = getIntegerFromRange("Podaj liczbe a", 1, 999);

	if (a % 2 == 0) a++; //Ponmiewa¿ liczby pierwsze zawsze s¹ liczbami nieparzystymi, w przypadku gdy liczba jest parzysta dodajemy 1 aby uzyskaæ nieparzyst¹. Pozwoli to zwiêkszaæ zmienn¹ steruj¹c¹ pêtli o 2 zamiast o 1

	while (i < 20)
	{
		if (czyPierwsza(a) && czyPierwsza(a + 2))
		{
			printf("Liczby blizniacze nr %d: %d i %d\n", i + 1, a, a + 2);
			i++;
		}
		a += 2;
	}

	return 0;
}

