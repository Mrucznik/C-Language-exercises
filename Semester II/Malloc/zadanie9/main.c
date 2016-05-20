#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define ERROR(__warunek) { if( __warunek) { printf("ERROR! Podano wskaznik na NULL"); exit(1); } }

typedef struct liczba_zespolona
{
	double Rz;
	double Im;
} zesp_t;

zesp_t* lz(double rzeczywista, double urojona)
{
	zesp_t *liczba = (zesp_t*)malloc(sizeof(zesp_t));
	liczba->Rz = rzeczywista;
	liczba->Im = urojona;
	return liczba;
}

double modul(zesp_t*);
double argument(zesp_t*);

void ustaw(zesp_t* liczba, double rzeczywista, double urojona)
{
	ERROR(liczba == NULL);
	liczba->Rz = rzeczywista;
	liczba->Im = urojona;
}

void wyswietl(zesp_t* liczba)
{
	ERROR(liczba == NULL);
	printf("%lf + (%lf*i)\n", liczba->Rz, liczba->Im);
	double arg = argument(liczba)*180/M_PI;
	printf("|%lf| * (cos(%lf) + i*sin(%lf))\n", modul(liczba), arg, arg);
}


void dodaj(zesp_t* a, zesp_t* b, zesp_t* wynik)
{
	ERROR(a == NULL || b == NULL || wynik == NULL);
	wynik->Rz = a->Rz + b->Rz;
	wynik->Im = a->Im + b->Im;
}


void odejmij(zesp_t* a, zesp_t* b, zesp_t* wynik)
{
	ERROR(a == NULL || b == NULL || wynik == NULL);
	wynik->Rz = a->Rz - b->Rz;
	wynik->Im = a->Im - b->Im;
}

void pomnoz(zesp_t* a, zesp_t* b, zesp_t* wynik)
{
	ERROR(a == NULL || b == NULL || wynik == NULL);
	double tmpRz = a->Rz * b->Rz - a->Im * b->Im;
	wynik->Im = (a->Rz * b->Im) + (a->Im * b->Rz);
	wynik->Rz = tmpRz;
}

double modul(zesp_t* liczba)
{
	ERROR(liczba == NULL);
	return sqrt(liczba->Rz*liczba->Rz + liczba->Im*liczba->Im);
}

double argument(zesp_t* liczba)
{
	ERROR(liczba == NULL);
	return atan2(liczba->Im, liczba->Rz);
}

int main(void)
{
	zesp_t *l = lz(14.5, -3.4);

	printf("((%lf + %lf*i) + (11.2 + 5.0*i) - (11.2 + 5.0*i))*(4.3 + -2.3*i) = ", l->Rz, l->Im);
	dodaj(l, lz(11.2, 5.0), l);
	odejmij(l, lz(11.2, 5.0), l);
	pomnoz(l, lz(4.3, -2.3), l);
	wyswietl(l);

	return 0;
}