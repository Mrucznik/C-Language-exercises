#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *f1, *f2;
	char filename[64];
	printf("Podaj nazwe pliku docelowego: ");
	scanf("%s[64]", filename);
	f1 = fopen(filename, "w");
	if(f1 == NULL)
	{
		printf("Nie udalo sie otworzyc pliku %s", filename);
		exit(1);
	}
	printf("Podaj nazwe pliku kopiowanego: ");
	scanf("%s[64]", filename);
	f2 = fopen(filename, "r");
	if (f2 == NULL)
	{
		printf("Nie udalo sie otworzyc pliku %s", filename);
		exit(1);
	}

	char znak;
	while(1)
	{
		fread(&znak, 1, sizeof(znak), f2);
		if (feof(f2)) break;
		fwrite(&znak, sizeof(char), 1, f1);
	}

	fclose(f1);
	fclose(f2);
	return 0;
}
