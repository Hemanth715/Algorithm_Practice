/**
 * @input A : Integer
 * 
 * @Output 2D int array. You need to malloc memory. Fill in number_of_rows as row, number_of_columns as columns 
 */
int** generateMatrix(int A, int *number_of_rows, int *number_of_columns) {
    *number_of_rows = A;
    *number_of_columns = A;
    int **result = (int **)malloc(A*sizeof(int *));
    int i;
    for (i = 0; i < A; i++)
         result[i] = (int *)malloc(A * sizeof(int));
    int dir = 0;
    int alt = 1;
    int val = A;
    int j = 0, k, l = val;
    i = 0;
    for (k = 1; k <= A*A; ++k)
    {
    	result[i][j] = k;
    	l--;
    	if (l == 0)
    	{
    		dir = (dir + 1) % 4;
    		if(alt == 1)
    		{
    			alt--;
    			val--;
    		}
    		else
    			alt++;
    		l = val;
    	}
    	switch(dir)
		{
			case 0: j++; break;
			case 1: i++; break;
			case 2: j--; break;
			case 3: i--; break;
		}
    }
    /*for (i = 0; i < A; ++i)
    {
        printf("[");
    	for (j = 0; j < A; ++j)
    	{
    		printf("%d ", result[i][j]);
    	}
    	printf("]");
    }*/
    return result;
}