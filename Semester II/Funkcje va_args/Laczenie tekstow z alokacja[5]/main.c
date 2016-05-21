#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void concat(char **bufor, int size, int ile, ...)
{
	va_list ap;
	va_start(ap, ile);
	char *tmp = (char*)malloc(size * sizeof(char));
	int totallength = 0;

	*bufor = (char*)malloc(size * sizeof(char));
	tmp[0] = '\0';
	*bufor[0] = '\0';
	for (int i = 0; i<ile; i++)
	{
		int length;
		strcpy(tmp, va_arg(ap, char*));
		length = strlen(tmp);

		if (totallength + length + 1 > size)
		{
			if (totallength + 4 > size)
			{
				//dwukropek:
				(*bufor)[size - 1] = '\0';
				(*bufor)[size - 2] = '.';
				(*bufor)[size - 3] = '.';
				(*bufor)[size - 4] = '.';
			}
			else if (size > 4)
			{
				//dwukropek:
				(*bufor)[totallength + 3] = '\0';
				(*bufor)[totallength + 2] = '.';
				(*bufor)[totallength + 1] = '.';
				(*bufor)[totallength] = '.';
			}
			break;
		}
		totallength += length;
		strcat(*bufor, tmp);
	}

	free(tmp);
	va_end(ap);
}

int main(void)
{
	char *string;
	concat(&string, 10, 5, "Ten", " tekst", " zostal", " zlaczony", " poprawnie");
	printf("Zlaczone teksty: %s\n", string);
	free(string);
	return 0;
}