#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	FILE *f1, *f2;
	otworzPlik(&f1, "plik2.txt", "rt");
	otworzPlik(&f2, "plik4a.txt", "wt");

	char bufor[2048];
	fseek(f1, 0, SEEK_END);
	while (ftell(f1) != 0)
	{
		int i = 0;
		while (ftell(f1) != 0 && i < 2047)
		{
			fseek(f1, -1, SEEK_CUR);
			bufor[i] = fgetc(f1);
			fseek(f1, -1, SEEK_CUR);
			if (bufor[i] == '\n')
			{
				fseek(f1, -1, SEEK_CUR);
				break;
			}
			i++;
		}
		
		//Zapisywanie lini do pliku
		for (i-=1; i >= 0; i--)
		{
			fputc(bufor[i], f2);
		}
		fputc('\n', f2);
	}

	fclose(f1);
	fclose(f2);
	return 0;
}