#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int Partition(int a[], int p, int r, int n){
	int i, j, temp;
	i = p-1;
	for (j = p; j < r; ++j)
	{
		if (a[j] <= a[r])
		{
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	return i+1;
}

void Quicksort(int a[], int p, int r, int n){
	if (p < r)
	{
		int q = Partition(a, p, r, n);
		Quicksort(a, p, q-1, n);
		Quicksort(a, q+1, r, n);
	}
	return;
}

int main() {
	int n, i, mindiff, x, qe;
	scanf("%d", &n);
	int a[n];
	int q[2*n];
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	Quicksort(a, 0, n-1, n);
	mindiff = a[1] - a[0];
    qe = 2;
    q[0] = a[0];
    q[1] = a[1];
    for (i = 2; i < n; ++i)
    {
    	x = a[i] - a[i-1];
    	if (x < mindiff)
    	{
    		qe = 2;
    		q[0] = a[i-1];
    		q[1] = a[i];
    		mindiff = x;
    	}
    	else if (x == mindiff)
    	{
    		q[qe] = a[i-1];
    		qe++;
    		q[qe] = a[i];
    		qe++;
    	}
    }
    for (i = 0; i < qe; ++i)
    {
    	printf("%d ", q[i]);
    }
    return 0;
}
