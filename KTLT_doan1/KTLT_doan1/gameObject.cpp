#include "functions.h"

//Hàm của thiên thạch
void CreateNewMeteorite(position meteoriteLoc[], int &meteoriteCount)
{
	int x = 1 + rand() % (boardWidth - 3);
	SetBoardValue(1, x, ' ', 112);
	SetBoardValue(1, x + 1, ' ', 112);
	meteoriteLoc[meteoriteCount].r = 1;
	meteoriteLoc[meteoriteCount].c = x;
	meteoriteCount++;
}

void MeteoriteControl(unsigned long &score, position meteoriteLoc[], int &meteoriteCount)
{
	for (int i = 0; i < meteoriteCount; i++)
	{
		meteoriteLoc[i].r++;
		if (meteoriteLoc[i].r >= boardHeight - 1)
		{
			score++;
			UpdateScore(score);
			SetBoardValue(meteoriteLoc[i].r - 1, meteoriteLoc[i].c);
			SetBoardValue(meteoriteLoc[i].r - 1, meteoriteLoc[i].c + 1);
			DeleteElement(meteoriteLoc, meteoriteCount, i);
			i--;
		}
		else
		{
			SetBoardValue(meteoriteLoc[i].r, meteoriteLoc[i].c, ' ', 112);
			SetBoardValue(meteoriteLoc[i].r, meteoriteLoc[i].c + 1, ' ', 112);
			SetBoardValue(meteoriteLoc[i].r - 1, meteoriteLoc[i].c);
			SetBoardValue(meteoriteLoc[i].r - 1, meteoriteLoc[i].c + 1);
		}
	}
}

void MeteoriteDestroy(position pos)
{
	SetBoardValue(pos.r, pos.c);
	SetBoardValue(pos.r, pos.c + 1);
}

//Player's Bullets functions
void Shoot(position pos, position bullets[], int &bulletCount, char bullet) {
	SetBoardValue(pos.r, pos.c, bullet);
	SetBoardValue(pos.r, pos.c, bullet);
	bullets[bulletCount] = { pos.r, pos.c };
	bulletCount++;
}

void BulletControl(position bullets[], int &bulletCount, char direction, char bullet) {
	for (int i = 0; i < bulletCount; i++)
	{
		if ((bullets[i].r == 1&&direction=='U') || (bullets[i].r == boardHeight - 2 && direction == 'D'))
		{
			SetBoardValue(bullets[i].r, bullets[i].c);
			DeleteElement(bullets, bulletCount, i);
			i--;
		}
		else
		{
			SetBoardValue(bullets[i].r, bullets[i].c);
			if (direction == 'U')
				bullets[i].r--;
			else
				bullets[i].r++;
			SetBoardValue(bullets[i].r, bullets[i].c, bullet);
		}
	}
}

//Boss Function
void CreateBoss(int &bossHp, position &bossPos)
{
	bossHp = 100;
	bossPos = { 1, boardWidth / 2 };
	DrawBoss(bossPos);
}

void BossMovement(position playerPos, position &bossPos)
{
	if (bossPos.c > playerPos.c)
	{
		bossPos.c--;
		DrawBoss(bossPos);
	}
	else if (bossPos.c < playerPos.c)
	{
		bossPos.c++;
		DrawBoss(bossPos);
	}
}

void DestroyBoss(position bossPos)
{
	int i, j;
	for (i = bossPos.r; i <= bossPos.r + 3; i++)
	{
		for (j = 0; j < 7; j++)
		{
			SetBoardValue(i, bossPos.c - j + i, ' ');
			SetBoardValue(i, bossPos.c + j - i, ' ');
		}
		SetBoardValue(i, bossPos.c - j + i, ' ');
		SetBoardValue(i, bossPos.c + j - i, ' ');
	}
	SetBoardValue(i++, bossPos.c, ' ');
	SetBoardValue(i, bossPos.c, ' ');
}

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

void CreatePowerUp(position &pos)
{
	pos.r = 1;
	pos.c = 1 + rand() % (boardWidth-1);
	DrawPowerUp(pos);
}

void MovePowerUp(position &pos, position playerPos, int &shootingDelay)
{
	pos.r++;
	DrawPowerUp(pos);
	if (pos.r == playerPos.r || (pos.r == playerPos.r + 1 && pos.c >= playerPos.c - 2 && pos.c <= playerPos.c + 2))
	{
		shootingDelay = 4;
		pos = { -1,-1 };
	}
}
