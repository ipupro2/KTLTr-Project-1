#include "meteorite.h"

void CreateNewMeteorite(position meteoritePos[], int &meteoriteCount)
{
	int x = 1 + rand() % (boardWidth - 3);
	SetBoardValue(1, x, ' ', 128);
	SetBoardValue(1, x + 1, ' ', 128);
	meteoritePos[meteoriteCount].r = 1;
	meteoritePos[meteoriteCount].c = x;
	meteoriteCount++;
}

//Hàm điều khiển thiên thạch bằng cách di chuyển nó xuống, khi nó chạm bên dưới màn hình thì phá hủy nó
void MeteoriteControl(position meteoritePos[], int &meteoriteCount)
{
	for (int i = 0; i < meteoriteCount; i++)
	{
		meteoritePos[i].r++;
		if (meteoritePos[i].r >= boardHeight - 1)
		{
			SetBoardValue(meteoritePos[i].r - 1, meteoritePos[i].c);
			SetBoardValue(meteoritePos[i].r - 1, meteoritePos[i].c + 1);
			DeleteElement(meteoritePos, meteoriteCount, i);
			i--;
		}
		else
		{
			SetBoardValue(meteoritePos[i].r, meteoritePos[i].c, ' ', 128);
			SetBoardValue(meteoritePos[i].r, meteoritePos[i].c + 1, ' ', 128);
			SetBoardValue(meteoritePos[i].r - 1, meteoritePos[i].c);
			SetBoardValue(meteoritePos[i].r - 1, meteoritePos[i].c + 1);
		}
	}
}

void MeteoriteDestroy(position pos)//Hàm xóa bỏ thiên thạch khỏi màn hình
{
	SetBoardValue(pos.r, pos.c);
	SetBoardValue(pos.r, pos.c + 1);
}

int CollideWithMeteor(position pos, position meteoritePos[], int &meteoriteCount) //Hàm kiểm tra tại vị pos có vật gì va chạm với thiên thạch không
{
	for (int i = 0; i < meteoriteCount; i++)
	{
		if (pos.r == meteoritePos[i].r && (pos.c == meteoritePos[i].c || pos.c == meteoritePos[i].c + 1))
		{
			MeteoriteDestroy(meteoritePos[i]);
			DeleteElement(meteoritePos, meteoriteCount, i);
			return 1;
		}
	}
	return 0;
}