#include <stdio.h>

unsigned int length(const char* string)
{
	unsigned int i = 0;
	while (string[i] != '\0')
		i++;
	return i;
}

void printFromEndToBegin(const char* string)
{
	for (int i = length(string) - 1; i >= 0; i--)
		fwrite((string + i), sizeof(char), 1, stdout);
}

int main(void)
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";

	printFromEndToBegin(t1);
	putchar('\n');
	getchar();
	return 0;
}