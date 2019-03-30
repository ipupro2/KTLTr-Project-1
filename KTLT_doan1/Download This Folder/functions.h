#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cmath>
using namespace std;

#define boardWidth 100
#define boardHeight 30
#define screenWidth 120
#define screenHeight 30
#define maxVerticalSpeed 1 //Thời gian chờ khi di chuyển lên xuống
#define fixedTime 15//Thời gian chờ để cập nhật lại game tính theo ms

//Define position of object in game
//Định nghĩa vị trí cho các vật thể trong game
struct position
{
	int r;//row
	int c;//column
};

//console.cpp

//Hide blinking cursor in console
//Ẩn con trỏ nhấp nháy trong màn hình console
void HideCursor();
//Move cursor to specified position
//Di chuyển con trỏ đến vị trí chỉ định (r: dòng, c: cột)
void GotoPosition(int r, int c);

///////////////////////////////////////////////////////////////////////

//coreProcessing.cpp

//Core processing for game
//Xử lí chính cho game
void GameCore();

///////////////////////////////////////////////////////////////////////

//draw.cpp

//Initialize data for the screen when begin game
//Khởi tạo giá trị cho màn hình khi bắt đầu game(Load dữ liệu từ file bên ngoài và vẽ ra màn hình)
void Intro();
void InitializeGame();
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


//gameObject.cpp
//Create a bullet in specified position
//Tạo viên đạn ở vị trí chỉ định
void Shoot(position pos, position playerBullets[], int &playerBulletCount, char bullet);

//Move playerBullets up or destroy enemy or disappear
//Điều khiển viên đạn, di chuyển lên hoặc xuống(direction là U hoặc D), biến bullet là hình dạng của đạn ví dụ ^ hoặc |
void BulletControl(position bullets[], int &bulletCount, char direction, char bullet);

//Create new Boss on top of screen

void CreateNewMeteorite(position meteoriteLoc[], int &meteoriteCount);
//Move the meteorite down and destroy if necessary
//Di chuyển thiên thạch xuống và phá hủy nó nếu cần
void MeteoriteControl(unsigned long &score, position meteoriteLoc[], int &meteoriteCount);
int CollideWithMeteor(position pos, position meteoriteLoc[], int &meteoriteCount);
//Phá hủy trùm khi máu nó  = 0
void DestroyBoss(position bossPos);

/////////////////////////////////////////////////////////////////////////////////////////

//functionality
//Update score on console
//Cập nhật điểm lên console
void UpdateScore(unsigned long score);
//Cập nhật hp của người chơi lên console
void UpdateHP(int hp);
//Pause game and show Pause Menu
//Tạm dừng và hiện menu tạm dừng
void PauseGame(int &pause);
//Enable user choose to continue or exit game
//CHo phép người chơi chọn tiếp tục hay thoát game
void PauseMenu(int &pause, int &curSelection);
//Delete an Element in aray in specific index
//Xóa phần tử trong mảng ở vị trí chỉ định
void DeleteElement(position a[], int &n, int vt);
//Show the gameover menu
//Hiện menu gameover
void GameOver();
//Enable player choose to try again or exit
//Cho phép người chơi chơi lại hoặc thoát
void GameOverMenu();

//Tạo trùm ở phía trên màn hình
void CreateBoss(int &bossHp, position &bossPos);
//Boss di chuyển đến người chơi(chỉ qua trái và phải)
void BossMovement(position playerPos, position &bossPos);
//Tạo thiên thạch mới ở vị trí ngẫu nhiên(ở phía trên màn hình)
void DrawBoss(position bossPos);
//////////////////////////////////////////////////////////////////////////////////////////

//physic.cpp
//Check if bullet hit other object, and  call DestroyObject function
//Kiểm tra nếu đạn va chạm các vật khác và gọi hàm phá hủy nếu cần
void BulletHit(position playerBullets[], int &playerBulletCount, position meteoriteLoc[], int &meteoriteCount, unsigned long score);
//If Player hit an object, game will over
//Kiểm tra người chơi có va chạm vật gì không
void HitPlayer(position playerPosition, position meteoriteLoc[], int &meteoriteCount, position enemyBullets[],
	int &enemyBulletCount, int &playerHP);
//Kiểm tra trùm có trúng đạn không
void HitBoss(position bullets[], int &bulletCount, position bossPosition, int &bossHP);

void DrawPlan(position pos);

//Xoá máy bay.
void DeletePlan(position pos);

//T?o m?ng ch?a v? trí máy bay.
void CreatePlan(position planLoc[], int &planCount);
void PlanShoot(position planLoc[], int &planCount, position bullets[], int &bulletCount);
void PlanComputer(position planLoc[], int &planCount);
void BulletHitPlan(position playerBullets[], int &playerBulletCount, position planLoc[],
	int &planCount, unsigned long &score);
int CollideWithPlan(position pos, position planLoc[], int &planCount);

//Items
void CreatePowerUp(position &pos);
void DrawPowerUp(position pos);
void MovePowerUp(position &pos, position playerPos, int &shootingDelay);
void DrawPlayer(position pos, char direction = ' ');
//Hàm di chuyển người chơi bằng các phím mũi tên
void PlayerMove(position &playerPos);

