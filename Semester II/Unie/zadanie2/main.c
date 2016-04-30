#include <stdio.h>

//S�owo to dwa bajty, wi�c poprawnie b�dzie je reprezentowa� typ short kt�ry w�a�nie tyle bajt�w przyjmuje.

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

