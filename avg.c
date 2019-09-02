#include<stdio.h>

int val[1000];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int n, i;
		int sum = 0, count = 0;
		float avg;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &val[i]);
			sum += val[i];
		}
		avg = (float)sum / (float)n;
		for (i = 0; i < n; i++)
		{
			if ((float)val[i] >= avg)
				count++;
		}
		printf("#%d %d\n", t, count);
	}
	return 0;
}