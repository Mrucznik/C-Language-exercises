#include <stdio.h>
#include <stdlib.h>

static int fibbonacci[26] = { 0, 1, 1, 0 };

int fib(int n)
{
	if (n < 0)
	{
		printf("Error");
		exit(1);
	}
	if (n <= 26)
	{
		if (fibbonacci[n] != 0)
			return fibbonacci[n];
		return fibbonacci[n] = fib(n - 2) + fib(n - 1);
	}
	return fib(n - 2) + fib(n - 1);
}

int sumuj(int n)
{
	if (n <= 1)
	{
		return fib(1);
	}
	return fib(n) + sumuj(n - 1);
}

int main(void)
{
	for(int i=5; i<=25; i++)
		printf("Suma %d elementow: %d\n", i, sumuj(i));
	return 0;
}