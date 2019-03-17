#include "functions.h"
//COMPOSED BY TRUC
static int upSpeed = 0;
static int downSpeed = 0;

void PlayerMove(position &playerPos)
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (playerPos.c > 3)
		{
			playerPos.c--;
			DrawPlayer(playerPos, 'L');
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (playerPos.c < boardWidth - 4)
		{
			playerPos.c++;
			DrawPlayer(playerPos, 'R');
		}
	}
	if (GetAsyncKeyState(VK_UP))
	{
		upSpeed++;
		if (playerPos.r > 2 && upSpeed >= maxVerticalSpeed)
		{
			upSpeed = 0;
			playerPos.r--;
			DrawPlayer(playerPos, 'U');
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		downSpeed++;
		if (playerPos.r < boardHeight - 3 && downSpeed >= maxVerticalSpeed)
		{ 
			downSpeed = 0;
			playerPos.r++;
			DrawPlayer(playerPos, 'D');
		}
	}
}