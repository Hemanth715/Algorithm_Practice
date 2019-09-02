#include<stdio.h>

int a[101];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int n, k, i, v;
		scanf("%d %d", &n, &k);
		for (i = 1; i < 101; i++)
			a[i] = 0;
		for (i = 0; i < k; i++)
		{
			scanf("%d", &v);
			a[v]++;
		}
		printf("#%d ", t);
		for (i = 1; i <= n; i++)
		{
			if (a[i] == 0)
				printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}