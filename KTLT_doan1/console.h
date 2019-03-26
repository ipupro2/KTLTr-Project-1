#ifndef CONSOLE_H
#define CONSOLE_H

#include <Windows.h>
//Hide blinking cursor in console
//Ẩn con trỏ nhấp nháy trong màn hình console
void HideCursor();
//Move cursor to specified position
//Di chuyển con trỏ đến vị trí chỉ định (r: dòng, c: cột)
void GotoPosition(int r, int c);

#endif // !CONSOLE_H