#include<stdio.h>

long long f(long long n)
{
	long long sum = 0;
	while(n > 0)
	{
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		long long n;
		scanf("%lld", &n);
		while(n / 10 > 0)
			n = f(n);
		printf("#%d %lld\n", t, n);
	}
	return 0;
}