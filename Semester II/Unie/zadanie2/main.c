#include <stdio.h>

//S³owo to dwa bajty, wiêc poprawnie bêdzie je reprezentowa³ typ short który w³aœnie tyle bajtów przyjmuje.

int main()
{
	union intbyteword
	{
		int integer;
		unsigned char byte[4];
		short word[2];
	} u;
	u.integer = 0x41424344;
	printf("Number: %d\n", u.integer);
	printf("Bytes: %d %d %d %d\n", u.byte[0], u.byte[1], u.byte[2], u.byte[3]);
	printf("Words: %d %d\n", u.word[0], u.word[1]);
	return 0;
}

