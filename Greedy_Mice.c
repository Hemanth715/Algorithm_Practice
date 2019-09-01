/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
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

int mice(int* A, int n1, int* B, int n2) {
    quickSort(A, 0, n1 - 1);
    quickSort(B, 0, n2 - 1);
    int i = 0, diff = 0;
    while(i < n1 && i < n2)
    {
        if (abs(A[i] - B[i]) > diff)
        {
            diff = abs(A[i] - B[i]);
        }
        i++;
    }
    return diff;
}