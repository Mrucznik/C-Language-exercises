#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	FALSE,
	TRUE
} bool;

#define STACK_API(__printformat, __t1, __t2, __t3 , __t4) \
typedef struct stack_##__t1##__t2##__t3##__t4##_t \
{ \
	int size; \
	int idx;  \
	__t1 __t2 __t3 __t4 *tab; \
} stack_##__t1##__t2##__t3##__t4##_t; \
\
stack_##__t1##__t2##__t3##__t4##_t* stack_##__t1##__t2##__t3##__t4##_create(int size) \
{ \
	stack_##__t1##__t2##__t3##__t4##_t* stos = (stack_##__t1##__t2##__t3##__t4##_t*)malloc(sizeof(stack_##__t1##__t2##__t3##__t4##_t));\
	stos->size = size;\
	stos->idx = 0;\
	stos->tab = (__t1 __t2 __t3 __t4*)malloc(sizeof(int)*size);\
	return stos;\
}\
\
bool stack_##__t1##__t2##__t3##__t4##_free(stack_##__t1##__t2##__t3##__t4##_t* pstack)\
{\
	if (pstack == NULL) return FALSE;\
	free(pstack->tab);\
	free(pstack);\
	return TRUE;\
}\
\
void stack_##__t1##__t2##__t3##__t4##_push(stack_##__t1##__t2##__t3##__t4##_t* pstack, __t1 __t2 __t3 __t4 value)\
{\
	pstack->tab[pstack->idx] = value;\
	pstack->idx++;\
}\
\
bool stack_##__t1##__t2##__t3##__t4##_try_pusch(stack_##__t1##__t2##__t3##__t4##_t* pstack, __t1 __t2 __t3 __t4 value)\
{\
	if (pstack->idx != pstack->size) \
	{\
		stack_##__t1##__t2##__t3##__t4##_push(pstack, value);\
		return TRUE; \
	}\
	return FALSE;\
}\
\
__t1 __t2 __t3 __t4 stack_##__t1##__t2##__t3##__t4##_pop(stack_##__t1##__t2##__t3##__t4##_t* pstack)\
{\
	pstack->idx--;\
	return pstack->tab[pstack->idx];\
}\
\
__t1 __t2 __t3 __t4 stack_##__t1##__t2##__t3##__t4##_try_pop(stack_##__t1##__t2##__t3##__t4##_t* pstack)\
{\
	if (pstack->idx != 0)\
	{\
		return stack_##__t1##__t2##__t3##__t4##_pop(pstack);\
	}\
	printf("Error! Nie mozna zdjac elementu ze stosu!");\
	exit(1);\
}\
\
void stack_##__t1##__t2##__t3##__t4##_clear(stack_##__t1##__t2##__t3##__t4##_t* pstack)\
{\
	pstack->idx = 0;\
}\
\
int stack_##__t1##__t2##__t3##__t4##_empty(const stack_##__t1##__t2##__t3##__t4##_t* pstack)\
{\
	return pstack->idx == 0;\
}\
\
void stack_##__t1##__t2##__t3##__t4##_save(const stack_##__t1##__t2##__t3##__t4##_t* pstack, const char filename[])\
{\
	FILE* f = fopen(filename, "wb");\
\
	fwrite(&pstack->idx, sizeof(int), 1, f);\
	fwrite(&pstack->size, sizeof(int), 1, f);\
	fwrite(pstack->tab, sizeof(int)*pstack->size, 1, f);\
\
	fclose(f);\
}\
\
void stack_##__t1##__t2##__t3##__t4##_load(stack_##__t1##__t2##__t3##__t4##_t* pstack, const char filename[])\
{\
	FILE* f = fopen(filename, "rb");\
\
	fread(&pstack->idx, sizeof(int), 1, f);\
	fread(&pstack->size, sizeof(int), 1, f);\
	fread(pstack->tab, sizeof(int)*pstack->size, 1, f);\
\
	fclose(f);\
}\
void stack_##__t1##__t2##__t3##__t4##_print(const stack_##__t1##__t2##__t3##__t4##_t* pstack)\
{\
	for (int i = 0; i < pstack->idx; i++)\
		printf("Wartosc %d: "##__printformat##"\n", i, pstack->tab[i]);\
}\

STACK_API("%d", char)
STACK_API("%u", unsigned, char)
STACK_API("%d", short)
STACK_API("%u", unsigned, short)
STACK_API("%d", int)
STACK_API("%u", unsigned, int)
STACK_API("%d", long, int)
STACK_API("%d", unsigned, long, int)
STACK_API("%lld", long, long, int)
STACK_API("%llu", unsigned, long, long, int)
STACK_API("%f", float)
STACK_API("%lf", double)


int main()
{
	stack_int_t* stos = stack_int_create(10);
	stack_float_t* stos3 = stack_float_create(123);
	stack_int_push(stos, 10);
	stack_int_push(stos, 20);
	stack_int_push(stos, 30);
	stack_int_print(stos);
	printf("%d\n", stack_int_pop(stos)); // 30
	stack_int_print(stos); // 20 10
	stack_int_save(stos, "stos.bin");
	stack_int_clear(stos);
	stack_int_load(stos, "stos.bin");
	stack_int_push(stos, 25);
	stack_int_print(stos);
	stack_int_free(stos);

	printf("\nStos float:\n");
	stack_float_push(stos3, 15.3);
	printf("%f\n", stack_float_pop(stos3));
	return 0;
}