#include <stdio.h>

int main(void)
{
	const char* t1 = "Ala Ma Kota a kot Ma AlE";

	//I spos�b:
	for(int i=0; i<25; i++)
	{
		putchar(t1[i]);
	}
	putchar('\n');

	//II spos�b:
	fwrite(t1, sizeof(char), 24, stdout);
	fwrite("\n", sizeof(char), 1, stdout);

	//III spos�b:
	fputs(t1, stdout);
	fputs("\n", stdout);
	return 0;
}