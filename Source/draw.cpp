#include "functions.h"

void InitializeBoard()
{
	//We don't use height of 30 lines because of stuttering issue
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

void DrawPlayer(position pos, char direction)
{
	GotoPosition(pos.r, pos.c + 1);
	cout << "\b";
	cout << square;
	GotoPosition(pos.r + 1, pos.c + 2);
	cout << "\b\b\b" << rect << rect << rect;
	switch (direction)
	{
		case 'L':
		{
			GotoPosition(pos.r, pos.c + 2);
			cout << "\b ";
			GotoPosition(pos.r + 1, pos.c + 3);
			cout << "\b ";
			break;
		}
		case 'R':
		{
			GotoPosition(pos.r, pos.c);
			cout << "\b ";
			GotoPosition(pos.r + 1, pos.c - 1);
			cout << "\b ";
			break;
		}
		case 'U':
		{
			GotoPosition(pos.r + 2, pos.c + 2);
			cout << "\b\b\b   ";
			break;
		}
		case 'D':
		{
			GotoPosition(pos.r - 1, pos.c + 1);
			cout << "\b ";
			GotoPosition(pos.r, pos.c + 2);
			cout << "\b ";
			GotoPosition(pos.r, pos.c);
			cout << "\b ";
		}
	}
}