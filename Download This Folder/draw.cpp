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
	SetConsoleTitleA("Galaxy War");
	HideCursor();
	GotoPosition(screenHeight / 2, screenWidth / 2 - 10);
	cout << "Who are we?";
	Sleep(1000);
	GotoPosition(screenHeight / 2, screenWidth / 2 - 10);
	cout << "We're here to make the difference!";
	Sleep(1000);
	DrawScreenFromFile("intro.map");
	while (!GetAsyncKeyState(VK_RETURN))
	{
		GotoPosition(24, 47);
		if (GetTickCount() % 500 == 0)
			cout << "<Press Enter to Continue>";
		else if (GetTickCount() % 250 == 0)
			cout << "                         ";
	}
	Sleep(200);
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