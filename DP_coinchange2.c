/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */

int store[100000];

int DP(int* A, int n1, int B)
{
	int i;
	int sum = 0;
	if (B == 0)
	{
		return 1;
	}
	else if (B < 0)
	{
		return 0;
	}
	if (store[B] != -1)
	{
		return store[B];
	}
	for (i = 0; i < n1; ++i)
	{
		sum += DP(A, n1, B - A[i]);
	}
	store[B] = sum;
	return store[B];
}

int coinchange2(int* A, int n1, int B) {
	int i;
	for (i = 0; i <= B; ++i)
	{
		store[i] = -1;
	}
	int val = DP(A, n1, B);
	return (val % 1000007);
}