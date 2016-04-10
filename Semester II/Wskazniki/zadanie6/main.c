#include <stdio.h>

int main()
{
	int tab[3] = { 16909060, 84281096, 151653132 };

	for (int i = 0; i < 3 * sizeof(int); i++)
	{
		unsigned char bajt = *((unsigned char*)tab + i);
		if (bajt >= 4 && bajt <= 7)
		{
			printf("%p\n", ((unsigned char*)tab + i));
		}
	}

	return 0;
}