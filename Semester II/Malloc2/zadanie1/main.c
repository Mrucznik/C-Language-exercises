#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

int main()
{
	setlocale(LC_ALL, "");

	fgeom_t* fig;

	fig = generuj_kolo(10.0f, 20.0f, 30.0f, NULL);
	wyswietl_figure(*fig);
	free(fig);

	fig = generuj_kwadrat(10.0f, 20.0f, 20.0f, 20.0f, 10.0f, 10.0f, 20.0f, 10.0f, NULL);
	wyswietl_figure(*fig);
	free(fig);
	return 0;
}

