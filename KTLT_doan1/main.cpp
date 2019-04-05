#include "core.h"

int main()
{
	Intro();
	MainMenu();
	while (1)
	{
		GameCore();
		GameOverMenu();
	}
	return 0;
}