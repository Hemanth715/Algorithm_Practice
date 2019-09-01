int ** prettyPrint(int A, int *number_of_rows, int *number_of_columns) {
    printf("A");
	*number_of_rows = (2*A)-1;
    *number_of_columns = (2*A)-1;
    int **result = (int **)malloc(((2*A)-1) * sizeof(int *));
    int i, j, k, val;
    for (i = 0; i < ((2*A)-1); i++)
         result[i] = (int *)malloc(((2*A)-1) * sizeof(int));
    result[A-1][A-1] = 1;
    for (i = 0; i < A; i++)
    {
        k = i;
        val = A;
        for (j = 0; j < A-1; j++)
        {
            if(k != 0)
            {
                val--;
                k--;
            }
            result[i][j] = val;
            result[((2*A)-2)-i][j] = val;
            result[((2*A)-2)-i][((2*A)-2)-j] = val;
            result[i][((2*A)-2)-j] = val;
        }
    }
    return result;
}