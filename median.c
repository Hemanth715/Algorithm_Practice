#include<stdio.h>
#include<malloc.h>

struct node{
	float val;
	struct node *next, *prev;
};

struct node* newNode(int val)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->val = (float)val;
	temp->next = NULL;
	temp->prev = NULL;

	return temp;
}

int main()
{
	int t, T, n;
	struct node *start, *point, *temp, *temp1;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		int x, i, j;
		float median;
		scanf("%d", &x);
		start = newNode(x);
		point = start;
		median = point->val;
		//printf("0#");
		printf("%.1f\n", median);
		for (i = 2; i <= n; i++)
		{
			scanf("%d", &x);
			temp = start;
			while (temp->next != NULL && temp->val < (float)x)
			{
				temp = temp->next;
			}
			if (temp->val < (float)x)
			{
				temp1 = newNode(x);
				temp->next = temp1;
				temp->next->prev = temp;
			}
			else
			{
				temp1 = newNode(x);
				temp1->prev = temp->prev;
				if (temp1->prev != NULL)
					temp1->prev->next = temp1;
				else
					start = temp1;
				temp1->next = temp;
				temp->prev = temp1;
			}

			if (temp1->val < median)
			{
				if (i % 2 == 0)
				{
					point = point->prev;
					median = (point->val + point->next->val) / 2;
					//printf("1#");
				}
				else
				{
					point = point->next;
					median = point->val;
					//printf("2#");
				}
			}
			else
			{
				if (i % 2 == 0)
				{
					median = (point->val + point->next->val) / 2;
					//printf("3#");
				}
				else
				{
					//printf("4#");
					point = point->next;
					median = point->val;
				}
			}
			printf("%.1f", median);
			printf("\n");
		}
	}
	return 0;
}