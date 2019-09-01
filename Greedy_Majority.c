/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int majorityElement(const int* A, int n1) {
    int element=A[0],count=1,i;
    for(i=1;i<n1;i++)
    {
        if(A[i]==element)
        count++;
        else 
        {
            if(count>0)
            count--;
            else
            {
                element=A[i];
                count=1;
            }
        }
    }
    return element;
}