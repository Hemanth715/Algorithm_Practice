/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output Integer
 */

struct node
{
    listnode* val;
    struct node *next;
}*top, *temp;

void push(listnode* data)
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

listnode* topval()
{
	return (top->val);
}

int lPalin(listnode* A) {
	top = NULL;
	int i, count = 0, j = 1;
	listnode *temp1;
	temp1 = A;
	while(temp1 != NULL)
	{
		temp1 = temp1->next;
		count++;
	}

	temp1 = A;

	for (i = 0; i < count/2; ++i)
	{
	    //printf("A%d ", temp1->val);
		push(temp1);
		temp1 = temp1->next;
	}
	
	if(count%2 == 1)
	{
	    temp1 = temp1->next;
	    i = (count/2) + 1;
	}
	else
	    i = count/2;
	for (; i < count - 1, j == 1; ++i)
	{
	    if (top == NULL) return j;
	    //printf("B%d ", temp1->val);
		if (topval()->val != temp1->val)
		{
			j = 0;
		}
		temp1 = temp1->next;
		pop();
	}
	//printf("/");
	return j;
}