#include<stdio.h>
#include<malloc.h>

int visited[50002];
int **a;

long long cost;

void span(int n)
{
	int i, j, min = 10005, mini, minj, flag = 0;
	for (i = 1; i <= n; i++)
	{
		if (visited[i] == 1)
		{
			for (j = 1; j <= n; j++)
			{
				if (a[i][j] >= 0 && visited[j] == 0 && a[i][j] < min)
				{
					min = a[i][j];
					mini = i;
					minj = j;
					flag = 1;
				}
			}
		}
	}
	if (flag == 1)
	{
		visited[minj] = 1;
		cost += min;
		span(n);
	}
	return;
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		cost = 0;
		int n, m, i, j, s, e, c;
		scanf("%d", &n);
		a = (int**)malloc((n + 2) * sizeof(int*));
		for (i = 1; i <= n; i++)
		{
			a[i] = (int*)malloc((n + 2) * sizeof(int));
		}
		scanf("%d", &m);
		for (i = 1; i <= n; i++)
		{
			visited[i] = 0;
			for (j = 1; j <= n; j++)
			{
				a[i][j] = -1;
			}
		}
		for (i = 0; i < m; i++)
		{
			scanf("%d %d %d", &s, &e, &c);
			a[s][e] = c;
			a[e][s] = c;
		}
		visited[1] = 1;
		span(n);
		printf("#%d %lld\n", t, cost);
	}
	return 0;
}