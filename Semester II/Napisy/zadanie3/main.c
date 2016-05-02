#include <stdio.h>

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

int main(void)
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";

	int smallletters = 0, bigletters = 0, spaces = 0;
	countSmallBigLettersAndSpaces(t1, &smallletters, &bigletters, &spaces);
	printf("Male litery: %d, Duze litery: %d, Spacje: %d\n", smallletters, bigletters, spaces);
	return 0;
}