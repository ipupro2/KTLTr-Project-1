#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

#define creditText "  Trieu Truc Thuy Trinh Tien"
#define width 100
#define height 30
#define delayTime 40
#define maxVerticalSpeed 1 //Number of calls is skipped when move up down
#define fixedTime 15

struct position
{
	int r;//row
	int c;//column
};

void HideCursor();//Hide blinking cursor in console
void GotoPosition(int r, int c);//Move cursor to specified position
void GameCore(position curPos);//Core processing for game
void InitializeBoard(CHAR_INFO board[], SMALL_RECT &rec);//Initialize data for the board when begin game
void DrawPlayer(position pos, char direction, CHAR_INFO board[]);//Draw player with the gun in specified position and the body in below
void RedrawBoard(CHAR_INFO board[]);//Redraw the screen
void Shoot(position loc, position bullets[], int bulletCount, CHAR_INFO board[]);//Create a bullet(*) in top of player
void BulletControl(position bullets[], int &bulletCount, CHAR_INFO board[]);//Move bullets up or destroy enemy or disappear
void DeleteElement(position a[], int &n, int vt);//Delete a Element in aray in specific index
void PlayerMove(position &curLoc, CHAR_INFO board[]);//Move player in 4 directions
void CreateNewMeteorite(position meteoriteLoc[], int &meteoriteCount, CHAR_INFO board[]);//Create new meteorite in random position
void MeteoriteControl(unsigned long &score, position meteoriteLoc[], int &meteoriteCount, CHAR_INFO board[]);//Move the meteorite down and destroy if necessary
void UpdateScore(unsigned long score);//Update score on console
void PauseGame(int &pause);//Pause game and show Pause Menu
void PauseMenu(int &pause, int &curSelection);//Enable use choose to continue or exit game
void BulletHit(position bullets[], int &bulletCount, position meteoriteLoc[], int &meteoriteCount, CHAR_INFO board[], unsigned long score);//Check if bullet hit other object, and  call DestroyObject function
void PlayerHit(position playerPosition, position meteoriteLoc[], int &meteoriteCount, int &gameOver, CHAR_INFO board[]);//If Player hit an object, game will over
void MeteoriteDestroy(position loc, CHAR_INFO board[]);//Destroy Meteor in specified position(remove it from console
void GameOver(int &gameOver);//Show the gameover menu
void GameOverMenu(position &curPos);//Enable player choose to try again or exit
void SetBoardValue(CHAR_INFO board[], int row, int column, int code = ' ', int color = 15);//Change the code(character) and the color of board element 