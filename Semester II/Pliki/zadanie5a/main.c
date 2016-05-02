#include <stdio.h>

//Użyto long long int ponieważ long int ma zakres z [−2147483647, +2147483647] a liczby w pliku wykraczają poza ten zakres.
//long long int zawiera się w zakresie [−9223372036854775807, +9223372036854775807], liczby w pliku też są w nim zawarte.

int main()
{
	FILE* f = fopen("zadania_pliki_DATA1.txt", "r");
	int ile;
	long long int suma = 0;

	if (f == NULL)
	{
		printf("Error! Nie mozna otworzyc pliku.");
		return 1;
	}

	fscanf(f, "%d", &ile);

	for (int i = 0; i < ile; i++)
	{
		int liczba;
		fscanf(f, "%d\t", &liczba);
		suma += liczba;
	}

	printf("Ile: %d\nSuma: %lld\nSrednia: %lld\n", ile, suma, suma / ile);

	fclose(f);
	return 0;
}

