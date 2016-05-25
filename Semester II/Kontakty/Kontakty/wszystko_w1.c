#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define KEY_ESC 27
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_EDIT 'e'
#define KEY_REMOVE 'u'
#define KEY_ADD 'd'
#define KEY_PRINT 'w'

#define MAX_CONTACTS	100
#define INVAILD_CONTACT -1

#define FILENAME "kontakty.db"

//-------------------------------------------< Deklaracje >-------------------------------------------
//--------------------< Kontakt >---------------------
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
void EditContact(Contact*);
void DeleteContact(Contact*);
void PrintContact(Contact);

int GetEmptyContactIndex(Contact[], int);
int GetNextContactIndex(Contact[], int, int);
int GetPreviousContactIndex(Contact[], int);

//--------------------< Menu >---------------------
typedef struct menu
{
	enum menuOptions
	{
		NAVIGATE,
		NEXT_RECORD,
		PREVIOUS_RECORD,
		PRINT_RECORD,
		ADD_RECORD,
		REMOVE_RECORD,
		EDIT_RECORD,
		EXIT
	} option;
	int record;
} Menu;

void controlMenu(Menu*);
void printMenu(Menu, Contact*);
void menuInit(Menu*);

//--------------------< Inne >---------------------
void getVariableFromConsoleWithMessagePrinting(const char[], const char[], ...);


//-------------------------------------------< Definicje >-------------------------------------------
//--------------------< Kontakt >---------------------
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
}

void PrintContact(Contact c)
{
	if (c.filled)
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
	int i = index + 1;
	while (i < zilu)
	{
		if (c[i].filled)
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
	int i = index - 1;
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


//--------------------< Menu >---------------------
void doTasks(Menu *menu, Contact *kontakty)
{
	switch (menu->option)
	{
	case NAVIGATE:
		printMenu(*menu, kontakty);
		return;
	case NEXT_RECORD:
		menu->record = GetNextContactIndex(kontakty, menu->record, MAX_CONTACTS);
		break;
	case PREVIOUS_RECORD:
		menu->record = GetPreviousContactIndex(kontakty, menu->record);
		break;
	case PRINT_RECORD:
		PrintContact(kontakty[menu->record]);
		return;
	case ADD_RECORD:
		menu->record = GetEmptyContactIndex(kontakty, MAX_CONTACTS);
		if (menu->record != INVAILD_CONTACT)
			CreateContact(&kontakty[menu->record]);
		break;
	case REMOVE_RECORD:
		DeleteContact(&kontakty[menu->record]);
		menu->option = PREVIOUS_RECORD;
		doTasks(menu, kontakty);
		system("cls");
		printf("Pomyslnie usunieto!\n");
		break;
	case EDIT_RECORD:
		EditContact(&kontakty[menu->record]);
		break;
	case EXIT:
		return;
	default:
		printf("ERROR! Nieprawidlowa opcja!\n");
		return;
	}
	menu->option = NAVIGATE;
	doTasks(menu, kontakty);
}

void menuInit(Menu* menu)
{
	menu->option = NAVIGATE;
	menu->record = 0;
}

void controlMenu(Menu* menu)
{
	enum menuOptions *option = &menu->option;
	char c;
	c = _getch();
	switch (c)
	{
	case -32:
		c = _getch();
		if (c == KEY_LEFT)
		{
			*option = PREVIOUS_RECORD;
		}
		else if (c == KEY_RIGHT)
		{
			*option = NEXT_RECORD;
		}
		break;
	case KEY_PRINT:
		*option = PRINT_RECORD;
		break;
	case KEY_ADD:
		*option = ADD_RECORD;
		break;
	case KEY_REMOVE:
		*option = REMOVE_RECORD;
		break;
	case KEY_EDIT:
		*option = EDIT_RECORD;
		break;
	case KEY_ESC:
		*option = EXIT;
		break;
	default:
		*option = NAVIGATE;
		break;
	}
}

void printMenu(Menu menu, Contact* kontakt)
{
	if (kontakt->filled)
	{
		puts("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
		printf("ş       Aktualny rekord: #%02d        ş\n", menu.record);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
		printf("ş Imie: %-27s ş\n", kontakt[menu.record].imie);
		printf("ş Nazwisko: %-23s ş\n", kontakt[menu.record].nazwisko);
		printf("ş Telefon: %-24d ş\n", kontakt[menu.record].telefon);
		puts("ÇÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¶");
		puts("ş E - edytuj      ł U - usun        ş");
		puts("ş D - dodaj       ł W - wyswietl    ş");
		puts("ş <- - poprzedni  ł -> - nastepny   ş");
		puts("ş ESC - wyjdz     ł                 ş");
		puts("ČÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍĎÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍĽ");
	}
	else
	{
		puts("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
		printf("ş       Aktualny rekord: #%02d        ş\n", menu.record);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
		puts("ş               Pusto               ş");
		puts("ÇÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¶");
		puts("ş E - edytuj      ł U - usun        ş");
		puts("ş D - dodaj       ł W - wyswietl    ş");
		puts("ş <- - poprzedni  ł -> - nastepny   ş");
		puts("ş ESC - wyjdz     ł                 ş");
		puts("ČÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍĎÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍĽ");
	}
}

void printMenuRow(const char* string)
{
	printf("ş %34s ş\n", string);
}

//--------------------< Inne >---------------------
void getVariableFromConsoleWithMessagePrinting(const char communicat[], const char format[], ...)
{
	va_list argsList;
	va_start(argsList, format);

	int isValueCorrect;
	do
	{
		printf(communicat);
		isValueCorrect = _vfscanf_l(stdin, format, NULL, argsList);
		fseek(stdin, 0, SEEK_END);
	} while (!isValueCorrect);
	va_end(argsList);
}


int main()
{
	//config:
	SetConsoleOutputCP(437); //znaczki ╔═╗║╝╚─╟╢
	system("mode CON: COLS=38 LINES=20");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);

	Contact kontakty[MAX_CONTACTS];
	LoadContacts(kontakty, MAX_CONTACTS);

	Menu menu;
	menuInit(&menu);

	while (menu.option != EXIT)
	{
		system("cls");
		doTasks(&menu, kontakty);
		controlMenu(&menu);
	}

	SaveContacts(kontakty, MAX_CONTACTS);
	return 0;
}