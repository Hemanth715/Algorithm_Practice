/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maxProfit(const int* A, int n1) {
	int i, max = 0;
	int *B = (int *)malloc (n1 * sizeof(int));
	max = A[n1 - 1];
	B[n1 - 1] = 0;

	for (i = n1 - 2; i >= 0; i--)
	{
		if (A[i] > A[i + 1])
		{
			max = A[i];
		}

		B[i] = max - A[i];
	}

    int sum = B[0];

	for (i = 0; i < n1 - 1; ++i)
	{
		if (B[i] == 0)
		{
			sum += B[i + 1];
		}
	}

	return sum;
}