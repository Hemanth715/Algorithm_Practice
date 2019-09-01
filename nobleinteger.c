/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int* arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    int j;
 
    for (j = low; j <= high- 1; j++)
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
 
void quickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int solve(int* A, int n1) {
	quickSort(A, 0, n1 - 1);
	int i;
	for (i = 0; i < n1; ++i)
	{
		if (n1 - 1 - i == A[i])
		{
			return 1;
		}
	}
	return -1;
}