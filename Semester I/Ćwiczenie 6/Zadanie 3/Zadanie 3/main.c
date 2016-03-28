//main.c

#include <stdio.h>
#include <math.h>

int main(void)
{
	int m;
	int x[200], suma_x = 0;
	double srednia, wariacja=0, odchylenie;
	
	//Pobieranie liczby pomiarow (m)
	do
	{
		printf("Podaj ilosc pomiarow (mniej niz 200): ");
		scanf("%d", &m);
	} while (!(m < 200));

	//Pobieranie x'ów i obliczanie ich sumy
	for (int i = 0; i < m; i++)
	{
		printf("Podaj %d x: ", i + 1);
		scanf("%d", &x[i]);
		suma_x += x[i];
	}

	//Liczenie œredniej
	srednia = (double)suma_x / m;

	//Uzyskiwanie ró¿nicy miêdzy x'ami a œredni¹, potem podnoszenie do kwadratu i sumowanie
	for (int i = 0; i < m; i++)
	{
		double potega = x[i] - srednia;
		wariacja += potega*potega;
	}
		

	wariacja /= (m - 1);
	odchylenie = sqrt(wariacja);

	printf("Wariacja o2(x)=%f, Odchylenie standardowe=%f\n", wariacja, odchylenie);
	return 0;
}