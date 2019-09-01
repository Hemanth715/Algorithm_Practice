/**
 * @input A : String termination by ' * @input B : String termination by ' * 
 * @Output Integer
 */
 int m(int a,int b){
     if(a<b)return a;
     return b;
 }
 int min(int a,int b,int c){
     return m(a,m(b,c));
 }
 int func(char *str1, char *str2, int m,int n){
  int dp[m+1][n+1];
  int i,j;
    // Fill d[][] in bottom up manner
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // isnert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
 
            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                   dp[i-1][j],  // Remove
                                   dp[i-1][j-1]); // Replace
        }
    }
 
    return dp[m][n];
 }
int minDistance(char* A, char* B) {
    int m=strlen(A);
    int n=strlen(B);
    return func(A,B,m,n);
}