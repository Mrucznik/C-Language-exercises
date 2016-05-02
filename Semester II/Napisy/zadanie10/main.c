#include <stdio.h>

void replaceSpaceToUnderscore(char* string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
			string[i] = '_';
		i++;
	}
}

int main(void)
{
	char napis[] = "Ala Ma Kota a kot Ma AlE";
	replaceSpaceToUnderscore(napis);
	puts(napis);
	return 0;
}