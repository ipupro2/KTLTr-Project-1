#ifndef METEORITE_H
#define METEORITE_H

#include "functionality.h"

//Tạo thiên thạch mới ở phía trên màn hình
void CreateNewMeteorite(position meteoritePos[], int &meteoriteCount);
//Move the meteorite down and destroy if necessary
//Di chuyển thiên thạch xuống và phá hủy nó nếu cần
void MeteoriteControl(unsigned long &score, position meteoritePos[], int &meteoriteCount);
int CollideWithMeteor(position pos, position meteoritePos[], int &meteoriteCount);

#endif