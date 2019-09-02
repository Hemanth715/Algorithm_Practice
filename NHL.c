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
	int n, k;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int i, j, count, maxn, minn, midn, res;
		scanf("%d %d", &n, &k);
		int nval[n], kval[k];
		for (i = 0; i < n; i++)
		{
			scanf("%d", &nval[i]);
			if (i == 0)
			{
				maxn = nval[i];
				minn = nval[i];
			}
			else
			{
				if (nval[i] > maxn)
					maxn = nval[i];
				if (nval[i] < minn)
					minn = nval[i];
			}
		}
		for (i = 0; i < k; i++)
			scanf("%d", &kval[i]);
		res = maxn;
		while (maxn >= minn)
		{
			midn = (maxn + minn) / 2;
			i = 0;
			j = 0;
			count = 0;
			while (j < k && i < n)
			{
				if (nval[i] > midn)
					count = 0;
				else
				{
					count++;
					if (count == kval[j])
					{
						j++;
						count = 0;
					}
				}
				i++;
			}
			if (j == k)
			{
				maxn = midn - 1;
				res = midn;
			}
			else
				minn = midn + 1;
		}
		printf("#%d %d\n", test_case, res);
	}
	return 0; //Your program should return 0 on normal termination.
}