#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

char* concat(int ile, ...)
{
	va_list ap;
	va_start(ap, ile);
	char* bufor = NULL;

	int buf_i = 0;
	for (int i = 0; i<ile; i++)
	{
		char *str = va_arg(ap, char*);
		for (int j = 0; str[j] != '\0'; j++)
		{
			bufor = realloc(bufor, buf_i + 1);
			bufor[buf_i] = str[j];
			buf_i++;
		}
	}
	bufor = realloc(bufor, buf_i + 1);
	bufor[buf_i] = '\0';
	va_end(ap);
	return bufor;
}

int main(void)
{
	char *buffer;
	buffer = concat(3, "Ala", "ma", "kota");
	printf("Zlaczone teksty: %s\n", buffer);
	free(buffer);
	buffer = concat(5, "Ala", " ", "ma", " ", "kota");
	printf("Zlaczone teksty: %s\n", buffer);
	free(buffer);
	buffer = concat(4, "Wlazl", "KotekNaPlotek", " i", " mruga");
	printf("Zlaczone teksty: %s\n", buffer);
	free(buffer);
	return 0;
}