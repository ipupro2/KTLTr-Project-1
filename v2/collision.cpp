#include "functions.h"

int CollideWithMeteor(position loc, position meteoriteLoc[], int &meteoriteCount, CHAR_INFO board[]) {//This function get position you want to check if something collect with Meteor
	for (int i = 0; i < meteoriteCount; i++)
	{
		if (loc.r == meteoriteLoc[i].r && (loc.c == meteoriteLoc[i].c || loc.c == meteoriteLoc[i].c + 1))
		{
			MeteoriteDestroy(meteoriteLoc[i], board);
			DeleteElement(meteoriteLoc, meteoriteCount, i);
			return 1;
		}
	}
	return 0;
}

void BulletHit(position bullets[], int &bulletCount, position meteoriteLoc[], int &meteoriteCount, CHAR_INFO board[], unsigned long score)
{
	for (int i = 0; i < bulletCount; i++)
	{
		if (CollideWithMeteor(bullets[i], meteoriteLoc, meteoriteCount, board))
		{
			score++;
			UpdateScore(score);
			DeleteElement(bullets, bulletCount, i);
		}
	}
}

void PlayerHit(position playerPosition, position meteoriteLoc[], int &meteoriteCount, int &gameOver, CHAR_INFO board[])
{
	if (CollideWithMeteor(playerPosition, meteoriteLoc, meteoriteCount, board))
		GameOver(gameOver);
	else
	{
		playerPosition.r++;
		if (CollideWithMeteor(playerPosition, meteoriteLoc, meteoriteCount, board))
			GameOver(gameOver);
		else
		{
			playerPosition.c++;
			if (CollideWithMeteor(playerPosition, meteoriteLoc, meteoriteCount, board))
				GameOver(gameOver);
			else
			{
				playerPosition.c-=2;
				if (CollideWithMeteor(playerPosition, meteoriteLoc, meteoriteCount, board))
					GameOver(gameOver);
			}
		}
	}
}