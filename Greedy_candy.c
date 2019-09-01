/**
 * @input ratings : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int candy(int* ratings, int n1) {
    int candy[n1],i,sum=0;
    for(i=0;i<n1;i++)
        candy[i]=1;
    for(i=1;i<n1;i++)
        if(ratings[i]>ratings[i-1])  
            candy[i]=candy[i-1]+1;
    for(i=n1-1;i>0;i--)
        if(ratings[i-1]>ratings[i] && candy[i-1]<=candy[i])
            candy[i-1]=candy[i]+1;
    for(i=0;i<n1;i++)
        sum+=candy[i];
    return sum;
    
}