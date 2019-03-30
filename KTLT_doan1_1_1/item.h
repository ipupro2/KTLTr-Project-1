#ifndef ITEM_H
#define ITEM_H

#include "gameSetting.h"
#include "draw.h"

//Items
void CreatePowerUp(position &pos);
void DrawPowerUp(position pos);
void MovePowerUp(position &pos, position playerPos, int &shootingDelay);

#endif