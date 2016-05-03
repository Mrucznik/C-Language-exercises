#pragma once
#include "contact.h"

#define KEY_ESC 27
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_EDIT 'e'
#define KEY_REMOVE 'u'
#define KEY_ADD 'd'
#define KEY_PRINT 'w'

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
		EDIT_UP,
		EDIT_DOWN,
		EXIT
	} option;
	int record;
} Menu;

void controlMenu(Menu*);
void printMenu(Menu, Contact*);
void menuInit(Menu*);
