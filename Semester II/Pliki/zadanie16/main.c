#include <stdio.h>
#include <stdlib.h>

void otworzPlik(FILE** file, const char* filename, const char* mode)
{
	if(file == NULL)
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
	FILE *f1, *f2;
	otworzPlik(&f1, "plik2.txt", "rt");
	otworzPlik(&f2, "plik4.txt", "wt");

	while (!feof(f1))
	{
		fputc(fgetc(f1), f2);
	}

	fclose(f1);
	fclose(f2);
	return 0;
}