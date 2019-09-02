#include<stdio.h>
#define MAX 1000001

long long a[MAX], b[MAX];
int max;
long long sum;

int main()
{
	a[0] = 0;
	int t, T, i, j;
	scanf("%d", &T);
	for (i = 1; i < MAX; i += 2)
	{
		for (j = i; j < MAX; j += i)
		{
			b[j] += i;
		}
	}

	for (i = 1; i < MAX; i++)
		a[i] = a[i - 1] + b[i];
	for (t = 1; t <= T; t++)
	{
		sum = 0;
		int l, r;
		scanf("%d %d", &l, &r);
		printf("#%d %lld\n", t, a[r] - a[l - 1]);
	}
	return 0;
}