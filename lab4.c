#include <stdio.h>
#include <malloc.h>


void parent(i)
{
	return i/2;
}

void left(i)
{
	return 2*i;
}

void right(i)
{
	return (2*i)+1;
}

void min_heapify(A,i)
{
	r = right(i);
	l = left(i);

	if((l<=A.heap_size)&&(A[l]<A[i]))
		smallest = l;
	else
		smallest = i;

	if((r<=A.heap_size)&&(A[r]<A[i]))
		smallest = r;
	else
		smallest = i;

	if(smallest != i)
	{
		int temp;
		temp = A[smallest];
		A[smallest] = A[i];
		A[i] = temp;

		min_heapify(A,smallest);
	}
}