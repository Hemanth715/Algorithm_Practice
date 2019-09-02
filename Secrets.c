#include<stdio.h>

int visit[12], count[12];
int a[12][12];
int n, max;

void traverse(int x, int len)
{
	visit[x] = 1;
	len++;
	if (len > max)
		max = len;
	int i;
	for (i = 1; i < n + 1; i++)
	{
		if (a[x][i] == 1 && visit[i] == 0)
		{
			traverse(i, len);
		}
	}
	visit[x] = 0;
	return;
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		max = 0;
		int k, i, j, m, x, y, len;
		scanf("%d %d", &n, &k);
		for (i = 1; i < n + 1; i++)
		{
			visit[i] = 0;
			count[i] = 0;
			for (j = 1; j < n + 1; j++)
			{
				a[i][j] = 0;
			}
		}
		for (i = 0; i < k; i++)
		{
			scanf("%d", &m);
			scanf("%d", &y);
			for (j = 0; j < m - 1; j++)
			{
				scanf("%d", &x);
				if (a[y][x] == 0)
					count[y]++;
				a[y][x] = 1;
				y = x;
			}
		}

		for (i = 1; i < n + 1; i++)
		{
			len = 0;
			traverse(i, len);
		}
		printf("#%d ", t);
		for (i = 1; i < n + 1; i++)
			printf("%d ", count[i]);
		printf("%d\n", max);
	}
	return 0;
}