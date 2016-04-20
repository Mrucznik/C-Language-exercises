#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "contact.h"
#include "menu.h"

#define MAX_CONTACTS	100

void doTasks(Menu *menu, Contact *kontakty)
{
	int *record = &menu->record;
	switch(menu->option)
	{
	case NAVIGATE:
		//Nothing to do
		break;
	case NEXT_RECORD:
		*record = GetNextContactIndex(kontakty, *record, MAX_CONTACTS);
		break;
	case PREVIOUS_RECORD:
		*record = GetPreviousContactIndex(kontakty, *record);
		break;
	case PRINT_RECORD:
		PrintContact(kontakty[*record]);
		break;
	case ADD_RECORD:
		*record = GetEmptyContactIndex(kontakty, MAX_CONTACTS);
		if (*record != INVAILD_CONTACT)
			CreateContact(&kontakty[*record]);
		break;
	case REMOVE_RECORD:
		DeleteContact(&kontakty[*record]);
		break;
	case EDIT_RECORD:
		EditContact(&kontakty[*record]);
		break;
	case EXIT:
		return;
	default:
		printf("ERROR! Nieprawidlowa opcja!\n");
		break;
	}
	menu->option = NAVIGATE;
}

int main()
{
	//config:
	SetConsoleOutputCP(437); //znaczki ╔═╗║╝╚─╟╢
	system("mode CON: COLS=38 LINES=20");

	Contact kontakty[MAX_CONTACTS];
	LoadContacts(kontakty, MAX_CONTACTS);

	Menu menu;
	menuInit(&menu);

	while(menu.option != EXIT)
	{
		system("cls");
		printMenu(menu, kontakty);
		controlMenu(&menu);
		doTasks(&menu, kontakty);
	}

	SaveContacts(kontakty, MAX_CONTACTS);
	return 0;
}