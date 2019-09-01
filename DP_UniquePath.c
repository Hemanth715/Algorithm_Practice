/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer
 */
void findPath(int** A, int n11, int n12, int i, int j, int *paths){
    if(i == n11-1 && j == n12-1 && A[i][j] != 1)
        *paths = *paths + 1;
    if( i >= n11 || j >= n12)
        return;
    if(A[i][j] == 1)
        return;
    findPath(A,n11,n12,i+1,j,paths);
    findPath(A,n11,n12,i,j+1,paths);
        
} 
 
int uniquePathsWithObstacles(int** A, int n11, int n12) {
    int paths = 0;
    findPath(A,n11,n12,0,0,&paths);
    return paths;
}