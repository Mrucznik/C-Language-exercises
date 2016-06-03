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

bool stack_try_pusch(stack_t* pstack, int value)
{
	if (pstack->idx != pstack->size) //program sprawdza, czy ilosc elementow na stosie nie jest rowna maksymalnej ilosci elementow na stosie
	{//jezeli prawda, dodaje element do stosu
		stack_push(pstack, value);
		return TRUE; //i zwraca true
	}//w przeciwnym razie zwraca false
	return FALSE;
}

int stack_pop(stack_t* pstack)
{
	pstack->idx--;
	return pstack->tab[pstack->idx];
}

int stack_try_pop(stack_t* pstack)
{
	if (pstack->idx != 0)//program sprawdza, czy ilosc elementow stosu nie jest rowna 0
	{//jezeli prawda - zdejmuje element ze stosu
		return stack_pop(pstack);
	}//w przeciwnym wpypadku wyswietla wiadomosc i konczy program
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
	struct stack_t* stos = stack_create(10);
	stack_push(stos, 10);
	stack_push(stos, 20);
	stack_push(stos, 30);
	stack_print(stos);
	printf("%d\n", stack_pop(stos)); // 30
	stack_print(stos); // 20 10
	stack_save(stos, "stos.bin");
	stack_clear(stos);
	stack_load(stos, "stos.bin");
	stack_push(stos, 25);
	stack_print(stos);
	stack_free(stos);
	return 0;
}