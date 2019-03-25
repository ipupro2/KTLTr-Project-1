#include "functions.h"

void Shoot(position pos, position bullets[], int &bulletCount, char bullet) {
	SetBoardValue(pos.r, pos.c, bullet);
	SetBoardValue(pos.r, pos.c, bullet);
	bullets[bulletCount] = { pos.r, pos.c };
	bulletCount++;
}

void BulletControl(position bullets[], int &bulletCount, char direction, char bullet) {
	for (int i = 0; i < bulletCount; i++)
	{
		if ((bullets[i].r == 1 && direction == 'U') || (bullets[i].r == boardHeight - 2 && direction == 'D'))
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

int CollideWithBoss(position pos, position bossPos)
{
	int i, j;
	for (i = bossPos.r; i <= bossPos.r + 3; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if ((pos.r == i && pos.c == bossPos.c - j + i) || (pos.r == i && pos.c == bossPos.c + j - i))
				return 1;
		}
	}
	return 0;
}

void HitBoss(position bullets[], int &bulletCount, position bossPosition, int &bossHP)
{
	for (int i = 0; i < bulletCount; i++)
	{
		if (CollideWithBoss(bullets[i], bossPosition))
		{
			SetBoardValue(bullets[i].r, bullets[i].c);
			DeleteElement(bullets, bulletCount, i);
			i--;
			DrawBoss(bossPosition);
			bossHP--;
		}
	}
	if (bossHP <= 0)
		DestroyBoss(bossPosition);
}

void BulletHit(position playerBullets[], int &playerBulletCount, position meteoriteLoc[],
	int &meteoriteCount, unsigned long score)
{
	for (int i = 0; i < playerBulletCount; i++)
	{
		if (CollideWithMeteor(playerBullets[i], meteoriteLoc, meteoriteCount))
		{
			score++;
			UpdateScore(score);
			DeleteElement(playerBullets, playerBulletCount, i);
		}
	}
}
void HitPlayer(position playerPosition, position meteoriteLoc[], int &meteoriteCount, position enemyBullets[],
	int &enemyBulletCount, int &playerHP)
{
	int r = playerPosition.r;
	int c = playerPosition.c;
	if (CollideWithMeteor({ r,c }, meteoriteLoc, meteoriteCount) || CollideWithMeteor({ r + 1,c }, meteoriteLoc, meteoriteCount)
		|| CollideWithMeteor({ r + 1,c + 1 }, meteoriteLoc, meteoriteCount) || CollideWithMeteor({ r + 1,c + 2 }, meteoriteLoc, meteoriteCount)
		|| CollideWithMeteor({ r + 1,c - 1 }, meteoriteLoc, meteoriteCount) || CollideWithMeteor({ r + 1,c - 2 }, meteoriteLoc, meteoriteCount))
	{
		playerHP--;
		FlashScreen();
	}
	for (int i = 0; i < enemyBulletCount; i++)
	{
		if ((enemyBullets[i].r == playerPosition.r && enemyBullets[i].c == playerPosition.c) ||
			(enemyBullets[i].r == playerPosition.r + 1 && enemyBullets[i].c >= playerPosition.c - 2
				&& enemyBullets[i].c <= playerPosition.c + 2))
		{
			DeleteElement(enemyBullets, enemyBulletCount, i);
			i--;
			playerHP--;
			FlashScreen();
			DrawPlayer(playerPosition);
		}
	}
}
int CollideWithPlan(position pos, position planLoc[], int &planCount)
{
	for (int i = 0; i < planCount; i++)
	{
		if (pos.r == planLoc[i].r && (pos.c == planLoc[i].c || pos.c == planLoc[i].c + 1 || pos.c == planLoc[i].c + 2))
		{
			DeletePlan(planLoc[i]);
			DeleteElement(planLoc, planCount, i);
			return 1;
		}
	}
	return 0;
}
void BulletHitPlan(position playerBullets[], int &playerBulletCount, position planLoc[],
	int &planCount, unsigned long &score)
{
	for (int i = 0; i < playerBulletCount; i++)
	{
		if (CollideWithPlan(playerBullets[i], planLoc, planCount))
		{
			score++;
			UpdateScore(score);
			DeleteElement(playerBullets, playerBulletCount, i);
		}
	}
}