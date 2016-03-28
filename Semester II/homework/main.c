#include <stdio.h>

unsigned int length(const char* string)
{
	int i = 0;
	while (string[i] != '\0')
		i++;
	return i;
}

void countSmallBigLettersAndSpaces(const char* string, int *smallletters, int *bigletters, int *spaces)
{
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			(*smallletters)++;
		else if (string[i] >= 'A' && string[i] <= 'Z')
			(*bigletters)++;
		else if (string[i] == ' ')
			(*spaces)++;
		i++;
	}
}

int getFirstWordLength(const char* string)
{
	int i = 0;
	while (*(string + i) != ' ' && *(string + i) != '\0')
		i++;
	return i;
}

int main()
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";

	//Zadanie 1. (Wy�wietl tekst na ekranie bez u�ywania funkcji printf/puts. Podpowied�: jaka inna funkcja pozwala wy�wietla� znaki na ekranie?)
	fwrite(t1, sizeof(char), 24, stdout);
	puts("");

	//Zadanie 2. (Zak�adaj�c, �e ci�gi znak�w w jezyku C zapisane s� w formacjie ASCIIZ, napisz program wyznaczaj�cy d�ugo�� tekstu.)
	printf("%d\n", length(t1));

	//Zadanie 3. (Napisz funkcj� licz�c� wielkie litery, ma�e litery oraz spacje w tek�cie t1. Wyniki (trzy warto�ci) powinny by� zwracane przez funkcj� poprzez wska�niki do zmiennych docelowych, przekazywanych w li�cie parametr�w wywo�ania funkcji.)
	int smallletters = 0, bigletters = 0, spaces = 0;
	countSmallBigLettersAndSpaces(t1, &smallletters, &bigletters, &spaces);
	printf("Male litery: %d, Duze litery: %d, Spacje: %d\n", smallletters, bigletters, spaces);

	//Zadanie 4. (Dana jest tablica typu char: const char* tekst = "Ala ma kota". Wykorzystuj�c wska�nik na znak (char), wy�wietl pierwsze s�owo tekstu (do spacji, bez spacji)
	const char* tekst = "Ala ma kota";
	fwrite(tekst, sizeof(char), getFirstWordLength(tekst), stdout);
	puts("");

	//Zadanie 5. Wy�wietl tekst od ko�ca (ElA aM tok a atoK aM alA).
	for (int i = length(t1)-1; i >= 0; i--)
		fwrite((t1 + i), sizeof(char), 1, stdout);
	puts("");

	//Zadanie 6. (Napisz odpowiedniki funkcji strcpy, strcat oraz strlen. Uzyj modyfikator�w const w li�cie parametr�w)

	//Zadanie 7. (Wy�wietl s�owa t1 w odwrotnej kolejno�ci (Ale Ma kot a Kota Ma Ala)

	//Zadanie 8. (Napisz funkcj�, tworzy kopi� tekstu t1, zmieniaj�c znaki ma�e na du�e a du�e na ma�e)

	//Zadanie 9. (Napisz funkcj�, kt�ra po��czy 3 oddzielne napisy)

	//Zadanie 10. (Napisz funkcj�, kt�ra zast�pi spacje w tek�cie znakiem "_". Tekst �r�d�owy ma by� przekazywany do funkcji jako jeden z parametr�w.)
	return 0;
}

