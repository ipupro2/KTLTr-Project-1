#include "functions.h"

int main()
{
	location curLocation; // currentLocation are default set to width/2 height/2
	curLocation.c = width/2;
	curLocation.r = height/2;
	InitializeBoard();
	GameCore(curLocation);
	return 0;
}