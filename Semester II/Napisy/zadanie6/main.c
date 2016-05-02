#include <stdio.h>

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
	while ((dest[j] = source[j - i]) != '\0')
	{
		j++;
	}
}

unsigned int strlen(const char* str)
{
	unsigned int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

int main(void)
{
	return 0;
}