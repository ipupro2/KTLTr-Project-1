#include "functions.h"

void DrawPowerUp(position pos)
{
	if (pos.r > 1)
	{
		SetBoardValue(pos.r - 1, pos.c, '^');
		SetBoardValue(pos.r - 1, pos.c - 1, '|');
		SetBoardValue(pos.r - 1, pos.c - 1, '|');
	}
	SetBoardValue(pos.r, pos.c, '^');
	SetBoardValue(pos.r, pos.c + 1, '|');
	SetBoardValue(pos.r, pos.c - 1, '|');
	if (pos.r > 2)
	{
		SetBoardValue(pos.r - 2, pos.c);
		SetBoardValue(pos.r - 2, pos.c - 1);
		SetBoardValue(pos.r - 2, pos.c + 1);
	}
}

void CreatePowerUp(position &pos)
{
	pos.r = 1;
	pos.c = 1 + rand() % (boardWidth - 1);
	DrawPowerUp(pos);
}

void MovePowerUp(position &pos, position playerPos, int &shootingDelay)
{
	pos.r++;
	DrawPowerUp(pos);
	if (pos.r == playerPos.r || (pos.r == playerPos.r + 1 && pos.c >= playerPos.c - 2 && pos.c <= playerPos.c + 2))
	{
		shootingDelay = 4;
		pos = { -1,-1 };
	}
}
