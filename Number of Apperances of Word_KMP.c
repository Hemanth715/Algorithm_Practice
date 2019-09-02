#include<stdio.h>

char b[500002];
char s[100002];
int lps[100002];
int n, m;

void compLPS()
{
	int l = 0, i = 1;
	lps[0] = 0;
	while (i < m)
	{
		if (s[i] == s[l])
		{
			l++;
			lps[i] = l;
			i++;
		}
		else
		{
			if (l != 0)
				l = lps[l - 1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int KMP()
{
	compLPS();

	int i = 0, j = 0, count = 0;

	while (i < n)
	{
		if (s[j] == b[i])
		{
			j++;
			i++;
		}

		if (j == m)
		{
			count++;
			j = lps[j - 1];
		}

		else if (i < n && s[j] != b[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}
	return count;
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		n = 0;
		m = 0;
		scanf("%s", b);
		scanf("%s", s);
		while (b[n] != '\0')
			n++;
		while (s[m] != '\0')
			m++;
		printf("#%d %d\n", t, KMP());
	}
	return 0;
}