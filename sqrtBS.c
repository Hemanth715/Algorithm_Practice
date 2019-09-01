/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int Sqrt(int A) {
	int l = 1, h = A - 1, m;
	while(l <= h)
	{
		m = l + (h - l)/2;
		if (m*m <= A && (m+1)*(m+1) > A) return m;
		else if ((m+1)*(m+1) <= A) l = m + 1;
		else h = m - 1;
	}
	return -1;
}
