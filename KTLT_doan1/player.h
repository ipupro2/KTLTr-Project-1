#ifndef PLAYER_H
#define PLAYER_H

#include "draw.h"

void DrawPlayer(position pos, char direction = ' ');
//Hàm di chuyển người chơi bằng các phím mũi tên
void PlayerMove(position &playerPos);

#endif // !PLAYER_H
