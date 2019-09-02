#include<stdio.h>

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

int main()
{
	int t, T;
	int times[103];
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int n, m, k, i, flag = 0;
		scanf("%d %d %d", &n, &m, &k);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &times[i]);
		}
		quickSort(times, 0, n - 1);
		for (i = 0; i < n; i++)
		{
			int count = times[i] / m;
			if (count * k < i + 1)
				flag = 1;
		}
		printf("#%d ", t);
		if (flag == 0)
			printf("Possible");
		else
			printf("Impossible");
		printf("\n");
	}
	return 0;
}