#include "functions.h"

void DeleteElement(location a[], int &n, int vt)
{
	int i;
	for (int i = vt; i < n - 1; i++)
		a[i] = a[i + 1];
	n--;
}