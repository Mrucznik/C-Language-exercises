#include <stdio.h>

int main()
{
	FILE* f = fopen("C:\\Users\\student\\Desktop\\Pliki\\zadanie1\\file.txt", "r");

	if (f == NULL)
	{
		printf("Error! Nie mozna otworzyc pliku.");
		return 1;
	}

	while (!feof(f))
	{
		int liczba;
		fscanf(f, "%d ", &liczba);
		printf("%d\n", liczba);
	}

	fclose(f);
	return 0;
}

