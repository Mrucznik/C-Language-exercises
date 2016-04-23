#include <stdlib.h>
#include <stdio.h>

typedef struct student_t
{
	char* imie;
	char* nazwisko;
	char* album;
} student_t;

student_t* wypelnij(void)
{
	student_t* student = (student_t*)malloc(sizeof(student_t));

	student->imie = (char*)malloc(sizeof(char) * 100);
	student->nazwisko = (char*)malloc(sizeof(char) * 100);
	student->album = (char*)malloc(sizeof(char) * 10);

	printf("Podaj imie: ");
	scanf("%s", student->imie);
	printf("Podaj nazwisko: ");
	scanf("%s", student->nazwisko);
	printf("Podaj album: ");
	scanf("%s", student->album);

	return student;
}

void wyswietl(student_t* student)
{
	printf("Imie: %s\nNazwisko: %s\nAlbum: %s\n", student->imie, student->nazwisko, student->album);
}

void zwolnij(student_t* student)
{
	free(student->imie);
	free(student->nazwisko);
	free(student->album);
	free(student);
}

int main(void)
{
	student_t* student;
	student = wypelnij();
	wyswietl(student);
	zwolnij(student);
	return 0;
}

