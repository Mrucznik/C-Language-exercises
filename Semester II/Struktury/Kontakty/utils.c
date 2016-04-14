#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void getVariableFromConsole(const char communicat[], const char format[], ...)
{
	int result;
	va_list argsList;
	va_start(argsList, format);

	int check = 0, countloopsteps = 0;
	do
	{
		printf(communicat);
		check = _vfscanf_l(stdin, format, NULL, argsList);
		countloopsteps++;
		if(countloopsteps > 1000)
		{
			printf("\n\n\n\n\nCRITICAL ERROR - INFINITE LOOP!\n");
			exit(1);
		}
		fseek(stdin, 0, SEEK_END);
	} while (!check);
	va_end(argsList);
}
