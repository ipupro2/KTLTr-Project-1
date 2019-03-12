#include "functions.h"

void GameCore(position playerPos)
{
	//Initialize data for new Game
	int playerBulletCount = 0, //Number of player's bullets in game
		enemyBulletCount = 0, //Number of enemies's bullets in game
		meteoriteCount = 0,  // Number of meteorites in game
		pause = 0, //The game will be pause if this variable is 1
		curSelection = 1,//Current Selection in Pause Menu
		gameOver = 0, //This variable will be 1 if game over
		count = 0, //If count reachs certain value, some events will be triggered
		bossHP = 0;//Boss Health Point
	unsigned long score = 0;//Score which player have achieved
	DWORD lastedTime = 0,//Lasted time since the last time call function, this is used for timing
		deltaTime,//This is time between 2 timing events
		lastTime = GetTickCount(),//Last time call function
		now;//Current Time
	position playerBullets[100],//Array of Player's bullet positions in game
		enemyBullets[100],//Array of Enemy's bullet position in game
		meteoriteLoc[100],//Array of Meteorite's position in game
		bossPosition;//Positions of Boss in game
	InitializeBoard();
	DrawPlayer(playerPos, 'D');

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
				BulletControl(playerBullets, playerBulletCount, 'U', '^');
				BulletControl(enemyBullets, enemyBulletCount, 'D', '|');
				if (count % 2 == 0)
					Shoot(playerPos, playerBullets, playerBulletCount, '^');
				BulletHit(playerBullets, playerBulletCount, meteoriteLoc, meteoriteCount, score);
				if (count % 4 == 0)
					MeteoriteControl(score, meteoriteLoc, meteoriteCount);
				if (count % 20 == 0)
					CreateNewMeteorite(meteoriteLoc, meteoriteCount);
				PlayerHit(playerPos, meteoriteLoc, meteoriteCount, gameOver);
				if(count%2==0)
					PlayerMove(playerPos);
				if(!gameOver)
					RedrawBoard();
				if (bossHP > 0 && count % 4 == 0)
				{
					BossMovement(playerPos, bossPosition);
					Shoot({ bossPosition.r + 6, bossPosition.c }, enemyBullets, enemyBulletCount, '|');
				}
				if (count % 1000 == 0 && bossHP <= 0)
					CreateBoss(bossHP, bossPosition);
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