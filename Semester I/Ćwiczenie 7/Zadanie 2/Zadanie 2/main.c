//main.c

#include <stdio.h>

#define MAX_WYMIAR 20

int getIntegerFromRange(const char* statement, int min, int max)
{
	int x;
	do
	{
		printf("%s [od %d do %d]:", statement, min, max);
		scanf("%d", &x);
	} while (x < min || x > max);
	return x;
}

void printArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Index %d: %d\n", i + 1, array[i]);
	}
}

void loadMatrixData(int matrix[MAX_WYMIAR][MAX_WYMIAR], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("Podaj wartosc w %d wierszu i %d kolumnie: ", i + 1, j + 1);
			scanf("%d", &matrix[i][j]);
		}
	}
}

int main(void)
{
	int matrix[MAX_WYMIAR][MAX_WYMIAR], rows, columns;
	int sumy_wierszy[MAX_WYMIAR];
	int sumy_kolumn[MAX_WYMIAR];

	rows = getIntegerFromRange("Podaj ilosc wierszy macierzy", 1, MAX_WYMIAR);
	columns = getIntegerFromRange("Podaj ilosc kolumn macierzy", 1, MAX_WYMIAR);

	loadMatrixData(matrix, rows, columns);
	
	//Podpunkt a. (sumowanie wierszy)
	for (int i = 0; i < rows; i++)
	{
		sumy_wierszy[i] = 0;
		for (int j = 0; j < columns; j++)
		{
			sumy_wierszy[i] += matrix[i][j];
		}
	}

	//Podpunkt b. (sumowanie kolumn)
	for (int i = 0; i < columns; i++)
	{
		sumy_kolumn[i] = 0;
		for (int j = 0; j < rows; j++)
		{
			sumy_kolumn[i] += matrix[j][i];
		}
	}

	//Wyœwietlanie danych:
	printf("Sumy wierszy macierzy:\n");
	printArray(sumy_wierszy, rows);

	printf("Sumy kolumn macierzy:\n");
	printArray(sumy_kolumn, columns);

	return 0;
}