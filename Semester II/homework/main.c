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

	//Zadanie 1. (Wyœwietl tekst na ekranie bez u¿ywania funkcji printf/puts. PodpowiedŸ: jaka inna funkcja pozwala wyœwietlaæ znaki na ekranie?)
	fwrite(t1, sizeof(char), 24, stdout);
	puts("");

	//Zadanie 2. (Zak³adaj¹c, ¿e ci¹gi znaków w jezyku C zapisane s¹ w formacjie ASCIIZ, napisz program wyznaczaj¹cy d³ugoœæ tekstu.)
	printf("%d\n", length(t1));

	//Zadanie 3. (Napisz funkcjê licz¹c¹ wielkie litery, ma³e litery oraz spacje w tekœcie t1. Wyniki (trzy wartoœci) powinny byæ zwracane przez funkcjê poprzez wskaŸniki do zmiennych docelowych, przekazywanych w liœcie parametrów wywo³ania funkcji.)
	int smallletters = 0, bigletters = 0, spaces = 0;
	countSmallBigLettersAndSpaces(t1, &smallletters, &bigletters, &spaces);
	printf("Male litery: %d, Duze litery: %d, Spacje: %d\n", smallletters, bigletters, spaces);

	//Zadanie 4. (Dana jest tablica typu char: const char* tekst = "Ala ma kota". Wykorzystuj¹c wskaŸnik na znak (char), wyœwietl pierwsze s³owo tekstu (do spacji, bez spacji)
	const char* tekst = "Ala ma kota";
	fwrite(tekst, sizeof(char), getFirstWordLength(tekst), stdout);
	puts("");

	//Zadanie 5. Wyœwietl tekst od koñca (ElA aM tok a atoK aM alA).
	for (int i = length(t1)-1; i >= 0; i--)
		fwrite((t1 + i), sizeof(char), 1, stdout);
	puts("");

	//Zadanie 6. (Napisz odpowiedniki funkcji strcpy, strcat oraz strlen. Uzyj modyfikatorów const w liœcie parametrów)

	//Zadanie 7. (Wyœwietl s³owa t1 w odwrotnej kolejnoœci (Ale Ma kot a Kota Ma Ala)

	//Zadanie 8. (Napisz funkcjê, tworzy kopiê tekstu t1, zmieniaj¹c znaki ma³e na du¿e a du¿e na ma³e)

	//Zadanie 9. (Napisz funkcjê, która po³¹czy 3 oddzielne napisy)

	//Zadanie 10. (Napisz funkcjê, która zast¹pi spacje w tekœcie znakiem "_". Tekst Ÿród³owy ma byæ przekazywany do funkcji jako jeden z parametrów.)
	return 0;
}

