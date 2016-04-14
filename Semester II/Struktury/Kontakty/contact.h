#pragma once
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
} Contact;

void LoadContacts(Contact[]);
void SaveContacts(Contact[]);
void LoadContact(Contact);
void SaveContact(Contact);
void CreateContact(Contact);
void DeleteContact(Contact);
void NextContact(Contact);
void PreviousContact(Contact);
void PrintContact(Contact);
