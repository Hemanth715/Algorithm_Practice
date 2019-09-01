/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * @input C : Integer array
 * @input n3 : Integer array's ( C ) length
 * 
 * @Output Integer
 */

int minimum (int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	else
		return c;
}

int maximum (int a, int b, int c)
{
	if (a >= b && a >= c)
		return a;
	else if (b >= a && b >= c)
		return b;
	else
		return c;
}

int solve(int* A, int n1, int* B, int n2, int* C, int n3) {
	int i = 0, j = 0, k = 0;
	int result = maximum(A[0], B[0], C[0]) - minimum(A[0], B[0], C[0]);
	int temp;
	while(i != n1 && j != n2 && k != n3)
	{
		temp = maximum(A[i], B[j], C[k]) - minimum(A[i], B[j], C[k]);
		if (temp < result)
			result = temp;
		temp = minimum(A[i], B[j], C[k]);
		if(temp == A[i])
		    i++;
		else if(temp == B[j])
		    j++;
		else
		    k++;
	}
	return result;
}