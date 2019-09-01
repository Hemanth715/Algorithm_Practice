/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

int jump(int* A, int n1) {
	int dp[n1], i, j, minval;
	dp[n1 - 1] = 0;
	for (i = n1 - 2; i >= 0; --i)
	{
		if (A[i] == 0)
		{
			dp[i] = INT_MAX;
		}
		if (A[i] + i >= n1 - 1)
		{
			dp[i] = 1;
		}
		else
		{
			minval = INT_MAX;
			for (j = i + 1; j <= A[i] + i; ++j)
			{
				minval = min(dp[j], minval);
			}
			if (minval == INT_MAX)
				dp[i] = INT_MAX;
			else
				dp[i] = minval + 1;
		}
	}

	if (dp[0] == INT_MAX)
	{
		return -1;
	}
	return dp[0];
}