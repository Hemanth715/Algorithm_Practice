#include<stdio.h>

char a[1002][82];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		printf("#%d ", t);
		int n, i, j;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%s", a[i]);
		}
		i = 0;
		if (n % 2 == 0)
			j = n / 2;
		else
			j = (n / 2) + 1;
		while (i < n / 2)
		{
			printf("%s %s ", a[i], a[j]);
			i++;
			j++;
		}
		if (n % 2 == 1)
			printf("%s", a[i]);
	}
	return 0;
}