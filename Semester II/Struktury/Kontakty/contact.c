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
	getVariableFromConsoleWithMessagePrinting("Podaj imie: ", "%s[32]", c->imie);
	getVariableFromConsoleWithMessagePrinting("Podaj nazwisko: ", "%s[32]", c->nazwisko);
	getVariableFromConsoleWithMessagePrinting("Podaj adres: ", "%s[64]", c->adres);
	getVariableFromConsoleWithMessagePrinting("Podaj telefon: ", "%d", &c->telefon);
	getVariableFromConsoleWithMessagePrinting("Podaj date urodzin (format: dzien/miesiac/rok): ", "%d/%d/%d", &c->data_urodzin.day, &c->data_urodzin.month, &c->data_urodzin.year);
	getVariableFromConsoleWithMessagePrinting("Podaj e-mail: ", "%s[64]", c->email);
}

void EditContact(Contact* c)
{
	getVariableFromConsoleWithMessagePrinting("Podaj zmieniony telefon: ", "%d", &c->telefon);
	getVariableFromConsoleWithMessagePrinting("Podaj zmieniony e-mail: ", "%s[64]", c->email);
}

void DeleteContact(Contact* c)
{
	c->filled = 0;
	printf("Rekord zostal pomyslnie usuniety!\n");
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
		printf("Ten rekord jest pusty!\n");
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
	printf("Nie ma wiecej kontaktow po prawo!\n");
	return index;
}

int GetPreviousContactIndex(Contact c[], int index)
{
	int i = index-1;
	while (i > -1)
	{
		if (c[i].filled)
		{
			return i;
		}
		i--;
	} 
	printf("Nie ma wiecej kontaktow po lewo!\n");
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
