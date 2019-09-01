/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

int B[10000][10000];

int DP(int i, int j, int diff)
{
	int k, val, maxval = 0;
	for (k = j + 1; k < n1; ++k)
	{
		if (B[j][k] == diff)
		{
			val = DP(j, k, diff);
			if (val > maxval)
			{
				maxval = val;
			}
		}
	}
	return (maxval + 1);
}

int solve(const int* A, int n1) {
	int i, j;
	for (i = 0; i < n1; ++i)
	{
		for (j = i + 1; j < n1; ++j)
		{
			B[i][j] = A[j] - A[i];
		}
	}

	int k, max = 1;

	for (i = 0; i < n1; ++i)
	{
		for (j = i + 1; j < n1; ++j)
		{
			k = DP(i, j, B[i][j]);
			if (k > max)
			{
				max = k;
			}
		}
	}
}