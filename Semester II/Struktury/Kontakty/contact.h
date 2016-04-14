#pragma once
typedef struct kontakt_t
{
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

void LoadContacts(Contact*[], int);
void SaveContacts(Contact[], int);
void CreateContact(Contact*);
void DeleteContact(Contact*);
void NextContact(Contact);
void PreviousContact(Contact);
void PrintContact(Contact);
