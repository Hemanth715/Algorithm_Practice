#include<stdio.h>

int a[50002];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int n, i;
		int sum = 0;
		scanf("%d", &n);
		int b[50002] = { 0, };
		int c[50002] = { 0, };
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);

		for (i = 1; i < n; i++)
		{
			if (a[i] > a[i - 1])
				b[i] = b[i - 1] + 1;
		}

		for (i = n - 1; i > 0; i--)
		{
			if (a[i - 1] > a[i])
				c[i - 1] = c[i] + 1;
		}
		for (i = 0; i < n; i++)
			sum += b[i] * c[i];
		printf("#%d %d\n", t, sum);
	}
	return 0;
}