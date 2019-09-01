int cmp(const void* a,const void* b)
   {
       return  ((interval *)a)->start-((interval *)b)->start;
   }
interval* merge(interval *intervals, int sz, int *len) {
  interval* newint=(interval *)malloc(sizeof(interval)*sz);
  qsort(intervals,sz,sizeof(interval),cmp);
  int i,count=0;
  for(i=0;i<sz;i++)
     { int pos=i;
         while(intervals[pos].end>=intervals[i+1].start && i+1<sz)
          {  int max=intervals[pos].end>intervals[i+1].end?intervals[pos].end:intervals[i+1].end;
             intervals[pos].end=max;
             ++i;
          }
          
          newint[count].start=intervals[pos].start;
          newint[count].end=intervals[pos].end;
          ++count;
          }
    *len=count;
    return newint;
}