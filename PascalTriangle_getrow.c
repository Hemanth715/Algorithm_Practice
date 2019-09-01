/**
 * @input A : Integer
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* getRow(int A, int *length_of_array) {
	*length_of_array = A + 1;
	int i, j;
	int **result = (int **)malloc((A + 1) * sizeof(int *));
	for (i = 0; i < A + 1; ++i)
	{
		result[i] = (int *)malloc((i + 1) * sizeof(int));
		result[i][0] = 1;
		result[i][i] = 1;
	}
	for (i = 1; i < A + 1; ++i)
	{
		for (j = 1; j < i; ++j)
		{
			result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
	}
	return result[A];
	 
}
