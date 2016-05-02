#include <stdio.h>

void strScal3Wyrazy(char* ss, char*s1, char*s2, char*s3)
{
	int i = 0, j = 0;
	while (s1[i] != '\0')
		ss[i++] = s1[i];
	ss[i++] = ' ';

	while (s2[j] != '\0')
		ss[i++] = s2[j++];
	ss[i++] = ' ';

	j = 0;
	while (s3[j] != '\0')
		ss[i++] = s3[j++];
	ss[i] = '\0';
}

int main(void)
{
	char n1[] = "Zadanie", n2[] = "nr", n3[] = "dziewiec", n123[128];
	strScal3Wyrazy(n123, n1, n2, n3);
	puts(n123);
	getchar();
	return 0;
}