#include "functions.h"

void UpdateScore(unsigned long score)
{
	int tam = score;
	GotoPosition(0, width + 18);
	cout << "\b\b\b\b\b\b\b\b";
	for (int i = 8; i >= 0; i--)
	{
		cout << tam/((int)pow(10, i));
		tam %= (int)pow(10, i);
	}
}