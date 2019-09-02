#include<stdio.h>

int bombx[100], bomby[100];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		int r, c, i, j, x, y, k;
		scanf("%d %d", &r, &c);
		int arr[r][c], bomb[r][c];
		k = 0;
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 0)
					bomb[i][j] = -1;
				else if (arr[i][j] == 1)
					bomb[i][j] = -2;
				else if (arr[i][j] == 2)
				{
					bomb[i][j] = 0;
					bombx[k] = i;
					bomby[k] = j;
					k++;
				}
				else
				{
					bomb[i][j] = -1;
					x = i;
					y = j;
				}
			}
		}




		/*for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				printf("%d ", bomb[i][j]);
			}
			printf("\n");
		}*/
	}
	return 0;
}