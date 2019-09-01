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
	int n, i, k;
	long int sum = 0;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	Quicksort(a, 0, n-1, n);
	for (i = n-1, k = 0; i >= 0; i--, k++)
	{
		sum += (long)a[i] * pow(2, k);
	}
	printf("%ld", sum);
    return 0;
}
