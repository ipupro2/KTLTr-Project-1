#include "functions.h"
#include <fstream>
#include <Windows.h>

//Vẽ người chơi, từ vị trí vẽ súng, bên dưới là thân, 
//biến direction dùng để định nghĩa hướng di chuyển(Hàm này đồng thời di chuyển người chơi)
void DrawPlayer(position pos, char direction = ' ');
//Redraw the screen
//Vẽ lại màn hình(Sau khi đã cập nhật đầy đủ dữ liệu và biến screen), hàm này được gọi cuối cùng trong xử lí chính
void RedrawBoard();
//Draw Boss at specified position
//Vẽ Boss ở vị tríchỉ định
void DrawBoss(position bossPos);
//Change the code(character) and the color of screen element 
//Đặt giá trị cho biến screen, có thể xem như mảng 2 chiều, thay đổi vị trí cột và hàng của mảng code: giá trị, color: màu,
//Lưu ý: Màu ở đây bao gồm cả màu nền và màu chữ, công thức tính color = màu chữ + màu nền * 16
void SetBoardValue(int row, int column, int code = ' ', int color = 15);
void FlashScreen();