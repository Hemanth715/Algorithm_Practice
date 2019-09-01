/**
 * @input A : Integer
 * 
 * @Output Integer 0 / 1. Return 0 if the number is not palindrome, else return 1
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

int isPalindrome(int A) {
	int count = 0, i;
	if (A == 0)
		return 1;
	if (A < 0)
	    return 0;
	int A1 = A;
	while (A1 != 0)
	{
		A1 /= 10;
		count++;
	}
	A1 = A;
	for (i = 1; i <= count/2; ++i)
	{
		push(A1 % 10);
		A1 /= 10;
	}
	if (count % 2 == 1)
	{
	    A1 /= 10;
		i++;
	}
	for (; i <= count; ++i)
	{
		if (topval() != A1 % 10)
		{
			return 0;
		}
		pop();
		A1 /= 10;
	}
	return 1;
}