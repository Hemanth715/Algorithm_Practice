/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 *
 * typedef struct Interval interval;
 */
/*
 * intervals : the array of interval
 * sz : number of entries in intervals
 * newInterval : new Interval to be inserted
 * len : populate the length of returned array of intervals in len
 */
interval* insert(interval *intervals, int sz, interval newInterval, int *len) {
    *len=sz+1;
    interval* result = (interval*)malloc(*len*sizeof(interval));
    int old,i,nw=0;
    for(i=0;i<sz && intervals[i].start<newInterval.start;i++)
    {
        result[nw].start=intervals[i].start;
        result[nw++].end=intervals[i].end;
    }
    if(nw!=0 && intervals[i-1].end>=newInterval.start)
    result[--nw].end=(intervals[i-1].end>=newInterval.end)?intervals[i-1].end:newInterval.end;
    else
    {
        result[nw].start=newInterval.start;
        result[nw].end=newInterval.end;
    }
    for(old=i;old<sz;old++)
    {
        if(result[nw].end>=intervals[old].start)
    result[nw].end=(result[nw].end>=intervals[old].end)?result[nw].end:intervals[old].end;
        else
        {
            result[++nw].start=intervals[old].start;
            result[nw].end=intervals[old].end;
        }
    }
    *len=nw+1;
    return result;
    
}