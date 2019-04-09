#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <Windows.h>
#include <ctime>
#include "plane.h"
#include "item.h"
#include "bullet.h"
using namespace std;

#define fixedTime 15//Thời gian chờ để cập nhật lại game tính theo ms

//Xử lí chính cho game
void GameCore();

#endif // !FUNCTIONS_H
