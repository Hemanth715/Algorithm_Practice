/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */

int searchInsert(int *A, int n, int x)
{
	int l = 0, h = n - 1, m;
	if (x < A[0])
	{
		return 0;
	}
	else if (x > A[h])
	{
		return n;
	}
	while(l <= h)
	{
		m = l + (h - l)/2;
		if (x == A[m]) return m;
		else if (x < A[m]) h = m - 1;
		else l = m + 1;
	}
	if (x < A[m])
		m--;
	return m+1;
}