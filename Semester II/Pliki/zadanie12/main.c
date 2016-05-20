#include <stdio.h>
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
	FILE *f1, *f2;
	char filename[64];

	printf("Podaj nazwe pliku kopiowanego: ");
	scanf("%s[64]", filename);
	otworzPlik(&f1, filename, "rb");

	printf("Podaj nazwe pliku docelowego: ");
	scanf("%s[64]", filename);
	otworzPlik(&f2, filename, "wb");

	fseek(f1, 0, SEEK_END);
	while (ftell(f1) != 0)
	{
		fseek(f1, -1, SEEK_CUR);
		fputc(fgetc(f1), f2);
		fseek(f1, -1, SEEK_CUR);
	}

	fclose(f1);
	fclose(f2);
	return 0;
}
