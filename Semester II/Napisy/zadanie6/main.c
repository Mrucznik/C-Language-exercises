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

void main() 
{
	char napis1[] = "Testowy napis";
	char napis2[] = " drugi napis";
	char skopiowany[20];
	printf("Dlugosc napisu \"%s\": %d\n", napis1, strlen(napis1));
	strcat(napis1, napis2);
	printf("strcat(napis1, napis2), napis1 = %s\n", napis1);
	strcpy(skopiowany, napis2);
	printf("strcpy(skopiowany, napis2); skopiowany = %s\n", skopiowany);
	return 0;
}
