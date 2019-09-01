/**
 * @input A : Integer
 * @input B : Integer
 * 
 * @Output Integer
 */

int C[10000][10000];

int DP(int A, int B)
{
	int sum = 0, i;
	if (B < 0)
	{
		return 0;
	}
	if (A == 1 && B <= 9)
	{
		return 1;
	}
	if (C[A - 1][B - 1] != -1)
	{
		return C[A - 1][B - 1];
	}
	for (i = 0; i <= 9; ++i)
	{
		sum += DP(A - 1, B - i);
	}
	C[A - 1][B - 1] = sum;
	return sum;
}

int solve(int A, int B) {
	int i, j, sum = 0;
	for (i = 0; i < A; ++i)
	{
		for (j = 0; j < B; ++j)
		{
			C[i][j] = -1;
		}
	}

	for (i = 1; i <= 9; ++i)
	{
		sum += DP(A - 1, B - i);
	}
	return (sum % 1000000007);
}