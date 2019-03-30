#include "plane.h"

//Vẽ máy bay.
void DrawPlane(position pos)
{
	SetBoardValue(pos.r, pos.c, '=',10);
	SetBoardValue(pos.r, pos.c + 1, 'X',10);
	SetBoardValue(pos.r, pos.c + 2, '=',10);
	SetBoardValue(pos.r + 1, pos.c + 1, 'V',10);
}
//Xoá máy bay.
void DeletePlane(position pos)
{
	SetBoardValue(pos.r, pos.c, ' ');
	SetBoardValue(pos.r, pos.c + 1, ' ');
	SetBoardValue(pos.r, pos.c + 2, ' ');
	SetBoardValue(pos.r + 1, pos.c + 1, ' ');
}

//Tạo máy bay mới và lưu vào mảng
void CreatePlane(position planePos[], int &planeCount)
{
	planePos[planeCount].r = 1;
	planePos[planeCount].c = 1;
	DrawPlane(planePos[planeCount]);
	planeCount++;
}

void PlaneShoot(position planePos[], int &planeCount, position bullets[], int &bulletCount)
{
	for (int i = 0; i < planeCount; i++)
	{
		Shoot({ planePos[i].r + 2, planePos[i].c + 1 }, bullets, bulletCount, '|');
	}
}

void PlaneComputer(position planePos[], int &planeCount)
{
	for (int i = 0; i < planeCount; i++)
	{
		DeletePlane(planePos[i]);
		if (planePos[i].c == 1 && planePos[i].r < 7)
		{
			planePos[i].r++;
		}
		else if (planePos[i].c == boardWidth - 4 && planePos[i].r > 1)
		{
			planePos[i].r--;
		}
		else if (planePos[i].r == 7)
			planePos[i].c++;
		else
		{
			planePos[i].c--;
		}
		DrawPlane(planePos[i]);
	}
}

int CollidePlane(position pos, position posPlane)
{
	if ((pos.r == posPlane.r && (pos.c == posPlane.c || pos.c == posPlane.c + 1 || pos.c == posPlane.c + 2))
		|| (pos.c == posPlane.c + 1 && pos.r == posPlane.r + 1))
	{
		DeletePlane(posPlane);
		return 1;
	}
	return 0;
}
void PlayerCollidePlan(position Player, position planePos[], int &planeCount, int &playerHP)
{

	int r = Player.r;
	int c = Player.c;
	for (int i = 0; i < planeCount; i++)
		if (CollidePlane({ r,c }, planePos[i]) || CollidePlane({ r + 1,c}, planePos[i]) 
			|| CollidePlane({ r + 1,c - 2 }, planePos[i]) || CollidePlane({ r + 1,c - 1 }, planePos[i]) 
			|| CollidePlane({ r + 1,c + 1 }, planePos[i]) || CollidePlane({ r + 1,c + 2 }, planePos[i]))
		{
			DeleteElement(planePos, planeCount, i);
			playerHP -= 5;
			FlashScreen();
		}
}