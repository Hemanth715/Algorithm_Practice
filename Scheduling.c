#include <stdio.h>
#include <malloc.h>

struct node
{
	int id, r, c, p;
	struct node* l;
	struct node* r;
};

typedef struct node *nodeptr;

nodeptr proc;

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

void inpval(nodeptr* arr)
{nodeptr* q = arr;
	while(scanf("%d %d %d %d", &((*q)->id), &((*q)->r), &((*q)->c), &((*q)->p)) > 0)
		{
			q += sizeof(nodeptr);
		}
}

void Insert_BST(nodeptr root, nodeptr q)
{
	if(root == NULL)
	{
		root = q;
	}
	else if (root->p > q->p)
	{
		Insert_BST(root->l, q);
	}
	else
	{
		Insert_BST(root->r, q);
	}
}

nodeptr Delete_BST(nodeptr root)
{	
	if(root == NULL)
	{
		return root;
	}
	else if(root->r != NULL)
	{
		root->r = Delete_BST(root->r);
	}
	else
	{	
		nodeptr temp = root;
		if(root->l != NULL)
		{
			root = root->l;
		}
		else
		{
			root = NULL;
		}
		return temp;
	}
}

void eval()
{
	proc = NULL;
	
}

void main()
{
	nodeptr arr = NULL;
	inpval(&arr);
	
}
