#include <stdlib.h>
#include <stdio.h>

typedef struct student_t
{
	char imie[100];
	char nazwisko[100];
	char album[10];
} student_t;

student_t* wypelnij(void)
{
	student_t *student = (student_t*)malloc(sizeof(student_t));
	printf("Podaj imie: ");
	scanf("%s[100]", student->imie);
	printf("Podaj nazwisko: ");
	scanf("%s[100]", student->nazwisko);
	printf("Podaj album: ");
	scanf("%s[10]", student->album);
	return student;
}

void wyswietl(student_t *student)
{
	printf("Imie: %s\nNazwisko: %s\nAlbum: %s\n", student->imie, student->nazwisko, student->album);
}

void zwolnij(student_t *student)
{
	free(student);
}

int main(void)
{
	student_t *student;
	student = wypelnij();
	printstudent(student);
	freestudent(student);
	return 0;
}
