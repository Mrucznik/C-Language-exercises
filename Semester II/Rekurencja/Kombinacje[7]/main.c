#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_t(int tab[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", tab[i]);
	putchar('\n');
}

void kombinuj(int tab[], int n, int k, int *ile)
{
	if (k == 1)
	{
		print_t(tab, n);
		*ile = *ile+1;
	}
	else
	{
		for(int i=0; i<k-1; i++)
		{
			kombinuj(tab, n, k - 1, ile);
			if (k % 2 == 0)
				swap(&tab[i], &tab[k - 1]);
			else
				swap(&tab[0], &tab[k - 1]);
		}
		kombinuj(tab, n, k - 1, ile);
	}
}

int main(void)
{
	int T[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ile=0;
	kombinuj(T, 9, 9, &ile);
	printf("Wyliczono %d kombinacji\n", ile);
	return 0;
}