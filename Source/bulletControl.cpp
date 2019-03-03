#include "functions.h"

void Shoot(position loc, position bullets[], int bulletCount) {
	GotoPosition(loc.r - 1, loc.c + 1);
	cout << "\b" << bullet;
	position _bullet;
	_bullet.r = loc.r - 1;
	_bullet.c = loc.c;
	bullets[bulletCount] = _bullet;
}

void BulletControl(position bullets[], int &bulletCount) {
	for (int i = 0; i < bulletCount; i++)
	{
		if (bullets[i].r == 0)
		{
			GotoPosition(0, bullets[i].c + 1);
			cout << "\b ";
			DeleteElement(bullets, bulletCount, i);
			i--;
		}
		else
		{
			GotoPosition(bullets[i].r, bullets[i].c + 1);
			cout << "\b ";
			GotoPosition(bullets[i].r - 1, bullets[i].c + 1);
			cout << "\b*";
			bullets[i].r--;
		}
	}
}