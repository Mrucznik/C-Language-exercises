#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	FALSE,
	TRUE
} bool;

typedef struct stack_t
{
	int size;
	int idx;
	int *tab;

} stack_t;

stack_t* stack_create(int size)
{
	stack_t* stos = (stack_t*)malloc(sizeof(stack_t));
	stos->size = size;
	stos->idx = 0;
	stos->tab = (int*)malloc(sizeof(int)*size);
	return stos;
}

bool stack_free(stack_t* pstack)
{
	if (pstack == NULL) return FALSE;
	free(pstack->tab);
	free(pstack);
	return TRUE;
}

void stack_push(stack_t* pstack, int value)
{
	pstack->tab[pstack->idx] = value;
	pstack->idx++;
}

int stack_pop(stack_t* pstack)
{
	pstack->idx--;
	return pstack->tab[pstack->idx];
}

void stack_clear(stack_t* pstack)
{
	pstack->idx = 0;
}

int stack_empty(const stack_t* pstack)
{
	return pstack->idx == 0;
}

void stack_print(const stack_t* pstack)
{
	for (int i = 0; i < pstack->idx; i++)
		printf("Wartosc %d: %d\n", i, pstack->tab[i]);
}

int main()
{
	struct stack_t* stos = stack_create(10);
	stack_push(stos, 10);
	stack_push(stos, 20);
	stack_push(stos, 30);
	stack_print(stos);
	printf("%d\n", stack_pop(stos)); // 30
	stack_print(stos); // 20 10
	stack_free(stos);
	return 0;
}