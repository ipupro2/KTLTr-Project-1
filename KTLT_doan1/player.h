#ifndef PLAYER_H
#define PLAYER_H

#include "draw.h"

//Vẽ người chơi tại vị trí pos, direction là hướng di chuyển của người chơi, ' ' là đứng yên
void DrawPlayer(position pos, char direction = ' ');
//Hàm di chuyển người chơi bằng các phím mũi tên
void PlayerMove(position &playerPos);

#endif // !PLAYER_H
