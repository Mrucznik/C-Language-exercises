//main.c

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
	int a, b;
	bool wszystkie = true;
	printf("Podaj granice przedzialu <a, b>: ");
	scanf("%d%d", &a, &b);
	printf("Obliczanie nierownosci n^3+20n<3n^2+370 dla przedzialu <%d, %d> . . . \n\n", a, b);

	for (int n = a; n <= b; n++)
	{
		if (!(n*n*n + 20 * n < 2 * n*n + 370))
		{
			printf("Liczba %d nie spelnia tej nierownosci\n", n);
			wszystkie = false;
		}
	}

	if(wszystkie)
		printf("Wszystkie liczby naturalne z przedzialu <%d, %d> spelniaja nierownosc", a, b);
	return 0;
}