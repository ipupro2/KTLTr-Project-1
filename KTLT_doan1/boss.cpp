#include "boss.h"

static const string BossSprite[] =
{
	" _____|___|_|___|_____ ",
	" |___________________| ",
	" |___________________| ",
	" |=|=====|===|=====|=| ",
	" |=|======\\=/======|=| ",
	"  V        V        V  "
};

void DrawBoss(position bossPos)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = -11; j <= 11; j++)
		{
			if(bossPos.c + j < boardWidth - 1 && bossPos.c + j > 0)
				SetBoardValue(bossPos.r + i, bossPos.c + j, BossSprite[i][j+11]);
		}
	}
}

void CreateBoss(int& bossHp, int& maxBossHP, position& bossPos)
{
	bossHp = maxBossHP;
	maxBossHP += 2;
	bossPos = { 1, boardWidth / 2 };
	DrawBoss(bossPos);
}

void BossMovement(position playerPos, position& bossPos)
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
	for (int i = 0; i < 6; i++)
	{
		for (int j = -10; j <= 10; j++)
		{
			if (bossPos.c + j < boardWidth - 1 && bossPos.c + j > 0)
				SetBoardValue(bossPos.r + i, bossPos.c + j);
		}
	}
}