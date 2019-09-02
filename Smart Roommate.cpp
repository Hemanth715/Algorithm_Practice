int c[20000002];

long long findSequences(int *a, int n)
{
	int i, j;
	long long count = 0;
	int *b = new int[n + 1];
	b[0] = a[0];
	if (b[0] == 0)
		count++;
	for (i = 1; i < n; i++)
	{
		b[i] = b[i - 1] + a[i];
		if (b[i] == 0)
			count++;
		c[b[i] + 10000000] = 0;
	}
	for (i = n - 1; i >= 0; i--)
	{
		c[b[i] + 10000000]++;
	}
	for (i = n - 1; i >= 0; i--)
	{
		c[b[i] + 10000000]--;
		count += c[b[i] + 10000000];
	}
	return count;
}