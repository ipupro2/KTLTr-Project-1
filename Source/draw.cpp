#include "functions.h"

void DrawBoard(char board[height][width])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << board[i][j];
		}
		cout << " " << rect << "              " << creditText[i] <<"\n";
	}
}

void DrawPlayer(location loc, char direction)
{
	GotoPosition(loc.r, loc.c + 1);
	cout << "\b";
	cout << square;
	GotoPosition(loc.r + 1, loc.c + 2);
	cout << "\b\b\b" << rect << rect << rect;
	switch (direction)
	{
		case 'L':
		{
			GotoPosition(loc.r, loc.c + 2);
			cout << "\b ";
			GotoPosition(loc.r + 1, loc.c + 3);
			cout << "\b ";
			break;
		}
		case 'R':
		{
			GotoPosition(loc.r, loc.c);
			cout << "\b ";
			GotoPosition(loc.r + 1, loc.c - 1);
			cout << "\b ";
			break;
		}
		case 'U':
		{
			GotoPosition(loc.r + 2, loc.c + 2);
			cout << "\b\b\b   ";
			break;
		}
		case 'D':
		{
			GotoPosition(loc.r - 1, loc.c + 1);
			cout << "\b ";
			GotoPosition(loc.r, loc.c + 2);
			cout << "\b ";
			GotoPosition(loc.r, loc.c);
			cout << "\b ";
		}
	}
}