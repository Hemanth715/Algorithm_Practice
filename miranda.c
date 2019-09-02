#include<stdio.h>

int a[501], b[501];

int x[10001], y[10001];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int n, m, i, count;
		scanf("%d %d", &n, &m);
		a[1] = 1;
		b[1] = 1;
		for (i = 2; i <= n; i++)
		{
			a[i] = 0;
			b[i] = 0;
		}
		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &x[i], &y[i]);
			if (x[i] == 1)
				a[y[i]] = 1;
			else if (y[i] == 1)
				a[x[i]] = 1;
		}
		for (i = 0; i < m; i++)
		{
			if (a[x[i]] == 1)
			{
				b[y[i]] = 1;
				b[x[i]] = 1;
			}
			if (a[y[i]] == 1)
			{
				b[x[i]] = 1;
				b[y[i]] = 1;
			}
		}
		count = 0;
		for (i = 2; i <= n; i++)
		{
			if (b[i] == 1)
				count++;
		}
		printf("#%d %d\n", t, count);
	}
	return 0;
}