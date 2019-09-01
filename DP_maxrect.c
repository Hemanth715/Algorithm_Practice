int min(int a, int b)
{
    if( a > b)
        return b;
    return a;
}
int max(int a, int b)
{
    if( a < b)
        return b;
    return a;
}
int maximalRectangle(int** A, int n11, int n12) {
    int dp[n11][n12];
    int i;
    int j;
    for(i = 0; i < n11; i++)
    {
        for(j = n12-1; j >=0 ; j--)
        {
            if(j == n12 -1)
            dp[i][j] = A[i][j];
            else
            {
                if(A[i][j] > 0)
                {
                    dp[i][j] = 1 + dp[i][j+1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    int k; int maxArr = 0;
    for(i = 0; i < n11; i++)
    {
        for(j = 0; j < n12; j++)
        {
            int w = dp[i][j];
            for(k = i; k < n11 && w > 0; k++)
            {
                w = min(w,dp[k][j]);
                maxArr = max(maxArr,(k-i + 1)*w);
            }
        }
    }
    return maxArr;
}