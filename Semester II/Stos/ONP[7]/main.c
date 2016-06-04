#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum
{
	FALSE,
	TRUE
} bool;

typedef struct stack_t
{
	int size;
	int idx;
	double *tab;

} stack_t;

stack_t* stack_create(int initial_capacity)
{
	stack_t* stos = (stack_t*)malloc(sizeof(stack_t));
	stos->size = initial_capacity;
	stos->idx = 0;
	stos->tab = (double*)malloc(sizeof(double)*initial_capacity);
	return stos;
}

bool stack_free(stack_t* pstack)
{
	if (pstack == NULL) return FALSE;
	free(pstack->tab);
	free(pstack);
	return TRUE;
}

void stack_push(stack_t* pstack, double value)
{
	if (pstack->idx >= pstack->size)
	{
		pstack->tab = realloc(pstack->tab, (pstack->idx + 1) * sizeof(int));
	}
	pstack->tab[pstack->idx] = value;
	pstack->idx++;
}

double stack_pop(stack_t* pstack)
{
	pstack->idx--;
	return pstack->tab[pstack->idx];
}

double stack_try_pop(stack_t* pstack)
{
	if (pstack->idx != 0)
	{
		return stack_pop(pstack);
	}
	printf("Error! Nie mozna zdjac elementu ze stosu!");
	exit(1);
}

void stack_clear(stack_t* pstack)
{
	pstack->idx = 0;
}

int stack_empty(const stack_t* pstack)
{
	return pstack->idx == 0;
}

//---------- ONP ----------
double oblicz_onp(const char onp[])
{
	stack_t *stos = stack_create(10);

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
		else //dodawanie wêz³a do stosu/obliczenie dzia³ania
		{
			double a, b;
			switch (onp[i])
			{
			case ' ':
				if (bufor_idx)
				{
					stack_push(stos, atoi(bufor));
					bufor_idx = 0;
				}
				break;
			case '+':
				b = stack_pop(stos);
				a = stack_pop(stos);
				stack_push(stos, a + b);
				break;
			case '-':
				b = stack_pop(stos);
				a = stack_pop(stos);
				stack_push(stos, a - b);
				break;
			case '*':
				b = stack_pop(stos);
				a = stack_pop(stos);
				stack_push(stos, a * b);
				break;
			case '/':
				b = stack_pop(stos);
				a = stack_pop(stos);
				stack_push(stos, a / b);
				break;
			}
		}
	}
	return stack_pop(stos);
}

int main()
{
	printf("100 + 200 + 300 + 400 = %lf\n", oblicz_onp("100 200 + 300 + 400 + "));
	printf("(25 + 13 / 4) * 2 = %lf\n", oblicz_onp("25 13 4 / + 2 * "));
	printf("-5 * (25 + 13 / 4) * 2 = %lf\n", oblicz_onp("-5 25 13 4 / + * 2 * "));
	printf("0 - (20 + 30 * 40) + (40 - 30 / 20) = %lf\n", oblicz_onp("0 20 30 40 * + - 40 30 20 / - + "));
	printf("-2 * -2 -(-3 - -4) = %lf\n", oblicz_onp("-2 -2 * -3 -4 - - "));
	printf("-1 / -10 - 10 = %lf\n", oblicz_onp("1 -10 / 10 - "));
	return 0;
}