//main.c

#include <stdio.h>

int hanoi(int source, int destination, int iloscObreczy)
{
	if (iloscObreczy > 1)
	{
		hanoi(source, 6 - source - destination, iloscObreczy - 1);
		hanoi(source, source, 1);
		hanoi(6 - source - destination, destination, iloscObreczy - 1);
	}
	else
	{
		printf("Przekladam z %d na %d\n", source, destination);
	}
}

int main(void)
{
	int iloscObreczy;
	printf("Podaj ilosc obreczy: ");
	scanf("%d", &iloscObreczy);

	hanoi(1, 3, iloscObreczy);

	return 0;
}

