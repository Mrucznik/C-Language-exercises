#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>

//-------------------< API drzew >-------------------
enum TYP { OP, LICZBA };

typedef struct wezel
{
	enum TYP typ;
	union
	{
		double(*operator)(struct wezel*, struct wezel*);
		double wartosc;
	};
	struct wezel* L;
	struct wezel* P;
} wezel;

wezel* wartosc(double w)
{
	wezel* tmp = (wezel*)malloc(sizeof(wezel));
	tmp->typ = LICZBA;
	tmp->wartosc = w;
	tmp->L = NULL;
	tmp->P = NULL;
	return tmp;
}

wezel* op(double(*func)(struct wezel*, struct wezel*), wezel* L, wezel* P)
{
	wezel* tmp = (wezel*)malloc(sizeof(wezel));
	tmp->typ = OP;
	tmp->operator = func;
	tmp->L = L;
	tmp->P = P;
	return tmp;
}

double ewaluacja(wezel* w)
{
	if (w == NULL) { printf("Error ewaluacji - wezel == NULL"); exit(1); }

	if (w->typ == OP)
		return w->operator(w->L, w->P);
	return w->wartosc;
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

//-------------------< API Stosu >-------------------
typedef struct stack
{
	int size;
	wezel** items;
} stack;

void stack_init(stack *s)
{
	s->items = NULL;
	s->size = 0;
}

void stack_free(stack *s)
{
	free(s->items);
}

void stack_push(stack *s, wezel* i)
{
	s->size++;
	s->items = realloc(s->items, sizeof(wezel)*s->size);
	s->items[s->size - 1] = i;
}

wezel* stack_pop(stack *s)
{
	if(s->size == 0)
	{
		printf("Stack empty!");
		exit(1);
	}
	wezel *w = s->items[s->size - 1];
	s->size--;
	s->items = realloc(s->items, sizeof(wezel)*s->size);
	return w;
}

//-------------------< ONP na drzewo >-------------------
wezel* ONPnadrzewo(const char* onp)
{
	int stos_size = 5;
	wezel **stos = (wezel**)malloc(sizeof(wezel) * stos_size);
	int sidx = 0;

	for (int i = 0; onp[i] != '\0'; i++)
	{
		if (isdigit(onp[i]) || onp[i] == '-' && isdigit(onp[i + 1])) //dodawanie wêz³a cyfry do stosu
		{
			int liczba;
			int cyfra = 0;
			char bufor[12];
			for (; isdigit(onp[i]) || onp[i] == '-'; i++)
			{
				bufor[cyfra] = onp[i];
				cyfra++;
			}
			bufor[cyfra] = '\0';
			liczba = atoi(bufor);
			stos[sidx] = wartosc(liczba);
			sidx++;
			if (sidx >= stos_size)
			{
				stos_size++;
				stos = realloc(stos, (stos_size) * sizeof(wezel));
			}
		}
		else //dodawanie wêz³a operatora do stosu
		{
			sidx--;
			switch (onp[i])
			{
			case ' ':
				sidx++;
				break;
			case '+':
				stos[sidx - 1] = op(suma, stos[sidx - 1], stos[sidx]);
				break;
			case '-':
				stos[sidx - 1] = op(roznica, stos[sidx - 1], stos[sidx]);
				break;
			case '*':
				stos[sidx - 1] = op(mnozenie, stos[sidx - 1], stos[sidx]);
				break;
			case '/':
				stos[sidx - 1] = op(dzielenie, stos[sidx - 1], stos[sidx]);
				break;
			}

		}
	}
	return *stos;
}


//-------------------< MAIN >-------------------
int main(void)
{
	//test
	stack s;
	stack_init(&s);
	stack_push(&s, wartosc(10.0));
	stack_push(&s, wartosc(5.0));
	printf("Wartosc: %lf\n", ewaluacja(stack_pop(&s)));
	printf("Wartosc: %lf\n", ewaluacja(stack_pop(&s)));
	stack_free(&s);

	//setlocale(LC_ALL, "");//polskie znaki

	//wezel* drzewo = ONPnadrzewo("100 200 + 300 + 400 +");
	//printf("Wynik 100 200 + 300 + 400 + : %lf\n", ewaluacja(drzewo));
	//zwolnij(drzewo);

	//drzewo = ONPnadrzewo("25 13 4 / + 2 *");
	//printf("Wynik 25 13 4 / + 2 *: %lf\n", ewaluacja(drzewo));
	//zwolnij(drzewo);

	//drzewo = ONPnadrzewo("-5 25 13 4 / + * 2 *");
	//printf("Wynik -5 25 13 4 / + * 2 *: %lf\n", ewaluacja(drzewo));
	//zwolnij(drzewo);

	//drzewo = ONPnadrzewo("-2 -2 * -3 -4 - - ");
	//printf("Wynik -2 -2 * -3 -4 - - : %lf\n", ewaluacja(drzewo));
	//zwolnij(drzewo);

	//drzewo = ONPnadrzewo("1 -10 / 10 - ");
	//printf("Wynik 1 -10 / 10 - : %lf\n", ewaluacja(drzewo));
	//zwolnij(drzewo);
	return 0;
}