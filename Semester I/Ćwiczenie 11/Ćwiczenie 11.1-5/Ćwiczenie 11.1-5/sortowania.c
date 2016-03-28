//sortowania.c

#include <stdlib.h>

//TODO: Je�eli chcesz mie� pewno��, �e kole� si� nie doczepi, pozmieniaj nazwy zmiennych i funkcji.
//Protip dla Visual Studio: PPM -> Refactor -> Rename lub CTRL+R CTRL+R

/*Opis algorytmu sortowania karcianego jak i wszystkie inne znajdziesz na:
http://lidia-js.kis.p.lodz.pl/WDI2/a_sort.html#karc
*/

//szczerze m�wi�c to nie rozumiem w pe�ni tego algorytmu
void cardSort(int tab[], int size)
{
	for (int i = size; i >= 2; i--) //p�tla iteruje "w d�", od najwi�kszego do 2
	{
		if (tab[i - 1] < tab[i - 2]) 
		{
			int tmp; //zamiana element�w, wyt�umaczone w sortowaniu b�belkowym
			tmp = tab[i - 1];
			tab[i - 1] = tab[i - 2];
			tab[i - 2] = tmp;
			cardSort(tab, size); //ponowne wywo�anie funkcji. Z rekurencji wyjdziemy dopiero wtedy, gdy warunek  w "if" nie b�dzie spe�niony
		}
	}
}

/* Opis algorytmu sortowania b�belkowego znajdziesz na:
https://pl.wikipedia.org/wiki/Sortowanie_b%C4%85belkowe
http://cpp0x.pl/kursy/Algorytmy/Sortowanie-danych/Sortowanie-babelkowe-ang-bubble-sort/444
*/

void bubbleSort(int tab[], int size)
{
	int n = size;
	do //p�tla do. Wykonuje si�, dop�ki zachodzi potrzeba dalszego sortowania. Warunek wykonywania: n > 1 - gdy n == 1, oznacza to, �e zosta� do posortowania tylko 1 element, wi�c mo�na przesta� sortowa�)
	{
		int czyZmieniono = 0;
		for (int i = 0; i < n - 1; i++) //P�tla kt�ra iteruje po elementach tablicy liczb. Iteruje po n-1 elementach, poniewa� po ka�dym obiegu p�tli mamy posortowany +1 element na ko�cu
		{
			if (tab[i] > tab[i + 1]) //Sprawdza, czy jeden element jest wi�kszy od drugiego, je�eli tak to zamienia elementy miejscami
			{
				int tmp = tab[i];//deklarujemy i inicjujemy zmienn� tymczasow� (tmp - skr�t od temporary) warto�ci� 1 elementu, aby go nie utraci�
				tab[i] = tab[i + 1]; //Do 1 wrzucamy element 2
				tab[i + 1] = tmp; //Do 2 wrzucamy warto�� tymczasow�, czyli element 1
				czyZmieniono = 1; //Ustawiamy, �e dokona�a si� zmiana w tym obiegu p�tli, b�dzie to potrzebne p�niej, aby wyj�� z sortowania, je�eli nie dokona�a si� �adna zmiana. Zabieg optymalizacyjny.
			}
		}
		
		n--;
		if (!czyZmieniono) //Je�eli nie zmieniono miejscami �adnego elementu, nie ma sensu dalej kontynuowa� sortowania, a wi�c wychodzimy z p�tli za pomoc� break;
			break; //mo�na te� zastosowa� return; ale jest to mniej wskazane, gdy� nie wykona�by si� nam kod, kt�ry umie�ciliby�my za p�tl�. Tutaj go nie ma, dlatego mo�na.
	}
	while (n > 1);
}

//Sortowanie proste
void simpleSort(int tab[], int size)
{
	for (int i = 0; i < size-1; i++) //Iteruje po size-1 elementach, gdy� ostatni element nie wymaga sortowania, poniewa� zostanie zamieniony w ostatnim kroku z elementem wi�kszym/pozostanie na miejscu
	{
		//Znajdywanie najmniejszego elementu w przedziale <i, size>
		int min = 0;
		for (int j = i; j < size; j++)
		{
			if (tab[j] < tab[min]) min = j;
		}

		//zamiana i'tego elementu ze znalezionym najmniejszym
		int tmp = tab[i];
		tab[i] = tab[min];
		tab[min] = tmp;
	}
}

//quicksorta ci ogarn� jutro
void quickSort(int tab[], int left, int right)
{
	int pktPodzialu;
	if (left < right)
	{
		int x = tab[left];
		int i = left, j = right;
		while (1)
		{
			while (tab[j] > x)
				j--;
			while (tab[i] < x)
				i++;

			if (i < j)
			{
				int tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;

				i++;
				j--;
			}
			else
			{
				pktPodzialu = j;
				break;
			}
		}
		quickSort(tab, left, pktPodzialu);
		quickSort(tab, pktPodzialu + 1, right);
	}
}

