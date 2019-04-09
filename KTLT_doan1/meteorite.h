#ifndef METEORITE_H
#define METEORITE_H

#include "functionality.h"

//Tạo thiên thạch mới ở phía trên màn hình
void CreateNewMeteorite(position meteoritePos[], int &meteoriteCount);

//Di chuyển thiên thạch xuống và phá hủy nó nếu cần
void MeteoriteControl(position meteoritePos[], int &meteoriteCount);

//Kiểm tra va chạm với thiên thạch ở vị trí pos
int CollideWithMeteor(position pos, position meteoritePos[], int &meteoriteCount);

#endif