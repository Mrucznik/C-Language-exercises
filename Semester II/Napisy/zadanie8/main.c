#include <stdio.h>

char switchLetterSize(char letter)
{
	if (letter >= 'a' && letter <= 'z')
		return letter - 'a' + 'A';
	if (letter >= 'A' && letter <= 'Z')
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

int main(void)
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";
	char t2[32];
	strCopyAndSwitchLetterSize(t2, t1);
	puts(t2);
	return 0;
}