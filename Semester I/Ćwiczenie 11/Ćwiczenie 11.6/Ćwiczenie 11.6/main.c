//main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_SIZE	101
#define MAX_NAME_LENGTH 32
#define MAX_SURNAME_LENGTH 32

typedef struct Student
{
	char imie[MAX_NAME_LENGTH];
	char nazwisko[MAX_SURNAME_LENGTH];
} Student;

int getIntegerFromRange(const char* statement, int min, int max)
{
	int number;
	do
	{
		printf("%s [od %d do %d]:", statement, min, max);
		scanf("%d", &number);
	}
	while (number < min || number > max);
	return number;
}

void fillStudentsArray(Student students[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Podaj imie studenta nr %d:", i);
		scanf("%s", &students[i].imie);
		printf("Podaj nazwisko studenta nr %d:", i);
		scanf("%s", &students[i].nazwisko);
	}
}

void printStudentsArray(Student students[], int size)
{
	printf("Posortowana lista studentow:\n");
	for (int i = 0; i < size; i++)
		printf("%s %s\n", students[i].imie, students[i].nazwisko);
}

void swap(char* str1, char* str2)
{
	char* temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	free(temp);
}

int maxSurnameStringLength(Student students[], int size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		int tmp = strlen(students[i].nazwisko);
		if (tmp > max)
			max = tmp;
	}
	return max;
}

void bubbleSortStudentsArrayByChar(Student students[], unsigned int char_pos, int size)
{
	int n = size;
	do
	{
		int czyZmieniono = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (char_pos > strlen(students[i].nazwisko) || char_pos > strlen(students[i + 1].nazwisko)) continue;
			if ((int) tolower(students[i].nazwisko[char_pos]) > (int) tolower(students[i + 1].nazwisko[char_pos]))
			{
				swap(students[i].nazwisko, students[i + 1].nazwisko);
				czyZmieniono = 1;
			}
		}

		if (czyZmieniono)
			n--;
		else
			return;
	}
	while (n > 1);
}

void sortStudents(Student students[], int size)
{
	int maxsurnamelength = maxSurnameStringLength(students, size);
	for (int i = maxsurnamelength; i >= 0; i--)
	{
		bubbleSortStudentsArrayByChar(students, i, size);
	}
}

int main(void)
{
	Student students[ARRAY_SIZE];

	int iloscStudentow;
	iloscStudentow = getIntegerFromRange("Podaj ilosc studentow", 1, ARRAY_SIZE - 1);
	fillStudentsArray(students, iloscStudentow);
	sortStudents(students, iloscStudentow);
	printStudentsArray(students, iloscStudentow);

	getchar();
	return 0;
}

