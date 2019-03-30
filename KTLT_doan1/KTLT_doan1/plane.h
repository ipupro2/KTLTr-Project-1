#ifndef Plane_H
#define Plane_H

#include "gameSetting.h"
#include "draw.h"
#include "functionality.h"
#include "bullet.h"

void DrawPlane(position pos);

//Xoá máy bay.
void DeletePlane(position pos);

//T?o m?ng ch?a v? trí máy bay.
void CreatePlane(position planeLoc[], int &planeCount);
void PlaneShoot(position planeLoc[], int &planeCount, position bullets[], int &bulletCount);
void PlaneComputer(position planeLoc[], int &planeCount);
void PlayerCollidePlan(position Player, position planeLoc[], int &planeCount, int &playerHP);

#endif // !Plane_H
