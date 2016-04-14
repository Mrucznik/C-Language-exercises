#pragma once
#define INVAILD_CONTACT -1

typedef struct kontakt_t
{
	unsigned char filled : 1;
	char imie[32];
	char nazwisko[32];
	char adres[64];
	int telefon;
	struct Data
	{
		int day;
		int month;
		int year;
	} data_urodzin;
	char email[64];
} Contact;

void LoadContacts(Contact[], int);
void SaveContacts(Contact[], int);
void CreateContact(Contact*);
void DeleteContact(Contact*);
void PrintContact(Contact);

int GetEmptyContactIndex(Contact[], int);
int GetNextContactIndex(Contact[], int, int);
int GetPreviousContactIndex(Contact[], int, int);
