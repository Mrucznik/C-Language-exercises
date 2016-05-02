#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));

	FILE* f = fopen("file", "wb");
	float tab[100];

	for (int i = 0; i < 100; i++)
	{
		tab[i] = rand() % 201 - 100;
	}

	if (f == NULL)
	{
		printf("Error! Nie mozna otworzyc pliku.");
		return 1;
	}

	fwrite(tab, sizeof(float), 100, f);

	fclose(f);
	return 0;
}

