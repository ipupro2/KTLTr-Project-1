#ifndef Plane_H
#define Plane_H

#include "bullet.h"

void DrawPlane(position pos);

//Xoá máy bay.
void DeletePlane(position pos);

//T?o m?ng ch?a v? trí máy bay.
void CreatePlane(position planePos[], int &planeCount);
void PlaneShoot(position planePos[], int &planeCount, position bullets[], int &bulletCount);
void PlaneComputer(position planePos[], int &planeCount);
void PlayerCollidePlane(position Player, position planePos[], int &planeCount, int &playerHP);

#endif // !Plane_H
