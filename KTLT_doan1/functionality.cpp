#include "functionality.h"
#include <conio.h>

static const char Number[11][5][8] =
{
	{
		"  ___  ",
		" |   | ",
		" |   | ",
		" |   | ",
		" |___| ",

	},
	{
		"       ",
		"   |   ",
		"   |   ",
		"   |   ",
		"   |   ",
	},
	{
		"  ___  ",
		"     | ",
		"  ___| ",
		" |     ",
		" |___  "
	},
	  {
		"  ___  ",
		"     | ",
		"  ___| ",
		"     | ",
		"  ___| "
	},
	 {
		"       ",
		" |   | ",
		" |___| ",
		"     | ",
		"     | ",
	},
	 {
		"  ___  ",
		" |     ",
		" |___  ",
		"     | ",
		"  ___| "
	},
	 {
		"  ___  ",
		" |     ",
		" |___  ",
		" |   | ",
		" |___| "
	},
	 {
		" _____ ",
		"     / ",
		"    /  ",
		"   /   ",
		"  /    ",
	},
	 {
		"  ___  ",
		" |   | ",
		" |___| ",
		" |   | ",
		" |___| ",
	},
	 {
		"  ___  ",
		" |   | ",
		" |___| ",
		"     | ",
		"  ___| "
	},
	 {
		"       ",
		"       ",
		"       ",
		"       ",
		"       ",
	},
};

void Intro()
{
	SetConsoleTitleA("Galaxy War");
	HWND console = GetConsoleWindow();
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), {120, 30});
	RECT rect;
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, rect.top, 1100, 647, true);
	HideCursor();
	system("cls");
	GotoPosition(screenHeight / 2, screenWidth / 2 - 10);
	cout << "Who are we?";
	Sleep(1000);
	GotoPosition(screenHeight / 2, screenWidth / 2 - 10);
	cout << "We're here to make the difference!";
	Sleep(1000);
	DrawScreenFromFile("intro.map");
	while (!GetAsyncKeyState(VK_RETURN))
	{
		GotoPosition(24, 47);
		if (GetTickCount64() % 500 == 0)
			cout << "<Press Enter to Continue>";
		else if (GetTickCount64() % 250 == 0)
			cout << "                         ";
	}
	Sleep(200);
}

void MainMenu()
{
	Sleep(200);
	DrawScreenFromFile("newgame.map");
	int pos = 0;
	GotoPosition(11, 33);
	cout << ">>";
	GotoPosition(11, 49);
	cout << "<<";
	while (1)
	{
		while (1)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				GotoPosition(pos + 11, 33);
				cout << "  ";
				GotoPosition(pos + 11, 49);
				cout << "  ";
				pos--;
				if (pos == -1)
				{
					pos = 3;
					GotoPosition(pos + 11, 33);
					cout << ">>";
					GotoPosition(pos + 11, 49);
					cout << "<<";
				}
				else
				{
					GotoPosition(pos + 11, 33);
					cout << ">>";
					GotoPosition(pos + 11, 49);
					cout << "<<";
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				GotoPosition(pos + 11, 33);
				cout << "  ";
				GotoPosition(pos + 11, 49);
				cout << "  ";
				pos++;
				if (pos == 4)
				{
					pos = 0;
					GotoPosition(pos + 11, 33);
					cout << ">>";
					GotoPosition(pos + 11, 49);
					cout << "<<";
				}

				else
				{
					GotoPosition(pos + 11, 33);
					cout << ">>";
					GotoPosition(pos + 11, 49);
					cout << "<<";

				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN))
			{
				switch (pos)
				{
				case 0:
				{
					return;

				} break;
				case 1:
				{
					int k = 3;
					string a;
					fstream outNameScore;
					outNameScore.open("save.sav");
					DrawScreenFromFile("leaderboard.map");
					for (int i = 1; i <= 10; i++)
					{
						GotoPosition(k, 85);
						getline(outNameScore, a);
						cout << i << "." << a;
						k++;
					}
					GotoPosition(pos + 11, 33);
					cout << ">>";
					GotoPosition(pos + 11, 49);
					cout << "<<";
					break;
				}
				case 2:
				{
					DrawScreenFromFile("help.map");
					GotoPosition(pos + 11, 33);
					cout << ">>";
					GotoPosition(pos + 11, 49);
					cout << "<<";

				}
				break;
				case 3:
				{
					exit(0);
				}
				break;
				}
				break;
			}

		}
		Sleep(200);
	}
}

void PauseGame(int &pause)
{
	if (GetAsyncKeyState(VK_RETURN) && !pause)
	{
		GotoPosition(boardHeight / 2, boardWidth / 2 - 5);
		cout << "PAUSE";
		Sleep(200);
		GotoPosition(boardHeight / 2+2, boardWidth / 2 - 6);
		cout << ">Continue";
		GotoPosition(boardHeight / 2 + 3, boardWidth / 2 - 5);
		cout << "End Game";
		pause = 1;
	}
}

