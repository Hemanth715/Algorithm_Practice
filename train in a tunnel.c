#include<stdio.h>

long long a[100002];
int o[100002];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		long long n, h;
		int i, ans, next;
		scanf("%lld %lld", &n, &h);
		for (i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &o[i]);
		if (o[0] == 0)
			ans = 1;
		else
			ans = 0;
		o[0] = 1;
		if (o[n - 1] == 0)
			ans++;
		o[n - 1] = 1;
		next = h;
		for (i = 1; i < n; i++)
		{
			if (o[i])
				next = h;
			else
			{
				next -= a[i];
				if (next <= 0)
				{
					next = h;
					ans++;
				}
			}
		}
		printf("#%d %d\n", t, ans);
	}
	return 0;
}