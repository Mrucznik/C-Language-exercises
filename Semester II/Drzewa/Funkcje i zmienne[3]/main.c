#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

//-------------------< API >-------------------
enum TYP { OP, LICZBA };

typedef struct wezel
{
	enum TYP typ;
	union cecha
	{
		double(*operator)(struct wezel*, struct wezel*);
		double wartosc;
	} cecha;
	struct wezel* L;
	struct wezel* P;
} wezel;

wezel* wartosc(double w)
{
	wezel* tmp = (wezel*)malloc(sizeof(wezel));
	tmp->typ = LICZBA;
	tmp->cecha.wartosc = w;
	tmp->L = NULL;
	tmp->P = NULL;
	return tmp;
}

wezel* op(double(*func)(struct wezel*, struct wezel*), wezel* L, wezel* P)
{
	wezel* tmp = (wezel*)malloc(sizeof(wezel));
	tmp->typ = OP;
	tmp->cecha.operator = func;
	tmp->L = L;
	tmp->P = P;
	return tmp;
}

double ewaluacja(wezel* w)
{
	if (w == NULL) { printf("Error ewaluacji - wezel == NULL"); exit(1); }

	if (w->typ == OP)
		return w->cecha.operator(w->L, w->P);
	return w->cecha.wartosc;
}

void zwolnij(wezel* w)
{
	if (w->L != NULL)
		zwolnij(w->L);
	if (w->P != NULL)
		zwolnij(w->P);

	free(w);
	w = NULL;
}

//-------------------< OPERATORY >-------------------
double suma(wezel* a, wezel* b)
{
	return ewaluacja(a) + ewaluacja(b);
}
double roznica(wezel* a, wezel* b)
{
	return ewaluacja(a) - ewaluacja(b);
}
double mnozenie(wezel* a, wezel* b)
{
	return ewaluacja(a) * ewaluacja(b);
}
double dzielenie(wezel* a, wezel* b)
{
	return ewaluacja(a) / ewaluacja(b);
}
double negacja(wezel* a, wezel* b)
{
	return a == NULL ? -ewaluacja(b) : -ewaluacja(a);
}
double pierwiastek(wezel* a, wezel* b)
{
	return a == NULL ? sqrt(ewaluacja(b)) : sqrt(ewaluacja(a));
}
double sinus(wezel* a, wezel* b)
{
	return a == NULL ? sin(ewaluacja(b)) : sin(ewaluacja(a));
}
double cosinus(wezel* a, wezel* b)
{
	return a == NULL ? cos(ewaluacja(b)) : cos(ewaluacja(a));
}

//-------------------< MAIN >-------------------
int main(void)
{
	int wyrazenie;
	double x, y, z;
	wezel *drzewo = NULL;
	setlocale(LC_ALL, "");//polskie znaki

	printf("\
1. x + 10\n\
2. x * (y - 20)\n\
3. 3 * 2 + 10\n\
4. - x + -y\n\
5. - x - -y - -z\n\
6. 2 * sin(x) * sin(y)\n\
7. 5 * a * a - 5 * b - c\n\
8. sqrt(zmA * zmA - 4 * zmA * zmB)\n\
9. cos(A) + sin(B) - sqrt(C)\n\n\
Wybierz wyra¿enie: ");
	scanf("%d", &wyrazenie);

	switch(wyrazenie)
	{
	case 1:
		printf("Podaj wartosc zmiennej x: ");
		scanf("%lf", &x);
		drzewo = op(suma, wartosc(x), wartosc(10));
		break;

	case 2:
		printf("Podaj wartosc zmiennej x: ");
		scanf("%lf", &x);
		printf("Podaj wartosc zmiennej y: ");
		scanf("%lf", &y);
		drzewo = op(mnozenie, wartosc(x),
			op(roznica, wartosc(y), wartosc(20))
		);
		break;

	case 3:
		drzewo = op(suma, op(mnozenie, wartosc(3), wartosc(2)), wartosc(10));
		break;

	case 4:
		printf("Podaj wartosc zmiennej x: ");
		scanf("%lf", &x);
		printf("Podaj wartosc zmiennej y: ");
		scanf("%lf", &y);
		drzewo = op(suma, op(negacja, wartosc(x), NULL), op(negacja, wartosc(y), NULL));
		break;

	case 5:
		printf("Podaj wartosc zmiennej x: ");
		scanf("%lf", &x);
		printf("Podaj wartosc zmiennej y: ");
		scanf("%lf", &y);
		printf("Podaj wartosc zmiennej z: ");
		scanf("%lf", &z);
		drzewo = op(roznica, 
			op(roznica, 
				op(negacja, wartosc(x), NULL), 
				op(negacja, wartosc(y), NULL)
			), 
			op(negacja, wartosc(z), NULL)
		);
		break;

	case 6:
		printf("Podaj wartosc zmiennej x: ");
		scanf("%lf", &x);
		printf("Podaj wartosc zmiennej y: ");
		scanf("%lf", &y);
		drzewo = op(mnozenie, wartosc(2),
			op(mnozenie, op(sinus, wartosc(x), NULL), op(sinus, wartosc(y), NULL))
		);
		break;

	case 7:
		printf("Podaj wartosc zmiennej a: ");
		scanf("%lf", &x);
		printf("Podaj wartosc zmiennej b: ");
		scanf("%lf", &y);
		printf("Podaj wartosc zmiennej c: ");
		scanf("%lf", &z);
		drzewo = op(roznica,
			op(roznica, 
				op(mnozenie, 
					wartosc(5), 
					op(mnozenie, wartosc(x), wartosc(x))
				), 
				op(mnozenie, 
					wartosc(5), 
					wartosc(y)
				)
			),
			wartosc(z)
		);
		break;

	case 8:
		printf("Podaj wartosc zmiennej zmA: ");
		scanf("%lf", &x);
		printf("Podaj wartosc zmiennej zmB: ");
		scanf("%lf", &y);
		drzewo = op(pierwiastek,
			op(roznica,
				op(mnozenie, wartosc(x), wartosc(x)),
				op(mnozenie, 
					wartosc(4), 
					op(mnozenie, wartosc(x), wartosc(y))
				)
			), 
			NULL
		);
		break;

	case 9:
		printf("Podaj wartosc zmiennej A: ");
		scanf("%lf", &x);
		printf("Podaj wartosc zmiennej B: ");
		scanf("%lf", &y);
		printf("Podaj wartosc zmiennej C: ");
		scanf("%lf", &z);
		drzewo = op(roznica, 
			op(suma, 
				op(cosinus, wartosc(x), NULL), 
				op(sinus, wartosc(y), NULL)
			), 
			op(pierwiastek, wartosc(z), NULL)
		);
		break;
	}

	printf("Wynik operacji: %lf\n", ewaluacja(drzewo));

	return 0;
}