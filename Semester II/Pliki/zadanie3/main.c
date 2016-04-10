#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));

	FILE * f = fopen("file.txt", "w");
	if (f == NULL)
	{
		printf("Error! Nie mozna otworzyc pliku.");
		return 1;
	}

	int i = 1;
	while (i <= 145)
	{
		fprintf(f, "%d ", rand()%101);
		if (i % 10 == 0)
			fputc('\n', f);
		i++;
	}

	fclose(f);
	return 0;
}