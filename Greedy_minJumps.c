/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int jump(int* A, int n1) {
    int step=1,flag=0;
    if(n1==1)
    {
        return 0;
    }
    if(A[0]==0)
    {
        return -1;
    }
    if(A[0]>=n1)
    {
        return 1;
    }
    
    call(A,n1,0,A[0],&step,&flag);
    if(flag==0)
    {
        return -1;
    }
    return step;
}
int call(int* A,int n1,int sind ,int eind,int *step,int *flag)
{
     
    int max=0,i,start=0,end=0;
   // printf("sind  %d eind  = %d\n",sind,eind);
    for(i=sind+1;i<=eind;i++)
    {
        
        if(A[i]+i>=max&&A[i]!=0)
        {
            
            max = A[i]+i;
            start = i;
            end = A[i]+i;
           // printf("max = %d , A[%d] = %d \n",max,i,A[i]);
            if(max>=n1-1&&sind!=eind)
            {
               // printf("yes1\n");
                *flag=1;
                *step = *step+1;
                return ;
            }
        }
    }
    //printf("start %d end  = %d\n",start,end);
    if(max==0)
    {
        //printf("yes2\n");
        return 0;
    }
    *step = *step+1;
    sind = start;
    eind = end;
    call(A,n1,sind,eind,step,flag);
}