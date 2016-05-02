#include <stdio.h>

int main(void)
{
	const char* tekst = "Ala ma kota";

	int i = 0;
	while(tekst[i] != ' ')
	{
		putchar(tekst[i]);
		i++;
	}
	return 0;
}