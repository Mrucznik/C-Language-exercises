#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

static char nazwy_miesiecy[12][13] = {
	"styczeñ",
	"luty",
	"marzec",
	"kwiecieñ",
	"maj",
	"czerwiec",
	"lipiec",
	"sierpieñ",
	"wrzesieñ",
	"paŸdziernik",
	"listopad",
	"grudzieñ"
};

struct data_t
{
	int dzien;
	int miesiac;
	int rok;
};

struct kontakt_t
{
	char imie[32];
	char nazwisko[32];
	int numer_tel;
	struct data_t data_urodzenia;
	enum plec_t
	{
		MEZCZYZNA,
		KOBIETA
	} plec;
};

void otworzPlik(FILE** file, const char* filename, const char* mode)
{
	if (file == NULL)
	{
		printf("Przekazano wskaznik NULL przy otwieraniu pliku %s w trybie %s\n", filename, mode);
		exit(1);
	}

	*file = fopen(filename, mode);
	if (*file == NULL)
	{
		printf("Nie udalo sie otworzyc pliku %s w trybie %s\n", filename, mode);
		exit(1);
	}
}

void wyswietlKontakt(struct kontakt_t k)
{
	printf("Imie: %s\nNazwisko: %s\nData urodzenia: %d %s %d\nP³eæ: %s\n",
		k.imie, k.nazwisko,
		k.data_urodzenia.dzien, nazwy_miesiecy[k.data_urodzenia.miesiac], k.data_urodzenia.rok,
		k.plec == MEZCZYZNA ? "Mê¿czyzna" : "Kobieta");
}

void zapiszKontaktTekstowo(struct kontakt_t k)
{
	FILE *f;
	otworzPlik(&f, "plik12.txt", "wt");

	fprintf(f, "Imie: %s\nNazwisko: %s\nData urodzenia: %d %s %d\nP³eæ: %s\n",
		k.imie, k.nazwisko,
		k.data_urodzenia.dzien, nazwy_miesiecy[k.data_urodzenia.miesiac], k.data_urodzenia.rok,
		k.plec == MEZCZYZNA ? "Mê¿czyzna" : "Kobieta");

	fclose(f);
}

void zapiszKontaktBinarnie(struct kontakt_t k)
{
	FILE *f;
	otworzPlik(&f, "plik12.bin", "wb");

	fwrite(&k, sizeof(k), 1, f);

	fclose(f);
}

int main(void)
{
	setlocale(LC_ALL, "");//polskie znaki

	struct kontakt_t kontakt;
	strcpy(kontakt.imie, "Jan");
	strcpy(kontakt.nazwisko, "Kowalski");
	kontakt.numer_tel = 667251848;
	kontakt.data_urodzenia.dzien = 26;
	kontakt.data_urodzenia.miesiac = 8;
	kontakt.data_urodzenia.rok = 1980;
	kontakt.plec = MEZCZYZNA;
	wyswietlKontakt(kontakt);
	zapiszKontaktTekstowo(kontakt);
	zapiszKontaktBinarnie(kontakt);
	return 0;
}