#include "functions.h"
#include <fstream>

static CHAR_INFO screen[10000];//Buffer for game screen
static CHAR_INFO flashScreen[10000];
static SMALL_RECT rect;//Rectangle which is drawn the game in

void DrawScreenFromFile(string stringPath)
{
	fstream file;
	file.open(stringPath);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = screenHeight;
	rect.Right = screenWidth;
	ReadConsoleOutput(h, screen, { screenWidth, screenHeight }, { 0, 0 }, &rect);

	for (int i = 0; i < screenHeight; i++)
	{
		for (int j = 0; j < screenWidth; j++)
		{
			file.get(screen[i*screenWidth + j].Char.AsciiChar);
			if (screen[i*screenWidth + j].Char.AsciiChar == '\n')
			{
				j--;
			}
		}
	}
	WriteConsoleOutput(h, screen, { screenWidth, screenHeight }, { 0, 0 }, &rect);
}

void Intro()
{
	SetConsoleTitle(L"Galaxy War");
	HideCursor();
	DrawScreenFromFile("intro.map");
	while (!GetAsyncKeyState(VK_RETURN))
	{
		GotoPosition(24, 47);
		if (GetTickCount() % 500 == 0)
			cout << "<Press Enter to Continue>";
		else if (GetTickCount() % 250 == 0)
			cout << "                         ";
	}
	Sleep(100);
}

void InitializeGame()
{
	DrawScreenFromFile("game.map");
}

void FlashScreen()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = screenHeight;
	rect.Right = screenWidth;
	WriteConsoleOutput(h, flashScreen, { screenWidth, screenHeight }, { 0,0 }, &rect);
	Sleep(40);
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
	for (i = 1; i <= 4; i++)
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

void DrawPowerUp(position pos)
{
	if (pos.r > 1)
	{
		SetBoardValue(pos.r - 1, pos.c, '^');
		SetBoardValue(pos.r - 1, pos.c - 1, '|');
		SetBoardValue(pos.r - 1, pos.c - 1, '|');
	}
	SetBoardValue(pos.r, pos.c, '^');
	SetBoardValue(pos.r, pos.c + 1, '|');
	SetBoardValue(pos.r, pos.c - 1, '|');
	if (pos.r > 2)
	{
		SetBoardValue(pos.r - 2, pos.c);
		SetBoardValue(pos.r - 2, pos.c - 1);
		SetBoardValue(pos.r - 2, pos.c + 1);
	}
}

void RedrawBoard()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = screenHeight;
	rect.Right = screenWidth;
	WriteConsoleOutput(h, screen, { screenWidth, screenHeight }, { 0,0 },&rect);
}

void SetBoardValue(int row, int column, int code, int color)
{
	screen[row*screenWidth + column].Char.UnicodeChar = code;
	screen[row*screenWidth + column].Attributes = color;
}