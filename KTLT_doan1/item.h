#ifndef ITEM_H
#define ITEM_H

#include "draw.h"

//Items
void DrawItem(position pos, char character);
void CreatePowerUp(position &pos);
void MovePowerUp(position &pos);
void PlayerCollidePowerUp(position &pos, position playerPos, int &powerUpRemainTime);
void CreateHP(position &pos);
void MoveHP(position &pos);
void PlayerCollideHP(position &pos, position playerPos, int &hp);

#endif