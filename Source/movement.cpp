#include "functions.h"

int upSpeed = 0;
int downSpeed = 0;

void playerMove(location &curLoc)
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (curLoc.c > 1)
		{
			curLoc.c--;
			DrawPlayer(curLoc, 'L');
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (curLoc.c < width - 1)
		{
			curLoc.c++;
			DrawPlayer(curLoc, 'R');
		}
	}
	if (GetAsyncKeyState(VK_UP))
	{
		upSpeed++;
		if (curLoc.r > 1 && upSpeed >= maxHorizontalSpeed)
		{
			upSpeed = 0;
			curLoc.r--;
			DrawPlayer(curLoc, 'U');
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		downSpeed++;
		if (curLoc.r < height - 2 && downSpeed >= maxHorizontalSpeed)
		{
			downSpeed = 0;
			curLoc.r++;
			DrawPlayer(curLoc, 'D');
		}
	}
}