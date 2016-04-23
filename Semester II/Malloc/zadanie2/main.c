#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* byte = (char*)malloc(1024 * 1024 * 1024);
	if (byte == NULL) printf("Nie udalo sie zaalokowac pamieci!");
	getchar();
	return 0;
}

