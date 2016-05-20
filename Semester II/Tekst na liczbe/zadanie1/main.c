#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char string[10];
	int suma = 0;
	while(1)
	{
		int liczba;
		char *error;
		scanf("%s[10]", string);
		liczba = strtol(string, &error, 10);
		if( *error > 0 )
		{
			if (strcmp(string, "koniec") == 0)
				break;
			printf("Podales zla liczbe!\n");
		}
		else
		{
			printf("%d+%d=%d\n", suma, liczba, (suma + liczba));
			suma += liczba;
		}
	}
	return 0;
}
