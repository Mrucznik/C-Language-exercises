//main.c

#include <stdio.h>

int main(void)
{
	int a, b;
	printf("Podaj przedzial <k, l> z ktorego wyznaczyc liczby fibbonaciego: ");
	scanf("%d%d", &a, &b);

	int fib[2] = {0, 1};
	while(fib[1] <= b)
	{
		if (fib[1] >= a)
			printf("%d\n", fib[1]);

		int tmp = fib[1];
		fib[1] += fib[0];
		fib[0] = tmp;
	}
	return 0;
}

