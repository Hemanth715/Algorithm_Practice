/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int bulbs(int* A, int n1) {
	int i;
	int k = 0, count = 0;
	for (i = 0; i < n1; ++i)
	{
		if (A[i] == k)
		{
			count++;
			k++;
			k %= 2;
		}
	}
	return count;
}