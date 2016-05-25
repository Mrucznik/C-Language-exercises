#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef struct polynomial_t
{
	int stopien;
	double *wagi;
} polynomial_t;

struct polynomial_t* poly_init(int stopien, ...)
{
	va_list ap;
	va_start(ap, stopien);

	polynomial_t *wielomian = (polynomial_t*)malloc(sizeof(polynomial_t));
	wielomian->stopien = stopien;
	wielomian->wagi = (double*)malloc(sizeof(double)*(stopien+1));
	for (int i = 0; i <= stopien; i++)
		wielomian->wagi[i] = va_arg(ap, double);

	va_end(ap);
	return wielomian;
}

void poly_free(polynomial_t *poly)
{
	free(poly->wagi);
	free(poly);
}

double poly_calc(polynomial_t *poly, double x)
{
	double wynik = 0;
	for(int i=0; i<=poly->stopien; i++)
	{
		wynik += poly->wagi[i]*pow(x, poly->stopien - i);
	}
	return wynik;
}

void poly_print(polynomial_t *poly)
{
	for (int i = 0; i < poly->stopien; i++)
	{
		printf("%.2lfx^%d + ", poly->wagi[i], poly->stopien - i);
	}
	printf("%.2lf", poly->wagi[poly->stopien]);
}

int main(void)
{
	setlocale(LC_ALL, "");
	polynomial_t *wielomian = poly_init(2, 1.0, 2.0, 5.0);
	printf("Wielomian W(x) = ");
	poly_print(wielomian);
	printf("\nDla x = 5: W(x) = %.2lf\n", poly_calc(wielomian, 5.0));
	poly_free(wielomian);

	wielomian = poly_init(3, 2.0, 1.0, 2.0, 5.0);
	printf("Wielomian W(x) = ");
	poly_print(wielomian);
	printf("\nDla x = 5: W(x) = %.2lf\n", poly_calc(wielomian, 5.0));
	poly_free(wielomian);
	
	wielomian = poly_init(5, 0.5, 1.0, 2.0, 1.0, 2.0, 5.0);
	printf("Wielomian W(x) = ");
	poly_print(wielomian);
	printf("\nDla x = 2: W(x) = %.2lf\n", poly_calc(wielomian, 2.0));
	poly_free(wielomian);

	wielomian = poly_init(50, 
		1.0, -2.0, -1.0, 2.0, 5.0,
		1.0, -2.0, -1.0, 2.0, 5.0,
		1.0, -2.0, -1.0, 2.0, -5.0,
		1.0, -2.0, -1.0, 2.0, 5.0,
		1.0, -2.0, -1.0, 2.0, 5.0,
		1.0, -2.0, -1.0, 2.0, -5.0,
		1.0, -2.0, -1.0, 2.0, 5.0, 
		1.0, -2.0, -1.0, 2.0, 5.0, 
		1.0, -2.0, -1.0, 2.0, -5.0, 
		1.0, -2.0, -1.0, 2.0, 10.0, 
		15.5);
	printf("Wielomian W(x) = ");
	poly_print(wielomian);
	printf("\nDla x = 1.1: W(x) = %.2lf\n", poly_calc(wielomian, 1.1));
	poly_free(wielomian);
	return 0;
}