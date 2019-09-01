/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer
 */
int solve(int** A, int n11, int n12) {
    int i,j,k,max,freq[n11+1];
    int dp[n11][n12];
    for(i=0;i<n12;i++){
        if(A[0][i]==1)
            dp[0][i]=1;
        else
            dp[0][i]=0;    
    }
    for(i=0;i<n12;i++){
        for(j=1;j<n11;j++){
            if(A[j][i]==1)
                dp[j][i]=dp[j-1][i]+1;
        
            else
                dp[j][i]=0;
        }
    }
    max=0;
    for(i=0;i<n11;i++){
        for(j=0;j<=n11;j++){
            freq[j]=0;
        }
        for(j=0;j<n12;j++){
            freq[dp[i][j]]++;
        }
        for(j=n11-1;j>0;j--){
            freq[j]+=freq[j+1];
        }
        for(j=n11;j>0;j--){
            if(max<(freq[j]*j))
                max=freq[j]*j;
        }
    }
    return max;
}
