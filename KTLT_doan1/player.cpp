#include "player.h"

static int upSpeed = 0;
static int downSpeed = 0;

void DrawPlayer(position pos, char direction)
{
	SetBoardValue(pos.r, pos.c, '^');
	SetBoardValue(pos.r + 1, pos.c, '=');
	SetBoardValue(pos.r + 1, pos.c - 1, '|');
	SetBoardValue(pos.r + 1, pos.c - 2, '<');
	SetBoardValue(pos.r + 1, pos.c + 1, '|');
	SetBoardValue(pos.r + 1, pos.c + 2, '>');
	switch (direction)
	{
		case 'L':
		{
			SetBoardValue(pos.r, pos.c + 1, ' ');
			SetBoardValue(pos.r + 1, pos.c + 3, ' ');
			break;
		}
		case 'R':
		{
			SetBoardValue(pos.r, pos.c - 1, ' ');
			SetBoardValue(pos.r + 1, pos.c - 3, ' ');
			break;
		}
		case 'U':
		{
			SetBoardValue(pos.r + 2, pos.c, ' ');
			SetBoardValue(pos.r + 2, pos.c - 1, ' ');
			SetBoardValue(pos.r + 2, pos.c - 2, ' ');
			SetBoardValue(pos.r + 2, pos.c + 1, ' ');
			SetBoardValue(pos.r + 2, pos.c + 2, ' ');
			break;
		}
		case 'D':
		{
			SetBoardValue(pos.r - 1, pos.c, ' ');
			SetBoardValue(pos.r, pos.c - 1, ' ');
			SetBoardValue(pos.r, pos.c - 2, ' ');
			SetBoardValue(pos.r, pos.c + 1, ' ');
			SetBoardValue(pos.r, pos.c + 2, ' ');
			break;
		}
	}
}

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