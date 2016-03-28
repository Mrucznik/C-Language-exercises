//main.c

#include <stdlib.h>
#include <stdio.h>

#define MAX_STUDENTS 9

typedef struct Student
{
	char imie[20];
	char nazwisko[20];
	char adres[20];
} Student;

int getIntegerFromRange(const char* statement, int min, int max)
{
	int number;
	do
	{
		printf("%s [od %d do %d]:", statement, min, max);
		scanf("%d", &number);
	} while ( number < min || number > max );
	return number;
}

void loadStudents(Student students[], int ammount)
{
	for (int i = 0; i < ammount; i++)
	{
		printf("Podaj imie %d studenta: ", i + 1);
		scanf("%s", students[i].imie);
		printf("Podaj nazwisko %d studenta: ", i + 1);
		scanf("%s", students[i].nazwisko);
		printf("Podaj adres %d studenta: ", i + 1);
		fflush(stdin);
		getchar(); //fflsuh nie czyœci wszystkiego, zostaje enter
		gets_s(students[i].adres, sizeof(students[i].adres));
	}
}

void writeStudents(Student students[], int ammount)
{
	printf("\n|----------------------------[ Studenci ]----------------------------|\n");
	printf("|         Imie         |       Nazwisko       |         Adres        |\n");
	printf("|----------------------|----------------------|----------------------|\n");
	for (int i = 0; i < ammount; i++)
	{
		printf("| ");

		// imie
		printf("%-s", students[i].imie);

		printf(" | ");

		// nazwisko
		printf("%-20s", students[i].nazwisko);

		printf(" | ");

		// adres
		printf("%-20s", students[i].adres);

		printf(" |\n");
	}
	printf("|----------------------|----------------------|----------------------|\n\n");
}

int main(void)
{
	int ammount;
	Student studenci[MAX_STUDENTS];

	ammount = getIntegerFromRange("Podaj ilosc studnetow", 1, MAX_STUDENTS);
	loadStudents(studenci, ammount);
	writeStudents(studenci, ammount);
	return 0;
}