#include <stdio.h>
#include <stdlib.h>

enum TYP { OP, LICZBA };
enum TYP_OP { SUMA, ROZNICA, MNOZENIE, DZIELENIE, NEGACJA };

typedef struct wezel
{
	enum TYP typ;
	enum TYP_OP typ_op;
	double wartosc;
	struct wezel* L;
	struct wezel* P;
} wezel;

wezel* wartosc(double w)
{
	wezel* tmp = (wezel*)malloc(sizeof(wezel));
	tmp->typ = LICZBA;
	tmp->wartosc = w;
	return tmp;
}

wezel* op(enum TYP_OP op, wezel* L, wezel* P)
{
	wezel* tmp = (wezel*)malloc(sizeof(wezel));
	tmp->typ = OP;
	tmp->typ_op = op;
	tmp->L = L;
	tmp->P = P;
	return tmp;
}

double ewaluacja(wezel* w)
{
	if (w->typ == OP)
	{
		switch (w->typ_op)
		{
		case SUMA:
			return ewaluacja(w->L) + ewaluacja(w->P);
		case ROZNICA:
			return ewaluacja(w->L) - ewaluacja(w->P);
		case MNOZENIE:
			return ewaluacja(w->L) * ewaluacja(w->P);
		case DZIELENIE:
			return ewaluacja(w->L) / ewaluacja(w->P);
		case NEGACJA:
			return -ewaluacja(w->L);
		default:
			printf("ERROR - brak typu operatora");
			exit(1);
		}
	}
	else
	{
		return w->wartosc;
	}
}

void zwolnij(wezel* w)
{
	if (w->typ == OP)
	{
		zwolnij(w->L);
		if (w->typ_op != NEGACJA)
		{
			zwolnij(w->P);
		}
	}

	free(w);
	w = NULL;
}

int main(void)
{
	wezel* drzewo = op(MNOZENIE, wartosc(2), op(SUMA, wartosc(3), wartosc(4)));
	printf("2*(3+4)  = %lf\n", ewaluacja(drzewo));
	zwolnij(drzewo);
	return 0;
}