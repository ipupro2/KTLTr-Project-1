#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include "draw.h"
#include "file.h"

//Các xử lí khi mới vào game
void Intro();

//Các xử lí trong menu chính
void MainMenu();

//Cập nhật điểm lên console
void UpdateScore(unsigned long score);

//Cập nhật hp của người chơi lên console
void UpdateHP(int hp);

//Tạm dừng và hiện menu tạm dừng
void PauseGame(int &pause);

//CHo phép người chơi chọn tiếp tục hay thoát game
void PauseMenu(int &pause, int &curSelection, int &gameOver);

//Xóa phần tử trong mảng ở vị trí chỉ định
void DeleteElement(position a[], int &n, int vt);

//Hiện menu gameover
void GameOver(unsigned long score);

//Cho phép người chơi chơi lại hoặc thoát về main menu, hàm trả về 1 nếu quay về main menu và 0 nếu chơi lại
int GameOverMenu();

//Tạo một máy bay bay xuyên qua màn hình(Hiệu ứng đầu game)
void PlaneThroughScreen();

#endif