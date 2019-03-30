﻿#ifndef BOSS_H
#define BOSS_H

#include "draw.h"

//Tạo trùm ở phía trên màn hình
void CreateBoss(int &bossHp, int &maxBossHP, position &bossPos);
//Boss di chuyển đến người chơi(chỉ qua trái và phải)
void BossMovement(position playerPos, position &bossPos);
//Tạo thiên thạch mới ở vị trí ngẫu nhiên(ở phía trên màn hình)
void DrawBoss(position bossPos);
//Phá hủy trùm khi máu nó  = 0
void DestroyBoss(position bossPos);
//Draw Boss at specified position
//Vẽ Boss ở vị tríchỉ định
void DrawBoss(position bossPos);

#endif // !BOSS_H