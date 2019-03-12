#include "functions.h"

int CollideWithMeteor(position pos, position meteoriteLoc[], int &meteoriteCount) {//This function get position you want to check if something collect with Meteor
	for (int i = 0; i < meteoriteCount; i++)
	{
		if (pos.r == meteoriteLoc[i].r && (pos.c == meteoriteLoc[i].c || pos.c == meteoriteLoc[i].c + 1))
		{
			MeteoriteDestroy(meteoriteLoc[i]);
			DeleteElement(meteoriteLoc, meteoriteCount, i);
			return 1;
		}
	}
	return 0;
}

void BulletHit(position playerBullets[], int &playerBulletCount, position meteoriteLoc[], int &meteoriteCount, unsigned long score)
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

void PlayerHit(position playerPosition, position meteoriteLoc[], int &meteoriteCount, int &gameOver)
{
	int r = playerPosition.r;
	int c = playerPosition.c;
	if (CollideWithMeteor({r,c}, meteoriteLoc, meteoriteCount) || CollideWithMeteor({r+1,c}, meteoriteLoc, meteoriteCount)
		|| CollideWithMeteor({ r + 1,c + 1}, meteoriteLoc, meteoriteCount) || CollideWithMeteor({ r + 1,c + 2}, meteoriteLoc, meteoriteCount)
		|| CollideWithMeteor({ r + 1,c - 1}, meteoriteLoc, meteoriteCount) || CollideWithMeteor({ r + 1,c -2}, meteoriteLoc, meteoriteCount))
		GameOver(gameOver);
}