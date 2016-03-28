//sortowania.h

#pragma once //zapobiega do��czeniu (include) pliku wi�cej ni� jeden raz
/*
Og�lnie mo�esz to usun�� by nie czepia� si�, �e to nie twoje.
Je�eli nie chcesz usuwa�, to kole� pyta� te� o alternatywny spos�b, wi�c tutaj go zamieszczam:

#ifndef JAKAS_NAZWA //Czy jest zdefiniowana sta�a preprocesora JAKAS_NAZWA?
#define JAKAS_NAZWA //Je�eli tak, kompilator przechodzi tutaj i definiuj� t� sta��.

Tutaj zamieszczasz kod pliku

#endif //Je�eli sta�a jest zdefiniowana, kompilator przechodzi tutaj, a wi�c na koniec pliku, a wi�c nie do��cza ponownie tego samego kodu.
	   //Sta�a jest zdefiniowana wtedy, gdy kompilator ju� raz "przelecia�" przez ten plik.
*/

extern void cardSort(int tab[], int size); //s�owo kluczowe extern oznacza, �e implementacja (cia�o) funkcji nie znajduje si� w tym samym pliku, co deklaracja
extern void bubbleSort(int tab[], int size); //wi�cej info: http://4programmers.net/C/Extern
extern void simpleSort(int tab[], int size); //po angielsku i bardzie rzeczowo: http://www.geeksforgeeks.org/understanding-extern-keyword-in-c/
extern void quickSort(int tab[], int left, int right);

