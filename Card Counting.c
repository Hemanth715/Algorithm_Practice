#include<stdio.h>

char s[1002];
int a[4][14];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int i, x;
		char c;
		for (i = 0; i < 4; i++)
		{
			for (x = 0; x < 14; x++)
			{
				a[i][x] = 0;
			}
		}
		scanf("%s", s);
		i = 0;
		int flag = 0;
		while (s[i] != '\0' && flag == 0)
		{
			c = s[i];
			i++;
			x = 10 * (s[i] - '0');
			i++;
			x += (s[i] - '0');
			if (c == 'S')
			{
				if (a[0][x] == 1)
					flag = 1;
				a[0][x] = 1;
				a[0][0]++;
			}
			else if(c == 'D')
			{
				if (a[1][x] == 1)
					flag = 1;
				a[1][x] = 1;
				a[1][0]++;
			}
			else if (c == 'H')
			{
				if (a[2][x] == 1)
					flag = 1;
				a[2][x] = 1;
				a[2][0]++;
			}
			else
			{
				if (a[3][x] == 1)
					flag = 1;
				a[3][x] = 1;
				a[3][0]++;
			}
			i++;
		}
		if (flag != 0)
			printf("#%d ERROR\n", t);
		else
			printf("#%d %d %d %d %d\n", t, 13 - a[0][0], 13 - a[1][0], 13 - a[2][0], 13 - a[3][0]);
	}
	return 0;
}