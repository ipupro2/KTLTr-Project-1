#include "core.h"

int main()
{
	Intro();
	while (1)
	{
		MainMenu();
		while (1)
		{
			GameCore();
			if (GameOverMenu())
				break;
		}
	}
	return 0;
}