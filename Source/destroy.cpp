#include "functions.h"

void MeteoriteDestroy(position loc)
{
	GotoPosition(loc.r, loc.c + 2);
	cout << "\b\b  ";
}