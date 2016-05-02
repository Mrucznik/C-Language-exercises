#include <stdio.h>

int main()
{
	FILE* f = fopen("..\\zadanie6\\file", "rb");
	float tab[100];

	if (f == NULL)
	{
		printf("Error! Nie mozna otworzyc pliku.");
		return 1;
	}

	fread(tab, sizeof(float), 100, f);

	for (int i = 0; i < 100; i++)
	{
		printf("%f\n", tab[i]);
	}

	fclose(f);
	return 0;
}

