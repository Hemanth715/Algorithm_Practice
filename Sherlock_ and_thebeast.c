#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    int n[t];
    int j;
    for(int a0 = 0; a0 < t; a0++)
    {
        scanf("%d",&n[a0]);
    }
    for (int i = 0; i < t; ++i)
    {
    	if (n[i] % 3 == 0)
    	{
    		for (int j = 0; j < n[i]; ++j)
    		{
    			printf("5");
    		}
    	}
    	else if (n[i] % 5 == 0)
    	{
    		for (int j = 0; j < n[i]; ++j)
    		{
    			printf("3");
    		}
    	}
    	else if (/* condition */)
    	{
    		/* code */
    	}
    	else
    		printf("-1");
    	printf("\n");
	}
    return 0;
}
