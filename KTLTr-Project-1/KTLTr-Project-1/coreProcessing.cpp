#include "functions.h"

void GameCore(char board[height][width], location curLoc)
{
	char c;
	int count = 0, bulletCount = 0;
	location bullets[1000];
	HideCursor();
	while (1)
	{
		if (kbhit())//Check if player input anything
		{
			c = getch();
			if (c == -32)//Get input character
				c = getch();
			switch (int(c))
			{
				case 75://left
					if (curLoc.c > 1)
					{
						curLoc.c--;
						DrawPlayer(curLoc, 'L');
					}
					break;
				case 77://right
					if (curLoc.c < width-1)
					{
						curLoc.c++;
						DrawPlayer(curLoc, 'R');
					}
					break;
				case 72://up
					if (curLoc.r > 1)
					{
						curLoc.r--;
						DrawPlayer(curLoc, 'U');
					}
					break;
				case 80://down
					if (curLoc.r < height-2)
					{
						curLoc.r++;
						DrawPlayer(curLoc, 'D');
					}
					break;
			}
		}
		count++;
		if (count % (shootingDelay/4) == 0)
		{
			BulletControl(bullets, bulletCount);
		}
		if (count == shootingDelay)
		{
			count = 0;
			Shoot(curLoc, board, bullets, bulletCount);
			bulletCount++;
		}
	}
}