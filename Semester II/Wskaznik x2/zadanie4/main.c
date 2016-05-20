#include <stdio.h>
#include <stdlib.h>

#define ELEMENTY 1000

double wyznacz_srednia(int** tablica, int N); // N - liczba elementów w tablicy
void zapisz_bin(int** liczba, int N); // zapis do pliku binarnego plik19.bin
void zapisz_txt(int** liczba, int N); // zapis do pliku 

int main(void)
{
	int **tab = (int**)malloc(sizeof(int) * ELEMENTY);
	for(int i = 0; i<ELEMENTY; i++)
	{
		
	}
	return 0;
}