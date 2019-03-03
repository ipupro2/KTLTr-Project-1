#include "functions.h"

void DeleteElement(position a[], int &n, int vt)
{
	for (int i = vt; i < n - 1; i++)
		a[i] = a[i + 1];
	n--;
}