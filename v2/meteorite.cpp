#include "functions.h"

void CreateNewMeteorite(position meteoriteLoc[], int &meteoriteCount, CHAR_INFO board[])
{
	int x = rand() % (width - 1);
	SetBoardValue(board, 0, x, ' ', 112);
	SetBoardValue(board, 0, x + 1, ' ', 112);
	meteoriteLoc[meteoriteCount].r = 0;
	meteoriteLoc[meteoriteCount].c = x;
	meteoriteCount++;
}

void MeteoriteControl(unsigned long &score, position meteoriteLoc[], int &meteoriteCount, CHAR_INFO board[])
{
	for (int i = 0; i < meteoriteCount; i++)
	{
		meteoriteLoc[i].r++;
		if (meteoriteLoc[i].r >= height)
		{
			score++;
			UpdateScore(score);
			SetBoardValue(board, meteoriteLoc[i].r - 1, meteoriteLoc[i].c);
			SetBoardValue(board, meteoriteLoc[i].r - 1, meteoriteLoc[i].c + 1);
			DeleteElement(meteoriteLoc, meteoriteCount, i);
			i--;
		}
		else
		{
			SetBoardValue(board, meteoriteLoc[i].r, meteoriteLoc[i].c, ' ', 112);
			SetBoardValue(board, meteoriteLoc[i].r, meteoriteLoc[i].c + 1, ' ', 112);
			SetBoardValue(board, meteoriteLoc[i].r - 1, meteoriteLoc[i].c);
			SetBoardValue(board, meteoriteLoc[i].r - 1, meteoriteLoc[i].c + 1);
		}
	}
}