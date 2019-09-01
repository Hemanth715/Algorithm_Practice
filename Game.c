#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i_t = 0; i_t < t; ++i_t)
    {
    	long int n, q, i;
    	int flag = 0, rc = 0;
    	scanf("%ld %ld", &n, &q);
    	int a[n][3];
    	for (i = 0; i < n; ++i)
    	{
    		a[i][0] = 0;
    		a[i][1] = 0;
    		a[i][2] = 0;
    	}
    	for (i = 0; i < q; ++i)
    	{
    		long int x, y;
    		scanf("%ld %ld", &x, &y);
    		a[x-1][y-1] = 1;
    	}
    	i = 0;
    	while(i < n && flag == 0){
    		rc = a[i][0] + a[i][1] + a[i][2];
    		if (rc == 3)
    		{
    			flag = 1;
    		}
    		else if (rc == 2)
    		{
    			if (a[i][0] > 0 && a[i][1] > 0 && a[i+1][2] > 0 && a[i+1][1] > 0)
    			{
    				flag = 1;
    			}
    			else if (a[i][2] > 0 && a[i][1] > 0 && a[i+1][0] > 0 && a[i+1][1] > 0)
    			{
    				flag = 1;
    			}
    		}
    		i++;
    		rc = 0;
    	}
    	if (flag == 1)
    	{
    		printf("%ld\n", i - 1);
    	}
    	else
    		printf("%ld\n", n);
    }
}
