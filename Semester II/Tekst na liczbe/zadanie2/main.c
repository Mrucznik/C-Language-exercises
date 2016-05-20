#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
liczba124 to 435290 3942utr riuga iaejrg3289t erigj3198
a49g8houn4ga
suma:=124+435290+3942+3289+3198+49+8+4
445904*trzy

Suma to 1337712
*/

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

int main(void)
{
	FILE *f;
	otworzPlik(&f, "plik.txt", "r");

	char bufor[12];
	int i = 0, suma = 0;;
	while (!feof(f))
	{
		char znak = fgetc(f);
		if(isdigit(znak))
		{
			bufor[i] = znak;
			i++;
		}
		else if(i > 0)
		{
			bufor[i] = '\0';
			i = 0;
			int lol = atoi(bufor);
			suma += lol;

		}
	}

	printf("Suma: %d", suma);

	fclose(f);
	return 0;
}