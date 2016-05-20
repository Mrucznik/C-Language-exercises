#include <stdio.h>
#include <stdlib.h>

int Silnia(int a)
{
	if (a == 0) return 1;
	if (a < 0)
	{
		printf("ERROR! Silnia moze byc wyznaczona tylko z liczb dodatnich!");
		exit(1);
	}
	return a * Silnia(a - 1);
}

int main(void)
{
	int liczba;
	puts("Podaj liczbe: ");
	scanf("%d", &liczba);
	printf("Wynik %d! = %d", liczba, Silnia(liczba));
	return 0;
}