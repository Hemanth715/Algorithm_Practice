/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
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

int* wave(int* A, int n1, int *len1) {
	int *B = (int *)malloc(n1 * sizeof(int));
	*len1 = n1;
	int i;
	for (i = 0; i < n1; ++i)
	{
		B[i] = A[i];
	}
	quickSort(B, 0, n1 - 1);
	for (i = 1; i < n1; i += 2)
	{
		swap(&B[i], &B[i - 1]);
	}
	return B;
}