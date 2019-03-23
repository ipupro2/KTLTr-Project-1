#include "functions.h"

void HideCursor()//Hide blinking color in console
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(h, &cursor);
	cursor.bVisible = false;
	SetConsoleCursorInfo(h, &cursor);
}

void GotoPosition(int r, int c)//Move cursor to specified posation
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD C = { (short)c, (short)r };
	SetConsoleCursorPosition(h, C);
}