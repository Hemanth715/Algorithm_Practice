/**
 * @input A : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
 
 int isprime(int a)
{
    int i;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}
 
int* primesum(int A, int *len1) {
    
     *len1 = 2;
    int i=2;
    int *a = (int *)malloc(2*sizeof(int));
    for(i=2;i<=A/2;i++)
    {
        //printf("\n%d %d %d %d",i,A-i,isprime(i),isprime(A-i));
        if(isprime(i)&&isprime(A-i))
        {
            a[0] = i;
            a[1] = A-i;
            return a;
        }
        if(i!=2)
            i++;
        
    }
    
    
}