#include "functions.h"

int upSpeed = 0;
int downSpeed = 0;

void PlayerMove(position &curLoc, CHAR_INFO board[])
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (curLoc.c > 2)
		{
			curLoc.c--;
			DrawPlayer(curLoc, 'L', board);
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (curLoc.c < width - 3)
		{
			curLoc.c++;
			DrawPlayer(curLoc, 'R', board);
		}
	}
	if (GetAsyncKeyState(VK_UP))
	{
		upSpeed++;
		if (curLoc.r > 1 && upSpeed >= maxVerticalSpeed)
		{
			upSpeed = 0;
			curLoc.r--;
			DrawPlayer(curLoc, 'U', board);
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		downSpeed++;
		if (curLoc.r < height - 2 && downSpeed >= maxVerticalSpeed)
		{
			downSpeed = 0;
			curLoc.r++;
			DrawPlayer(curLoc, 'D', board);
		}
	}
}