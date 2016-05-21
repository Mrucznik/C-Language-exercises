#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void lacz(char bufor[], int ile, ...)
{
	va_list ap;
	va_start(ap, ile);

	bufor[0] = '\0';
	for(int i=0; i<ile; i++)
	{
		strcat(bufor, va_arg(ap, char*));
	}

	va_end(ap);
}

int main(void)
{
	char string[128];
	lacz(string, 5, "Ten", " tekst", " zostal", " zlaczony", " poprawnie");
	printf("Zlaczone teksty: %s\n", string);
	return 0;
}