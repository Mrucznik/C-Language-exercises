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
	stack stos;
	stack_init(&stos);

	char bufor[12];
	int bufor_idx = 0;
	for (int i = 0; onp[i] != '\0'; i++)
	{
		if (isdigit(onp[i]) || onp[i] == '-' && isdigit(onp[i + 1])) //dodawanie cyfr do bufora
		{
			bufor[bufor_idx] = onp[i];
			bufor_idx++;
			bufor[bufor_idx] = '\0';
		}
		else //dodawanie wêz³a do stosu
		{
			wezel *tmp;
			switch (onp[i])
			{
			case ' ':
				if(bufor_idx)
				{
					stack_push(&stos, wartosc(atoi(bufor)));
					bufor_idx = 0;
				}
				break;
			case '+':
				tmp = stack_pop(&stos);
				stack_push(&stos, op(suma, stack_pop(&stos), tmp));
				break;
			case '-':
				tmp = stack_pop(&stos);
				stack_push(&stos, op(roznica, stack_pop(&stos), tmp));
				break;
			case '*':
				tmp = stack_pop(&stos);
				stack_push(&stos, op(mnozenie, stack_pop(&stos), tmp));
				break;
			case '/':
				tmp = stack_pop(&stos);
				stack_push(&stos, op(dzielenie, stack_pop(&stos), tmp));
				break;
			}
		}
	}
	wezel *tmp = stack_pop(&stos);
	stack_free(&stos);
	return tmp;
}

//-------------------< Drzewo do tekstu >-------------------
void DrzewoNaTekst(wezel* drzewo)
{
	if (drzewo == NULL) return;
	if (drzewo->typ == OP)
	{
		putchar('(');
		DrzewoNaTekst(drzewo->L);
		if(drzewo->operator == suma)
			printf(" + ");
		else if (drzewo->operator == roznica)
			printf(" - ");
		else if (drzewo->operator == mnozenie)
			printf(" * ");
		else if (drzewo->operator == dzielenie)
			printf(" / ");
		DrzewoNaTekst(drzewo->P);
		putchar(')');
	}
	else
		printf("%lf", drzewo->wartosc);
}

//-------------------< MAIN >-------------------
int main(void)
{
	setlocale(LC_ALL, "");//polskie znaki
	wezel* drzewo = ONPnadrzewo("100 200 + 300 + 400 +");
	printf("Wynik 100 200 + 300 + 400 + : %lf\nWersja tekstowa: ", ewaluacja(drzewo));
	DrzewoNaTekst(drzewo); puts("\n");
	zwolnij(drzewo);

	drzewo = ONPnadrzewo("25 13 4 / + 2 *");
	printf("Wynik 25 13 4 / + 2 *: %lf\nWersja tekstowa: ", ewaluacja(drzewo));
	DrzewoNaTekst(drzewo); puts("\n");
	zwolnij(drzewo);

	drzewo = ONPnadrzewo("-5 25 13 4 / + * 2 *");
	printf("Wynik -5 25 13 4 / + * 2 *: %lf\nWersja tekstowa: ", ewaluacja(drzewo));
	DrzewoNaTekst(drzewo); puts("\n");
	zwolnij(drzewo);

	drzewo = ONPnadrzewo("-2 -2 * -3 -4 - - ");
	printf("Wynik -2 -2 * -3 -4 - - : %lf\nWersja tekstowa: ", ewaluacja(drzewo));
	DrzewoNaTekst(drzewo); puts("\n");
	zwolnij(drzewo);

	drzewo = ONPnadrzewo("1 -10 / 10 - ");
	printf("Wynik 1 -10 / 10 - : %lf\nWersja tekstowa: ", ewaluacja(drzewo));
	DrzewoNaTekst(drzewo); puts("\n");
	zwolnij(drzewo);
	return 0;
}