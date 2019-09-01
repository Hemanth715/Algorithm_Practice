int NextNum(int * cur, int start,int pos,int count,int total, int ** out, int high){
    int i;
    if(start > high)
        return count;
    if(high-start < total-1-pos)
        return count;

    if(pos==total || (pos==total-1 && start==high)){
        out[count]=(int *)(malloc(sizeof(int)* total));
      
        if(pos==total-1)
            cur[pos]=high;
        for(i=0;i<total;i++)
           out[count][i]=cur[i];
        
        count ++;
        return count;
    } 
    if(start)
    cur[pos]=start;
    count=NextNum(cur,start+1,pos+1,count,total,out,high);
    count=NextNum(cur,start+1,pos,count,total,out,high);
    return count;
    
}

int ** combine(int n, int k, int *len1, int *len2) {
    int ** out = (int **)(malloc(sizeof(int*)*1000));
    int * cur = (int *)(malloc (sizeof(int)* k));
    if(k==0){
        *len1=0;
        *len2=0;
        return out;
    }
    int count = NextNum(cur,1,0,0,k,out,n);
    
    *len1=count;
    *len2=k;
    return out;
}