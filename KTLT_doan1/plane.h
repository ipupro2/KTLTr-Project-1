#ifndef Plane_H
#define Plane_H

#include "bullet.h"

void DrawPlane(position pos);

//Xoá máy bay.
void DeletePlane(position pos);

//Tạo một máy bay mới và thêm nó vào mảng 
void CreatePlane(position planePos[], int &planeCount);

//Bắn các viết đạn từ súng của máy bay địch
void PlaneShoot(position planePos[], int &planeCount, position bullets[], int &bulletCount);

//Các xử lí tính toán của máy bay
void PlaneComputer(position planePos[], int &planeCount);

//Kiểm tra va chạm giữa người chơi và máy bay địch
void PlayerCollidePlane(position Player, position planePos[], int &planeCount, int &playerHP);

#endif // !Plane_H
