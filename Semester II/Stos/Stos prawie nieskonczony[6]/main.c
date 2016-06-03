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

stack_t* stack_create(int initial_capacity)
{
	stack_t* stos = (stack_t*)malloc(sizeof(stack_t));
	stos->size = initial_capacity;
	stos->idx = 0;
	stos->tab = (int*)malloc(sizeof(int)*initial_capacity);
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
	if (pstack->idx >= pstack->size)
	{
		pstack->tab = realloc(pstack->tab, (pstack->idx + 1) * sizeof(int));
	}
	pstack->tab[pstack->idx] = value;
	pstack->idx++;
}

int stack_pop(stack_t* pstack)
{
	pstack->idx--;
	return pstack->tab[pstack->idx];
}

int stack_try_pop(stack_t* pstack)
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

void stack_print(const stack_t* pstack)
{
	for (int i = 0; i < pstack->idx; i++)
		printf("Wartosc %d: %d\n", i, pstack->tab[i]);
}

void stack_save(const stack_t* pstack, const char filename[])
{
	FILE* f = fopen(filename, "wb");

	fwrite(&pstack->idx, sizeof(int), 1, f);
	fwrite(&pstack->size, sizeof(int), 1, f);
	fwrite(pstack->tab, sizeof(int)*pstack->size, 1, f);

	fclose(f);
}

void stack_load(stack_t* pstack, const char filename[])
{
	FILE* f = fopen(filename, "rb");

	fread(&pstack->idx, sizeof(int), 1, f);
	fread(&pstack->size, sizeof(int), 1, f);
	fread(pstack->tab, sizeof(int)*pstack->size, 1, f);

	fclose(f);
}

int main()
{
	stack_t* stos = stack_create(32);
	for (int i = 0; i <= 1000; i++)
		stack_push(stos, i);
	for (int i = 0; i <= 1000; i++)
		printf("Wartosc %d: %d\n", i, stack_pop(stos));
	return 0;
}