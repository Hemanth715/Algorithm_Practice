#include<stdio.h>

int a[1001][1001];
int n;

int traverse(int i, int j)
{
	if (i + 1 < n && a[i + 1][j] == a[i][j] + 1)
		return 1 + traverse(i + 1, j);
	if (j + 1 < n && a[i][j + 1] == a[i][j] + 1)
		return 1 + traverse(i, j + 1);
	if (i - 1 > -1 && a[i - 1][j] == a[i][j] + 1)
		return 1 + traverse(i - 1, j);
	if (j - 1 > -1 && a[i][j - 1] == a[i][j] + 1)
		return 1 + traverse(i, j - 1);
	return 1;
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int i, j;
		int val, max = 0, maxpos;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				val = traverse(i, j);
				if (val == max && a[i][j] < maxpos)
					maxpos = a[i][j];
				else if (val > max)
				{
					max = val;
					maxpos = a[i][j];
				}
			}
		}

		printf("#%d %d %d\n", t, maxpos, max);
	}
	return 0;
}