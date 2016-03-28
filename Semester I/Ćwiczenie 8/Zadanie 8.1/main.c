//main.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funkcja(double x, double A, double B, double C, double beta)
{
	return A * exp(-beta * x) / (B * x * x + C);
}

int main(void)
{
	double a, b, c, beta;
	double deltax, epsilon;
	double x, y;
	int lines = 0;

	do
	{
		printf("Wprowadz parametry funkcji A, B, C (po spacji, wieksze od 0): ");
		scanf("%lf%lf%lf", &a, &b, &c);
	}
	while (a <= 0 || b <= 0 || c <= 0);

	printf("Podaj beta: ");
	scanf("%lf", &beta);

	printf("Podaj od jakiego x'a zaczac: ");
	scanf("%lf", &x);

	printf("Podaj krok tablicowania (delta x): ");
	scanf("%lf", &deltax);

	printf("Podaj epsilon: ");
	scanf("%lf", &epsilon);

	while ((y = funkcja(x, a, b, c, beta)) > epsilon)
	{
		printf("%12f\t %12f\n", x, y);
		x += deltax;
		lines++;
		if (lines % 24 == 0)
			system("pause");
	}

	return 0;
}

