#include <stdio.h>
#include <stdarg.h>

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

void printFromEndToBegin(const char* string)
{
	for (int i = length(string) - 1; i >= 0; i--)
		fwrite((string + i), sizeof(char), 1, stdout);
}

void strcpy(char dest[], const char source[])
{
	int i = 0;
	while ((dest[i] = source[i]) != '\0') {
		i++;
	}
}

void strcat(char* dest, const char* source)
{
	int i = 0, j;
	while (dest[i] != '\0') {
		i++;
	}
	j = i;
	while((dest[j] = source[j - i]) != '\0')
	{
		j++;
	}
}

unsigned int strlen(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

void writeOneWord(const char* str, int idx)
{
	while (str[idx] != '\0' && str[idx] != ' ')
	{
		putc(str[idx], stdout);
		idx++;
	}
}

void printInReverseWordOrder(const char* str)
{
	int end = strlen(str);
	for (int i = end; i > 0; i--)
	{
		if (str[i] == ' ')
		{
			writeOneWord(str, i + 1);
			putc(' ', stdout);
		}
	}
	writeOneWord(str, 0);
}

char switchLetterSize(char letter)
{
	if (letter >= 'a' && letter <= 'z')
		return letter - 'a' + 'A';
	if(letter >= 'A' && letter <= 'Z')
		return letter - 'A' + 'a';
	return letter;
}

void strCopyAndSwitchLetterSize(char* dest, const char* source)
{
	int i = 0;
	while (source[i] != '\0')
	{
		dest[i] = switchLetterSize(source[i]);
		i++;
	}
	dest[i] = '\0';
}

void strScal3Wyrazy(char* ss, char*s1, char*s2, char*s3)
{
	int i = 0, j = 0;
	while(s1[i] != '\0')
	{
		ss[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ss[i] = s2[j];
		i++;
		j++;
	}
	j = 0;
	while (s3[j] != '\0')
	{
		ss[i] = s3[j];
		i++;
		j++;
	}
	ss[i] = '\0';
}

void replaceSpaceToUnderscore(char* string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		if (string[i] == ' ')
			string[i] = '_';
		i++;
	}
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
	printFromEndToBegin(t1);
	puts("");

	//Zadanie 6. (Napisz odpowiedniki funkcji strcpy, strcat oraz strlen. Uzyj modyfikator�w const w li�cie parametr�w)
	char test[32] = "Test";
	char cpy[32] = "Siema";
	char cat[32] = " PL";
	puts(test);
	strcpy(test, cpy);
	puts(test);
	strcat(test, cat);
	puts(test);
	printf("%d\n", strlen(test));

	//Zadanie 7. (Wy�wietl s�owa t1 w odwrotnej kolejno�ci (Ale Ma kot a Kota Ma Ala)
	printInReverseWordOrder(t1);
	puts("");

	//Zadanie 8. (Napisz funkcj�, tworzy kopi� tekstu t1, zmieniaj�c znaki ma�e na du�e a du�e na ma�e)
	char t2[32];
	strCopyAndSwitchLetterSize(t2, t1);
	puts(t2);

	//Zadanie 9. (Napisz funkcj�, kt�ra po��czy 3 oddzielne napisy)
	char n1[] = "Liberty ", n2[] = "or ", n3[] = "death", n123[128];
	strScal3Wyrazy(n123, n1, n2, n3);
	puts(n123);

	//Zadanie 10. (Napisz funkcj�, kt�ra zast�pi spacje w tek�cie znakiem "_". Tekst �r�d�owy ma by� przekazywany do funkcji jako jeden z parametr�w.)
	char napis[] = "Ala Ma Kota a kot Ma AlE";
	replaceSpaceToUnderscore(napis);
	puts(napis);
	return 0;
}

