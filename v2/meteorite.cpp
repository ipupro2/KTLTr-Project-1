#include "functions.h"

void CreateNewMeteorite(position meteoriteLoc[], int &meteoriteCount, CHAR_INFO board[])
{
	int x = rand() % width;
	SetBoardValue(board, 0, x, 219);
	SetBoardValue(board, 0, x + 1, 219);
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
			SetBoardValue(board, meteoriteLoc[i].r, meteoriteLoc[i].c, 219);
			SetBoardValue(board, meteoriteLoc[i].r, meteoriteLoc[i].c + 1, 219);
			SetBoardValue(board, meteoriteLoc[i].r - 1, meteoriteLoc[i].c);
			SetBoardValue(board, meteoriteLoc[i].r - 1, meteoriteLoc[i].c + 1);
		}
	}
}