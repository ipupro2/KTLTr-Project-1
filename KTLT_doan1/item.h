#ifndef ITEM_H
#define ITEM_H

#include "draw.h"

//Vẽ item có kí hiệu là character ở vị trí pos
void DrawItem(position pos, char character);

//Tạo một power up ở vị trí pos
void CreatePowerUp(position &pos);

//Di chuyển Power Up xuống bên dưới
void MovePowerUp(position &pos);

//Kiểm tra va chạm giữa người chơi và Power Up
void PlayerCollidePowerUp(position &pos, position playerPos, int &powerUpRemainTime);

//Tạo một HP mới ở vị trí pos
void CreateHP(position &pos);

//Di chuyển HP xuống bên dưới
void MoveHP(position &pos);

//Kiểm tra va chạm giữa người chơi và HP
void PlayerCollideHP(position &pos, position playerPos, int &hp);

#endif