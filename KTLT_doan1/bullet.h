#ifndef BULLET_H
#define BULLET_H

#include "boss.h"
#include "meteorite.h"
#include "player.h"
#include "plane.h"
//gameObject.cpp
//Create a bullet in specified position
//Tạo viên đạn ở vị trí chỉ định
void Shoot(position pos, position playerBullets[], int &playerBulletCount, char bullet);

//Move playerBullets up or destroy enemy or disappear
//Điều khiển viên đạn, di chuyển lên hoặc xuống(direction là U hoặc D), biến bullet là hình dạng của đạn ví dụ ^ hoặc |
void BulletControl(position bullets[], int &bulletCount, char direction, char bullet);

//////////////////////////////////////////////////////////////////////////////////////////

//physic.cpp
//Check if bullet hit other object, and  call DestroyObject function
//Kiểm tra nếu đạn va chạm các vật khác và gọi hàm phá hủy nếu cần
void HitMeteorite(position playerBullets[], int &playerBulletCount, position meteoritePos[], int &meteoriteCount, unsigned long score);
//If Player hit an object, game will over
//Kiểm tra người chơi có va chạm vật gì không
void HitPlayer(position playerPosition, position meteoritePos[], int &meteoriteCount, position enemyBullets[],
	int &enemyBulletCount, int &playerHP);
//Kiểm tra trùm có trúng đạn không
void HitBoss(position bullets[], int &bulletCount, position bossPosition, int &bossHP, unsigned long &score);
void BulletHitPlane(position playerBullets[], int &playerBulletCount, position planePos[],
	int &planeCount, unsigned long &score);

#endif