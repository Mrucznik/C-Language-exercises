//main.c

#include <stdio.h>

int main(void)
{
	const float e = 0.0001;
	int n = 1;
	float suma = 0;
	float wyraz;

	while ((wyraz = 1.0 / (n*(n + 1))) > e)
	{
		suma += wyraz;
		n++;
	}

	printf("Suma wyrazow to: %f\n", suma);
	return 0;
}