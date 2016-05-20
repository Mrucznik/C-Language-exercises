#include <stdio.h>

void wyswietl(const char *c)
{
	if (c[0] != '\0')
	{
		putchar(c[0]);
		wyswietl(c + 1);
	}
}

int main(void)
{
	wyswietl("Test\n");
	return 0;
}