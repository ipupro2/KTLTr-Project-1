#ifndef DRAW_H
#define DRAW_H

#include "gameSetting.h"
#include "console.h"
#include <iostream>
using namespace std;

//Initialize data for the screen when begin game
//Khởi tạo giá trị cho màn hình khi bắt đầu game(Load dữ liệu từ file bên ngoài và vẽ ra màn hình)
void Intro();
void InitializeGame();
//Redraw the screen
//Vẽ lại màn hình(Sau khi đã cập nhật đầy đủ dữ liệu và biến screen), hàm này được gọi cuối cùng trong xử lí chính
void RedrawBoard();
//Change the code(character) and the color of screen element 
//Đặt giá trị cho biến screen, có thể xem như mảng 2 chiều, thay đổi vị trí cột và hàng của mảng code: giá trị, color: màu,
//Lưu ý: Màu ở đây bao gồm cả màu nền và màu chữ, công thức tính color = màu chữ + màu nền * 16
void SetBoardValue(int row, int column, int code = ' ', int color = 15);
void FlashScreen();

#endif // !DRAW_H