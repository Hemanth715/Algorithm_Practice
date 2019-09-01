/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int numTrees(int A) {
	int *B = (int *) malloc ((A + 1) * sizeof(int));
	int i, j, sum;

	B[0] = 1;
	B[1] = 1;

	for (i = 2; i <= A; ++i)
	{
		sum = 0;
		for (j = 0; j < i; ++j)
		{
			sum += B[j]*B[i - j - 1];
		}
		B[i] = sum;
	}
	return B[A];
}