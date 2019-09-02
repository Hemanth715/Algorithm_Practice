#include <stdio.h>
#define SIZE 100004


int primes[SIZE], prime_numbers[10000];
int counter = 1, a, b, c;
unsigned long long result;

void findPrimes()
{
	primes[0] = primes[1] = 0;
	primes[2] = primes[3] = 1;
	prime_numbers[counter++] = 2;
	prime_numbers[counter++] = 3;
	for (int i = 4; i <= 100004; ++i)
	{
		int prime = 1;
		for (int j = 2; j <= i / j && prime; ++j)
		{
			if (primes[j] && i%j == 0) prime = 0;
		}
		primes[i] = prime;
		if (prime) prime_numbers[counter++] = i;
	}
	--counter;
}

int power(int n, int p)
{
	int power = 0;
	for (int qt = n / p; qt; qt /= p)
	{
		power += qt;
	}
	return power;
}


int main(void)
{
	int T, test_case, n, k;
	scanf("%d", &T);
	findPrimes();
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &n, &k);
		result = 1;
		int i = 1;
		int p = prime_numbers[i];
		while (p <= n)
		{
			a = power(n, p);
			b = 0;
			c = 0;
			if (p <= k) b = power(k, p);
			if (p <= n - k) c = power(n - k, p);
			result *= (++a - b - c);
			result %= 1000000007;
			p = prime_numbers[++i];
		}
		printf("#%d %u\n", test_case, result);
	}
	return 0;
}
