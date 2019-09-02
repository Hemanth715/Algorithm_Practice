#include <stdio.h>

int main(void)
{
	int test_case;
	int T;
	/*
	freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	// freopen("input.txt", "r", stdin);
	/*
	If you remove the statement below, your program's output may not be recorded
	when your program is aborted due to the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	Read each test case from standard input.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m, i, j, k;
		scanf("%d %d", &n, &m);
		int p[m];
		int a[n], b[n], c[n], count[n];
		for (i = 0; i < m; i++)
			scanf("%d", &p[i]);
		for (i = 1; i < n; i++)
		{
			count[i] = 0;
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
		}
		j = p[0];
		for (i = 1; i < m; i++)
		{
			if (p[i] > p[i - 1])
			{
				while (j < p[i])
				{
					count[j]++;
					j++;
				}
			}
			else
			{
				while (j > p[i])
				{
					j--;
					count[j]++;
				}
			}
			/*for (k = 0; k < n - 1; k++)
			printf("%d\n", count[k]);
			printf("\n");*/
		}
		int sum = 0;
		for (i = 1; i < n; i++)
		{
			if (a[i] * count[i] < (b[i] * count[i]) + c[i])
				sum += a[i] * count[i];
			else
				sum += (b[i] * count[i]) + c[i];
		}
		for (k = 1; k < n; k++)
			printf("%d ", count[k]);
		printf("\n");
		printf("#%d %d\n", test_case, sum);
	}
	return 0; //Your program should return 0 on normal termination.
}