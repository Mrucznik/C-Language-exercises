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
	otworzPlik(&f1, filename, "r");

	printf("Podaj nazwe pliku docelowego: ");
	scanf("%s[64]", filename);
	otworzPlik(&f2, filename, "w");

	int i = 0;
	while (1)
	{
		fseek(f1, (i -= 1), SEEK_END);
		if(ftell(f1) == 0)
		{
			fputc(fgetc(f1), f2);
			break;
		}
		fputc(fgetc(f1), f2);//nie mo¿na daæ przed warunkiem wyjœcia z pêtli bo zmienia pozycjê wskaŸnika pliku
	}

	fclose(f1);
	fclose(f2);
	return 0;
}
