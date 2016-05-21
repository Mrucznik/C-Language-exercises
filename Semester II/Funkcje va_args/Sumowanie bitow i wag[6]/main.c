#include <stdio.h>
#include <stdarg.h>
#include <math.h>

unsigned int suma_bitow(int ile, ...)
{
	unsigned int suma = 0;
	va_list ap;
	va_start(ap, ile);

	for(int i=0; i<ile; i++)
	{
		suma += va_arg(ap, int)*(pow(2, ile-i-1));
	}

	va_end(ap);
	return suma;
}

int main(void)
{
	printf("Suma: %u\n", suma_bitow(1, 0));
	printf("Suma: %u\n", suma_bitow(1, 1));
	printf("Suma: %u\n", suma_bitow(3, 0, 1, 0));
	printf("Suma: %u\n", suma_bitow(3, 1, 1, 1));
	printf("Suma: %u\n", suma_bitow(8, 0, 0, 0, 0, 0, 0, 0, 1));
	printf("Suma: %u\n", suma_bitow(8, 1, 0, 0, 0, 0, 0, 0, 1));
	printf("Suma: %u\n", suma_bitow(32, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0));
	return 0;
}