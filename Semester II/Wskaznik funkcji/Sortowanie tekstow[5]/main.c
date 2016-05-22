#include <stdio.h>
#include <locale.h>

int szukaj_litery(const char litera)
{
	static char litery[] = "A�BCC�DE�FGHIJKL�MNO�PRSTWVUXYZ��a�bc�de�fghijkl�mno�prstwvuxyz��";
	for(int i =0; i<66; i++)
	{
		if (litery[i] == litera)
			return i;
	}
	return -1;
}

int mystrcmp(const char *a, const char *b)
{
	while (*a && *b && *a == *b)
	{
		++a; 
		++b;
	}
	int ia = szukaj_litery(*a), ib = szukaj_litery(*b);
	return (ia != -1 && ib != -1) ? (ia - ib) : (*a - *b);
}

int rosnaco(const char a[], const char b[])
{
	return mystrcmp(a, b) > 0;
}

int malejaco(const char a[], const char b[])
{
	return mystrcmp(a, b) < 0;
}

void sortuj(char* tab[], const int size, int(*func)(char[], char[]))
{
	int n = size;
	do
	{
		int czyZmieniono = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (func(tab[i], tab[i + 1]))
			{
				char* tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				czyZmieniono = 1;
			}
		}

		n--;
		if (!czyZmieniono)
			break;
	} while (n > 1);
}

void wyswietl(const char *tab[], const int size)
{
	for (int i = 0; i<size; i++)
	{
		if (i % 5 == 0)
			putchar('\n');
		printf("%-25s", tab[i]);
	}
	putchar('\n');
}

int main(void)
{
	setlocale(LC_ALL, "");//Polskie znaki w konsoli
	char *miasta[] = {
		"�och�w", "Czerniejewo", "Lubomierz", "Be�chat�w", "�osice", "Lublin", "Kutno",
		"Lubliniec", "Lubniewice", "Czerwionka - Leszczyny", "Cz�stochowa", "Lubsko", "Czelad�",
		"Czempi�", "Bytom Odrza�ski", "Byt�w", "Legionowo", "Lubo�", "Lubraniec",
		"Bieru�", "Bierut�w", "�owicz", "��d�", "�uk�w", "Cz�uch�w", "L�dek - Zdr�j",
		"Bytom", "�omianki", "�om�a", "Czersk", "Czerwie�sk", "Be��yce", "B�dzin", "Cz�opa", "Lubin"
	};
	printf("Tablica:");
	wyswietl(miasta, 35);
	printf("\n\nPosortowana rosnaco:");
	sortuj(miasta, 35, rosnaco);
	wyswietl(miasta, 35);
	printf("\n\nPosortowana malejaco:");
	sortuj(miasta, 35, malejaco);
	wyswietl(miasta, 35);
	return 0;
}