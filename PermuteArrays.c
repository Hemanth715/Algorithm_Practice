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
	int t;
	scanf("%d", &t);
	for (i_t = 0; i_t < t; ++i_t)
	{
		int n, k, i;
		scanf("%d %d", &n, &k);
		int a[n], b[n];
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &b[i]);
		}
		Quicksort(a, 0, n-1, n);
		Quicksort(b, 0, n-1, n);
		int flag = 0;
		for (i = 0; i < n; ++i)
		{
			if (a[i] + b[n - 1 - i] < k)
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			printf("NO\n");
		}
		else
			printf("YES\n");
	}
    return 0;
}
