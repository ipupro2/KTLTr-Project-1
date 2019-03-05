#include "functions.h"

void GameCore(position curLoc)
{
	//Initialize data for new Game
	int /*count = 0,*/ bulletCount = 0, meteoriteCount = 0, pause = 0, curSelection = 1, gameOver = 0, count = 0;
	short verticalSpeed = 0;//Due to the lineheight of console, we must reduce the speed when player move up down
	unsigned long score = 0, start, sleepTime;
	position bullets[100], meteoriteLoc[100];//Positions of bullets, meteorites in the game
	HideCursor();
	InitializeBoard();
	DrawPlayer(curLoc, 'D');

	//Core processing
	while (!gameOver)
	{
		if (!pause)
		{
			count++;
			start = GetTickCount();
			if (count % 8 == 0)
			{
				CreateNewMeteorite(meteoriteLoc, meteoriteCount);
			}
			if (count % 4 == 0)
			{
				Shoot(curLoc, bullets, bulletCount);
				bulletCount++;
			}
			if (count % 2 == 0)
			{
				BulletControl(bullets, bulletCount);
				BulletHit(bullets, bulletCount, meteoriteLoc, meteoriteCount);
				MeteoriteControl(score, meteoriteLoc, meteoriteCount);
				PlayerHit(curLoc, meteoriteLoc, meteoriteCount, gameOver);
			}
			PlayerMove(curLoc);
			if (!gameOver)
			{
				sleepTime = delayTime - GetTickCount() + start;
				if (sleepTime < 0)
				{
					GotoPosition(height / 2, width / 2 + 3);
					cout << "ERROR WITH SLEEP";
				}
				Sleep(sleepTime);
			}
			PauseGame(pause);
		}
		else
		{
			PauseMenu(pause, curSelection);
		}
	}
}