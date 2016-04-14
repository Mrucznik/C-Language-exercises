#include <stdio.h>
#include "contact.h"
#include "utils.h"
#include <stdlib.h>

#define MAX_CONTACTS	100

int main()
{
	Contact kontakty[MAX_CONTACTS];
	LoadContacts(kontakty, MAX_CONTACTS);

	int menu = 0, record = 0;
	do
	{
		system("cls");
		printf("Record #%d\n", record);
		printf("Choose menu option: \n1. Next record\n2. Previous record\n3. Print record\n4. Delete record\n5. Add record\n0. Exit\n: ");
		scanf("%d", &menu);
		if (menu == 1)
		{
			record = GetNextContactIndex(kontakty, record, MAX_CONTACTS);
		}
		else if(menu == 2)
		{
			record = GetPreviousContactIndex(kontakty, record, MAX_CONTACTS);
		}
		else if(menu == 3)
		{
			PrintContact(kontakty[record]);
		}
		else if(menu == 4)
		{
			DeleteContact(&kontakty[record]);
		}
		else if (menu == 5)
		{
			record = GetEmptyContactIndex(kontakty, MAX_CONTACTS);
			if (record != INVAILD_CONTACT)
				CreateContact(&kontakty[record]);
			else
			{
				printf("Brak wolnych rekordow!");
			}
		}
		else if (menu == 0)
			break;
		else
		{
			printf("Nieprawidlowa opcja!");
		}
		getchar();
		getchar();
	} while (menu);

	SaveContacts(kontakty, MAX_CONTACTS);
	return 0;
}