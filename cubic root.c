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
	long int x3;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld", &x3);
		long int minx, maxx, mid, mid3, res;
		minx = 1;
		maxx = x3;
		while (maxx > minx)
		{
			mid = (minx + maxx) / 2;
			mid3 = mid * mid * mid;
			if (mid3 == x3)
			{
				res = mid;
				break;
			}
			else if (mid3 < x3)
				minx = mid + 1;
			else
				maxx = mid - 1;
		}
		mid3 = mid * mid * mid;
		if (mid3 == x3)
			res = mid;
		else
			res = -1;
		printf("#%d %d\n", test_case, res);
	}
	return 0; //Your program should return 0 on normal termination.
}