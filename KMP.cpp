void compLPS(char *s, int m, int *lps)
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

int FindString(int n, char *b, int m, char *s)
{
	int lps[100005];

	compLPS(s, m, lps);

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