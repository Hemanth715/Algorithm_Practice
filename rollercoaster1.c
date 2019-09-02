#define mod 1000000009


void swap(int *a, int *b){
	int t = *a; *a = *b, *b = t;
}

bool compare(int a1, int b1, int a2, int b2){
	return (((long long)b1*a2) + b2) <  (((long long)b2*a1) + b1);
}

int partition(int arr[], int*a, int *b, int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (compare(a[arr[j]], b[arr[j]], a[pivot], b[pivot]))
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quickSort(int arr[], int *a, int *b, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, a, b, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, a, b, low, pi - 1);
		quickSort(arr, a, b, pi + 1, high);
	}
}







int MinRailSpeed(int N, int *a, int *b){
	int arr[N];
	for (int i = 0; i<N; i++) arr[i] = i;
	quickSort(arr, a, b, 0, N - 1);
	int v = 1;

	for (int i = 0; i < N; i++) {

		int CurRail = arr[i];

		v = (int)(((long long)(a[CurRail])*v + b[CurRail]) % 1000000007);
	}

	return v;

}
