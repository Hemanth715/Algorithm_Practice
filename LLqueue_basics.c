struct node
{
    int val;
    struct node *next;
}*front, *rear, *temp;

void enQueue(int data)
{
	temp = (struct node *)malloc(sizeof(struct node));
	temp->val = data;
	temp->next = NULL;
	if (rear == NULL)
	{
		front = temp;
		rear = temp;
		return;
	}

	rear->next = temp;
	rear = temp;
}

void deQueue()
{
	if (rear == NULL)
		return;
	temp = front;
	front = front->next;
	if (front == NULL)
		rear = NULL;
	free(temp);
}

int frontval()
{
	return (front->val);
}

node* front()
{
	return front;
}
