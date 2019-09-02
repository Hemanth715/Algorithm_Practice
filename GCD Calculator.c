#include<stdio.h>

#define LIM 1000000007

long long a[100002];
long long sum;

long long modulus(long long x)
{
	if (x < 0)
		return (-1 * x);
	return x;
}

long long gcd(long long x, long long y)
{
	if (y == 0)
		return x;
	return gcd(y, x%y);
}

long long calcgcd(int l, int r)
{
	if (l == r)
		return modulus(a[l]);
	long long ans = gcd(modulus(a[l]), modulus(a[l + 1]));
	int i;
	for (i = l + 2; i <= r; i++)
	{
		ans = gcd(ans, modulus(a[i]));
	}
	return ans;
}

int main()
{
	int t, T, count;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		sum = 0;
		count = 0;
		int n, m, i, j;
		int type, l, r, c;
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		for (j = 0; j < m; j++)
		{
			scanf("%d", &type);
			if (type == 1)
			{
				scanf("%d %d", &l, &r);
				count++;
				sum = (sum + (count * calcgcd(l, r))) % LIM;
			}
			else
			{
				scanf("%d %d %d", &l, &r, &c);
				for (i = l; i <= r; i++)
					a[i] += c;
			}
		}

		printf("#%d %lld\n", t, sum);
	}
	return 0;
}