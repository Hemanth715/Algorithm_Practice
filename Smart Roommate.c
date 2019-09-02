#include<stdio.h>

int a[100002], b[100002];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int n, i, j, count = 0;
		scanf("%d", &n);
		scanf("%d", &a[0]);
		b[0] = a[0];
		for (i = 1; i < n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = b[i - 1] + a[i];
		}

		for (i = 0; i < n; i++)
		{
			for (j = i; j >= 0; j--)
			{
				if (b[i] - b[j - 1] == 0)
					count++;
			}
		}
		printf("#%d %d\n", t, count);
	}
	return 0;
}