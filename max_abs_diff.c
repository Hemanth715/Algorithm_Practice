/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

int maxArr(int* A, int n1) {
	int max = 0, temp1, temp2, temp;
	int i, j;
	for (i = 0; i < n1; ++i)
	{
		for (j = 0; j < n1; ++j)
		{
			temp1 = A[i] - A[j];
			if(temp1 < 0)
				temp1 = -temp1;
			temp2 = i - j;
			if(temp2 < 0)
				temp2 = -temp2;
			temp = temp1 + temp2;
			if (temp > max)
			{
				max = temp;
			}
		}
	}
}