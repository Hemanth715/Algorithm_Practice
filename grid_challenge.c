#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int Partition(char a[], int p, int r, int n){
	int i, j;
	char temp;
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

void Quicksort(char a[], int p, int r, int n){
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
	for (int i_t = 0; i_t < t; ++i_t)
	{
		int n, i;
		scanf("%d", &n);
		char a[n][n];
		for (i = 0; i < n; ++i)
		{
			scanf("%s", a[i]);
		}
		for (i = 0; i < n; ++i)
		{
			Quicksort(a[i], 0, n-1, n);
		}
		int flag = 0;
		for (int j = 0; j < n; ++j)
		{
			for (i = 1; i < n; ++i)
			{
				if (a[i][j] < a[i-1][j])
				{
					flag = 1;
				}
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
