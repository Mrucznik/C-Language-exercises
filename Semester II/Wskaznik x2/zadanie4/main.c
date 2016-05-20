#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTY 1000

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
	for(int i=0; i<N; i++)
	{
		suma += *(*(tablica)+i);
	}
	return suma / (double)N;
}

void zapisz_bin(int** liczba, int N)
{
	FILE *f;
	otworzPlik(&f, "plik19.bin", "wb");

	fwrite(&N, sizeof(int), 1, f);
	fwrite(*liczba, sizeof(int), N, f);

	free(*liczba);
	liczba = NULL;
	fclose(f);
}

void zapisz_txt(int** liczba, int N)
{
	FILE *f;
	otworzPlik(&f, "plik19.txt", "wt");

	fprintf(f, "%d\n", N);
	for (int i = 0; i < N; i++)
	{
		fprintf(f, "%d\n", *(*(liczba)+i));
	}

	free(*liczba);
	liczba = NULL;
	fclose(f);
}

void generujLiczby(int **tab)
{
	*tab = (int*)malloc(sizeof(int) * ELEMENTY);
	for (int i = 0; i<ELEMENTY; i++)
	{
		*(*(tab)+i) = rand() % 201 - 100;
	}
}

int main(void)
{
	srand(time(NULL));
	int *tab;
	generujLiczby(&tab);
	printf("Srednia: %lf\n", wyznacz_srednia(&tab, ELEMENTY));
	zapisz_bin(&tab, ELEMENTY);

	generujLiczby(&tab);
	zapisz_txt(&tab, ELEMENTY);
	return 0;
}