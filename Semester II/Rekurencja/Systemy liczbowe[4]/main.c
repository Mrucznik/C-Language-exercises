#include <stdio.h>

void wyswietl(int liczba, int system)
{
	int l = liczba / system;
	if(l!=0)
	wyswietl(l, system);
	if(system > 10) printf("%x", liczba % system);
	else printf("%d", liczba % system);
}

int main(void)
{
	int liczba;
	puts("Podaj liczbe: ");
	scanf("%d", &liczba);
	printf("W systemie dwojkowym: ");
	wyswietl(liczba, 2);
	printf("\nW systemie czworkowym: ");
	wyswietl(liczba, 4);
	printf("\nW systemie osemkowym: ");
	wyswietl(liczba, 8);
	printf("\nW systemie dziesietnym: ");
	wyswietl(liczba, 10);
	printf("\nW systemie szesnastkowym: ");
	wyswietl(liczba, 16);
	printf("\nW systemie szostkowym: ");
	wyswietl(liczba, 6);
	return 0;
}