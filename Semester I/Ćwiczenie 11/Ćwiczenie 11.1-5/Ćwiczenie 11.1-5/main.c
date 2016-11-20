//main.c

#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE	100

extern void cardSort(int tab[], int size); //s�owo kluczowe extern oznacza, �e implementacja (cia�o) funkcji nie znajduje si� w tym samym pliku, co deklaracja
extern void bubbleSort(int tab[], int size); //wi�cej info: http://4programmers.net/C/Extern
extern void simpleSort(int tab[], int size); //po angielsku i bardzie rzeczowo: http://www.geeksforgeeks.org/understanding-extern-keyword-in-c/
extern void quickSort(int tab[], int left, int right);

int main(void)
{
	srand((unsigned int)time(NULL));

	//interfejs u�ytkownika, obs�ug� i wywo�ania zr�b samemu.
	return 0;
}

