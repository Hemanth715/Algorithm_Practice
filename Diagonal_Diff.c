#include <stdio.h>

void diag_diff (int **a, int n)
{
	int i, j;
	int pd = 0;
	int sd = 0;
	int diff;
	for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (j == i)
				{
					pd += a[i][j];
				}
				if (j == n-i)
				{
					sd += a[i][j];
				}
			}
		}
	diff = sd - pd;
	if (diff < 0)
		{diff *= (-1);}
	printf("%d", diff);
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    int a_i, a_j;
    for(a_i = 0; a_i < n; a_i++){
       for(a_j = 0; a_j < n; a_j++){

          scanf("%d",&a[a_i][a_j]);
       }
    }
    diag_diff((int **)a, n);
    return 0;
}
