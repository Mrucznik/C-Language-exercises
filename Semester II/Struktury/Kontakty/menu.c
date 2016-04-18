#include "menu.h"
#include <conio.h>
#include <stdio.h>
#include "contact.h"

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
	puts  ("╔═══════════════════════════════════╗");
	printf("║  Aktualny rekord #%02d              ║\n", menu.record);
	printf("║ Imie: %-27s ║\n", kontakt[menu.option].imie);
	printf("║ Nazwisko: %-23s ║\n", kontakt[menu.option].nazwisko);
	printf("║ Telefon: %-24d ║\n", kontakt[menu.option].telefon);
	puts  ("╟───────────────────────────────────╢");
	puts  ("║ E - edytuj      ║ U - usuń        ║");
	puts  ("║ D - dodaj       ║ W - wyświetl    ║");
	puts  ("║ <- - poprzedni  ║ -> - następny   ║");
	puts  ("║ ESC - wyjdz     ║                 ║");
	puts  ("╚═══════════════════════════════════╝");
}
