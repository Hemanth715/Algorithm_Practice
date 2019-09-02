#include<stdio.h>

int main()
{
	int t, T;
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		long long n, sum1 = 0, sum2 = 0, sum3 = 0, i;
		scanf("%lld", &n);
		sum1 = n * (n + 1)/2;
		sum2 = n * n;
		sum3 = sum1 * 2;
		printf("#%d %lld %lld %lld\n", t, sum1, sum2, sum3);
	}
	return 0;
}