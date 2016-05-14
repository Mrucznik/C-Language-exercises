#include <stdio.h>

struct Student
{
	char imie[32];
	char nazwisko[32];
	int index;
};
typedef struct Student student_t;

void wpisz_dane(student_t *rekord)
{
	printf("Podaj imie studenta: ");
	scanf("%s[32]", rekord->imie);
	printf("Podaj nazwisko studenta: ");
	scanf("%s[32]", rekord->nazwisko);
	printf("Podaj nr indexu studenta: ");
	scanf("%d", &rekord->index);
}

void wyswietl_dane(const student_t *rekord)
{
	printf("%s\n%s\n%d\n", rekord->imie, rekord->nazwisko, rekord->index);
}

void zapisz_dane_t(const char* plik, const student_t* rekord)
{
	FILE *f = fopen(plik, "w");
	
	if(f == NULL)
	{
		printf("Error! Nie udalo sie wczytac pliku.");
		return;
	}

	fprintf(f, "%s %s %d", rekord->imie, rekord->nazwisko, rekord->index);

	fclose(f);
}

void wczytaj_dane_t(const char* plik, student_t* rekord)
{
	FILE *f = fopen(plik, "r");

	if (f == NULL)
	{
		printf("Error! Nie udalo sie wczytac pliku.");
		return;
	}

	fscanf(f, "%s[32]", rekord->imie);
	fscanf(f, "%s[32]", rekord->nazwisko);
	fscanf(f, "%d", &rekord->index);

	fclose(f);
}

void zapisz_dane_b(const char* plik, const student_t* rekord)
{
	FILE *f = fopen(plik, "wb");

	if (f == NULL)
	{
		printf("Error! Nie udalo sie wczytac pliku.");
		return;
	}

	fwrite(rekord, sizeof(student_t), 1, f);

	fclose(f);
}

void wczytaj_dane_b(const char* plik, student_t* rekord)
{
	FILE *f = fopen(plik, "rb");

	if (f == NULL)
	{
		printf("Error! Nie udalo sie wczytac pliku.");
		return;
	}

	fread(rekord, sizeof(student_t), 1, f);

	fclose(f);
}


int main()
{
	student_t student;
	student_t student1;
	student_t student2;
	wpisz_dane(&student);
	zapisz_dane_t("plik.txt", &student);
	zapisz_dane_b("plik", &student);
	wczytaj_dane_t("plik.txt", &student1);
	wyswietl_dane(&student1);
	wczytaj_dane_b("plik", &student2);
	wyswietl_dane(&student2);
	return 0;
}