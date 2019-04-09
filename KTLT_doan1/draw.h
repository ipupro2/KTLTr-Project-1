#ifndef DRAW_H
#define DRAW_H

#include "console.h"
#include <iostream>
using namespace std;

//Định nghĩa vị trí cho các vật thể trong game
struct position
{
	int r;//row
	int c;//column
};

#define boardWidth 100
#define boardHeight 30
#define screenWidth 120
#define screenHeight 30
#define maxVerticalSpeed 1 //Thời gian chờ khi di chuyển lên xuống

//Vẽ lại màn hình từ file bên ngoài
void DrawScreenFromFile(string stringPath);

//Vẽ lại màn hình(Sau khi đã cập nhật đầy đủ dữ liệu và biến screen), hàm này được gọi cuối cùng trong xử lí chính
void RedrawBoard();

//Đặt giá trị cho biến screen, có thể xem như mảng 2 chiều, thay đổi vị trí cột và hàng của mảng code: giá trị, color: màu,
//Lưu ý: Màu ở đây bao gồm cả màu nền và màu chữ, công thức tính color = màu chữ + màu nền * 16
void SetBoardValue(int row, int column, char code = ' ', int color = 15);
void FlashScreen();

#endif // !DRAW_H