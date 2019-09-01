/**
 * @input A : 2D integer array ++
 * @input n11 : Integer array's ( A ) rows
 * Each row in the 2D array starts with the size of the row. A[i][0] represents the number of elements in row i. 
 * 
 * @Output Integer
 */
 #define min(a,b) ((a<b)?a:b)
int minimumTotal(int** A, int n11) {
    int i,j;
    int sum=0;
    int size;
    int *B=malloc((n11)*sizeof(int));
    size=A[n11-1][0];
    for(i=0;i<size;i++) {B[i]=A[n11-1][i+1];}
    for(i=n11-2;i>=0;i--)
    {
      size=A[i][0];
      for(j=0;j<size;j++)
      {
          B[j]=min(B[j],B[j+1])+A[i][j+1];
      }
    }
    return B[0];
}