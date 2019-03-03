#include "functions.h"

void InitializeBoard()
{
	//We don't use height is 30 because of stuttering issue
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << " ";
		}
		cout << " " << rect << "              " << creditText[i] <<"\n";
	}
	GotoPosition(height, width+2);
	cout << "\b" << rect;
	GotoPosition(0, width + 14);
	cout << "\b\b\b\b\b\b\b\b\b\b\bScore: 000000000";
}

void DrawPlayer(position loc, char direction)
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