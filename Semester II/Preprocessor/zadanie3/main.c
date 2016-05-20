#include <stdio.h>

#define assert(__expression, __error) { if(!(__expression)) { printf("%s\nFile: %s, line %d", __error, __FILE__, __LINE__); } }

int stworzPlik(const char filename[])
{
	FILE* f = fopen(filename, "w");
	if (f == NULL)
		return 0;
	fclose(f);
	return 1;
}


int main(void)
{
	for(int i=0; i<10; i++)
	{
		char filename[32], komunikat[64];
		sprintf(filename, "plik%d.txt", i);
		sprintf(komunikat, "Nie udalo sie otworzyc pliku plik%d.txt", i);
		assert(stworzPlik(filename), komunikat);
	}
	return 0;
}