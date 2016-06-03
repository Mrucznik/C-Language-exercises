#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void dodaj_kropki(char str[], int size)
{
	if(size >= 4)
	{
		for (int i = 2; i < 5; i++)
			str[size - i] = '.';
		str[size - 1] = '\0';
	}
	else
	{
		for (int i = 0; i < size-1; i++)
			str[i] = '.';
		str[size-1] = '\0';
	}
}

void concat(char bufor[], int size, int ile, ...)
{
	va_list ap;
	va_start(ap, ile);

	int buf_i=0;
	for (int i = 0; i<ile; i++)
	{
		char *str = va_arg(ap, char*);
		for(int j=0; str[j] != '\0'; j++)
		{
			if (buf_i >= size - 4)
			{
				dodaj_kropki(bufor, size);
				va_end(ap);
				return;
			}
			bufor[buf_i] = str[j];
			buf_i++;
		}
	}
	bufor[buf_i] = '\0';
	va_end(ap);
}

int main(void)
{
	char buffer[25];
	concat(buffer, sizeof(buffer), 3, "Ala", "ma", "kota");
	printf("Zlaczone teksty: %s\n", buffer);
	concat(buffer, sizeof(buffer), 5, "Ala", " ", "ma", " ", "kota");
	printf("Zlaczone teksty: %s\n", buffer);
	concat(buffer, sizeof(buffer), 4, "Wlazl", "KotekNaPlotek", " i", " mruga");
	printf("Zlaczone teksty: %s\n", buffer);
	return 0;
}