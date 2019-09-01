/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row
 * For each row i, A[i][0] should indicate the number of columns in row i.
 * Then A[i][1] to A[i][col] should have the values in those columns.
 */
 int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
 
 
 int row;
 void powersetRec(int *A, int *s, int **arr, int k, int m, int n) {
    int i, j;
    if (m < n) {
        s[k+1] = A[m];
        for(i = 0, j = 1; i <=k+1; i++)
        {
            arr[row] = realloc(arr[row], (j+1) * sizeof(int));
            arr[row][j++] = s[i];
        }
        arr[row][0] = j - 1;
        row++;
        powersetRec(A, s, arr, k+1, m+1, n) ; 
        powersetRec(A, s, arr, k, m+1, n) ; 
    }
}
int ** subsets(int* A, int n1, int *len1) {
    int i, j,k, num, **arr, s[n1];
    num = pow(2, n1);
    row = 1;
    qsort(A, n1, sizeof(int), cmpfunc);
    *len1 = num;
    arr = (int **) malloc(num * sizeof(int *));
    for (i = 0; i < num; i++)
    {
        arr[i] = (int *)malloc(sizeof(int));
    }
    arr[0][0] = 0;
    powersetRec(A, s, arr, -1, 0, n1);
    return arr;
}