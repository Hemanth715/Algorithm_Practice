#include<stdio.h>

int a[1002], b[1002];

int max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int knapsack(int l, int n)
{
	if (n == 0 || l == 0)
		return 0;
	if (b[n - 1] > l)
		return knapsack(l, n - 1);
	else
		return max(knapsack(l - b[n - 1], n - 1) + a[n - 1], knapsack(l, n - 1));
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int n, l, i;
		scanf("%d %d", &n, &l);
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &a[i], &b[i]);
		}
		printf("#%d %d\n", t, knapsack(l, n));
	}
	return 0;
}