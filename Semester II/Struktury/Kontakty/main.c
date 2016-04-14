#include <stdio.h>
#include "contact.h"
#include "utils.h"

int main()
{
	Contact kontakty[100];
	CreateContact(&kontakty[0]);
	PrintContact(kontakty[0]);
	return 0;
}