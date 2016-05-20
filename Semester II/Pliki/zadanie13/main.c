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
	FILE *f;
	char filename[64];

	printf("Podaj nazwe pliku: ");
	scanf("%s[64]", filename);
	otworzPlik(&f, filename, "r");

	while(!feof(f))
	{
		putchar(fgetc(f));
	}
	return 0;
}