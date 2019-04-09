#include "draw.h"
#include <fstream>
#include <string>

static CHAR_INFO screen[10000];//Buffer for game screen
static CHAR_INFO flashScreen[10000];
static SMALL_RECT rect;//Rectangle which is drawn the game in

void DrawScreenFromFile(string stringPath)
{
	ifstream file;
	file.open("Resources/map/" + stringPath);
	if (!file)
	{
		system("cls");
		cout << "Missing file \"" << stringPath << "\". \nGame will exit in few seconds.";
		Sleep(5000);
		exit(0);
	}
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
			screen[i*screenWidth + j].Attributes = 7;
			if (screen[i*screenWidth + j].Char.AsciiChar == '\n')
			{
				j--;
			}
		}
	}
	WriteConsoleOutput(h, screen, { screenWidth, screenHeight }, { 0, 0 }, &rect);
	file.close();
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
	WriteConsoleOutput(h, screen, { screenWidth, screenHeight }, { 0,0 }, &rect);
}

void SetBoardValue(int row, int column, char code, int color)
{
	screen[row*screenWidth + column].Char.UnicodeChar = code;
	screen[row*screenWidth + column].Attributes = color;
}

void PlaneThroughScreen()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	fstream file;
	file.open("Resources/map/plane.map");
	if (!file)
	{
		system("cls");
		cout << "Missing file \"plane.map\". \nGame will exit in few seconds.";
		Sleep(5000);
		exit(0);
	}
	for (int i = 0; i < screenHeight; i++)
	{
		for (int j = 0; j < screenWidth; j++)
		{
			file.get(screen[i * screenWidth + j].Char.AsciiChar);
			if (screen[i * screenWidth + j].Char.AsciiChar == '\n')
			{
				j--;
			}
		}
	}
	file.close();
	for (int i = 0; i < 120; i++)
	{
		WriteConsoleOutput(h, screen, { 120,30 }, { 0, 0 }, &rect);
		for (int j = 29; j >= 0; j--)
		{
			for (int k = 118; k >= 2; k--)
			{
				screen[j * 120 + k] = screen[j * 120 + k - 1];
			}
		}
		Sleep(10);
	}
}