#include<stdio.h>

int main()
{
	int t, T;
	scanf("%d", &T);

	for (t = 1; t <= T; t++)
	{
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);

		int r = 1, p, c;

		while (p <= n)
		{
			p = r*r;
			r++;
		}

		r -= 2;
		c = r;

	}

	return 0;
}