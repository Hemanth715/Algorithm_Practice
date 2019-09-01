/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int diffPossible(int* A, int n1, int B) {
	int i = n1 - 2, j = n1 - 1;
	while (i >= 0 && j >= 0)
	{
		if(i != j && A[j] - A[i] == B) return 1;
		if(i != j && A[j] - A[i] > B) j--;
		else i--;
	}
	return 0;
}
