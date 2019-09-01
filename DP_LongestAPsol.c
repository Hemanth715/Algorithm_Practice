/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

int solve(const int* A, int n1) {
 
   int table[n1][n1];
   int i,j,k;
   int pos;
   int max_len=2;
   
   
   if(n1<=1)
    return n1;
    
   for(i=0; i<n1-1; i++)
   {
       for(j=i+1; j<n1; j++)
       {
           table[i][j]=2;
           pos=-1;
           for(k=i-1; k>=0; k--)
           {
               if(A[k]==(2*A[i]-A[j]))
               {
                pos=k;
                break;
               }
           }
           if(pos!=-1)
           {
               if(table[i][j]<(table[pos][i]+1))
               {
                    table[i][j]=table[pos][i]+1;
                    if(max_len<table[i][j])
                        max_len=table[i][j];
               }
           }
       }
   }
   
   return max_len;
    
}