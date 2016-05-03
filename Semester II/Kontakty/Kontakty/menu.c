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
	puts  ("�����������������������������������ͻ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
	printf("�       Aktualny rekord: #%02d        �\n", menu.record);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
	printf("� Imie: %-27s �\n", kontakt[menu.record].imie);
	printf("� Nazwisko: %-23s �\n", kontakt[menu.record].nazwisko);
	printf("� Telefon: %-24d �\n", kontakt[menu.record].telefon);
	puts  ("�����������������������������������Ķ");
	puts  ("� E - edytuj      � U - usun        �");
	puts  ("� D - dodaj       � W - wyswietl    �");
	puts  ("� <- - poprzedni  � -> - nastepny   �");
	puts  ("� ESC - wyjdz     �                 �");
	puts  ("�����������������������������������ͼ");
}

void printMenuRow(const char* string)
{
	printf("� %34s �\n", string);
}
