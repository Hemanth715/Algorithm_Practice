/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer
 */

int min(int a, int b)
{
	if (a >= b)
		return b;
	else
		return a;
}

int minPathSum(int** A, int n11, int n12) {
	int i, j;
	int **B = (int **)malloc(n11 * sizeof(int *));
	for (i = 0; i < n11; ++i)
	{
		B[i] = (int *)malloc(n12 * sizeof(int));
	}
	for (i = n11 - 1; i >= 0; --i)
	{
		for (j = n12 - 1; j >= 0; --j)
		{
			if (i == n11 - 1 && j == n12 - 1)
			{
				B[i][j] = A[i][j];
			}
			else if (i == n11 - 1)
			{
				B[i][j] = A[i][j] + B[i][j + 1];
			}
			else if (j == n12 - 1)
			{
				B[i][j] = A[i][j] + B[i + 1][j];
			}
			else
			{
				B[i][j] = A[i][j] + min(B[i][j + 1], B[i + 1][j]);
			}
		}
	}
	return B[0][0];
}