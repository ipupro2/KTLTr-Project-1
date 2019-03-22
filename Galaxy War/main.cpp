#include "functions.h"

int main()
{
	Intro();
	while (1)
	{
		GameCore();
		GameOverMenu();
	}
	return 0;
}