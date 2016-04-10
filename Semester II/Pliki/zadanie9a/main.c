#include <stdio.h>

int main()
{
	FILE* f = fopen("file.txt", "w");
	char string[100];

	if (f == NULL)
	{
		printf("Error! Nie mozna otworzyc pliku.");
		return 1;
	}

	for (gets_s(string, sizeof string); string[0]; gets_s(string, sizeof string))
	{
		fputs(string, f);
		fputs("\n", f);
	}


	fclose(f);
	return 0;
}

