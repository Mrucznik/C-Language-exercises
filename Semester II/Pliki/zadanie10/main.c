#include <stdio.h>

int main(void)
{
	FILE *f = fopen("plik.txt", "r");
	if(f != NULL)
	{
		printf("Ten plik juz istnieje");
	}
	else
	{
		f = fopen("plik.txt", "w");
		if(f == NULL)
		{
			printf("Nie da sie stworzyc pliku");
			return 0;
		}
		else
		{
			printf("Stworzono plik.txt");
		}
	}
	fclose(f);
	return 0;
}