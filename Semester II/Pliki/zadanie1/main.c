#include <stdio.h>

int main()
{
	FILE* f = fopen("file.txt", "w");
	if (f == NULL)
	{
		printf("Error! Nie mozna otworzyc pliku.");
		return 1;
	}

	for (int i = 0; i < 101; i++)
		fprintf(f, "%d\n", i);

	fclose(f);
	return 0;
}

