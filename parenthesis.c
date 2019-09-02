#include<stdio.h>
#include<malloc.h>

char s[2002], s1[2002];
int pos[2002];

struct StackNode
{
	char data;
	struct StackNode* next;
};

struct StackNode1
{
	int data;
	struct StackNode1* next;
};

struct StackNode* newNode(char data)
{
	struct StackNode* stackNode =
		(struct StackNode*) malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(struct StackNode *root)
{
	return !root;
}

void push(struct StackNode** root, char data)
{
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
}

char pop(struct StackNode** root)
{
	if (isEmpty(*root))
		return '$';
	struct StackNode* temp = *root;
	*root = (*root)->next;
	char popped = temp->data;
	free(temp);

	return popped;
}

char peek(struct StackNode* root)
{
	if (isEmpty(root))
		return '$';
	return root->data;
}

struct StackNode1* newNode1(int data)
{
	struct StackNode1* stackNode =
		(struct StackNode1*) malloc(sizeof(struct StackNode1));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty1(struct StackNode1 *root)
{
	return !root;
}

void push1(struct StackNode1** root, int data)
{
	struct StackNode1* stackNode = newNode1(data);
	stackNode->next = *root;
	*root = stackNode;
}

int pop1(struct StackNode1** root)
{
	if (isEmpty1(*root))
		return -1;
	struct StackNode1* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek1(struct StackNode1* root)
{
	if (isEmpty1(root))
		return -1;
	return root->data;
}

int main()
{
	struct StackNode *top, *toppos;
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		top = NULL;
		toppos = NULL;
		int val1;
		char val;
		int l, i, count = 0;
		scanf("%d", &l);
		scanf("%s", s);
		if (l % 2 == 1)
		{
			printf("#%d %d\n", t, -1);
		}
		else
		{
			for (i = 0; i < l; i++)
			{
				if (peek(top) == '$')
				{
					push(&top, s[i]);
					push1(&toppos, i);
					count = 1;
				}
				else if (peek(top) == '(' && s[i] == ')')
				{
					val = pop(&top);
					val1 = pop1(&toppos);
					count--;
				}
				else
				{
					count++;
					push(&top, s[i]);
					push1(&toppos, i);
				}
				//printf("%d\n", peek1(toppos));
			}
			if (count == 0)
				printf("#%d %d\n", t, 0);
			else
			{
				s1[count] = '\0';
				int x = 0, y = 0;
				for (i = count - 1; i >= 0; i--)
				{
					s1[i] = pop(&top);
					if (s1[i] == '(')
						x++;
					else
						y++;
					pos[i] = pop1(&toppos);
				}
				
				/*for (i = 0; i < count; i++)
				{
					printf("%d\n", pos[i]);
				}
				/*printf("#%d %s ", t, s1);
				for (i = 0; i < count; i++)
				printf("%d ", pos[i]);
				printf("\n");*/
				if (x == 0) ..s//
				{
					printf("#%d %d\n", t, 1);
					printf("%d %d\n", pos[0], pos[(y / 2) - 1]);
				}
				else if (y == 0)
				{
					printf("#%d %d\n", t, 1);
					printf("%d %d\n", pos[x / 2], pos[x - 1]);
				}
				else if (x == y)
				{
					printf("#%d %d\n", t, 2);
					printf("%d %d\n", pos[0], pos[x - 1]);
					printf("%d %d\n", pos[x], pos[count - 1]);
				}
				else
				{
					printf("#%d %d\n", t, 2);
					if (y > x)
					{
						printf("%d %d\n", pos[0], pos[count / 2 - 1]);
						printf("%d %d\n", pos[count - x], pos[count - 1]);
					}
					else
					{
						printf("%d %d\n", pos[0], pos[y - 1]);
						printf("%d %d\n", pos[count / 2], pos[count - 1]);
					}
				}
			}
		}
	}
	return 0;
}