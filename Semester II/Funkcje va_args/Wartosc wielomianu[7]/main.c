#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double wielomian(int stopien, double x, ...)
{
	double wynik = 0;
	va_list ap;
	va_start(ap, x);

	for (int i = 0; i <= stopien; i++)
	{
		wynik += va_arg(ap, double)*pow(x, stopien - i);
	}

	va_end(ap);
	return wynik;
}

int main(void)
{
	printf("Wynik 3x^2+2x-5 dla x=5: %lf", wielomian(2, 5.0, 3.0, 2.0, -5.0));
	return 0;
}