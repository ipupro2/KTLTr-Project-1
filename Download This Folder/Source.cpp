
#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;
char map[50][50];

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}


void DeleteScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle
	(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle
	(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,
		Cursor_an_Pos);
}

void DrawBoard()
{
	int i;
	for (i = 0; i < 45; i++)
	{
		map[0][i] = '*';
		map[29][i] = '*';

	}
	for (i = 1; i < 30; i++)
	{
		map[i][0] = '*';
		map[i][44] = '*';

	}
	
	

}

void DrawBoard2()
{
	int i;
	for (i = 0; i < 34; i++)
	{
		map[0][i] = '*';
		map[29][i] = '*';

	}
	for (i = 1; i < 30; i++)
	{
		map[i][0] = '*';
		map[i][33] = '*';

	}



}

void PrintBoard()
{
	int i, j;
	for (i = 0; i < 30; i++)
	{
		cout << "\t\t\t";
		for (j = 0; j < 45; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}


void PrintBoard2()
{
	int i, j;
	for (i = 0; i < 30; i++)
	{
		gotoxy(69, i+1);
		for (j = 0; j < 34; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}


int main()
{
	resizeConsole(1000, 600);
	

	DrawBoard();
	PrintBoard();


	string Menu[5] = { "START GAME", "OPTIONS", "DIRECTIONS","CREDITS","EXIT" };
	int pointer = 0;
	


	while (true)
	{
		
		DeleteScreen();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		gotoxy(43, 3);
		cout << "MAIN MENU";

		for (int i = 0; i < 5; ++i)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 100);
				gotoxy(43, i+10);
				cout << Menu[i] << endl;
			
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				gotoxy(43, i+10);
				cout << Menu[i] << endl;
			}
		}

		while (true)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				pointer--;
				if (pointer == -1)
				{
					pointer = 4;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				pointer += 1;
				if (pointer == 5)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN))
			{
				switch (pointer)
				{
				case 0:
				{
					/*while (1)
					{
						GameCore();
						GameOverMenu();
					}*/
				} break;
				case 1:
				{
					//SOUND
				} break;
				case 2:
				{
					DrawBoard2();
					PrintBoard2();
					gotoxy(71, 2);
					cout << "Nguoi choi su dung 4 phim mui";
					gotoxy(71, 3);
					cout << "de duy chuyen. Phi thuyen se";
					gotoxy(71, 4);
					cout << "tu dong ban ve truoc. Se co cac";
					gotoxy(71, 5);
					cout << "ke dich tan cong nguoi choi va";
					gotoxy(71, 6);
					cout << "cac thien thach roi xuong mot ";
					gotoxy(71, 7);
					cout << "cach ngau nhien.";
					
				} break;
				case 3:
				{
					DrawBoard2();
					PrintBoard2();

					gotoxy(75, 9);
					cout << "VO MINH TRIEU";
					gotoxy(75, 10);
					cout << "NGUYEN DUC TRUC";
					gotoxy(75, 11);
					cout << "LUONG THI PHUONG THUY";
					gotoxy(75, 12);
					cout << "NGUYEN NHI CAM TIEN";
					gotoxy(75, 13);
					cout << "TRAN THI TUYET TRINH";
				
				
				} break;
				case 4:
				{
					return 0;
				} break;

				}
				break;
			}
		}
		
		Sleep(200);
	}

	return 0;
}

