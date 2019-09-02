#include<stdio.h>
#include<malloc.h>

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
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int n, k, i, sum = 0;
		int *a, *b;
		scanf("%d", &n);
		a = (int*)malloc(n * sizeof(int));
		b = (int*)malloc((n - 1) * sizeof(int));
		scanf("%d", &k);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		quickSort(a, 0, n - 1);

		for (i = 1; i < n; i++)
		{
			b[i - 1] = a[i] - a[i - 1];
		}

		quickSort(b, 0, n - 2);

		for (i = 0; i < n - k; i++)
		{
			sum += b[i];
		}
		printf("#%d %d\n", t, sum);
	}
	return 0;
}