#include<stdio.h>

int a[1002][1002], dp[1002][1002];

char s[1002];

int min(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

int min3(int x, int y, int z)
{
	return min(x, min(y, z));
}

int main()
{
	int t, T, max;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int n, i, j;
		max = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%s", s);
			for (j = 0; j < n; j++)
			{
				a[i][j] = s[j] - '0';
				if (i == 0 || j == 0)
					dp[i][j] = 1 - a[i][j];
				else
				{
					if (a[i][j] == 0)
						dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
					else
						dp[i][j] = 0;
				}
				if (dp[i][j] > max)
					max = dp[i][j];
			}
		}
		printf("#%d %d\n", t, max);
	}
	return 0;
}