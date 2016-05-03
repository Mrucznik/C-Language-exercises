#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "contact.h"
#include "menu.h"

#define MAX_CONTACTS	100

void doTasks(Menu *menu, Contact *kontakty)
{
	int oldOption = NAVIGATE;
	switch(menu->option)
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

	while(menu.option != EXIT)
	{
		system("cls");
		doTasks(&menu, kontakty);
		controlMenu(&menu);
	}

	SaveContacts(kontakty, MAX_CONTACTS);
	return 0;
}