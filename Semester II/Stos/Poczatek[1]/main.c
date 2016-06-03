#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int stos[MAX_SIZE];
int size = 0;

void push(int value)
{
	if (size != MAX_SIZE)
	{
		stos[size] = value;
		size++;
	}
	else
	{
		printf("Error! Nie mozna dodac elementu do stosu!");
		exit(1);
	}
}

int pop()
{
	if (size != 0)
	{
		size--;
		return stos[size];
	}
	printf("Error! Nie mozna zdjac elementu ze stosu!");
	exit(1);
}

void clear()
{
	size = 0;
}

int empty()
{
	return size == 0;
}

void print()
{
	for (int i = 0; i < size; i++)
		printf("Wartosc %d: %d\n", i, stos[i]);
}

int main()
{
	printf("Push 1, 2, 3\n");
	push(1);
	push(2);
	push(3);
	printf("Pop: %d\n", pop());
	printf("Pop: %d\n", pop());
	printf("Pop: %d\n", pop());
	printf("Pusty?: %s\n", empty() ? "Tak" : "Nie");
	return 0;
}