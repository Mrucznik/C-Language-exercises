#include <stdio.h>

unsigned int length(int *tab)
{
	int i = 0;
	while (*(tab+i) != -1)
		i++;
	return i;
}

int main()
{
	int tab[] = { 16909060, 84281096, 151653132, -1 };
	printf("Length: %d\n", length(tab));
	return 0;
}