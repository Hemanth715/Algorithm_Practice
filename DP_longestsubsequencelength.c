/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int longestSubsequenceLength(const int* A, int n1) {
    int B[100004];
    int C[100004];
    int D[100004];
    int i,j,k,max;
    B[0]=1;
    for(i=1;i<n1;i++)
    {
        B[i]=1;
        for(j=0;j<i;j++)
        {
            if(B[j]+1>B[i] && A[j]<A[i])
            {
                B[i]=B[j]+1;
            }
        }
    }
    j=0;
    D[n1-1]=1;
     for(i=n1-2;i>=0;i--)
    {
        D[i]=1;
        for(j=i+1;j<n1;j++)
        {
            if(D[j]+1>D[i] && A[j]<A[i])
            {
                D[i]=D[j]+1;
            }
        }
    }
    for(i=0;i<n1;i++)
    {
        C[i]=D[i]+B[i]-1;
    }
    max=C[0];
    max=0;
    for(i=0;i<n1;i++)
    {
        if(C[i]>=max)
        max=C[i];
    }
    return max;
}