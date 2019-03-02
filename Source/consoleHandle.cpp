#include "functions.h"

void HideCursor()//Hide blinking color in console
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(h, &info);
	info.bVisible = false;
	SetConsoleCursorInfo(h, &info);
}

void GotoPosition(int r, int c)//Move cursor to specified location
{
	HANDLE h = NULL;
	if (!h)
	{
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD C = { (short)c, (short)r };
	SetConsoleCursorPosition(h, C);
}