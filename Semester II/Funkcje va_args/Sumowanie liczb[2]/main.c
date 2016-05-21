#include <stdio.h>
#include <stdarg.h>

int suma(int ile, ...)
{
	int w = 0;
	va_list ap;
	va_start(ap, ile);

	for(int i=0; i<ile; i++)
	{
		w += va_arg(ap, int);
	}

	va_end(ap);
	return w;
}

int iloczyn(int ile, ...)
{
	int w = 1;
	va_list ap;
	va_start(ap, ile);

	for (int i = 0; i<ile; i++)
	{
		w *= va_arg(ap, int);
	}

	va_end(ap);
	return w;
}

int main(void)
{
	printf("Suma liczb 3, 4 i 6: %d\n", suma(3, 3, 4, 6));
	printf("Iloczyn liczb 3, 4 i 6: %d\n", iloczyn(3, 3, 4, 6));
	return 0;
}