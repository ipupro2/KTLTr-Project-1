#include "item.h"

void DrawItem(position pos, char character)
{
	if(pos.r > 1)
		SetBoardValue(pos.r - 1, pos.c, ' ');
	SetBoardValue(pos.r, pos.c, character);
}

void CreatePowerUp(position &pos)
{
	pos.r = 1;
	pos.c = 1 + rand() % (boardWidth - 1);
	DrawItem(pos, 'P');
}

void MovePowerUp(position &pos)
{
	pos.r++;
	if (pos.r >= boardHeight - 1)
	{
		SetBoardValue(pos.r - 1, pos.c);
		pos = { -1, -1 };
		return;
	}
	DrawItem(pos, 'P');
}

void PlayerCollidePowerUp(position &pos, position playerPos, int &powerUpRemainTime)
{
	if ((pos.r == playerPos.r && pos.c == playerPos.c)
		|| (pos.r == playerPos.r + 1 && pos.c >= playerPos.c - 2 && pos.c <= playerPos.c + 2))
	{
		PlaySound(TEXT("Resources/gameEffect/pickItem.wav"), NULL, SND_ASYNC);
		powerUpRemainTime = 1000;
		pos = { -1,-1 };
	}
}

void CreateHP(position &pos)
{
	pos.r = 1;
	pos.c = 1 + rand() % (boardWidth - 1);
	DrawItem(pos, '+');
}

void MoveHP(position &pos)
{
	pos.r++;
	if (pos.r >= boardHeight - 1)
	{
		SetBoardValue(pos.r - 1, pos.c);
		pos = { -1, -1 };
		return;
	}
	DrawItem(pos, '+');
}

void PlayerCollideHP(position &pos, position playerPos, int &hp)
{
	if ((pos.r == playerPos.r && pos.c == playerPos.c)
		|| (pos.r == playerPos.r + 1 && pos.c >= playerPos.c - 2 && pos.c <= playerPos.c + 2))
	{
		PlaySound(TEXT("Resources/gameEffect/pickItem.wav"), NULL, SND_ASYNC);
		hp += 5;
		if (hp > 99)
			hp = 99;
		pos = { -1,-1 };
	}
}