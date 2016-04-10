#include <stdio.h>

int main()
{
	FILE* f = fopen("..\\zadanie9a\\file.txt", "r");
	int ile = 0;

	if (f == NULL)
	{
		printf("Error! Nie mozna otworzyc pliku.");
		return 1;
	}

	while (!feof(f))
	{
		char string[100];
		fgets(string, 100, f);
		printf("%s", string);
		ile++;
	}
	printf("Wyswietlono %d rekordow\n", ile);

	fclose(f);
	return 0;
}

