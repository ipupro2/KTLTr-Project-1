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