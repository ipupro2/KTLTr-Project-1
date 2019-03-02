#include "functions.h"

void InitializeBoard(char board[height][width], location curLocation)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == curLocation.r && j == curLocation.c)
			{
				board[i + 1][j - 1] = board[i + 1][j] = board[i + 1][j + 1] = rect;
				board[i][j] = square;
			}
			else if (board[i][j] != rect)
			{
				board[i][j] = ' ';
			}
		}
	}
	GotoPosition(0, 0);
}