#include <stdio.h>

int wiekszy(int a, int b)
{
	return a > b;
}

int mniejszy(int a, int b)
{
	return a < b;
}

void sortuj(int tab[], int size, int (*func)(int, int))
{
	int n = size;
	do
	{
		int czyZmieniono = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (func(tab[i], tab[i + 1]))
			{
				int tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				czyZmieniono = 1;
			}
		}

		n--;
		if (!czyZmieniono)
			break;
	} while (n > 1);
}

void wyswietl(int tab[], int size)
{
	for(int i=0; i<size; i++)
	{
		if (i % 10 == 0)
			putchar('\n');
		printf("%-3d ", tab[i]);
	}
	putchar('\n');
}

int main(void)
{
	int tab[] = {	13,6,3,11,7,2,19,13,2,4,
					18,12,2,19,20,8,2,5,14,12,
					11,8,16,2,22,24,1,10,9,2,
					11,10,20,10,16,7,14,7,19,16,
					25,14,2,18,5,2,19,17,2,3,
					15,25,25,21,16,14,10,9,5,16,
					4,13,2,16,12,20,2,25,18,4,
					3,2,6,6,25,2,20,3,8,6,
					7,5,5,15,10,8,16,7,1,4,
					8,19,22,18,18,2,14,5,15,11 };
	int size = sizeof(tab) / sizeof(int);
	printf("Tablica:");
	wyswietl(tab, size);
	printf("Posortowana rosnaco:");
	sortuj(tab, size, wiekszy);
	wyswietl(tab, size);
	printf("Posortowana malejaco:");
	sortuj(tab, size, mniejszy);
	wyswietl(tab, size);
	return 0;
}