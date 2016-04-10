#include <stdio.h>

int main()
{
	FILE* f = fopen("file.txt", "w");
	if (f == NULL)
	{
		printf("Error! Nie mozna otworzyc pliku.");
		return 1;
	}

	int i = 0;
	while (i <= 100)
	{
		fprintf(f, "%d ", i);
		if ((i + 1) % 10 == 0)
			fputc('\n', f);
		i++;
	}

	fclose(f);
	return 0;
}

