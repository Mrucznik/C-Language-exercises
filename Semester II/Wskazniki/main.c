#include <stdio.h>

int main()
{
	int a = 1;
	double b = 1.0;
	unsigned char c = 1;

	int* wska = &a;
	double* wskb = &b;
	unsigned char* wskc = &c;

	*wska = 5;
	*wskb = 3.6;
	*wskc = 255;

	printf("a: %d b: %lf c:%u\n", a, b, c);

	return 0;
}