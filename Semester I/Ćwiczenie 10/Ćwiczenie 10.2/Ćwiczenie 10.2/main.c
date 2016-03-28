//main.c

#include <stdio.h>

int iteracyjna(int wykladnik)
{
	int wynik = 1;
	for (int i = 1; i <= wykladnik; i++)
	{
		wynik *= 2;
	}
	return wynik;
}

int rekurencyjna(int wykladnik)
{
	if (wykladnik == 0)
		return 1;
	return 2 * rekurencyjna(wykladnik - 1);
}


int main(void)
{
	int n;
	printf("Podaj wykladnik funckji 2^n: ");
	scanf("%d", &n);

	for (n = 0; n < 10; n++)
		printf("Liczba: %d\tIteracyjna: %d\tRekurencyjna: %d\n", n, iteracyjna(n), rekurencyjna(n));

	return 0;
}

