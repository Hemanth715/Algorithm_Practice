#include <stdio.h>

#define MAX_N 16

int N, M;
int visitAll;
int precede[MAX_N];
long long dp[1 << MAX_N];

long long solve(int visit)
{
	if (visit == visitAll)
	{
		return 1;
	}

	if (dp[visit] != 0)
	{
		return dp[visit];
	}

	for (int i = 0; i < N; i++)
	{
		if (((visit & (1 << i)) == 0) && // if i is not visited
			(precede[i] & visit) == precede[i]) // if everyone who precede i is visited
		{
			dp[visit] += solve(visit | (1 << i));
		}
	}

	return dp[visit];
}

int main()
{
	int T; scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &N, &M);
		visitAll = (1 << N) - 1;

		for (int i = 0; i < N; i++)
		{
			precede[i] = 0;
		}

		int x, y;

		for (int i = 0; i < M; i++)
		{
			scanf("%d %d", &x, &y);
			x--; y--;

			precede[y] |= 1 << x;
		}

		for (int i = 0; i <= visitAll; i++)
		{
			dp[i] = 0;
		}

		printf("#%d %lld\n", tc, solve(0));
	}

	return 0;
}
