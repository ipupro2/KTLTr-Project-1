#include "functions.h"

void InitializeBoard(CHAR_INFO board[], SMALL_RECT &rec)
{
	SetConsoleTitle(L"Galaxy War");
	HideCursor();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	rec.Top = 0;
	rec.Left = 0;
	rec.Bottom = height;
	rec.Right = width;
	ReadConsoleOutput(h, board, { width, height }, { 0, 0 }, &rec);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			SetBoardValue(board, i, j);
		}
	}
}

void DrawPlayer(position pos, char direction, CHAR_INFO board[])
{
	SetBoardValue(board, pos.r, pos.c, '^');
	SetBoardValue(board, pos.r + 1, pos.c, '=');
	SetBoardValue(board, pos.r + 1, pos.c - 1, '|');
	SetBoardValue(board, pos.r + 1, pos.c - 2, '<');
	SetBoardValue(board, pos.r + 1, pos.c + 1, '|');
	SetBoardValue(board, pos.r + 1, pos.c + 2, '>');
	switch (direction)
	{
		case 'L':
		{
			SetBoardValue(board, pos.r, pos.c + 1, ' ');
			SetBoardValue(board, pos.r + 1, pos.c + 3, ' ');
			break;
		}
		case 'R':
		{
			SetBoardValue(board, pos.r, pos.c - 1, ' ');
			SetBoardValue(board, pos.r + 1, pos.c - 3, ' ');
			break;
		}
		case 'U':
		{
			SetBoardValue(board, pos.r + 2, pos.c, ' ');
			SetBoardValue(board, pos.r + 2, pos.c - 1, ' ');
			SetBoardValue(board, pos.r + 2, pos.c - 2, ' ');
			SetBoardValue(board, pos.r + 2, pos.c + 1, ' ');
			SetBoardValue(board, pos.r + 2, pos.c + 2, ' ');
			break;
		}
		case 'D':
		{
			SetBoardValue(board, pos.r - 1, pos.c, ' ');
			SetBoardValue(board, pos.r, pos.c - 1, ' ');
			SetBoardValue(board, pos.r, pos.c - 2, ' ');
			SetBoardValue(board, pos.r, pos.c + 1, ' ');
			SetBoardValue(board, pos.r, pos.c + 2, ' ');
			break;
		}
	}
}

void RedrawBoard(CHAR_INFO board[])
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = height;
	rect.Right = width;
	WriteConsoleOutput(h, board, { width, height }, { 0,0 },&rect);
}