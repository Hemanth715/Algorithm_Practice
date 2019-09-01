/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maxp3(int* A, int n1) {
    int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN,min1=INT_MAX,min2=INT_MAX,i;
    for(i=0;i<n1;i++)
    {
        if(A[i]>=max1)
        {
            max3=max2;
            max2=max1;
            max1=A[i];
        }
        else if(A[i]>=max2)
        {
            max3=max2;
            max2=A[i];
        }
        else if(A[i]>max3)
            max3=A[i];
        if(A[i]<=min1)
        {
            min2=min1;
            min1=A[i];
        }
        else if(A[i]<min2)
            min2=A[i];
    }
    return ((max1*max2*max3>max1*min1*min2)?(max1*max2*max3):(max1*min1*min2));
}