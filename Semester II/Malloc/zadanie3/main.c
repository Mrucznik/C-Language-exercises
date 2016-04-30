#include <stdlib.h>

//System alokuje pami�� dop�ki pami�� wykorzystana przez program nie osi�gnie 2Gb
//Po osi�gni�ciu tej warto�ci program ca�y czas b�dzie wykonywa� p�tle ale �adna dodatkowa pami�� nie zostanie ju� przydzielona.
//System pracuje stabilnie w przypadku gdy zosta�a jeszcze pami�� RAM.
//W przypadku jej braku (3x uruchomiony program) s� problemy ze stabilno�ci� (zacinanie si� myszki i d�wi�ku), ale tylko przez pare sekund. Potem system zmniejsza wykorzystanie z 8GB/8GB na 7GB/8GB. w mened�erze zada� jest napisane, �e 2 jako pierwsze uruchomione programy wykorzystuj� 0,1MB pami�ci a 3 tyle, ile uda�o si� przydzieli� (43,7MB). Co dziwne, zaj�ta pami�� RAM to nadal 7GB z 8GB.
//Kolejne uruchomienia programu powoduj� ten sam efekt (chwilowy brak pami�ci i problemy ze stabilno�ci� a nast�pnie powr�t do 1GB wolnej pami�ci)
//Testy przeprowadzane na Windows 10

int main(void)
{
	char* byte;
	while (1)
		byte = (char*)malloc(1024);
	return 0;
}

