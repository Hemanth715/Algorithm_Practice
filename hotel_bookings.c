/**
 * @input arrive : Integer array
 * @input n1 : Integer array's ( arrive ) length
 * @input depart : Integer array
 * @input n2 : Integer array's ( depart ) length
 * @input K : Integer
 * 
 * @Output Integer 0 / 1. 0 if not possible, else 1. 
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

// int hotel(int* arrive, int n1, int* depart, int n2, int max) {
// 	quickSort(arrive, 0, n1 - 1);
// 	quickSort(depart, 0, n2 - 1);
// 	int i, j = 0, k = 0, curr = 0;
// 	int size = depart[n2 - 1];
// 	for (i = 0; i < size; ++i)
// 	{
// 		while (arrive[j] == i && j < n1)
// 		{
// 			curr++;
// 			j++;
// 		}
// 		while (depart[k] == i && k < n2)
// 		{
// 			curr--;
// 			k++;
// 		}
// 		if (curr > max)
// 		{
// 			return 0;
// 		}
// 	}
// 	return 1;
// }

int hotel(int* arrive, int n1, int* depart, int n2, int max) {
	quickSort(arrive, 0, n1 - 1);
	quickSort(depart, 0, n2 - 1);
	int j = 0, k = 0, curr = 0;
	while(k < n11)
	{
		if (j == n11)
		{
			return 1;
		}
		if (arrive[j] == depart[k])
		{
			j++;
			k++;
		}
		else if (arrive[j] < depart[k])
		{
			curr++;
			j++;
		}
		else
		{
			curr--;
			k++;
		}
		if (curr > max)
		{
			return 0;
		}
	}
	return 1;
}