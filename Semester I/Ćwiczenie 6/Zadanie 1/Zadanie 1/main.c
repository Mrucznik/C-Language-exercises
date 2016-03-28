//main.c

#include <stdio.h>

int main(void)
{
	int n;
	float suma = 0;
	printf("Podaj ilosc liczb: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		float f;
		printf("Podaj %d liczbe: ", i + 1);
		scanf("%f", &f);
		suma += f;
	}

	printf("Suma tych liczb to: %f\n", suma);
	return 0;
}