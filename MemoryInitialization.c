#include<stdio.h>

char s[52];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		char c;
		int i = 0;
		int count;
		scanf("%s", s);
		count = s[i] - '0';
		c = s[i];
		i++;
		while (s[i] != '\0')
		{
			if (c != s[i])
			{
				count++;
				c = s[i];
			}
			i++;
		}
		printf("#%d %d\n", t, count);
	}
	return 0;
}