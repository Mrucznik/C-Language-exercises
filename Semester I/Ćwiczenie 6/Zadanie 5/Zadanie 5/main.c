//main.c

#include <stdio.h>
#include <math.h>

int main(void)
{
	//Podpunkt a.
	int n = 1;
	while (!(pow(1.02, n) > 1000*n*n))
		n++;
	printf("a. Najmniejsza liczba naturalna taka, ze (1.02)^n > 1000n^2 to %d\n\n", n);

	//Podpunkt b.
	float e, suma=0;

	do
	{
		printf("Podaj e (dodatnie): ");
		scanf("%f", &e);
	} while (e <= 0);
	
	n = 1;
	while (suma <= e)
	{
		suma += 1.0 / n;
		n++;
	}
	printf("b. Najmniejsza liczba naturalna n taka, ze 1+1/2+1/3+...+1/n>%f to %d\n\n", e, n);
	return 0;
}