#include "bullet.h"

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

void HitBoss(position bullets[], int &bulletCount, position bossPosition, int &bossHP, unsigned long &score)
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
	{
		score += 50;
		DestroyBoss(bossPosition);
	}
}

void HitMeteorite(position playerBullets[], int &playerBulletCount, position meteoritePos[],
	int &meteoriteCount, unsigned long score)
{
	for (int i = 0; i < playerBulletCount; i++)
	{
		if (CollideWithMeteor(playerBullets[i], meteoritePos, meteoriteCount))
		{
			score++;
			UpdateScore(score);
			DeleteElement(playerBullets, playerBulletCount, i);
		}
	}
}
void HitPlayer(position playerPosition, position meteoritePos[], int &meteoriteCount, position enemyBullets[],
	int &enemyBulletCount, int &playerHP)
{
	int r = playerPosition.r;
	int c = playerPosition.c;
	if (CollideWithMeteor({ r,c }, meteoritePos, meteoriteCount) || CollideWithMeteor({ r + 1,c }, meteoritePos, meteoriteCount)
		|| CollideWithMeteor({ r + 1,c + 1 }, meteoritePos, meteoriteCount) || CollideWithMeteor({ r + 1,c + 2 }, meteoritePos, meteoriteCount)
		|| CollideWithMeteor({ r + 1,c - 1 }, meteoritePos, meteoriteCount) || CollideWithMeteor({ r + 1,c - 2 }, meteoritePos, meteoriteCount))
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
int CollideWithPlane(position pos, position planePos[], int &planeCount)
{
	for (int i = 0; i < planeCount; i++)
	{
		if (pos.r == planePos[i].r && (pos.c == planePos[i].c || pos.c == planePos[i].c + 1 || pos.c == planePos[i].c + 2))
		{
			DeletePlane(planePos[i]);
			DeleteElement(planePos, planeCount, i);
			return 1;
		}
	}
	return 0;
}

void BulletHitPlane(position playerBullets[], int &playerBulletCount, position planePos[],
	int &planeCount, unsigned long &score)
{
	for (int i = 0; i < playerBulletCount; i++)
	{
		if (CollideWithPlane(playerBullets[i], planePos, planeCount))
		{
			score++;
			UpdateScore(score);
			DeleteElement(playerBullets, playerBulletCount, i);
		}
	}
}