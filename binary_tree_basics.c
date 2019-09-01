#include <stdio.h>
#include <malloc.h>

struct node
{
	int freq;
	char info;
	struct node *left;
	struct node *right;
	struct node *parent;
};

typedef struct node *nodeptr;

nodeptr newnode(void)
{
	nodeptr p;
	p = (nodeptr) malloc(sizeof(struct node));
	return(p);
}

void freenode(nodeptr p)
{
	free(p);
}

void addleft(nodeptr p, char x, int fval)
{
	q = newnode();
	p->left = q;
	q->parent = p;
	q->left = NULL;
	q->right = NULL;
	q->info = x;
	q->freq = fval;
}

void addright(nodeptr p, char x, int fval)
{
	q = newnode();
	p->right = q;
	q->parent = p;
	q->left = NULL;
	q->right = NULL;
	q->info = x;
	q->freq = fval;
}

void min_heapify(nodeptr p)
{
	nodeptr q;
	int smallest = 0;
	if(p->left.freq < p.freq)
		smallest = 1;
	if(p->right.freq < p.freq)
		smallest = 2;

	if(smallest == 1)
	{
		int temp;
		char temp1;
		temp = p->left.freq;
		p->left.freq = p.freq;
		p.freq = temp;

		temp1 = p->left.info;
		p->left.info = p.info;
		p.info = temp1;
		min_heapify(p->left);
	}

	if(smallest == 2)
	{
		int temp;
		char temp1;
		temp = p->right.freq;
		p->right.freq = p.freq;
		p.freq = temp;

		temp1 = p->right.info;
		p->right.info = p.info;
		p.info = temp1;
		min_heapify(p->right);
	}
}

void build_min_heap()