#include<stdio.h>

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int a, b, c, res;
		scanf("%d %d %d", &a, &b, &c);
		if (a >= b)
			res = c / b;
		else
			res = c / a;
		printf("#%d %d\n", t, res);
	}
	return 0;
}