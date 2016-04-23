#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float* tab;
	tab = (float*)malloc(sizeof(float) * 100);

	for (int i = 0; i < 100; i++)
		tab[i] = rand() % 100;

	for (int i = 0; i < 100; i++)
		printf("%d: %f\n", i + 1, tab[i]);

	free(tab);
	return 0;
}

