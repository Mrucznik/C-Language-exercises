#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "funkcje_geom.h"

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	fgeom_t* figura[10];

	for (int i = 0; i < 10; i++)
	{
		switch (rand() % 4)
		{
		case trojkat:
			figura[i] = generuj_trojkat(rand() % 100, rand() % 100, rand() % 100, rand() % 100, rand() % 100, rand() % 100, NULL);
			break;
		case kolo:
			figura[i] = generuj_kolo(rand() % 100, rand() % 100, rand() % 10, NULL);
			break;
		case kwadrat:
			figura[i] = generuj_kwadrat(rand() % 100, rand() % 100, rand() % 100, rand() % 100, rand() % 100, rand() % 100, rand() % 100, rand() % 100, NULL);
			break;
		case odcinek:
			figura[i] = generuj_odcin(rand() % 100, rand() % 100, rand() % 100, rand() % 100, NULL);
			break;
		}

		if (figura[i] == NULL)
		{
			printf("ERROR! Nie uda³o siê stworzyæ figury!");
			return 1;
		}
	}

	zapisz_figure(figura, 10);
	wczytaj_figure(figura, 10);

	for (int i = 0; i < 10; i++)
	{
		wyswietl_figure(*figura[i]);
	}

	return 0;
}