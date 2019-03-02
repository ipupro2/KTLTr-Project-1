#include "functions.h"

void GameCore(char board[height][width], location curLoc)
{
	int count = 0, bulletCount = 0;
	location bullets[20];
	HideCursor();
	short horizontalSpeed = 0;//Due to the lineheight of console, we must reduce the speed when player move up down
	CreateNewMeteorite();
	while (1)
	{
		count++;
		if (count % (delayTime/200) == 0)
		{
			BulletControl(bullets, bulletCount);
		}
		if (count % (delayTime/100) == 0)
		{
			PlayerMove(curLoc);
			Shoot(curLoc, board, bullets, bulletCount);
			bulletCount++;
		}
		if (count % (delayTime / 40) == 0)
			MeteoriteControl();
		if (count%delayTime==0)
		{
			count = 0;
			CreateNewMeteorite();
		}
	}
}