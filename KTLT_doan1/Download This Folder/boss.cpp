#include "functions.h"

void DrawBoss(position bossPos)
{
	int i = 0, j = 0;
	for (i = 1; i <= 4; i++)
	{
		for (j = 0; j < 7; j++)
		{
			SetBoardValue(i, bossPos.c - j + i, '=');
			SetBoardValue(i, bossPos.c + j - i, '=');
		}
		SetBoardValue(i, bossPos.c - j + i, '|');
		SetBoardValue(i, bossPos.c - j - 1 + i, ' ');
		SetBoardValue(i, bossPos.c + j - i, '|');
		SetBoardValue(i, bossPos.c + j + 1 - i, ' ');
	}
	SetBoardValue(i, bossPos.c, '=');
	SetBoardValue(i, bossPos.c + 1, ' ');
	SetBoardValue(i++, bossPos.c - 1, ' ');
	SetBoardValue(i, bossPos.c, '=');
	SetBoardValue(i, bossPos.c + 1, ' ');
	SetBoardValue(i, bossPos.c - 1, ' ');
}

void CreateBoss(int &bossHp, position &bossPos)
{
	bossHp = 10;
	bossPos = { 1, boardWidth / 2 };
	DrawBoss(bossPos);
}

void BossMovement(position playerPos, position &bossPos)
{
	if (bossPos.c > playerPos.c)
	{
		bossPos.c--;
		DrawBoss(bossPos);
	}
	else if (bossPos.c < playerPos.c)
	{
		bossPos.c++;
		DrawBoss(bossPos);
	}
}

void DestroyBoss(position bossPos)
{
	int i, j;
	for (i = bossPos.r; i <= bossPos.r + 3; i++)
	{
		for (j = 0; j < 7; j++)
		{
			SetBoardValue(i, bossPos.c - j + i, ' ');
			SetBoardValue(i, bossPos.c + j - i, ' ');
		}
		SetBoardValue(i, bossPos.c - j + i, ' ');
		SetBoardValue(i, bossPos.c + j - i, ' ');
	}
	SetBoardValue(i++, bossPos.c, ' ');
	SetBoardValue(i, bossPos.c, ' ');
}