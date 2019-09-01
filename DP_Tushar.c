/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Read only ( DON'T MODIFY ) Integer array
 * @input n2 : Integer array's ( B ) length
 * @input C : Read only ( DON'T MODIFY ) Integer array
 * @input n3 : Integer array's ( C ) length
 * 
 * @Output Integer
 */

int memo[1001][1001];
int end;

int min(int a, int b, int c)
{
	if (a >= b && c >= b)
		return b;
	else if (a >= c && b >= c)
		return c;
	else
		return a;
}

int DP(const int *B, const int *C, int i, int X)
{
	if (X < 0 || i >= end)
	{
		return INT_MIN;
	}
	if (X == 0)
	{
		memo[i][X] = 0;
		return 0;
	}
	if (memo[i][X] != -1)
	{
		return memo[i][X];
	}
	memo[i][X] = min(DP(B, C, i + 1, X), DP(B, C, i + 1, X - C[i]) + B[i], DP(B, C, i, X - C[i]) + B[i]);
	return memo[i][X];

}

int solve(const int* A, int n1, const int* B, int n2, const int* C, int n3) {
	int *resarray = (int *) malloc (n1 * sizeof(int));
	int r, i, j;
	end = n2;
	int sum = 0;
	for (r = 0; r < n1; ++r)
	{
		for (i = 0; i <= n2; ++i)
		{
			for (j = 0; j <= A[r]; ++j)
			{
				memo[i][j] = -1;
			}
		}
		resarray[r] = DP(B, C, 0, A[r]);
	}
	for (i = 0; i < n1; ++i)
	{
		sum += resarray[i];
	}
	return sum;
}