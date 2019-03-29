#ifndef METEORITE_H
#define METEORITE_H

#include "draw.h"
#include "functionality.h"

//Tạo thiên thạch mới ở phía trên màn hình
void CreateNewMeteorite(position meteoriteLoc[], int &meteoriteCount);
//Move the meteorite down and destroy if necessary
//Di chuyển thiên thạch xuống và phá hủy nó nếu cần
void MeteoriteControl(unsigned long &score, position meteoriteLoc[], int &meteoriteCount);
int CollideWithMeteor(position pos, position meteoriteLoc[], int &meteoriteCount);

#endif