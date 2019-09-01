/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, and first entry in result array must be size of that row.  
 */
int ** diagonal(int** A, int n11, int n12, int *len1) {
	*len1 = (2 * n11) - 1;
	int** result = (int **) malloc ((*len1) * sizeof(int *));
	int i, j, k, l;
	for (i = 0; i < *len1; ++i)
	{
		if ((i + 1) <= n11)
		{
			j = i + 1;
		}
		else
		{
			j = (2 * n11) - i - 1;
		}
		result[i] = (int *) malloc (j * sizeof(int));
		result[i][0] = j;
	}
	
// 	printf("//");

	for (i = 0; i < n11; ++i)
	{
		j = 0;
		k = i;
		while(k >= 0)
		{
			result[i][j + 1] = A[j][k];
			k--;
			j++;
		}
	}

	for (i = 1; i < n11; ++i)
	{
	    l = 1;
		j = i;
		k = n11 - 1;
		while(j <= n11 - 1)
		{
			result[n11 + i - 1][l] = A[j][k];
			k--;
			j++;
			l++;
		}
	}
	
// 	result[(*len1) - 1][1] = A[n11 - 1][n11 - 1];

	return result;
}