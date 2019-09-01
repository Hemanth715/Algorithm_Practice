/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int canJump(int* A, int n1) {
    
    int dp[n1],i,j;
    if(n1<2)
    return 1;
    
    j=n1;
    for(i=n1-1;i>=0;i--)
    {
        if(A[i]+i>=j)
        j=i;
        
        
    }
    if(j==0)
    	return 1;
    else
    	return 0;
    
    
}