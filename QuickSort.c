#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void partition(int ar_size, int *  ar) {
	int left[ar_size], right[ar_size], equal[ar_size];
	int i, l = 0, e = 1, r = 0;
	equal[0] = ar[0];
	for (i = 1; i < ar_size; ++i)
	{
		if (ar[i] == ar[0])
		{
			equal[e] = ar[i];
			e++;
		}
		else if (ar[i] > ar[0])
		{
			right[r] = ar[i];
			r++;
		}
		else
		{
			left[l] = ar[i];
			l++;
		}
	}
	for (i = 0; i < l; ++i)
	{
		printf("%d ", left[i]);
	}
	for (i = 0; i < e; ++i)
	{
		printf("%d ", equal[i]);
	}
	for (i = 0; i < r; ++i)
	{
		printf("%d ", right[i]);
	}
}
int main(void) {

	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
		scanf("%d", &_ar[_ar_i]); 
	}
	partition(_ar_size, _ar);
	return 0;
}
