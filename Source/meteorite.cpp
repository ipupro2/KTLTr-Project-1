#include "functions.h"

void CreateNewMeteorite(position meteoriteLoc[], int &meteoriteCount)
{
	int x = rand() % width;
	GotoPosition(0, x + 2);
	cout << "\b\b" << rect << rect;
	meteoriteLoc[meteoriteCount].r = 0;
	meteoriteLoc[meteoriteCount].c = x;
	meteoriteCount++;
}

void MeteoriteControl(unsigned long &score, position meteoriteLoc[], int &meteoriteCount)
{
	for (int i = 0; i < meteoriteCount; i++)
	{
		GotoPosition(meteoriteLoc[i].r, meteoriteLoc[i].c + 2);
		cout << "\b\b  ";
		meteoriteLoc[i].r++;
		if (meteoriteLoc[i].r > height)
		{
			DeleteElement(meteoriteLoc, meteoriteCount, i);
			i--;
			score++;
			UpdateScore(score);
		}
		else
		{
			GotoPosition(meteoriteLoc[i].r, meteoriteLoc[i].c + 2);
			cout << "\b\b" << rect << rect;
		}
	}
}