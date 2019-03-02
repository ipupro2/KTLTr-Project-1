#include "functions.h"

location meteoriteLoc[20];
int n = 0;

void CreateNewMeteorite()
{
	int x = rand() % width;
	GotoPosition(0, x + 2);
	cout << "\b\b" << rect << rect;
	meteoriteLoc[n].r = 0;
	meteoriteLoc[n].c = x;
	n++;
}

void MeteoriteControl()
{
	for (int i = 0; i < n; i++)
	{
		GotoPosition(meteoriteLoc[i].r, meteoriteLoc[i].c + 2);
		cout << "\b\b  ";
		meteoriteLoc[i].r++;
		if (meteoriteLoc[i].r > height)
		{
			DeleteElement(meteoriteLoc, n, i);
			i--;
		}
		else
		{
			GotoPosition(meteoriteLoc[i].r, meteoriteLoc[i].c + 2);
			cout << "\b\b" << rect << rect;
		}
	}
}