#include <stdio.h>

int main()
{
	char filename[FILENAME_MAX];

	printf("Podaj nazwe pliku do wczytania: ");
	scanf("%s", filename);

	FILE* f = fopen(filename, "rb");

	if (f == NULL)
	{
		printf("Error! Nie mozna otworzyc pliku.");
		return 1;
	}

	while (!feof(f))
	{
		char tmp = 0;
		fread(&tmp, sizeof(tmp), 1, f);
		printf("%d ", tmp);
	}
	printf("\n");

	fclose(f);
	return 0;
}

