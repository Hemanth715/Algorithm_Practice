/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Void. Just modifies the args passed by reference 
 */
void sortColors(int* A, int n1) {
	int i, B[3];
	for (i = 0; i < n1; ++i)
	{
		B[A[i]]++;
	}
	for (i = 0; i < B[0]; ++i)
	{
		A[i] = 0;
	}
	for (i = 0; i < B[1]; ++i)
	{
		A[i + B[0]] = 1;
	}
	for (i = 0; i < B[2]; ++i)
	{
		A[i + B[0] + B[1]] = 2;
	}
}