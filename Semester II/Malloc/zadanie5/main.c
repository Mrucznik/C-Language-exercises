#include <stdlib.h>

float* alokuj(int N)
{
	float *tab = (float*)malloc(sizeof(float)*N);
	return tab;
}

int main(void)
{
	float *tab;
	tab = alokuj(10);
	free(tab);
	return 0;
}
