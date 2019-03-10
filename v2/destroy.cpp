#include "functions.h"

void MeteoriteDestroy(position loc, CHAR_INFO board[])
{
	SetBoardValue(board, loc.r, loc.c);
	SetBoardValue(board, loc.r, loc.c + 1);
}