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

struct fgeom_t
{
	enum TYP_FIGURY typ;

	struct punkt_t p1, p2, p3, p4;
	float R;
};
typedef struct fgeom_t fgeom_t;

fgeom_t* generuj_trojkat(float, float, float, float, float, float, int *);
fgeom_t* generuj_kolo(float, float, float, int*);
fgeom_t* generuj_kwadrat(float, float, float, float, float, float, float, float, int *);
fgeom_t* generuj_odcin(float, float, float, float, int *);
void wyswietl_figure(fgeom_t);
void zapisz_figure(fgeom_t **, int);
void wczytaj_figure(fgeom_t **, int);