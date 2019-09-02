#include <stdio.h>

int arr[1000];

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
	//setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	Read each test case from standard input.
	*/
	int n, q, i;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &n, &q);
		int l, r, j;
		for (i = 0; i < n; i++)
			arr[i] = 0;
		for (i = 1; i <= q; i++)
		{
			scanf("%d %d", &l, &r);
			for (j = l - 1; j < r; j++)
				arr[j] = i;
		}
		printf("#%d ", test_case);
		for (i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	return 0; //Your program should return 0 on normal termination.
}