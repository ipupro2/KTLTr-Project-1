#include "functions.h"

//Hàm c?a thiên th?ch
void CreateNewMeteorite(position meteoriteLoc[], int &meteoriteCount)
{
	int x = 1 + rand() % (boardWidth - 3);
	SetBoardValue(1, x, ' ', 112);
	SetBoardValue(1, x + 1, ' ', 112);
	meteoriteLoc[meteoriteCount].r = 1;
	meteoriteLoc[meteoriteCount].c = x;
	meteoriteCount++;
}

void MeteoriteControl(unsigned long &score, position meteoriteLoc[], int &meteoriteCount)
{
	for (int i = 0; i < meteoriteCount; i++)
	{
		meteoriteLoc[i].r++;
		if (meteoriteLoc[i].r >= boardHeight - 1)
		{
			score++;
			UpdateScore(score);
			SetBoardValue(meteoriteLoc[i].r - 1, meteoriteLoc[i].c);
			SetBoardValue(meteoriteLoc[i].r - 1, meteoriteLoc[i].c + 1);
			DeleteElement(meteoriteLoc, meteoriteCount, i);
			i--;
		}
		else
		{
			SetBoardValue(meteoriteLoc[i].r, meteoriteLoc[i].c, ' ', 112);
			SetBoardValue(meteoriteLoc[i].r, meteoriteLoc[i].c + 1, ' ', 112);
			SetBoardValue(meteoriteLoc[i].r - 1, meteoriteLoc[i].c);
			SetBoardValue(meteoriteLoc[i].r - 1, meteoriteLoc[i].c + 1);
		}
	}
}

void MeteoriteDestroy(position pos)
{
	SetBoardValue(pos.r, pos.c);
	SetBoardValue(pos.r, pos.c + 1);
}

//Player's Bullets functions
void Shoot(position pos, position bullets[], int &bulletCount,char bullet) {
	SetBoardValue(pos.r, pos.c, bullet);
	SetBoardValue(pos.r - 1, pos.c, bullet);
	position _bullet;
	_bullet.r = pos.r - 1;
	_bullet.c = pos.c;
	bullets[bulletCount] = _bullet;
	bulletCount++;
}

void BulletControl(position bullets[], int &bulletCount, char direction, char bullet) {
	for (int i = 0; i < bulletCount; i++)
	{
		if ((bullets[i].r == 1&&direction=='U') || (bullets[i].r == boardHeight - 2 && direction == 'D'))
		{
			SetBoardValue(bullets[i].r, bullets[i].c);
			DeleteElement(bullets, bulletCount, i);
			i--;
		}
		else
		{
			SetBoardValue(bullets[i].r, bullets[i].c);
			if (direction == 'U')
				bullets[i].r--;
			else
				bullets[i].r++;
			SetBoardValue(bullets[i].r, bullets[i].c, bullet);
		}
	}
}

//Boss Function
void CreateBoss(int &bossHp, position &bossPos)
{
	bossHp = 100;
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