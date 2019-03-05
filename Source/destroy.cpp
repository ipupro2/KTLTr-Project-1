#include "functions.h"

void MeteoriteDestroy(position loc)
{
	GotoPosition(loc.r, loc.c + 2);
	cout << "\b\b  ";
	GotoPosition(loc.r - 1, loc.c + 2);
	cout << "\b\b  ";
	GotoPosition(loc.r - 2, loc.c + 2);
	cout << "\b\b  ";
}