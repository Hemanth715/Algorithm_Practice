#define MAXN 500000

int a1[MAXN], a2[MAXN];

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
		if (arr[j] >= pivot)
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

void init(int n, const int api1[], const int api2[])
{
	int i;
	for (i = 0; i < n; i++)
	{
		a1[i] = api1[i];
		a2[i] = api2[i];
	}
	quickSort(a1, 0, n - 1);
	quickSort(a2, 0, n - 1); 
}

void findSlowestServers(int k, int slowest[])
{
	int i = 0, j = 0, l = 0;
	while (l < k)
	{
		slowest[l] = a1[i] + a2[j];
		l++;
		if (a1[i] + a2[j + 1] == a1[i + 1] + a2[j])
		{
			if (l >= k)
				return;
			j++;
			slowest[l] = a1[i] + a2[j];
			l++;
			i++;
		}
		else if (a1[i] + a2[j + 1] > a1[i + 1] + a2[j])
			j++;
		else
			i++;
	}
}