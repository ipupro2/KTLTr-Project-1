#include "functions.h"

void Shoot(position loc, position bullets[], int bulletCount, CHAR_INFO board[]) {
	SetBoardValue(board, loc.r, loc.c, '^');
	SetBoardValue(board, loc.r - 1, loc.c, '^');
	position _bullet;
	_bullet.r = loc.r - 1;
	_bullet.c = loc.c;
	bullets[bulletCount] = _bullet;
}

void BulletControl(position bullets[], int &bulletCount, CHAR_INFO board[]) {
	for (int i = 0; i < bulletCount; i++)
	{
		if (bullets[i].r == 0)
		{
			SetBoardValue(board, bullets[i].r, bullets[i].c);
			DeleteElement(bullets, bulletCount, i);
			i--;
		}
		else
		{
			SetBoardValue(board, bullets[i].r, bullets[i].c);
			SetBoardValue(board, bullets[i].r - 1, bullets[i].c, '^');
			bullets[i].r--;
		}
	}
}