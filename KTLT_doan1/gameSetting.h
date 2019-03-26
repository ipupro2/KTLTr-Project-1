#ifndef GAMESETTING_H
#define	GAMESETTING_H

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
#define fixedTime 15//Thời gian chờ để cập nhật lại game tính theo ms

#endif !GAMESETTING_H