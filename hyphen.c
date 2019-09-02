#include<stdio.h>

char s[25], ans[125];
int hyp[101];

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
		int h, i, j, k;
		scanf("%s", s);
		scanf("%d", &h);
		for (i = 0; i < h; i++)
		{
			scanf("%d", &hyp[i]);
		}
		quickSort(hyp, 0, h - 1);
		i = 0;
		j = 0;
		k = 0;
		while (s[i] != '\0' && j < h)
		{
			if (hyp[j] == i)
			{
				ans[k] = '-';
				j++;
			}
			else
			{
				ans[k] = s[i];
				i++;
			}
			k++;
		}
		while (s[i] != '\0')
		{
			ans[k] = s[i];
			i++;
			k++;
		}
		while (j < h)
		{
			ans[k] = '-';
			j++;
			k++;
		}
		ans[k] = '\0';
		printf("#%d %s\n", t, ans);
	}
	return 0;
}