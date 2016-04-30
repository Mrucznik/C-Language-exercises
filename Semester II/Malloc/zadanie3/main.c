#include <stdlib.h>

//System alokuje pamiêæ dopóki pamiêæ wykorzystana przez program nie osi¹gnie 2Gb
//Po osi¹gniêciu tej wartoœci program ca³y czas bêdzie wykonywa³ pêtle ale ¿adna dodatkowa pamiêæ nie zostanie ju¿ przydzielona.
//System pracuje stabilnie w przypadku gdy zosta³a jeszcze pamiêæ RAM.
//W przypadku jej braku (3x uruchomiony program) s¹ problemy ze stabilnoœci¹ (zacinanie siê myszki i dŸwiêku), ale tylko przez pare sekund. Potem system zmniejsza wykorzystanie z 8GB/8GB na 7GB/8GB. w mened¿erze zadañ jest napisane, ¿e 2 jako pierwsze uruchomione programy wykorzystuj¹ 0,1MB pamiêci a 3 tyle, ile uda³o siê przydzieliæ (43,7MB). Co dziwne, zajêta pamiêæ RAM to nadal 7GB z 8GB.
//Kolejne uruchomienia programu powoduj¹ ten sam efekt (chwilowy brak pamiêci i problemy ze stabilnoœci¹ a nastêpnie powrót do 1GB wolnej pamiêci)
//Testy przeprowadzane na Windows 10

int main(void)
{
	char* byte;
	while (1)
		byte = (char*)malloc(1024);
	return 0;
}

