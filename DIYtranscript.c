#include<stdio.h>

int a[101];

int main()
{
	int t, T, sum;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int n, k, i, val;
		scanf("%d %d", &n, &k);
		for (i = 1; i <= 100; i++)
			a[i] = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &val);
			a[val]++;
		}
		i = 100;
		sum = 0;
		while (k > 0)
		{
			if (k <= a[i])
			{
				sum += i * k;
				k = 0;
			}
			else
			{
				sum += i * a[i];
				k -= a[i];
			}
			i--;
		}
		printf("#%d %d\n", t, sum);
	}
	return 0;
}