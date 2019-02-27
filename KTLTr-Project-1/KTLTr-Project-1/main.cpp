#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

struct location
{
	int r;//row
	int c;//column
};

void GotoPosition(int r, int c);
void DrawBoard(char board[30][100]);
void UpdateBoard(char board[30][100], location curLocation);
void HideCursor();
void GameCore(char board[30][100], location curLoc)
{
	char c;
	HideCursor();
	while (1)
	{
		if (kbhit())//Check if player input anything
		{
			c = getch();
			if (c == -32)//Get input character
				c = getch();
			switch (int(c))
			{
				case 75://left
					if (curLoc.c > 0)
					{
						GotoPosition(curLoc.r, curLoc.c+1);
						cout << "\b\b";
						cout << "o ";
						curLoc.c--;
					}
					break;
				case 77://right
					if (curLoc.c < 99)
					{
						GotoPosition(curLoc.r, curLoc.c+2);
						cout << "\b\b";
						cout << " o";
						curLoc.c++;
					}
					break;
				case 72://up
					if (curLoc.r > 0)
						curLoc.r--;
					break;
				case 80://down
					if (curLoc.r < 30)
						curLoc.r++;
					break;
			}
			UpdateBoard(board, curLoc);
		}
	}
}

int main()
{
	char board[30][100];
	location curLocation; // currentLocation are default set to 50 50
	curLocation.c = 50;
	curLocation.r = 15;
	UpdateBoard(board, curLocation);
	DrawBoard(board);
	GameCore(board, curLocation);
	return 0;
}

//Utilities

void DrawBoard(char board[30][100])
{
	system("cls");
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
}

void UpdateBoard(char board[30][100], location curLocation)
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (i == curLocation.r && j == curLocation.c)
				board[i][j] = 'o';
			else
				board[i][j] = ' ';
		}
	}
}

void HideCursor()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(h, &info);
	info.bVisible = false;
	SetConsoleCursorInfo(h, &info);
}

void GotoPosition(int r, int c)
{
	HANDLE h = NULL;
	if (!h)
	{
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD C = { c, r };
	SetConsoleCursorPosition(h, C);
}