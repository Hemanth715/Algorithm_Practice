#include<stdio.h>

char a[500002];
char b[500002];
char c[1000002];
int lps[500002];
int n, m;

void compLPS()
{
	int l = 0, i = 1;
	lps[0] = 0;
	while (i < m)
	{
		if (b[i] == b[l])
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

	int i = 0, j = 0;

	while (i < n)
	{
		if (b[j] == c[i])
		{
			j++;
			i++;
		}

		if (j == m)
		{
			return i - j;
			j = lps[j - 1];
		}

		else if (i < n && b[j] != c[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}
	return -1;
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		n = 0;
		scanf("%s", a);
		scanf("%s", b);
		while (a[n] != '\0')
		{
			c[n] = a[n];
			n++;
		}
		m = 0;
		while (m < n)
		{
			c[m + n] = a[m];
			m++;
		}
		n = 2 * n;
		printf("#%d %d\n", t, KMP());
	}
	return 0;
}