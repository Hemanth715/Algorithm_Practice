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
	int n, i, div, rem, flag1, sum = 0;
	scanf("%d", &n);
	int a[n], flag = 0;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	Quicksort(a, 0, n-1, n);
	div = a[0];
	while(div >= 1 && flag == 0){
		i = 0;
		flag1 = 0;
		while(i < n && flag1 == 0)
		{
			rem = a[i] % (div+1);
			if (rem > 1 && rem < div-1)
			{
				flag1 = 1;
			}
			i++;
		}
		if (flag1 == 0)
			flag = 1;
		else
			div--;
	}
	for (i = 0; i < n; ++i)
	{
		sum += a[i]/div;
		rem = a[i]%div;
		if (rem > 1)
		{
			sum++;
		}
	}
	printf("%d", sum);
    return 0;
}
