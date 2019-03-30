#include "functions.h"

//Vẽ máy bay.
void DrawPlan(position pos)
{
	SetBoardValue(pos.r, pos.c, '=');
	SetBoardValue(pos.r, pos.c + 1, 'X');
	SetBoardValue(pos.r, pos.c + 2, '=');
	SetBoardValue(pos.r + 1, pos.c + 1, 'V');
}
//Xoá máy bay.
void DeletePlan(position pos)
{
	SetBoardValue(pos.r, pos.c, ' ');
	SetBoardValue(pos.r, pos.c + 1, ' ');
	SetBoardValue(pos.r, pos.c + 2, ' ');
	SetBoardValue(pos.r + 1, pos.c + 1, ' ');
}

//Tạo máy bay mới và lưu vào mảng
void CreatePlan(position planLoc[], int &planCount)
{
	planLoc[planCount].r = 1;
	planLoc[planCount].c = 1;
	DrawPlan(planLoc[planCount]);
	planCount++;
}

void PlanShoot(position planLoc[], int &planCount, position bullets[], int &bulletCount)
{
	for (int i = 0; i < planCount; i++)
	{
		Shoot({ planLoc[i].r + 2, planLoc[i].c + 1 }, bullets, bulletCount, '+');
	}
}

void PlanComputer(position planLoc[], int &planCount)
{
	for (int i = 0; i < planCount; i++)
	{
		DeletePlan(planLoc[i]);
		if (planLoc[i].c == 1 && planLoc[i].r < 7)
		{
			planLoc[i].r++;
		}
		else if (planLoc[i].c == boardWidth - 4 && planLoc[i].r > 1)
		{
			planLoc[i].r--;
		}
		else if (planLoc[i].r == 7)
			planLoc[i].c++;
		else
		{
			planLoc[i].c--;
		}
		DrawPlan(planLoc[i]);
	}
}
