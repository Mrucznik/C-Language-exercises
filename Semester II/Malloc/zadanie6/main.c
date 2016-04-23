#include <stdlib.h>
#include <stdio.h>

void wyswietl(const int* ptr, int N)
{
	for (int i = 0; i < N; i++)
		printf("%d: %d\n", i + 1, ptr[i]);
}

int* kopia(const int* ptr, int N)
{
	int* tab = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		tab[i] = ptr[i];
	return tab;
}

int main(void)
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int* b;
	b = kopia(a, 10);
	puts("Tablica A:");
	wyswietl(a, 10);
	puts("\nTablica B:");
	wyswietl(b, 10);
	free(b);
	return 0;
}

