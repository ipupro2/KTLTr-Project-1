#include "functions.h"

void GameCore(char board[height][width], location curLoc)
{
	char c;
	int count = 0, bulletCount = 0;
	location bullets[20];
	HideCursor();
	short horizontalSpeed = 0;//Due to the lineheight of console, we must reduce the speed when player move up down

	while (1)
	{
		count++;
		if (count % (delayTime/5) == 0)
		{
			BulletControl(bullets, bulletCount);
		}
		if (count % delayTime == 0)
		{
			playerMove(curLoc);
			count = 0;
			Shoot(curLoc, board, bullets, bulletCount);
			bulletCount++;
		}
	}
}