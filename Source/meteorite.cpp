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
		meteoriteLoc[i].r++;
		if (meteoriteLoc[i].r > height)
		{
			score++;
			UpdateScore(score);
			if (meteoriteLoc[i].r == height + 1)
			{
				GotoPosition(meteoriteLoc[i].r - 2, meteoriteLoc[i].c + 2);
				cout << "\b\b  ";
				GotoPosition(meteoriteLoc[i].r - 3, meteoriteLoc[i].c + 2);
				cout << "\b\b  ";
				GotoPosition(meteoriteLoc[i].r - 1, meteoriteLoc[i].c + 2);
				cout << "\b\b||";
			}
			else
			{
				GotoPosition(meteoriteLoc[i].r - 2, meteoriteLoc[i].c + 2);
				DeleteElement(meteoriteLoc, meteoriteCount, i);
				cout << "\b\b  ";
				i--;
			}
		}
		else
		{
			GotoPosition(meteoriteLoc[i].r - 3, meteoriteLoc[i].c + 2);
			cout << "\b\b  ";
			GotoPosition(meteoriteLoc[i].r - 1, meteoriteLoc[i].c + 2);
			cout << "\b\b||";
			GotoPosition(meteoriteLoc[i].r, meteoriteLoc[i].c + 2);
			cout << "\b\b" << rect << rect;
		}
	}
}