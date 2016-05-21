#include <stdio.h>
#include <stdarg.h>

/*
Gdy wywo³amy funkcjê bez dodatkowych parametrów funkcja va_arg(list, int) bêdzie pobiera³a bloki pamiêci, które nie s¹ zarezerwowane jako argumenty funkcji
wiêc wynikiem bêd¹ liczby, które sk³adaj¹ siê z bajtów pamiêci bêd¹cych za ostatnim przekazanym argumentem.
Wyniki:
Dla wywolania 4 argumentow:
Liczba 0: 1
Liczba 1: 2
Liczba 2: 3
Dla wywolania 3 argumentow:
Liczba 0: 1
Liczba 1: 2
Liczba 2: 1642566
Dla wywolania 2 argumentow:
Liczba 0: 1
Liczba 1: 1642566
Liczba 2: 1642566
Dla wywolania 1 argumentow:
Liczba 0: 1642566
Liczba 1: 1642566
Liczba 2: 2252800
*/

void show(int dummy, ...)
{
	va_list list;
	va_start(list, dummy);

	for(int i=0; i<3; i++)
	{
		printf("Liczba %d: %d\n", i, va_arg(list, int));
	}

	va_end(list);
}

int main(void)
{
	puts("Dla wywolania 4 argumentow:");
	show(0, 1, 2, 3);
	puts("Dla wywolania 3 argumentow:");
	show(0, 1, 2);
	puts("Dla wywolania 2 argumentow:");
	show(0, 1);
	puts("Dla wywolania 1 argumentow:");
	show(0);
	return 0;
}