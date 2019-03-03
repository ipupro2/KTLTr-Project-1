#include "functions.h"

void PauseGame(int &pause)
{
	if (GetAsyncKeyState(VK_RETURN) && !pause)
	{
		GotoPosition(height / 2, width / 2 +3);
		cout << "\b\b\b\b\bPAUSE";
		Sleep(200);
		GotoPosition(height / 2+2, width / 2 + 6);
		cout << "\b\b\b\b\b\b\b\b\b>Continue";
		GotoPosition(height / 2 + 3, width / 2 + 2);
		cout << "\b\b\b\bExit";
		pause = 1;
	}
}

void PauseMenu(int &pause, int &curSelection)
{
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN))
	{
		if (curSelection == 1)
		{
			curSelection = 2;
			GotoPosition(height / 2 + 2, width / 2 - 2);
			cout << "\b ";
			GotoPosition(height / 2 + 3, width / 2 - 2);
			cout << "\b>";
			Sleep(200);
		}
		else
		{
			curSelection = 1;
			GotoPosition(height / 2 + 3, width / 2 - 2);
			cout << "\b ";
			GotoPosition(height / 2 + 2, width / 2 - 2);
			cout << "\b>";
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		if (curSelection == 1)
		{
			pause = 0;
			GotoPosition(height / 2, width / 2 + 3);
			cout << "\b\b\b\b\b     ";
			GotoPosition(height / 2 + 2, width / 2 + 7);
			cout << "\b\b\b\b\b\b\b\b\b\b         ";
			GotoPosition(height / 2 + 3, width / 2 + 2);
			cout << "\b\b\b\b    ";
			Sleep(200);
		}
		else
			exit(0);
	}
}

void GameOver(int &gameOver)
{
	GotoPosition(height / 2, width / 2 + 4);
	cout << "\b\b\b\b\\b\b\b\b\bGAME OVER";
	GotoPosition(height / 2 + 2, width / 2 + 6);
	cout << "\b\b\b\b\b\b\b\b\b>Try Again";
	GotoPosition(height / 2 + 3, width / 2 + 2);
	cout << "\b\b\b\bExit";
	gameOver = 1;
}

void GameOverMenu(position &curPos)
{
	int curSelection = 1;
	while (1)
	{
		if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN))
		{
			if (curSelection == 1)
			{
				curSelection = 2;
				GotoPosition(height / 2 + 2, width / 2 - 2);
				cout << "\b ";
				GotoPosition(height / 2 + 3, width / 2 - 2);
				cout << "\b>";
				Sleep(200);
			}
			else
			{
				curSelection = 1;
				GotoPosition(height / 2 + 3, width / 2 - 2);
				cout << "\b ";
				GotoPosition(height / 2 + 2, width / 2 - 2);
				cout << "\b>";
				Sleep(200);
			}
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			if (curSelection == 1)
			{
				curPos.c = width / 2;
				curPos.r = height / 2;
				system("cls");
				Sleep(200);
				break;
			}
			else
				exit(0);
		}
	}
}