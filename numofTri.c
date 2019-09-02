#include<stdio.h>

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		int n, m, i, j, k;
		scanf("%d %d", &n, &m);
		int arr[n + 1][n + 1];
		for (i = 1; i < n + 1; i++)
		{
			for (j = 1; j < n + 1; j++)
				arr[i][j] = 0;
		}

		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &j, &k);
			arr[j][k] = 1;
			arr[k][j] = 1;
		}
		int sum = 0;

		for (i = 1; i < n + 1; i++)
		{
			for (j = i + 1; j < n + 1; j++)
			{
				if (arr[i][j] == 1)
				{
					for (k = j + 1; k < n + 1; k++)
					{
						if (arr[i][k] == 1)
						{
							if (arr[j][k] == 1)
								sum++;
						}
					}
				}
			}
		}

		printf("#%d %d\n", t, sum);
	}
	return 0;
}