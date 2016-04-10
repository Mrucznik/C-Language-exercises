#include <stdio.h>

int main()
{
	FILE* f = fopen("zadania_pliki_DATA3.txt", "r");
	int suma = 0, ile = 0;

	if (f == NULL)
	{
		printf("Error! Nie mozna otworzyc pliku.");
		return 1;
	}

	fscanf(f, "%d", &ile);

	while (!feof(f))
	{
		int liczba;
		fscanf(f, "%d\t", &liczba);
		suma += liczba;
	}

	printf("Suma: %d\nSrednia: %d\n", suma, suma / ile);

	fclose(f);
	return 0;
}

