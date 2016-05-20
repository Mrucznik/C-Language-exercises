#include <stdio.h>
#include <locale.h>

#define L(__instrukcja) printf("Linia %d: %s\n", __LINE__, #__instrukcja); __instrukcja;

int main(void)
{
	L(setlocale(LC_ALL, ""));
	L(printf("Nazwa pliku Ÿród³owego: %s\n", __FILE__));
	L(printf("Data kompilacji: %s\n", __DATE__));
	L(printf("Czas kompilacji: %s\n", __TIME__));
	return 0;
}