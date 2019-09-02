#include<stdio.h>

#define MAX_N 1000002

long long phisum[MAX_N];

long long phi(long long n)
{
	long long p;
	float pro = n;
	for (p = 2; p*p <= n; p++)
	{
		if (n % p == 0)
		{
			while (n % p == 0)
				n /= p;
			pro *= (1.0 - (1.0 / (float)p));
		}
	}

	if (n > 1)
		pro *= (1.0 - (1.0 / (float)n));


	return (long long)pro;
}

int main()
{
	phisum[0] = 0;
	int t, T;
	long long maxphi = 0;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		long long a, b, i;
		scanf("%lld %lld", &a, &b);

		if (b > maxphi)
		{
			for (i = maxphi + 1; i <= b; i++)
			{
				phisum[i] = phisum[i - 1] + phi(i);
			}
			maxphi = b;
		}

		printf("#%d %lld\n", t, phisum[b] - phisum[a-1]);
	}
	return 0;
}