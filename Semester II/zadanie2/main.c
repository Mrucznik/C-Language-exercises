#include <stdio.h>

int main()
{
	int T[10];
	int* wskT = T;

	for (int i = 0; i < 10; i++)
	{
		*(wskT+i) = i;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", *(wskT+i));
	}

	return 0;
}