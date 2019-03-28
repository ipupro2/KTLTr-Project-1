#include "item.h"

void DrawPowerUp(position pos)
{
	if(pos.r > 1)
		SetBoardValue(pos.r - 1, pos.c, ' ');
	SetBoardValue(pos.r, pos.c, 'P');
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
	if (pos.r >= boardHeight)
	{
		SetBoardValue(pos.r - 1, pos.c);
		pos = { -1, -1 };
		return;
	}
	DrawPowerUp(pos);
	if ((pos.r == playerPos.r && pos.c == playerPos.c)
		|| (pos.r == playerPos.r + 1 && pos.c >= playerPos.c - 2 && pos.c <= playerPos.c + 2))
	{
		shootingDelay = 4;
		pos = { -1,-1 };
	}
}
