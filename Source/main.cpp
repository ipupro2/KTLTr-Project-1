#include "functions.h"

int main()
{
	char board[height][width];
	location curLocation; // currentLocation are default set to width/2 height/2
	curLocation.c = width/2;
	curLocation.r = height/2;
	InitializeBoard(board, curLocation);
	DrawBoard(board);
	GameCore(board, curLocation);
	return 0;
}