#include <stdio.h>

int main()
{
	double T[999] = {
		53, 38, 76, 70, 19, 100, 67, 36, 68, 26,
		23, 40, 18, 61, 17, 24, 86, 46, 56, 89,
		36, 77, 14, 93, 35, 88, 37, 33, 34, 19,
		8, 65, 96, 12, 82, 10, 73, 4, 49, 92,
		90, 24, 77, 74, 61, 50, 92, 73, 28, 62,
		24, 35, 84, 70, 50, 44, 6, 94, 51, 26,
		7, 71, 71, 12, 27, 45, 40, 78, 22, 36,
		2, 10, 89, 31, 18, 25, 13, 77, 32, 59,
		60, 74, 34, 50, 59, 75, 17, 59, 30, 42,
		35, 15, 65, 75, 99, 1, 67, 18, 57, 73,
		14, 36, 32, 67, 81, 77, 49, 9, 36, 47,
		88, 81, 16, 22, 48, 68, 60, 41, 49, 22,
		27, 65, 1, 85, 2, 100, 96, 97, 48, 70,
		96, 37, 47, 46, 83, 31, 45, 66, 93, 36,
		27, 18, 68, 12, 10, 5, 97, 65, 61, 8,
		56, 41, 66, 89, 38, 99, 75, 88, 21, 71,
		11, 57, 88, 71, 48, 22, 77, 81, 11, 5,
		68, 9, 77, 50, 56, 83, 93, 24, 62, 29,
		17, 17, 64, 41, 38, 49, 38, 46, 11, 61,
		34, 90, 11, 58, 28, 1, 33, 64, 23, 34,
		15, 41, 58, 98, 58, 27, 89, 44, 76, 68,
		73, 71, 26, 2, 2, 10, 31, 70, 80, 77,
		23, 48, 49, 4, 52, 21, 76, 21, 56, 35,
		96, 6, 30, 90, 97, 45, 59, 29, 43, 87,
		1, 35, 43, 10, 71, 78, 6, 7, 34, 5,
		4, 52, 10, 24, 5, 10, 71, 23, 10, 41,
		3, 67, 73, 30, 62, 30, 77, 100, 69, 70,
		25, 93, 34, 32, 75, 51, 34, 32, 100, 10,
		32, 92, 50, 85, 100, 69, 62, 55, 17, 60,
		34, 7, 51, 25, 78, 52, 78, 23, 67, 80,
		74, 43, 44, 35, 9, 34, 21, 8, 63, 4,
		40, 41, 98, 50, 77, 51, 17, 66, 19, 9,
		78, 55, 33, 89, 26, 3, 23, 9, 74, 21,
		81, 41, 36, 93, 68, 82, 15, 51, 18, 69,
		91, 59, 24, 84, 45, 41, 65, 90, 13, 23,
		48, 87, 57, 47, 7, 62, 11, 18, 5, 75,
		88, 95, 52, 66, 60, 5, 12, 79, 14, 35,
		85, 84, 30, 93, 85, 85, 6, 62, 81, 45,
		20, 12, 24, 61, 95, 32, 54, 92, 61, 87,
		26, 15, 37, 49, 2, 85, 82, 63, 98, 80,
		78, 66, 12, 15, 74, 18, 29, 3, 66, 37,
		49, 86, 61, 1, 31, 36, 27, 45, 82, 13,
		18, 70, 70, 47, 71, 57, 76, 90, 78, 37,
		10, 77, 41, 36, 43, 22, 21, 82, 25, 94,
		11, 61, 18, 99, 97, 89, 49, 32, 86, 34,
		70, 90, 27, 45, 18, 14, 40, 67, 59, 92,
		43, 18, 6, 21, 4, 50, 40, 38, 98, 5,
		57, 39, 64, 17, 70, 93, 37, 100, 22, 3,
		95, 98, 10, 37, 56, 12, 73, 24, 15, 50,
		89, 32, 90, 14, 60, 27, 88, 71, 74, 88,
		57, 44, 28, 83, 47, 60, 13, 75, 52, 30,
		97, 36, 7, 24, 5, 36, 9, 90, 94, 9,
		100, 34, 73, 19, 40, 89, 69, 16, 95, 38,
		26, 21, 99, 21, 85, 48, 25, 96, 53, 50,
		74, 35, 42, 39, 87, 70, 31, 100, 26, 39,
		53, 54, 91, 73, 14, 82, 25, 82, 28, 14,
		27, 77, 33, 84, 61, 89, 85, 10, 61, 84,
		87, 5, 68, 46, 14, 19, 28, 44, 82, 45,
		40, 3, 26, 43, 21, 17, 44, 44, 54, 58,
		94, 50, 19, 66, 30, 69, 7, 67, 15, 70,
		7, 75, 15, 42, 9, 48, 7, 87, 76, 16,
		27, 91, 92, 46, 50, 34, 2, 41, 41, 82,
		92, 98, 69, 52, 22, 63, 80, 39, 50, 31,
		26, 49, 79, 40, 27, 85, 63, 73, 88, 30,
		97, 12, 7, 97, 97, 35, 90, 73, 91, 18,
		41, 20, 72, 36, 76, 25, 12, 52, 73, 61,
		65, 6, 67, 93, 81, 39, 6, 44, 84, 45,
		56, 96, 80, 57, 36, 52, 14, 76, 68, 41,
		24, 7, 39, 16, 85, 93, 54, 96, 87, 94,
		85, 52, 68, 45, 46, 11, 13, 19, 50, 3,
		62, 82, 88, 65, 64, 81, 50, 24, 20, 19,
		24, 86, 65, 74, 38, 78, 95, 36, 64, 52,
		74, 64, 73, 40, 17, 38, 43, 20, 2, 19,
		38, 47, 71, 92, 5, 5, 37, 16, 79, 32,
		80, 30, 90, 18, 54, 83, 54, 58, 50, 43,
		23, 74, 73, 26, 32, 72, 14, 39, 54, 43,
		41, 31, 46, 98, 75, 29, 28, 73, 87, 42,
		40, 46, 52, 17, 86, 70, 55, 63, 50, 95,
		36, 92, 35, 67, 31, 12, 51, 8, 11, 53,
		51, 75, 18, 88, 30, 86, 28, 99, 94, 18,
		68, 61, 95, 50, 88, 99, 13, 62, 75, 66,
		54, 91, 91, 1, 31, 30, 33, 16, 26, 87,
		27, 30, 12, 78, 25, 16, 2, 22, 27, 66,
		11, 63, 5, 2, 6, 91, 23, 75, 49, 79,
		25, 62, 12, 11, 36, 32, 36, 42, 73, 4,
		38, 29, 89, 42, 47, 39, 12, 77, 72, 11,
		84, 65, 82, 38, 40, 26, 54, 88, 61, 11,
		81, 55, 98, 54, 54, 96, 67, 21, 78, 84,
		72, 36, 2, 28, 78, 22, 53, 73, 12, 49,
		78, 20, 76, 15, 12, 25, 10, 83, 37, 67,
		82, 13, 74, 72, 78, 57, 90, 100, 64, 38,
		33, 44, 78, 97, 13, 54, 79, 90, 38, 100,
		16, 97, 66, 34, 36, 40, 58, 79, 46, 77,
		53, 18, 12, 82, 94, 58, 6, 64, 67, 65,
		52, 9, 4, 10, 36, 21, 21, 61, 65, 94,
		64, 46, 10, 73, 70, 1, 93, 99, 41, 66,
		22, 27, 53, 60, 89, 81, 70, 46, 65, 63,
		14, 6, 30, 68, 76, 42, 14, 54, 5, 62,
		65, 54, 70, 26, 7, 20, 50, 43, 45, 54,
		92, 3, 60, 30, 50, 74, 38, 99, 30 
	};
	double suma = 0.0;
	double srednia = 0.0;

	for (int i = 0; i < 999; i++)
	{
		suma += *(T + i);
	}

	srednia = suma / 999;

	printf("Suma: %lf, Srednia: %lf\n", suma, srednia);

	return 0;
}