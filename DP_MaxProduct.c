/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maxProduct(const int* A, int n1) {
	int start, neg, negcount, max;
	int i, dp[n1];
	start = 0;
	neg = -1;
	negcount = 0;
	max = 0;
	for (i = 0; i < n1; ++i)
	{
		if (A[i] == 0)
		{
			dp[i] = 0;
			start = i + 1;
			negcount = 0;
		}
		else if (A[i] < 0)
		{
			negcount++;
			if (negcount % 2 == 1)
			{
				neg = i;
				if (i == start)
				{
					dp[i] = A[i];
				}
				else
					dp[i] = dp[i - 1];
			    start = i + 1;
			}
			else
			{
			    if (i == neg + 1)
			    {
			    	dp[i] = dp[neg] * A[i];
			    }
			    else
					dp[i] = dp[neg] * dp[i - 1] * A[i];
			}
		}
		else
		{
		    if (i == start)
		        dp[i] = A[i];
		    else
			    dp[i] = dp[i - 1] * A[i];
		}
		if (dp[i] > max)
		{
			max = dp[i];
		}
	}
	return max;
}
