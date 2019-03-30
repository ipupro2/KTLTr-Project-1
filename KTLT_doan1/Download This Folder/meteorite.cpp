#include "functions.h"

void CreateNewMeteorite(position meteoriteLoc[], int &meteoriteCount)
{
	int x = 1 + rand() % (boardWidth - 3);
	SetBoardValue(1, x, ' ', 112);
	SetBoardValue(1, x + 1, ' ', 112);
	meteoriteLoc[meteoriteCount].r = 1;
	meteoriteLoc[meteoriteCount].c = x;
	meteoriteCount++;
}

//Hàm điều khiển thiên thạch bằng cách di chuyển nó xuống, khi nó chạm bên dưới màn hình thì phá hủy nó
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

void MeteoriteDestroy(position pos)//Hàm xóa bỏ thiên thạch khỏi màn hình
{
	SetBoardValue(pos.r, pos.c);
	SetBoardValue(pos.r, pos.c + 1);
}

int CollideWithMeteor(position pos, position meteoriteLoc[], int &meteoriteCount) //Hàm kiểm tra tại vị pos có vật gì va chạm với thiên thạch không
{
	for (int i = 0; i < meteoriteCount; i++)
	{
		if (pos.r == meteoriteLoc[i].r && (pos.c == meteoriteLoc[i].c || pos.c == meteoriteLoc[i].c + 1))
		{
			MeteoriteDestroy(meteoriteLoc[i]);
			DeleteElement(meteoriteLoc, meteoriteCount, i);
			return 1;
		}
	}
	return 0;
}