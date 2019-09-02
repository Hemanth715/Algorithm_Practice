#include<stdio.h>

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int d, h, m, a;
		scanf("%d %d %d", &d, &h, &m);
		a = ((d - 11) * 24 * 60) + ((h - 11) * 60) + (m - 11);
		if (a < 0)
			a = -1;
		printf("#%d %d\n", t, a);
	}
	return 0;
}