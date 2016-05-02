#include <stdio.h>

unsigned int strlen(const char* str)
{
	unsigned int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

void writeOneWord(const char* str, int idx)
{
	while (str[idx] != '\0' && str[idx] != ' ')
	{
		putchar(str[idx]);
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
			putchar(' ');
		}
	}
	writeOneWord(str, 0);
}


int main(void)
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";

	printInReverseWordOrder(t1);
	putchar('\n');
	getchar();
	return 0;
}