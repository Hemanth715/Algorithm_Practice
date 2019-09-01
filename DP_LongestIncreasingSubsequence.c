/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int lis(const int* A, int n1) {
    int *lcs = (int*)malloc(n1*sizeof(int));
    
    lcs[0] = 1;
    int i,j;
    int max = 1;
    for(i=1;i<n1;i++) {
        lcs[i] = 1;
        for(j=0;j<i;j++) {
            if(A[j]<A[i] && lcs[j]+1>lcs[i])
                lcs[i] = lcs[j]+1;
        }
        
        if(lcs[i]>max)
            max = lcs[i];
    }
    
    return max;
}