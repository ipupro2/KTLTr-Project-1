#include "functions.h"

void GameCore(position curLoc)
{
	//Initialize data for new Game
	CHAR_INFO board[10000];
	SMALL_RECT rect;
	int bulletCount = 0, meteoriteCount = 0, pause = 0, curSelection = 1, gameOver = 0, count = 0;
	short verticalSpeed = 0;//Due to the lineheight of console, we must reduce the speed when player move up down
	unsigned long score = 0;
	DWORD lastedTime = 0, deltaTime, lastTime = GetTickCount(), now;
	position bullets[100], meteoriteLoc[100];//Positions of bullets, meteorites in the game
	InitializeBoard(board, rect);
	DrawPlayer(curLoc, 'D', board);

	//Core processing
	while (!gameOver)
	{
		if (!pause)
		{
			now = GetTickCount();
			deltaTime = now - lastTime;
			lastedTime += deltaTime;
			lastTime = now;
			if (lastedTime > fixedTime)
			{
				lastedTime -= fixedTime;
				count++;
				BulletControl(bullets, bulletCount, board);
				if (count % 2 == 0)
				{
					Shoot(curLoc, bullets, bulletCount, board);
					bulletCount++;
				}
				BulletHit(bullets, bulletCount, meteoriteLoc, meteoriteCount, board, score);
				if (count % 5 == 0)
					MeteoriteControl(score, meteoriteLoc, meteoriteCount, board);
				if (count % 20 == 0)
					CreateNewMeteorite(meteoriteLoc, meteoriteCount, board);
				PlayerHit(curLoc, meteoriteLoc, meteoriteCount, gameOver, board);
				if(count%2==0)
					PlayerMove(curLoc, board);
				if(!gameOver)
					RedrawBoard(board);
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