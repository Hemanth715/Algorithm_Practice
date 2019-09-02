#include<stdio.h>

char s[100001];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%s", s);
		int i = 0;
		int p = 0;
		long long sum = 0;
		while (s[i] != '\0')
		{
			if (s[i] == '(' && s[i + 1] != ')')
				p++;
			else if (s[i] == '(' && s[i + 1] == ')')
			{
				sum += p;
				i++;
			}
			else if (s[i] == ')')
			{
				sum++;
				p--;
			}
			i++;
		}
		printf("#%d %lld\n", t, sum);
	}
	return 0;
}