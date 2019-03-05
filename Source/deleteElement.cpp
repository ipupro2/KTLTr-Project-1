#include "functions.h"

void DeleteElement(position a[], int &n, int pos)
{
	for (int i = pos; i < n - 1; i++)
		a[i] = a[i + 1];
	n--;
}