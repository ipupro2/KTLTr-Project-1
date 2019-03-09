#include "functions.h"

void GameCore(position curLoc)
{
	//Initialize data for new Game
	int /*count = 0,*/ bulletCount = 0, meteoriteCount = 0, pause = 0, curSelection = 1, gameOver = 0, count = 0;
	short verticalSpeed = 0;//Due to the lineheight of console, we must reduce the speed when player move up down
	unsigned long score = 0, start, sleepTime;
	DWORD lastedTime = 0, deltaTime, lastTime = GetTickCount(), now;
	position bullets[100], meteoriteLoc[100];//Positions of bullets, meteorites in the game
	HideCursor();
	InitializeBoard();
	DrawPlayer(curLoc, 'D');

	//Core processing
	while (!gameOver)
	{
		if (!pause)
		{
			now = GetTickCount();
			deltaTime = 1.0*(now - lastTime);
			lastedTime += deltaTime;
			lastTime = now;
			if (lastedTime > fixedTime)
			{
				lastedTime -= fixedTime;
				count++;
				if (count % 20 == 0)
					CreateNewMeteorite(meteoriteLoc, meteoriteCount);
				Shoot(curLoc, bullets, bulletCount);
				bulletCount++;
				BulletControl(bullets, bulletCount);
				BulletHit(bullets, bulletCount, meteoriteLoc, meteoriteCount);
				MeteoriteControl(score, meteoriteLoc, meteoriteCount);
				PlayerHit(curLoc, meteoriteLoc, meteoriteCount, gameOver);
				PlayerMove(curLoc);
				PauseGame(pause);
			}
			while (lastedTime > fixedTime)
			{
				lastedTime -= fixedTime;
			}
		}
		else
		{
			PauseMenu(pause, curSelection);
		}
	}
}