void PauseMenu(int &pause, int &curSelection, int &gameOver)
{
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN))
	{
		if (curSelection == 1)
		{
			curSelection = 2;
			GotoPosition(boardHeight / 2 + 2, boardWidth / 2 - 6);
			cout << " ";
			GotoPosition(boardHeight / 2 + 3, boardWidth / 2 - 6);
			cout << ">";
			Sleep(200);
		}
		else
		{
			curSelection = 1;
			GotoPosition(boardHeight / 2 + 3, boardWidth / 2 - 6);
			cout << " ";
			GotoPosition(boardHeight / 2 + 2, boardWidth / 2 - 6);
			cout << ">";
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		if (curSelection == 1)
		{
			pause = 0;
			GotoPosition(boardHeight / 2, boardWidth / 2 - 6);
			cout << "      ";
			GotoPosition(boardHeight / 2 + 2, boardWidth / 2 - 6);
			cout << "          ";
			GotoPosition(boardHeight / 2 + 3, boardWidth / 2 - 6);
			cout << "     ";
			Sleep(200);
		}
		else
			gameOver = 1;
	}
}

void PrintScore(unsigned long score)
{
	for (int i = 0; i < screenHeight; i++)
	{
		for (int j = 0; j < screenWidth; j++)
		{
			SetBoardValue(i, j);
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				SetBoardValue(boardHeight - 10 + j, boardWidth / 2 - 15 + k + i*7, Number[score / (int)pow(10, 8 - i - 1)][j][k]);
			}
		}
		score %= (int)pow(10, 8 - i - 1);
		RedrawBoard();
		Sleep(500);
	}
}
	

void GameOver(unsigned long score)
{
	string name;
	PrintScore(score);
	UnhideCursor();
	GotoPosition(screenHeight / 2, screenWidth / 2 - 20);
	cout << "Enter your name(No space): ";
	//Xóa bỏ input người dùng
	while (_kbhit())
		_getch();
	cin >> name;
	HideCursor();
	//Lệnh sau để loại bỏ nút Enter khi người dùng nhập
	GetAsyncKeyState(VK_RETURN);
	Sleep(200);
	SaveScore({ name, score });
	saveData data[10];
	LoadScore(data);
	FlashScreen();
	GotoPosition(boardHeight / 2 - 2, boardWidth / 2 + 20);
	cout << "Leaderboard:";
	for (int i = 0; i < 10; i++)
	{
		GotoPosition(boardHeight / 2 + i, boardWidth / 2 + 20);
		cout << data[i].name << " " << data[i].score;
	}
	GotoPosition(boardHeight / 2, boardWidth / 2 - 5);
	cout << "GAME OVER";
	GotoPosition(boardHeight / 2 + 2, boardWidth / 2 - 6);
	cout << ">Try Again";
	GotoPosition(boardHeight / 2 + 3, boardWidth / 2 - 5);
	cout << "Main Menu";
	GotoPosition(boardHeight / 2 + 4, boardWidth / 2 - 5);
	cout << "Exit";
}

int GameOverMenu()
{
	int curSelection = 1;
	while (1)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			GotoPosition(boardHeight / 2 + curSelection + 1, boardWidth / 2 - 6);
			cout << " ";
			curSelection--;
			if (curSelection == 0)
				curSelection = 3;
			GotoPosition(boardHeight / 2 + curSelection + 1, boardWidth / 2 - 6);
			cout << ">";
			Sleep(200);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			GotoPosition(boardHeight / 2 + curSelection + 1, boardWidth / 2 - 6);
			cout << " ";
			curSelection++;
			if (curSelection == 4)
				curSelection = 1;
			GotoPosition(boardHeight / 2 + curSelection + 1, boardWidth / 2 - 6);
			cout << ">";
			Sleep(200);
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			if (curSelection == 1)
			{
				FlashScreen();
				Sleep(200);
				return 0;
			}
			else if (curSelection == 2)
				return 1;
			else
				exit(0);
		}
	}
	return 1;
}

void UpdateScore(unsigned long score)
{
	int tam = score;
	for (int i = 7; i >= 0; i--)
	{
		char code = tam / ((int)pow(10, i)) + 48;
		SetBoardValue(1, 109 + 8 - i,  code);
		tam %= (int)pow(10, i);
	}
}

void UpdateHP(int hp)
{
	SetBoardValue(27, 106, hp / 10 + 48);
	SetBoardValue(27, 107, hp % 10 + 48);
}

void DeleteElement(position a[], int &n, int pos)
{
	for (int i = pos; i < n - 1; i++)
		a[i] = a[i + 1];
	n--;
}