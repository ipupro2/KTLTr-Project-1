#include "functions.h"

static CHAR_INFO board[10000];//Buffer for game screen 
static SMALL_RECT rect;//Rectangle which is drawn the game in

void InitializeBoard()
{
	SetConsoleTitle(L"Galaxy War");
	HideCursor();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = height;
	rect.Right = width;
	ReadConsoleOutput(h, board, { width, height }, { 0, 0 }, &rect);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			SetBoardValue(i, j);
		}
	}
}

void DrawPlayer(position pos, char direction)
{
	SetBoardValue(pos.r, pos.c, '^');
	SetBoardValue(pos.r + 1, pos.c, '=');
	SetBoardValue(pos.r + 1, pos.c - 1, '|');
	SetBoardValue(pos.r + 1, pos.c - 2, '<');
	SetBoardValue(pos.r + 1, pos.c + 1, '|');
	SetBoardValue(pos.r + 1, pos.c + 2, '>');
	switch (direction)
	{
		case 'L':
		{
			SetBoardValue(pos.r, pos.c + 1, ' ');
			SetBoardValue(pos.r + 1, pos.c + 3, ' ');
			break;
		}
		case 'R':
		{
			SetBoardValue(pos.r, pos.c - 1, ' ');
			SetBoardValue(pos.r + 1, pos.c - 3, ' ');
			break;
		}
		case 'U':
		{
			SetBoardValue(pos.r + 2, pos.c, ' ');
			SetBoardValue(pos.r + 2, pos.c - 1, ' ');
			SetBoardValue(pos.r + 2, pos.c - 2, ' ');
			SetBoardValue(pos.r + 2, pos.c + 1, ' ');
			SetBoardValue(pos.r + 2, pos.c + 2, ' ');
			break;
		}
		case 'D':
		{
			SetBoardValue(pos.r - 1, pos.c, ' ');
			SetBoardValue(pos.r, pos.c - 1, ' ');
			SetBoardValue(pos.r, pos.c - 2, ' ');
			SetBoardValue(pos.r, pos.c + 1, ' ');
			SetBoardValue(pos.r, pos.c + 2, ' ');
			break;
		}
	}
}

void DrawBoss(position bossPos)
{
	int i = 0, j = 0;
	for (i = 0; i <= 3; i++)
	{
		for (j = 0; j < 7; j++)
		{
			SetBoardValue(i, bossPos.c - j + i, '=');
			SetBoardValue(i, bossPos.c + j - i, '=');
		}
		SetBoardValue(i, bossPos.c - j + i, '|');
		SetBoardValue(i, bossPos.c - j - 1 + i, ' ');
		SetBoardValue(i, bossPos.c + j - i, '|');
		SetBoardValue(i, bossPos.c + j + 1 - i, ' ');
	}
	SetBoardValue(i, bossPos.c, '=');
	SetBoardValue(i, bossPos.c + 1, ' ');
	SetBoardValue(i++, bossPos.c - 1, ' ');
	SetBoardValue(i, bossPos.c, '=');
	SetBoardValue(i, bossPos.c + 1, ' ');
	SetBoardValue(i, bossPos.c - 1, ' ');
}

void RedrawBoard()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = height;
	rect.Right = width;
	WriteConsoleOutput(h, board, { width, height }, { 0,0 },&rect);
}

void SetBoardValue(int row, int column, int code, int color)
{
	board[row*width + column].Char.UnicodeChar = code;
	board[row*width + column].Attributes = color;
}