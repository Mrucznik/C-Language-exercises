#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define ERR(__warunek, __errcode) { if(__warunek) { if(err != NULL) *err = __errcode; return NULL; } }

enum TYP_FIGURY
{
	trojkat,
	kolo,
	kwadrat,
	odcinek
};

struct punkt_t
{
	float x, y;
};

typedef struct fgeom_t
{
	enum TYP_FIGURY typ;

	struct punkt_t p1, p2, p3, p4;
	float R;
} fgeom_t;

fgeom_t* generuj_trojkat(float x1, float y1, float x2, float y2, float x3, float y3, int* err)
{
	if (err != NULL)
		*err = 0;

	fgeom_t* fig = (fgeom_t*)malloc(sizeof(fgeom_t));

	ERR(fig == NULL, 4);

	fig->typ = odcinek;
	fig->p1.x = x1;
	fig->p1.y = y1;
	fig->p2.x = x2;
	fig->p2.y = y2;
	fig->p3.x = x3;
	fig->p4.y = y3;

	return fig;
}

fgeom_t* generuj_kolo(float x, float y, float r, int* err)
{
	if (err != NULL)
		*err = 0;
	ERR(r < 0, 1);
	ERR(x < 0 || x > 100, 2);
	ERR(y < 0 || y > 100, 3);

	fgeom_t* fig = (fgeom_t*)malloc(sizeof(fgeom_t));

	ERR(fig == NULL, 4);

	fig->typ = kolo;
	fig->p1.x = x;
	fig->p1.y = y;
	fig->R = r;

	return fig;
}

fgeom_t* generuj_kwadrat(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int* err)
{
	if (err != NULL)
		*err = 0;

	fgeom_t* fig = (fgeom_t*)malloc(sizeof(fgeom_t));

	ERR(fig == NULL, 4);

	fig->typ = kwadrat;
	fig->p1.x = x1;
	fig->p1.y = y1;
	fig->p2.x = x2;
	fig->p2.y = y2;
	fig->p3.x = x3;
	fig->p3.y = y3;
	fig->p4.x = x4;
	fig->p4.y = y4;

	return fig;
}

fgeom_t* generuj_odcin(float x1, float y1, float x2, float y2, int* err)
{
	if (err != NULL)
		*err = 0;

	fgeom_t* fig = (fgeom_t*)malloc(sizeof(fgeom_t));

	ERR(fig == NULL, 4);

	fig->typ = odcinek;
	fig->p1.x = x1;
	fig->p1.y = y1;
	fig->p2.x = x2;
	fig->p2.y = y2;

	return fig;
}

void wyswietl_figure(fgeom_t fig)
{
	switch (fig.typ)
	{
	case trojkat:
		printf("Figura: trojkat\nPierwszy wierzcho³ek:\n\tX: %f\n\tY: %f\nDrugi wierzcho³ek:\n\tX: %f\n\tY: %f\nTrzeci wierzcho³ek:\n\tX: %f\n\tY: %f\n", fig.p1.x, fig.p1.y, fig.p2.x, fig.p2.y, fig.p3.x, fig.p3.y);
		break;
	case kolo:
		printf("Figura: ko³o\nX: %f\nY: %f\nPromieñ: %f\n", fig.p1.x, fig.p1.y, fig.R);
		break;
	case kwadrat:
		printf("Figura: kwadrat\nPierwszy wierzcho³ek:\n\tX: %f\n\tY: %f\nDrugi wierzcho³ek:\n\tX: %f\n\tY: %f\nTrzeci wierzcho³ek:\n\tX: %f\n\tY: %f\nCzwarty wierzcho³ek:\n\tX: %f\n\tY: %f\n", fig.p1.x, fig.p1.y, fig.p2.x, fig.p2.y, fig.p3.x, fig.p3.y, fig.p4.x, fig.p4.y);
		break;
	case odcinek:
		printf("Figura: odcinek\nPoczatek:\n\tX: %f\n\tY: %f\nKoniec:\n\tX: %f\n\tY: %f\n", fig.p1.x, fig.p1.y, fig.p2.x, fig.p2.y);
		break;
	}
}

void zapisz_figure(fgeom_t** fig, int ile)
{
	FILE* f = fopen("file.dat", "wb");
	if (f == NULL)
	{
		printf("Nie uda³o siê otworzyæ pliku file.dat!");
		exit(1);
	}

	fwrite(*fig, sizeof(fgeom_t), ile, f);

	fclose(f);
}

void wczytaj_figure(fgeom_t** fig, int ile)
{
	FILE* f = fopen("file.dat", "wb");
	if (f == NULL)
	{
		printf("Nie uda³o siê otworzyæ pliku file.dat!");
		exit(1);
	}

	fread(fig, sizeof(fgeom_t), ile, f);

	fclose(f);
}

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

