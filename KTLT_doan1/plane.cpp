#include "plane.h"

//Vẽ máy bay.
void DrawPlane(position pos)
{
	SetBoardValue(pos.r, pos.c, '=');
	SetBoardValue(pos.r, pos.c + 1, 'X');
	SetBoardValue(pos.r, pos.c + 2, '=');
	SetBoardValue(pos.r + 1, pos.c + 1, 'V');
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
void CreatePlane(position planeLoc[], int &planeCount)
{
	planeLoc[planeCount].r = 1;
	planeLoc[planeCount].c = 1;
	DrawPlane(planeLoc[planeCount]);
	planeCount++;
}

void PlaneShoot(position planeLoc[], int &planeCount, position bullets[], int &bulletCount)
{
	for (int i = 0; i < planeCount; i++)
	{
		Shoot({ planeLoc[i].r + 2, planeLoc[i].c + 1 }, bullets, bulletCount, '+');
	}
}

void PlaneComputer(position planeLoc[], int &planeCount)
{
	for (int i = 0; i < planeCount; i++)
	{
		DeletePlane(planeLoc[i]);
		if (planeLoc[i].c == 1 && planeLoc[i].r < 7)
		{
			planeLoc[i].r++;
		}
		else if (planeLoc[i].c == boardWidth - 4 && planeLoc[i].r > 1)
		{
			planeLoc[i].r--;
		}
		else if (planeLoc[i].r == 7)
			planeLoc[i].c++;
		else
		{
			planeLoc[i].c--;
		}
		DrawPlane(planeLoc[i]);
	}
}
