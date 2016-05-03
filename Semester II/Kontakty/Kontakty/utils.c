#include "utils.h"
#include <stdio.h>
#include <stdarg.h>

void getVariableFromConsoleWithMessagePrinting(const char communicat[], const char format[], ...)
{
	int result;
	va_list argsList;
	va_start(argsList, format);

	int isValueCorrect;
	do
	{
		printf(communicat);
		isValueCorrect = _vfscanf_l(stdin, format, NULL, argsList);
		fseek(stdin, 0, SEEK_END);
	} while (!isValueCorrect);
	va_end(argsList);
}
