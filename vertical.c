#include<stdio.h>

char s[5][17];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int i, j, k, l, m, max = 0;
		for (i = 0; i < 5; i++)
		{
			scanf("%s", s[i]);
			j = 0;
			while (s[i][j] != '\0')
				j++;
			if (j > max)
				max = j;
		}
		printf("#%d ", t);
		i = 0;
		j = 0;
		k = 0;
		l = 0;
		m = 0;
		while (i < max && j < max && k < max && l < max && m < max)
		{
			if (s[0][i] != '\0')
			{
				printf("%c", s[0][i]);
				i++;
			}
			if (s[1][j] != '\0')
			{
				printf("%c", s[1][j]);
				j++;
			}
			if (s[2][k] != '\0')
			{
				printf("%c", s[2][k]);
				k++;
			}
			if (s[3][l] != '\0')
			{
				printf("%c", s[3][l]);
				l++;
			}
			if (s[4][m] != '\0')
			{
				printf("%c", s[4][m]);
				m++;
			}
		}
		printf("\n");
	}
	return 0;
}