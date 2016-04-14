#include "contact.h"
#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

#define FILENAME "kontakty.db"

void LoadContacts(Contact c[], int ile)
{
	FILE *f = fopen(FILENAME, "rb");

	if (f == NULL)
	{
		SaveContacts(c, ile);
		f = fopen(FILENAME, "rb");
	}

	if (f == NULL)
	{
		printf("ERROR! Nie udalo sie wczytac pliku.\n");
		exit(1);
	}

	fread(c, sizeof(Contact), ile, f);

	fclose(f);
}

void SaveContacts(Contact c[], int ile)
{
	FILE *f = fopen(FILENAME, "wb");

	if (f == NULL)
	{
		printf("ERROR! Nie udalo sie wczytac pliku.\n");
		exit(1);
	}

	fwrite(c, sizeof(Contact), ile, f);

	fclose(f);
}

void CreateContact(Contact* c)
{
	c->filled = 1;
	getVariableFromConsole("Podaj imie: ", "%s[32]", c->imie);
	getVariableFromConsole("Podaj nazwisko: ", "%s[32]", c->nazwisko);
	getVariableFromConsole("Podaj adres: ", "%s[64]", c->adres);
	getVariableFromConsole("Podaj telefon: ", "%d", &c->telefon);
	getVariableFromConsole("Podaj date urodzin (format: dzien/miesiac/rok): ", "%d/%d/%d", &c->data_urodzin.day, &c->data_urodzin.month, &c->data_urodzin.year);
	getVariableFromConsole("Podaj e-mail: ", "%s[64]", c->email);
}

void DeleteContact(Contact* c)
{
	c->filled = 0;
	printf("Rekord zostal pomyslnie usuniety!");
}

void PrintContact(Contact c)
{
	if(c.filled)
	{
		printf("Imie: %s\nNazwisko: %s\nAdres:%s\nTelefon: %d\nData urodzin: %d/%d/%d\nE-mail: %s\n",
			c.imie, c.nazwisko, c.adres, c.telefon, c.data_urodzin.day, c.data_urodzin.month, c.data_urodzin.year, c.email);
	}
	else
	{
		printf("Ten rekord jest pusty!");
	}
}

int GetNextContactIndex(Contact c[], int index, int zilu)
{
	int i = index+1;
	while (i < zilu)
	{
		if(c[i].filled)
		{
			return i;
		}

		i++;
	} 
	printf("Nie ma wiecej kontaktow po prawo!");
	return index;
}

int GetPreviousContactIndex(Contact c[], int index, int zilu)
{
	int i = index -1;
	while (i > -1)
	{
		if (c[i].filled)
		{
			return i;
		}
		i--;
	} 
	printf("Nie ma wiecej kontaktow po lewo!");
	return index;
}

int GetEmptyContactIndex(Contact c[], int zilu)
{
	for (int i = 0; i < zilu; i++)
	{
		if (c[i].filled == 0)
			return i;
	}
	return INVAILD_CONTACT;
}
