#include<stdio.h>

#define MAX_N 100005

char s[MAX_N];
char t[MAX_N];

int moddiff(int a, int b)
{
	if (a > b)
		return a - b;
	return b - a;
}

int main()
{
	int t1, T;
	scanf("%d", &T);
	for (t1 = 0; t1 < T; t1++)
	{
		int i = 0, j = 0;
		long long sum = 0;
		scanf("%s", s);
		scanf("%s", t);
		while (s[i] != '\0')
		{
			if (s[i] == 'a')
				i++;
			if (t[j] == 'a')
				j++;
			if (s[i] == 'b' && t[j] == 'b')
			{
				sum += (long long)moddiff(i, j);
				i++;
				j++;
			}
		}
		printf("#%d %lld\n", t1 + 1, sum);
	}
	return 0;
}