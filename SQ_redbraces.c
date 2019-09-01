/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */

struct node
{
    char val;
    struct node *next;
}*top, *temp;

void push(char data)
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

char topval()
{
	return (top->val);
}

int braces(char* A) {
	char *c;
	c = A;
	while(*c != '\0')
	{
		if(*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c == '(')
			push(*c);
		else if (*c == ')')
		{
			if(topval() == '(')
				return 1;
			else
			{
				while(top != NULL && topval() != '(')
					pop();
				pop();
			}
		}
		c++;
	}
	return 0;
}