#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n, k, q, i, m, v;
	scanf("%d %d %d", &n, &k, &q);
	int a[n], u[q];
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < q; ++i)
	{
		scanf("%d", &u[i]);
	}
	for (i = 0; i < q; ++i)
	{
		if(u[i] < k)
			v = n + u[i] - k;
		else
			v = u[i] - k;
		printf("\n%d", a[u[v]]);
	}
    return 0;
}
