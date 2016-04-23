#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

int main(void)
{
	double *number;
	number = (double*)malloc(sizeof(double));
	*number = M_PI;
	printf("Wartosc: %lf, Adres: 0x%p\n", *number, number);
	free(number);
	return 0;
}
