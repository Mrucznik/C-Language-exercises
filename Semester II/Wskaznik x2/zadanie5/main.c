#include <stdio.h>
#include <stdlib.h>

void otworzPlik(FILE** file, const char* filename, const char* mode)
{
	if (file == NULL)
	{
		printf("Przekazano wskaznik NULL przy otwieraniu pliku %s w trybie %s\n", filename, mode);
		exit(1);
	}

	*file = fopen(filename, mode);
	if (*file == NULL)
	{
		printf("Nie udalo sie otworzyc pliku %s w trybie %s\n", filename, mode);
		exit(1);
	}
}

double wyznacz_srednia(int** tablica, int N)
{
	int suma = 0;
	for (int i = 0; i<N; i++)
	{
		suma += *(*(tablica)+i);
	}
	return suma / (double)N;
}

int main(void)
{
	FILE *f;
	int *tab, ile;
	otworzPlik(&f, "plik19.bin", "rb");
	fread(&ile, sizeof(int), 1, f);
	tab = (int*)malloc(sizeof(int)*ile);
	fread(tab, sizeof(int), ile, f);
	printf("Srednia: %lf", wyznacz_srednia(&tab, ile));
	free(tab);
	return 0;
}