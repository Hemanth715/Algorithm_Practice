/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* plusOne(int* A, int n1, int *length_of_array) {
   // SAMPLE CODE
         int i, j, k, flag = 0, carry = 0;
         *length_of_array = n1 + 1; // length of result array
         int *result = (int *) malloc(*length_of_array * sizeof(int));
         int *A1 = (int *) malloc(*length_of_array * sizeof(int));
         A[n1 - 1]++;
         for (i = n1 - 1; i >= 0; --i)
         {
            A[i] += carry;
            carry = A[i] / 10;
            A[i] %= 10;
         }
         if (carry > 0)
         {
            A1[0] = carry;
            for (i = 1; i <= n1; ++i)
            {
               A1[i] = A[i - 1];
            }
         }
         else
         {
            for (i = 0; i < n1; ++i)
            {
               A1[i] = A[i];
            }
         }
         j = 0;
         while(flag == 0 && i < n1)
         {
            if (A1[i] != 0)
            {
               flag = 1;
            }
            j++;
         }
         for (i = j, k = 0; i < n1; ++i, ++k)
         {
            result[k] = A1[i];
         }
         *length_of_array = n1 - j;
         // DO STUFF HERE. NOTE : length_of_array can be n1 OR n1 + 1. 
         return result;
         
}


/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* plusOne(int* A, int n1, int *len1) {
    int i,dig,carry=1,len=0;
    int *out = (int *)malloc(sizeof(int)*(n1+1));
    int oind = n1;
    for(i=n1-1;i>=0;i--){
        out[oind--] = (A[i]+carry)%10;
        carry = (A[i]+carry)/10;
    }
    out[oind] = carry;
    for(i=0;i<n1+1&&out[i]==0;i++)
        len++;
    out = out+len;
    *len1=n1+1-len;
    return out;
}