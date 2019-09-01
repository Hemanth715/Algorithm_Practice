#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct node
{
	char str[100];
	int h;
	struct node *left;
	struct node *right;
};

typedef struct node* nodeptr;

int maxval(int a, int b)
{
    if (a > b)
    	return a;
    else
    	return b;
}

int h(nodeptr N)
{
	if (N == NULL)
		{
			return 0;
		}
	return N->h;
}

int getbal(nodeptr N)
{
	if (N == NULL)
		{
			return 0;
		}
	return h(N->left) - h(N->right);
}

nodeptr createNode(char newstr[])
{
	nodeptr node = (struct node*) malloc(sizeof(struct node));

	node->h = 1;
	strcpy(node->str, newstr);
	node->right = NULL;
	node->left = NULL;

	return(node);
}

void AVL_in(nodeptr root)
{
	if(root != NULL)
	{
		AVL_in(root->left);
		printf("%s %d %d\n", root->str, root->h, getbal(root));
		AVL_in(root->right);
	}
}

void AVL_pre(nodeptr root)
{
    
	if(root != NULL)
	{
		printf("%s %d %d\n", root->str, root->h, getbal(root));
		AVL_pre(root->left);
		AVL_pre(root->right);
	}
}

nodeptr rot_right(nodeptr y)
{
	struct node *x = y->left;
	struct node *temp = x->right;

	x->right = y;
	y->left = temp;

	y->h = maxval(h(y->left), h(y->right))+1;
	x->h = maxval(h(x->left), h(x->right))+1;

	return x;
}
 

nodeptr rot_left(nodeptr x)
{
	struct node *y = x->right;
	struct node *temp = y->left;

	y->left = x;
	x->right = temp;

	x->h = maxval(h(x->left), h(x->right))+1;
	y->h = maxval(h(y->left), h(y->right))+1;

	return y;
}
 
nodeptr insert(nodeptr node, char newstr[])
{
	if (node == NULL)
        {
        	return(createNode(newstr));
		}
		
	if (strcmp(newstr, node->str) < 0)
		{
			node->left  = insert(node->left, newstr);
		}
		
	else
		{
			node->right = insert(node->right, newstr);
		}

	node->h = maxval(h(node->left), h(node->right)) + 1;

	int bal = getbal(node);
	
	// Right Left Case
	if (bal < -1 && (strcmp(newstr, node->right->str) < 0))
		{
			node->right = rot_right(node->right);
			return rot_left(node);
		}
	
	// Left Right Case
	else if (bal > 1 && (strcmp(newstr, node->left->str) >= 0))
		{
			node->left =  rot_left(node->left);
			return rot_right(node);
		}

	// Left left Case
	else if (bal > 1 && (strcmp(newstr, node->left->str) < 0))
		{
			return rot_right(node);
		}
 
	// Right Right Case
	else if (bal < -1 && (strcmp(newstr, node->right->str) >= 0))
		{
			return rot_left(node);
		}

	return node;
}

int main()
{
	nodeptr root = NULL;
	char str[100];

	while(scanf("%s", str) != EOF)
	{
		root = insert(root, str);
	}
	
	AVL_in(root);
	AVL_pre(root);

	return 0;
}
