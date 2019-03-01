#include "functions.h"

void Delete(int a[],int &n,int vt)
{
	int i;
	    for (int i=vt; i<n-1; i++)
	        a[i]=a[i+1];
	    n--;
}
void Deletearray(int a[],int &m,int vt[],int n)
{
	int i, j;
	for (int i=0; i<n; i++)
	    a[vt[i]]=0;
	for (int i=0; i<m; i++)
	   if (a[i]==0)
	    Delete(a,m,i);
}





