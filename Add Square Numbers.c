#include<stdio.h>

#define max_limit 1000000000000000000
__int128 x, b;

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		x = 0;
		int n, i, j;
		long long p, a;
		long long sum1, sum2;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &a);
			p = a % 10;
			a /= 10;
			b = 1;
			for (j = 0; j < p; j++)
				b *= a;
			x += b;
		}
		if (x > max_limit)
		{
			sum1 = x / max_limit;
			sum2 = x % max_limit;
			printf("#%d %lld%lld\n", t, sum1, sum2);
		}
		else
			printf("#%d %lld\n", t, x);
	}
	return 0;
}