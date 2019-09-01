#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
    int t; 
    scanf("%d",&t);
    if (t > 10 || t < 1)
        {
        	return 0;
        }
    int ans[t];
    int pr;
    for(int a0 = 0; a0 < t; a0++)
    {
        ans[a0] = 0;
        int n;
        int k;
        scanf("%d %d",&n,&k);
        if (k > n || k < 1)
        {
        	return 0;
        }
        if (n > 1000 || n < 1)
        {
        	return 0;
        }
        int a[n];
        pr = 0;
        for(int a_i = 0; a_i < n; a_i++)
        {
           scanf("%d",&a[a_i]);
            if (a[a_i] > 100 || a[a_i] < -100)
        	{
        		return 0;
        	}
           if (a[a_i] <= 0)
           {
            pr++;
           }
        }
        if (pr < k)
        {
        	ans[a0]++;
        }
    }

    for (int i = 0; i < t; ++i)
    {
    	if (ans[i] == 1)
    	{
    		printf("YES\n");
    	}
    	else
    	{
    		printf("NO\n");
    	}
    }
    return 0;
}
