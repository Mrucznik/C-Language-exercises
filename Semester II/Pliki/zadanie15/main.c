#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void otworzPlik(FILE** file, const char* filename, const char* mode)
{
	*file = fopen(filename, mode);
	if (*file == NULL)
	{
		printf("Nie udalo sie otworzyc pliku %s w trybie %s\n", filename, mode);
		exit(1);
	}
}

int main(void)
{
	setlocale(LC_ALL, "");//polskie znaki

	FILE *f;
	char bufor[128];
	otworzPlik(&f, "plik5.txt", "a");

	puts("Podaj jaki tekst dopisaæ do pliku plik5.txt:");
	scanf("%s[128]", bufor);

	fputs(bufor, f);
	fputc('\n', f);
	
	fclose(f);
	return 0;
}