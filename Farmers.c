#include<stdio.h>

int arr[51][51];
int temp[51][51];
int temp1[51][51];
int count[5000000];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int n, i, j, k, l;
		int sum = 0;
		scanf("%d", &n);
		for (i = 0; i < 500000; i++)
			count[i] = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - 1; j++)
			{
				for (k = i; k >= 0; k--)
				{
					for (l = j; l >= 0; l--)
					{
						if (k == i)
							temp[k][l] = arr[k][l];
						else
							temp[k][l] = temp[k + 1][l] + arr[k][l];
					}
				}

				for (k = i; k >= 0; k--)
				{
					for (l = j - 1; l >= 0; l--)
					{
						temp[k][l] = temp[k][l + 1] + temp[k][l];
					}
				}

				for (k = i; k >= 0; k--)
				{
					for (l = j; l >= 0; l--)
					{
						//printf("%d ", temp[k][l]);
						count[temp[k][l]+2500000]++;
					}
					//printf("\n");
				}

				for (k = i + 1; k < n; k++)
				{
					for (l = j + 1; l < n; l++)
					{
						if (k == i + 1)
							temp1[k][l] = arr[k][l];
						else
							temp1[k][l] = temp1[k - 1][l] + arr[k][l];
					}
				}

				for (k = i + 1; k < n; k++)
				{
					for (l = j + 2; l < n; l++)
					{
						temp1[k][l] = temp1[k][l - 1] + temp1[k][l];
					}
				}

				/*for (k = 0; k < n*n; k++)
					printf("%d ", count[k]);
				printf("\n");*/

				for (k = i + 1; k < n; k++)
				{
					for (l = j + 1; l < n; l++)
					{
						sum += count[temp1[k][l] + 2500000];
						//printf("$%d @ %d %d @ %d %d ^ %d\n", sum, i, j, k, l, count[temp1[k][l]]);
					}
				}

				for (k = i; k >= 0; k--)
				{
					for (l = j; l >= 0; l--)
					{
						count[temp[k][l] + 2500000]--;
					}
				}

				for (k = i; k >= 0; k--)
				{
					for (l = j + 1; l < n; l++)
					{
						if (k == i)
							temp[k][l] = arr[k][l];
						else
							temp[k][l] = temp[k + 1][l] + arr[k][l];
					}
				}

				for (k = i; k >= 0; k--)
				{
					for (l = j + 2; l < n; l++)
					{
						temp[k][l] = temp[k][l - 1] + temp[k][l];
					}
				}

				for (k = i; k >= 0; k--)
				{
					for (l = j + 1; l < n; l++)
					{
						//printf("%d ", temp[k][l]);
						count[temp[k][l] + 2500000]++;
					}
					//printf("\n");
				}

				for (k = i + 1; k < n; k++)
				{
					for (l = j; l >= 0; l--)
					{
						if (k == i + 1)
							temp1[k][l] = arr[k][l];
						else
							temp1[k][l] = temp1[k - 1][l] + arr[k][l];
					}
				}

				for (k = i + 1; k < n; k++)
				{
					for (l = j - 1; l >= 0; l--)
					{
						temp1[k][l] = temp1[k][l + 1] + temp1[k][l];
					}
				}

				for (k = i + 1; k < n; k++)
				{
					for (l = j; l >= 0; l--)
					{
						sum += count[temp1[k][l] + 2500000];
						//printf("$%d @ %d %d @ %d %d ^ %d\n", sum, i, j, k, l, count[temp1[k][l]]);
					}
				}

				for (k = i; k >= 0; k--)
				{
					for (l = j + 1; l < n; l++)
					{
						//printf("%d ", temp[k][l]);
						count[temp[k][l] + 2500000]--;
					}
					//printf("\n");
				}
			}
		}
		printf("#%d %d\n", t, sum);
	}
	return 0;
}