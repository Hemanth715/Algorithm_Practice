#include <stdio.h>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

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
	int arr[7];
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int i, j, k, count = 4;
		for (i = 0; i < 7; i++)
			scanf("%d", &arr[i]);
		quickSort(arr, 0, 6);
		i = 3; j = 5; k = 6;
		while (count > 0)
		{
			
		}
	}
	return 0; //Your program should return 0 on normal termination.
}