#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node_t
{
	int value;
	struct node_t* next;
} node_t;  

void dodaj(node_t *root, int n, node_t *item)
{
	for (int i = 0; root->next != NULL && i<n; root = root->next, i++)
		;
	item->next = root->next;
	root->next = item;
}

void print(const node_t *root)
{
	for (int i = 1; root != NULL; root = root->next, i++)
		printf("Element[%d]: %d\n", i, root->value);
}

int main(void)
{
	srand(time(NULL));
	node_t *rootA = NULL, *rootB = NULL, *rootC = NULL, *rootD = NULL;

	//Lista rootA:
	rootA = (node_t*)malloc(sizeof(node_t));//1
	rootA->value = rand()%11;
	rootA->next = (node_t*)malloc(sizeof(node_t));//2
	rootA->next->value = rand() % 11;
	rootA->next->next = (node_t*)malloc(sizeof(node_t));//3
	rootA->next->next->value = rand() % 11;
	rootA->next->next->next = (node_t*)malloc(sizeof(node_t));//4
	rootA->next->next->next->value = rand() % 11;
	rootA->next->next->next->next = (node_t*)malloc(sizeof(node_t));//5
	rootA->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//6
	rootA->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//7
	rootA->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//8
	rootA->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//9
	rootA->next->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//10
	rootA->next->next->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//11
	rootA->next->next->next->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//12
	rootA->next->next->next->next->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//13
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//14
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//15
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//16
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//17
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//18
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//19
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = (node_t*)malloc(sizeof(node_t));//20
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->value = rand() % 11;
	rootA->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = NULL;
	puts("Lista rootA:");
	print(rootA);

	//Lista rootB:
	rootB = (node_t*)malloc(sizeof(node_t));
	rootB->value = rand() % 11 + 10;
	node_t* last = rootB;
	for(int i=0; i<19; i++)
	{
		last->next = (node_t*)malloc(sizeof(node_t));
		last = last->next;
		last->value = rand()%11+20;
		last->next = NULL;
	}
	puts("Lista rootB:");
	print(rootB);

	//Lista rootC:
	node_t* first = rootC;
	for (int i = 0; i<20; i++)
	{
		node_t* next = rootC;
		rootC = (node_t*)malloc(sizeof(node_t));
		rootC->value = rand() % 11 + 40;
		rootC->next = next;
	}
	puts("Lista rootC:");
	print(rootC);

	//Lista rootD:
	rootD = (node_t*)malloc(sizeof(node_t));
	rootD->value = rand() % 11 + 60;
	rootD->next = NULL;
	for (int i = 0; i<19; i++)
	{
		node_t *item = (node_t*)malloc(sizeof(node_t));
		item->value = rand() % 11 + 60;
		dodaj(rootD, rand() % 21, item);
	}
	puts("Lista rootD:");
	print(rootD);
	return 0;
}