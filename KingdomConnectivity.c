#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int i, n, m;
	scanf("%d %d", &n, &m);
	int g[n][n];
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			g[i][j] = 0;
		}
	}
	for (i = 0; i < m; ++i)
	{
		scanf("%d %d", &x, &y);
		g[x-1][y-1] = 1;
	}
	
    return 0;
}
