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
	wezel* drzewo = op(SUMA, wartosc(100),
		op(SUMA, wartosc(200),
			op(SUMA, wartosc(300),
				wartosc(400))));
	printf("100 + 200 + 300 + 400 = %lf\n", ewaluacja(drzewo));
	zwolnij(drzewo);

	drzewo =
		op(MNOZENIE,
			op(SUMA, wartosc(25),
				op(DZIELENIE, wartosc(13), wartosc(4))
			),
			wartosc(2));
	printf("(25 + 13 / 4) * 2 = %lf\n", ewaluacja(drzewo));

	drzewo = op(MNOZENIE, wartosc(-5), drzewo);
	printf("-5 * (25 + 13 / 4) * 2 = %lf\n", ewaluacja(drzewo));
	zwolnij(drzewo);

	drzewo = op(SUMA,
		op(NEGACJA,
			op(SUMA,
				wartosc(20),
				op(MNOZENIE, wartosc(30), wartosc(40))
			), NULL
		),
		op(ROZNICA,
			wartosc(40),
			op(DZIELENIE, wartosc(30), wartosc(20))
		)
	);
	printf("-(20 + 30 * 40) + (40 - 30 / 20) = %lf\n", ewaluacja(drzewo));
	zwolnij(drzewo);

	drzewo = op(ROZNICA,
		op(MNOZENIE, wartosc(-2), wartosc(-2)),
		op(ROZNICA, wartosc(-3), wartosc(-4))
	);
	printf("-2 * -2 -(-3 - -4) = %lf\n", ewaluacja(drzewo));
	zwolnij(drzewo);

	drzewo = op(ROZNICA,
		op(DZIELENIE, wartosc(-1), wartosc(-10)),
		wartosc(10)
	);
	printf("-1 / -10 - 10 = %lf\n", ewaluacja(drzewo));
	zwolnij(drzewo);
	return 0;
}