#include <stdio.h>

//Ka¿dy bajt to 8 bitów, a wiêc pierwszy bajt reprezentuje liczbê 0x44, drugi 0x43 itd.
//1094861636 powstaje z nich nastêpuj¹co: bajt1*256^0 + bajt2*256^1 + bajt3*256^2 + bajt4*256^4 = 68*256^0 + 67*256^1 + 66*256^2 + 65*256^3 = 1094861636

int main()
{
	union intbyteword
	{
		int integer;
		unsigned char byte[4];
	} u;
	u.integer = 0x41424344;
	printf("Number: %d\n", u.integer);
	printf("Bytes: %d %d %d %d\n", u.byte[0], u.byte[1], u.byte[2], u.byte[3]);
	return 0;
}

