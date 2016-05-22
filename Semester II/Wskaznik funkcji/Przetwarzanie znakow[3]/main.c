#include <stdio.h>
#include <ctype.h>

char spacjeNaMyslniki(char ch)
{
	return ch == ' ' ? '-' : ch;
}

void przetwarzaj(char *string, char (*func)(char))
{
	int i = 0;
	while(string[i] != '\0')
	{
		string[i] = func(string[i]);
		i++;
	}
}

int main(void)
{
	char string[] = "Testowy TEKST 123.";
	char string2[] = "Testowy TEKST 123.";
	char string3[] = "Testowy TEKST 123.";
	printf("Podczatkowy tekst: %s\n\n", string);
	przetwarzaj(string, toupper);
	printf("Male na duze: %s\n", string);
	przetwarzaj(string2, tolower);
	printf("Duze na male: %s\n", string2);
	przetwarzaj(string3, spacjeNaMyslniki);
	printf("Spacje na myslniki: %s\n", string3);
	return 0;
}