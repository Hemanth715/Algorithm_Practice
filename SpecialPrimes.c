#include<stdio.h>

int primes[1000002];

int isPrime(int n)
{
	int i;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (n % 2 == 0)
		return 0;
	for (i = 3; i*i <= n; i += 2)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int t, T, i;
	for (i = 1; i <= 1000000; i++)
		primes[i] = isPrime(i);
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int d, a, b, x, flag;
		int count = 0;
		scanf("%d %d %d", &d, &a, &b);
		for (i = a; i <= b; i++)
		{
			if (primes[i] == 1)
			{
				flag = 0;
				x = i;
				while (x != 0)
				{
					if (x % 10 == d)
						flag = 1;
					x /= 10;
				}
				if (flag == 1)
					count++;
			}
		}
		printf("#%d %d\n", t, count);
	}
	return 0;
}