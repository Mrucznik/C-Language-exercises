#include "menu.h"
#include <conio.h>
#include <stdio.h>
#include "contact.h"
#include <windows.h>

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
	switch(c)
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
		else if(*option == EDIT_RECORD)
		{
			if (c == KEY_UP)
			{
				*option = EDIT_UP;
			}
			else if (c == KEY_DOWN)
			{
				*option = EDIT_DOWN;
			}
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
		printf("Invaild option!\n");
		break;
	}
}

void printMenu(Menu menu, Contact* kontakt)
{
	puts  ("ษอออออออออออออออออออออออออออออออออออป");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
	printf("บ       Aktualny rekord: #%02d        บ\n", menu.record);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
	printf("บ Imie: %-27s บ\n", kontakt[menu.record].imie);
	printf("บ Nazwisko: %-23s บ\n", kontakt[menu.record].nazwisko);
	printf("บ Telefon: %-24d บ\n", kontakt[menu.record].telefon);
	puts  ("วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤยฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
	puts  ("บ E - edytuj      ณ U - usun        บ");
	puts  ("บ D - dodaj       ณ W - wyswietl    บ");
	puts  ("บ <- - poprzedni  ณ -> - nastepny   บ");
	puts  ("บ ESC - wyjdz     ณ                 บ");
	puts  ("ศอออออออออออออออออฯอออออออออออออออออผ");
}

void printMenuRow(const char* string)
{
	printf("บ %34s บ\n", string);
}
