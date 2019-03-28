#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include "console.h"
#include "gameSetting.h"
#include "draw.h"
#include "file.h"
#include <iostream>
using namespace std;

//Update score on console
//Cập nhật điểm lên console
void UpdateScore(unsigned long score);
//Cập nhật hp của người chơi lên console
void UpdateHP(int hp);
//Pause game and show Pause Menu
//Tạm dừng và hiện menu tạm dừng
void PauseGame(int &pause);
//Enable user choose to continue or exit game
//CHo phép người chơi chọn tiếp tục hay thoát game
void PauseMenu(int &pause, int &curSelection);
//Delete an Element in aray in specific index
//Xóa phần tử trong mảng ở vị trí chỉ định
void DeleteElement(position a[], int &n, int vt);
//Show the gameover menu
//Hiện menu gameover
void GameOver(unsigned long score);
//Enable player choose to try again or exit
//Cho phép người chơi chơi lại hoặc thoát
void GameOverMenu();

#endif