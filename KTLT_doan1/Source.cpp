
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

void Deletescreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void GotoPosition(int r, int c)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD C = { (short)c, (short)r };
	SetConsoleCursorPosition(h, C);
}

int main()
{
	resizeConsole(920, 550);

	fstream f("tep.txt");
	fstream f1("tep1.txt");
	
	
	while (!f1.eof())
	{
		char temp[255];
		f1.getline(temp, 255);
		string line = temp;
		cout << line << endl;
	}

	int pos = 0;
	    
	GotoPosition(11, 33);
	cout << ">>";
	GotoPosition(11, 49);
	cout << "<<";


	while (1)

	{
		Deletescreen();
		
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
					return 0;

				} break;
				case 1:
				{
					
				} break;
				case 2:
				{
				 
					while (!f.eof())
					{
						char temp[255];
						f.getline(temp, 255);
						string line = temp;
						cout << line << endl;
					}
					GotoPosition(pos + 11, 33);
					cout << ">>";
					GotoPosition(pos + 11, 49);
					cout << "<<";

				} break;

				case 3:
				{
					return 0;
				} break;

				}
				break;
			}

		}
		Sleep(300);
	}

    f.close();
	f1.close();

	return 0;
}

