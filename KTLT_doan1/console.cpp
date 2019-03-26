#include "console.h"

void HideCursor()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(h, &cursor);
	cursor.bVisible = false;
	SetConsoleCursorInfo(h, &cursor);
}

void GotoPosition(int r, int c)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD C = { (short)c, (short)r };
	SetConsoleCursorPosition(h, C);
}