#include <stdio.h>

int countBits(unsigned int number)
{
	int count = 0;
	while (number != 0)
	{
		number &= (number - 1); //awesome, thanks Brian Kernighan!
		count++;
	}
	return count;
}

int isBitsEven(unsigned int number)
{
	return !(countBits(number) % 2);
}

int main()
{
	int number = 0;
	printf("Podaj wartosc: ");
	scanf("%u", &number);
	printf("Ta wartosc jest %s bitowo.\n", isBitsEven(number) ? "parzysta" : "nieparzysta");
	return 0;
}

