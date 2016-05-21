#include <stdio.h>
#include <stdarg.h>

/*
Problemy pojawi³y siê, poniewa¿ podczas wywo³ania funkcji liczby typu float s¹ zmieniane na double.
*/

int sumuj_i(int ile, ...)
{
	int w = 0;
	va_list ap;
	va_start(ap, ile);

	for (int i = 0; i<ile; i++)
	{
		w += va_arg(ap, int);
	}

	va_end(ap);
	return w;
}

float sumuj_f(int ile, ...)
{
	float w = 0;
	va_list ap;
	va_start(ap, ile);
	
	for (int i = 0; i<ile; i++)
	{
		w += va_arg(ap, double); // zmieniono z float na double
	}

	va_end(ap);
	return w;

}
double sumuj_d(int ile, ...)
{
	double w = 0;
	va_list ap;
	va_start(ap, ile);

	for (int i = 0; i<ile; i++)
	{
		w += va_arg(ap, double);
	}

	va_end(ap);
	return w;
}

int main(void)
{
	int ai = 10, bi = 20, ci = 30;
	printf("Suma int zmiennych: %d\n", sumuj_i(3,ai,bi,ci));
	printf("Suma int bezposrednio: %d\n", sumuj_i(3, 10, 20, 30));

	float af = 10.0f, bf = 20.0f, cf = 30.0f;
	printf("Suma float zmiennych: %f\n", sumuj_f(3, af, bf, cf));
	printf("Suma float bezposrednio: %f\n", sumuj_f(3, 10.0f, 20.0f, 30.0f));

	double da = 10.0, db = 20.0, dc = 30.0;
	printf("Suma double zmiennych: %lf\n", sumuj_d(3, da, db, dc));
	printf("Suma double bezposrednio: %lf\n", sumuj_d(3, 10.0, 20.0, 30.0));
	return 0;
}