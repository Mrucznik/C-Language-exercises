#include <stdio.h>

int main()
{
	int tab[3] = { 16909060, 84281096, 151653132 };

	for (int i = 0; i < 3 * sizeof(int); i++)
	{
		printf("%u\n", *((unsigned char*)tab + i));
	}
	return 0;
}