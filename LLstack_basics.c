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

node* top()
{
    return top;
}