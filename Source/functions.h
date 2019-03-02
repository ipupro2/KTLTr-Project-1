#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
using namespace std;

//ASCII code
#define square (char)220
#define rect (char)219
#define bullet '*'

#define creditText "  Trieu Truc Thuy Trinh Tien"
#define width 100
#define height 30
#define delayTime 1000000
#define maxHorizontalSpeed 3 //Number of calls is skipped when move up down

struct location
{
	int r;//row
	int c;//column
};

void HideCursor();//Hide blinking color in console
void GotoPosition(int r, int c);//Move cursor to specified location
void GameCore(char board[height][width], location curLoc);//Core processing for game
void InitializeBoard(char board[height][width], location curLocation);//Initialize starting data for game
void DrawBoard(char board[height][width]);//Draw the board when begin game
void DrawPlayer(location loc, char direction);//Draw player with the gun in specified location and the body in below
void Shoot(location loc, char board[height][width], location bullets[], int bulletCount);//Create a bullet(*) in top of player
void BulletControl(location bullets[], int &bulletCount);//Move bullets up or destroy enemy or disappear
void DeleteElement(location a[], int &n, int vt);//Delete a Element in aray in specific index
void playerMove(location &curLoc);//Move player in 4 directions