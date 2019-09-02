#include<stdio.h>

int main()
{
	int a[10];
	int win, val;
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int i;
		win = 0;
		for (i = 0; i < 10; i++)
		{
			scanf("%d", &a[i]);
		}
		for (i = 0; i < 10; i++)
		{
			scanf("%d", &val);
			if (val < a[i])
				win++;
			else if (val > a[i])
				win--;
		}
		if (win > 0)
			printf("#%d %c\n", t, 'A');
		else if (win < 0)
			printf("#%d %c\n", t, 'B');
		else
			printf("#%d %c\n", t, 'D');
	}
	return 0;
}