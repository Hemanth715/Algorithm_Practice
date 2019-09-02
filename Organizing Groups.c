#include<stdio.h>

int a[1002];
int dp[1002];

int modulus(int x)
{
	if (x < 0)
		return -1 * x;
	return x;
}

int max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int temp;
		int n, i, j;
		scanf("%d", &n);
		dp[0] = 0;
		for (i = 1; i < n + 1; i++)
		{
			scanf("%d", &a[i]);
			dp[i] = 0;
		}
		for (i = 1; i < n + 1; i++)
		{
			temp = 0;
			for (j = i; j >= 1; j--)
				temp = max(temp, dp[j - 1] + modulus(a[i] - a[j]));
			dp[i] = temp;
		}
		printf("#%d %d\n", t, dp[n]);
	}
	return 0;
}