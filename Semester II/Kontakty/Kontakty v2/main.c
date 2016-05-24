#include <stdio.h>
#include <stdlib.h>
#include <wincon.h>

struct menukey
{
	int key;
	void(*action)(struct menu, struct menuview);
};

struct menuview
{
	const char *(*verse)(const char *format, ...);
};

struct menu
{
	int height;
	int width;
	int maincolor;
	int selectcolor;
};

int main(void)
{
	struct menu *menu = (struct menu*)malloc(sizeof(struct menu));
	menu->height = 38;
	menu->width = 20;
	menu->maincolor = BACKGROUND_GREEN;
	menu->selectcolor = BACKGROUND_INTENSITY;


	return 0;
}