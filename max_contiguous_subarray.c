 #define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
int maxSubArray(const int* A, int n1) {
      int m1=A[0];
    int m2=A[0];
    int i;
    for(i=1;i<n1;i++)
    {
        m2=max(A[i],m2+A[i]);
        m1=max(m2,m1);
    }
    
    return m1;
}
