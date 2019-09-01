/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* searchRange(const int* A, int n1, int B, int *len1) {
	*len1 = 2;
	int *result = (int *)malloc(2 * sizeof(int));
	int l = 0, h = n1 - 1, m;
	while(l <= h)
	{
		m = l + (h - l)/2;
		if (B == A[m])
		{
			result[0] = m;
			result[1] = m;
			while (B == A[result[0]])
			{
				result[0]--;
			}
			result[0]++;
			while (B == A[result[1]])
			{
				result[1]++;
			}
			result[1]--;
			return result;
		}
		else if (B < A[m]) h = m - 1;
		else l = m + 1;
	}
	result[0] = -1;
	result[1] = -1;
	return result;
}
