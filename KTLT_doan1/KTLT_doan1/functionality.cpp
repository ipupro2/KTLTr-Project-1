#include "functions.h"

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
		cout << "Exit";
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
			cout << "     ";
			GotoPosition(boardHeight / 2 + 2, boardWidth / 2 - 6);
			cout << "         ";
			GotoPosition(boardHeight / 2 + 3, boardWidth / 2 - 6);
			cout << "    ";
			Sleep(200);
		}
		else
			exit(0);
	}
}

void GameOver()
{
	GotoPosition(boardHeight / 2, boardWidth / 2 - 5);
	cout << "GAME OVER";
	GotoPosition(boardHeight / 2 + 2, boardWidth / 2 - 6);
	cout << ">Try Again";
	GotoPosition(boardHeight / 2 + 3, boardWidth / 2 - 5);
	cout << "Exit";
}

void GameOverMenu()
{
	int curSelection = 1;
	while (1)
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
				system("cls");
				Sleep(200);
				break;
			}
			else
				exit(0);
		}
	}
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