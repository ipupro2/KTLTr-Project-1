#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

//ASCII code
#define square (char)220
#define rect (char)219
#define bullet '*'

#define creditText "  Trieu Truc Thuy Trinh Tien"
#define width 100
#define height 29
#define delayTime 100000000
#define maxHorizontalSpeed 1 //Number of calls is skipped when move up down

struct location
{
	int r;//row
	int c;//column
};

void HideCursor();//Hide blinking color in console
void GotoPosition(int r, int c);//Move cursor to specified location
void GameCore(location curLoc);//Core processing for game
void InitializeBoard();//Draw the board when begin game
void DrawPlayer(location loc, char direction);//Draw player with the gun in specified location and the body in below
void Shoot(location loc, location bullets[], int bulletCount);//Create a bullet(*) in top of player
void BulletControl(location bullets[], int &bulletCount);//Move bullets up or destroy enemy or disappear
void DeleteElement(location a[], int &n, int vt);//Delete a Element in aray in specific index
void PlayerMove(location &curLoc);//Move player in 4 directions
void CreateNewMeteorite();//Create new meteorite in random position
void MeteoriteControl(unsigned long &score);//Move the meteorite down and destroy if necessary
void UpdateScore(unsigned long score);//Update score on console
void PauseGame(int &pause);//Pause game and show Pause Menu
void PauseMenu(int &pause, int &curSelection);//Enable use choose to continue or exit game