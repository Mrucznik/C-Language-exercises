1. Napisz program, który alokuje tablicę 100 liczb typu float. Wypełniją ją wartościami od 0 do 99 i wyświetl. Pamiętaj o zwolnieniu pamięci przed zakończeniem programu.
 
 
2. Spróbuj zaalokować 1GB pamięci. Sprawdź, jak zachowa się system operacyjny (skorzystaj z menedżera zadań).
 
3. Alokuj bloki pamięci po 1kB w nieskończonej pętli. Sprawdź, jak zachowa się system operacyjny (skorzystaj z menedżera zadań).
 
4. Zaalokuj pamięć dla liczby typu double. Do zaalokowanej pamięci zapisz liczbe PI. Wyświetla wartość tej pamięci (zaalokowanej zmiennej) oraz jej adres.
 
5. Napisz funkcję alokującą tablice typu float o podanej liczbie elementów. Wykorzystaj prototyp:
float* alokuj(int N);
 
6. Dana jest tablica: int tab[] a = {1,2,3,4,5,6,7,8,9,10};
Napisz funkcję wyświetlającą tablice typu int o następującym prototypie:
void wyswietl(const int* ptr, int N);
Następnie napisz funkcje, która wykonuje kopię tablicy w parametrze. Prototyp funkcji kopiującej:
int* kopia(const int* ptr, int N);
Wykonaj kopię tablicy a. Wyświetl zawartość tej tablicy oraz jej kopii.
 
7. Utwórz strukturę student_t, zawierającą trzy pola: imie (100 znaków), nazwisko (100 znaków), album (10 znaków). Napisz funkcję, która zwraca wskaźnik na strukturę wypełnioną danymi, podanymi z klawiatury przez użytkownika. Przykładowy prototyp:
student_t* wypelnij(void);
Dodaj funkcję wyświetlającą oraz zwalniającą pamięć.
 
8. Zmodyfikuj poprzednie zadanie tak, aby pola nie były tablicami znaków a wskaźnikami.
Ponownie napisz funkcje
student_t* wypelnij(void);
oraz wyswietl i zwolnij. Pamiętaj ze zwolnić należy nie tylko pamięć struktury student_t ale też i tekstów w poszczególnych polach.
