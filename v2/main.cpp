#include "functions.h"

int main()
{
	position curPosition; // currentLocation are default set to width/2 height/2
	curPosition.c = width/2;
	curPosition.r = height/2;
	while (1)
	{
		GameCore(curPosition);
		GameOverMenu(curPosition);
	}
	return 0;
}