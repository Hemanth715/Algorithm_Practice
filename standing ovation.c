#include<stdio.h>

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int i = 0;
		int sum = 0;
		int count = 0;
		char c;
		char a[1002];
		scanf("%s", a);
		while (a[i] != '\0')
		{
			c = a[i];
			sum += (c - '0');
			if (sum < i + 1)
			{
				count += (i + 1 - sum);
				sum = i + 1;
			}
			i++;
		}
		printf("#%d %d\n", t, count);
	}
	return 0;
}