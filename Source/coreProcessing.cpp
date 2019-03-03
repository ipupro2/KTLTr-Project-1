#include "functions.h"

void GameCore(position curLoc)
{
	//Initialize data for new Game
	int count = 0, bulletCount = 0, meteoriteCount = 0, pause = 0, curSelection = 1, gameOver = 0;
	short verticalSpeed = 0;//Due to the lineheight of console, we must reduce the speed when player move up down
	unsigned long score = 0;
	position bullets[20], meteoriteLoc[20];//Positions of bullets, meteorites in the game
	HideCursor();
	InitializeBoard();
	DrawPlayer(curLoc, 'D');

	//Core processing
	while (!gameOver)
	{
		if (!pause)
		{
			count++;
			if (count % (delayTime / 200) == 0)
			{
				BulletControl(bullets, bulletCount);
				BulletHit(bullets, bulletCount, meteoriteLoc, meteoriteCount);
			}
			if (count % (delayTime / 100) == 0)
			{
				PlayerMove(curLoc);
				Shoot(curLoc, bullets, bulletCount);
				bulletCount++;
			}
			if (count % (delayTime / 40) == 0)
			{
				MeteoriteControl(score, meteoriteLoc, meteoriteCount);
				PlayerHit(curLoc, meteoriteLoc, meteoriteCount,gameOver);
			}
			if (count% (delayTime/10) == 0)
			{
				count = 0;
				CreateNewMeteorite(meteoriteLoc, meteoriteCount);
			}
			PauseGame(pause);
		}
		else
		{
			PauseMenu(pause, curSelection);
		}
	}
}