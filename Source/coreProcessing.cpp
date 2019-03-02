#include "functions.h"

void GameCore(location curLoc)
{
	int count = 0, bulletCount = 0, pause = 0, curSelection = 1;
	unsigned long score = 0;
	location bullets[20];
	HideCursor();
	short horizontalSpeed = 0;//Due to the lineheight of console, we must reduce the speed when player move up down
	DrawPlayer(curLoc, 'D');
	while (1)
	{
		if (!pause)
		{
			count++;
			if (count % (delayTime / 200) == 0)
			{
				BulletControl(bullets, bulletCount);
			}
			if (count % (delayTime / 100) == 0)
			{
				PlayerMove(curLoc);
				Shoot(curLoc, bullets, bulletCount);
				bulletCount++;
			}
			if (count % (delayTime / 40) == 0)
				MeteoriteControl(score);
			if (count%delayTime == 0)
			{
				count = 0;
				CreateNewMeteorite();
			}
			PauseGame(pause);
		}
		else
		{
			PauseMenu(pause, curSelection);
		}
	}
}