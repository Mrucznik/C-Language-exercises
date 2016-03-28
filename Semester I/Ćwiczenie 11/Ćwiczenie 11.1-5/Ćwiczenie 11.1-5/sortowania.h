//sortowania.h

#pragma once //zapobiega do³¹czeniu (include) pliku wiêcej ni¿ jeden raz
/*
Ogólnie mo¿esz to usun¹æ by nie czepia³ siê, ¿e to nie twoje.
Je¿eli nie chcesz usuwaæ, to koleœ pyta³ te¿ o alternatywny sposób, wiêc tutaj go zamieszczam:

#ifndef JAKAS_NAZWA //Czy jest zdefiniowana sta³a preprocesora JAKAS_NAZWA?
#define JAKAS_NAZWA //Je¿eli tak, kompilator przechodzi tutaj i definiujê t¹ sta³¹.

Tutaj zamieszczasz kod pliku

#endif //Je¿eli sta³a jest zdefiniowana, kompilator przechodzi tutaj, a wiêc na koniec pliku, a wiêc nie do³¹cza ponownie tego samego kodu.
	   //Sta³a jest zdefiniowana wtedy, gdy kompilator ju¿ raz "przelecia³" przez ten plik.
*/

extern void cardSort(int tab[], int size); //s³owo kluczowe extern oznacza, ¿e implementacja (cia³o) funkcji nie znajduje siê w tym samym pliku, co deklaracja
extern void bubbleSort(int tab[], int size); //wiêcej info: http://4programmers.net/C/Extern
extern void simpleSort(int tab[], int size); //po angielsku i bardzie rzeczowo: http://www.geeksforgeeks.org/understanding-extern-keyword-in-c/
extern void quickSort(int tab[], int left, int right);

