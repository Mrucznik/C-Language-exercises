//main.c

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	float N[100], suma=0, srednia;
	int n = 0, absolute = 0;

	do //Wprowadzanie danych:
	{
		printf("Wprowadz %d. element ciagu: ", n + 1);
		scanf("%f", &N[n]);
		n++;
	} while ( N[n-1]!=0 );
	n--; //korekta danych - koñcowego zera nie wliczamy do ci¹gu

	//Obliczenia:
	for (int i = 0; i < n; i++)
	{
		if (N[i] > 0)
			suma += N[i];
		if (abs(N[i] < 100))
			absolute++;
	}
	srednia = suma / n;

	printf("Srednia: %f\nIlosc wyrazow ktorych wartosc bezwzgledna jest < 100: %d\n", srednia, absolute);
	return 0;
}