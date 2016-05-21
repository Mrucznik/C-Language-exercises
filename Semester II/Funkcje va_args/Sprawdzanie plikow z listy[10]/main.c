#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void sprawdzPliki(int ile, ...)
{
	va_list ap;
	va_start(ap, ile);
	char file_name[128];

	for (int i = 0; i<ile; i++)
	{
		strcpy(file_name, va_arg(ap, char*));
		FILE *f = fopen(file_name, "r");
		if (f == NULL || ferror(f))
		{
			printf("%s nie istnieje!\n", file_name);
		}
		else
		{
			fseek(f, 0, SEEK_END);
			printf("%s, dlugosc: %d\n", file_name, ftell(f));
			fclose(f);
		}
	}

	va_end(ap);
}

int main(void)
{
	sprawdzPliki(3, "Exercise.txt", "lol.txt", "main.c");
	return 0;
}