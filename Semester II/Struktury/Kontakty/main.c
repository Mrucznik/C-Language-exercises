#include <stdio.h>

typedef struct kontakt_t
{
	char imie[32];
	char nazwisko[32];
	char adres[64];
	int telefon;
	struct Data
	{
		unsigned char day;
		unsigned char month;
		short year;
	} data_urodzin;
	char email[64];
} kontakt;

int main()
{

	return 0;
}