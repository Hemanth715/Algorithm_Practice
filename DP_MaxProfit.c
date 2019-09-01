/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maxProfit(const int* A, int n1) {
	int i, max = 0;
	int *B = (int *)malloc (n1 * sizeof(int));

	for (i = n1 - 1; i >= 0; i--)
	{
		if (A[i] > max)
		{
			max = A[i];
		}

		B[i] = max - A[i];
	}

    max = B[0];

	for (i = 0; i < n1; ++i)
	{
		if (B[i] > max)
		{
			max = B[i];
		}
	}

	return max;
}