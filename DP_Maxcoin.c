/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int maxcoin(int* A, int n1) {
	int i = 0, j = n1-1;
	int a[2];
	a[0] = 0;
	a[1] = 0;
	int turn = 0;
	while(i <= j)
	{
		if(A[i] > A[j])
		{
			a[turn] += A[i];
			i++;
		}
		else
		{
			a[turn] += A[j];
			j--;
		}
		turn = (turn+1)%2;
	}
	return max(a[0], a[1]);
}