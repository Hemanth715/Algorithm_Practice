#include<stdio.h>

#define MIN_VAL -1001

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		int n, i, k;
		scanf("%d", &n);
		int A[n];
		for (i = 0; i < n; i++)
			scanf("%d", &A[i]);
		k = 0;
		long long sum = 0;
		long long max = MIN_VAL;
		while (k < n)
		{
			sum += A[k];
			k++;
			if (sum > max)
				max = sum;
			if (sum <= 0)
				sum = 0;
		}
		printf("#%d %lld\n", t + 1, max);
	}

	return 0;
}