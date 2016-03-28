//sortowania.c

#include <stdlib.h>

//TODO: Je¿eli chcesz mieæ pewnoœæ, ¿e koleœ siê nie doczepi, pozmieniaj nazwy zmiennych i funkcji.
//Protip dla Visual Studio: PPM -> Refactor -> Rename lub CTRL+R CTRL+R

/*Opis algorytmu sortowania karcianego jak i wszystkie inne znajdziesz na:
http://lidia-js.kis.p.lodz.pl/WDI2/a_sort.html#karc
*/

//szczerze mówi¹c to nie rozumiem w pe³ni tego algorytmu
void cardSort(int tab[], int size)
{
	for (int i = size; i >= 2; i--) //pêtla iteruje "w dó³", od najwiêkszego do 2
	{
		if (tab[i - 1] < tab[i - 2]) 
		{
			int tmp; //zamiana elementów, wyt³umaczone w sortowaniu b¹belkowym
			tmp = tab[i - 1];
			tab[i - 1] = tab[i - 2];
			tab[i - 2] = tmp;
			cardSort(tab, size); //ponowne wywo³anie funkcji. Z rekurencji wyjdziemy dopiero wtedy, gdy warunek  w "if" nie bêdzie spe³niony
		}
	}
}

/* Opis algorytmu sortowania b¹belkowego znajdziesz na:
https://pl.wikipedia.org/wiki/Sortowanie_b%C4%85belkowe
http://cpp0x.pl/kursy/Algorytmy/Sortowanie-danych/Sortowanie-babelkowe-ang-bubble-sort/444
*/

void bubbleSort(int tab[], int size)
{
	int n = size;
	do //pêtla do. Wykonuje siê, dopóki zachodzi potrzeba dalszego sortowania. Warunek wykonywania: n > 1 - gdy n == 1, oznacza to, ¿e zosta³ do posortowania tylko 1 element, wiêc mo¿na przestaæ sortowaæ)
	{
		int czyZmieniono = 0;
		for (int i = 0; i < n - 1; i++) //Pêtla która iteruje po elementach tablicy liczb. Iteruje po n-1 elementach, poniewa¿ po ka¿dym obiegu pêtli mamy posortowany +1 element na koñcu
		{
			if (tab[i] > tab[i + 1]) //Sprawdza, czy jeden element jest wiêkszy od drugiego, je¿eli tak to zamienia elementy miejscami
			{
				int tmp = tab[i];//deklarujemy i inicjujemy zmienn¹ tymczasow¹ (tmp - skrót od temporary) wartoœci¹ 1 elementu, aby go nie utraciæ
				tab[i] = tab[i + 1]; //Do 1 wrzucamy element 2
				tab[i + 1] = tmp; //Do 2 wrzucamy wartoœæ tymczasow¹, czyli element 1
				czyZmieniono = 1; //Ustawiamy, ¿e dokona³a siê zmiana w tym obiegu pêtli, bêdzie to potrzebne póŸniej, aby wyjœæ z sortowania, je¿eli nie dokona³a siê ¿adna zmiana. Zabieg optymalizacyjny.
			}
		}
		
		n--;
		if (!czyZmieniono) //Je¿eli nie zmieniono miejscami ¿adnego elementu, nie ma sensu dalej kontynuowaæ sortowania, a wiêc wychodzimy z pêtli za pomoc¹ break;
			break; //mo¿na te¿ zastosowaæ return; ale jest to mniej wskazane, gdy¿ nie wykona³by siê nam kod, który umieœcilibyœmy za pêtl¹. Tutaj go nie ma, dlatego mo¿na.
	}
	while (n > 1);
}

//Sortowanie proste
void simpleSort(int tab[], int size)
{
	for (int i = 0; i < size-1; i++) //Iteruje po size-1 elementach, gdy¿ ostatni element nie wymaga sortowania, poniewa¿ zostanie zamieniony w ostatnim kroku z elementem wiêkszym/pozostanie na miejscu
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

//quicksorta ci ogarnê jutro
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

