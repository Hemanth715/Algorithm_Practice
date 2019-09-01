/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

struct node
{
    int val;
    struct node *next;
}*top, *temp;

void push(int data)
{
    if (top == NULL)
    {
        top = (struct node *)malloc(sizeof(struct node));
        top->next = NULL;
        top->val = data;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->next = top;
        temp->val = data;
        top = temp;
    }
}

void pop()
{
	if (top == NULL)
		return;
	temp = top;
	top = top->next;
	free(temp);
}

int topval()
{
	return (top->val);
}

int* prevSmaller(int* A, int n1, int *len1) {
    top = NULL;
	int i = 0;
	*len1 = n1;
	push(A[0]);
	int *G = (int *)malloc(n1 * sizeof(int));
	G[i] = -1;
	for (i = 1; i < n1; ++i)
	{
		while(top != NULL && topval() >= A[i])
			pop();
		if (top == NULL)
			G[i] = -1;
		else
			G[i] = topval();
		push(A[i]);
	}
	return G;
}