#include <iostream>
#include <Windows.h>
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
void InitializeBoard();//Initialize data for the board when begin game
void DrawPlayer(position pos, char direction);//Draw player with the gun in specified position and the body in below
void RedrawBoard();//Redraw the screen
void Shoot(position pos, position playerBullets[], int &playerBulletCount, char bullet);//Create a bullet(*) in top of player
void BulletControl(position bullets[], int &bulletCount, char direction, char bullet);//Move playerBullets up or destroy enemy or disappear
void DeleteElement(position a[], int &n, int vt);//Delete a Element in aray in specific index
void PlayerMove(position &playerPos);//Move player in 4 directions
void CreateNewMeteorite(position meteoriteLoc[], int &meteoriteCount);//Create new meteorite in random position
void MeteoriteControl(unsigned long &score, position meteoriteLoc[], int &meteoriteCount);//Move the meteorite down and destroy if necessary
void UpdateScore(unsigned long score);//Update score on console
void PauseGame(int &pause);//Pause game and show Pause Menu
void PauseMenu(int &pause, int &curSelection);//Enable use choose to continue or exit game
void BulletHit(position playerBullets[], int &playerBulletCount, position meteoriteLoc[], int &meteoriteCount, unsigned long score);//Check if bullet hit other object, and  call DestroyObject function
void PlayerHit(position playerPosition, position meteoriteLoc[], int &meteoriteCount, int &gameOver);//If Player hit an object, game will over
void MeteoriteDestroy(position pos);//Destroy Meteor in specified position(remove it from console
void GameOver(int &gameOver);//Show the gameover menu
void GameOverMenu(position &curPos);//Enable player choose to try again or exit
void SetBoardValue(int row, int column, int code = ' ', int color = 15);//Change the code(character) and the color of board element 
void CreateBoss(int &bossHp, position &bossPos);//Create new Boss on top of screen
void DrawBoss(position bossPos);//Draw Boss at specified position
void BossMovement(position playerPos, position &bossPos);//Move Pos to Player