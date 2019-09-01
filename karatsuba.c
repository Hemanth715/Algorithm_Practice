#include <stdio.h>
#include <malloc.h>

struct node
{
	long int left;
	long int right;
	long int res;
	struct node *a;
	struct node *b;
	struct node *c;
	struct node *par;
	struct node *next;
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

int count_digit(long int a)
{
	int i = 1;
	a /= 10;
	while(a != 0)
	{
		i++;
		a /= 10;
	}
	return i;
}

long int higher(long int x)
{
	int size = count_digit(x);
	int i;
	for (i = 0; i < size/2; ++i)
	{
		x /= 10;
	}
	return x;
}

long int lower(long int x)
{
	int size = count_digit(x);
	long int high = higher(x);
	int i;
	for (i = 0; i < size/2; ++i)
	{
		high *= 10;
	}
	x -= high;
	return x;
}

void addleft(nodeptr p)
{
	nodeptr q = newnode();
	p->a = q;
	q->par = p;
	q->a = NULL;
	q->b = NULL;
	q->c = NULL;
	q->next = NULL;
	q->left = higher(p->left) + lower(p->left);
	q->right = higher(p->right) + lower(p->right);
	q->res = -1;
}

void addcenter(nodeptr p)
{
	nodeptr q = newnode();
	p->b = q;
	q->par = p;
	q->a = NULL;
	q->b = NULL;
	q->c = NULL;
	q->next = NULL;
	q->left = higher(p->left);
	q->right = higher(p->right);
	q->res = -1;
}

void addright(nodeptr p)
{
	nodeptr q = newnode();
	p->c = q;
	q->par = p;
	q->a = NULL;
	q->b = NULL;
	q->c = NULL;
	q->next = NULL;
	q->left = lower(p->left);
	q->right = lower(p->right);
	q->res = -1;
}

void push(nodeptr *top, nodeptr p)
{
	p->next = *top;
	*top = p;
}

nodeptr pop(nodeptr *top)
{
	if (*top == NULL)
	{
		return *top;
	}
	nodeptr p = *top;
	*top = p->next;
	return p;
}

void in_q(nodeptr *r, nodeptr p)
{
	(*r)->next = p;
	*r = p;
}

nodeptr out_q(nodeptr *f)
{
	if (*f == NULL)
	{
		exit(1);
	}
	nodeptr p = *f;
	*f = p->next;
	return p;
}

int create_tree(long int x, long int y, nodeptr *top, nodeptr *tree, nodeptr *point)
{
	nodeptr root = newnode();
	root->left = x;
	root->right = y;
	root->res = -1;
	root->par = NULL;
	root->a = NULL;
	root->b = NULL;
	root->c = NULL;
	root->next = NULL;
	*tree = (nodeptr *) malloc (100 * sizeof(nodeptr));  //currently set value at max 100 nodes in tree
	int leaf = 1;
	int val = 0;
	int i, n, k;
	*tree = root;
	*point = root;
	while(val != leaf)
	{	point -= ((leaf-1) * sizeof(nodeptr));
		k = leaf - 1;
		for(i = 0; i < k; i++)
		{
			if((*point)->left > 10 || (*point)->right > 10)
			{
				leaf += 2;
				addleft(*point);
				addcenter(*point);
				addright(*point);
				n = (*point - *tree)/sizeof(nodeptr);
				tree[3*n+1] = (*point)->a;
				tree[3*n+2] = (*point)->b;
				tree[3*n+3] = (*point)->c;
			}
			else
			{
				val++;
			}
			point += sizeof(nodeptr);
		}
		point += ((leaf - k + 1) * sizeof(nodeptr) * 1.5);
	}
	
	point -= ((leaf-1) * sizeof(nodeptr));
	for(i = 0; i < leaf-1; i++)
	{
		push(top, *point);
		point += sizeof(nodeptr);
	}
	return leaf;
}

void st_to_q(nodeptr *top, nodeptr *r)
{	
	nodeptr temp;
	while(*top != NULL)
	{
		temp = pop(top);
		(temp)->res = (temp)->left * (temp)->right;
		in_q(r, temp);
	}
}

void tree_to_q(nodeptr *tree, nodeptr *r, nodeptr *point, int leaf)
{	
	point -= ((leaf-1) * sizeof(nodeptr));
	while(tree != point)
	{
		(*point)->res = (*point)->left * (*point)->right;
		in_q(r, *point);
		point -= sizeof(nodeptr);
	}
}

void print(nodeptr *f, int leaf)
{	
	nodeptr temp;
	long int powten;
	for(int i = 0; i < leaf; i++)
	{
		temp = out_q(f);
		printf("%ldX%ld=%ld\n",(temp)->left, (temp)->right, (temp)->res);
	}
	while(*f != NULL)
	{
		temp = out_q(f);
		powten = (((temp)->left) - lower((temp)->left))/higher((temp)->left);
		printf("%ldX%ld=%ldX%ldX%ld+(%ld-%ld-%ld)X%ld+%ld=%ld",(temp)->left, (temp)->right, (temp)->b->res, powten, powten, (temp)->a->res, (temp)->b->res, (temp)->c->res, powten, (temp)->c->res);
	}
}

int main()
{
	nodeptr root, pt, stack, qf, qr;
	char str[1000];
    char str1[1000];
    char str2[1000];
    qf = qr;
    scanf("%s",str);
    int i=0;
    while(str[i]!='X')
    {
        str1[i]=str[i];
        i++;
    }
    str1[i]='\0';
    i++;
    int j=0;
    while(i<strlen(str))
    {
        str2[j]=str[i];
        j++;
        i++;
    }
    long int a=atoi(str1);
    long int b=atoi(str2);
    int leaf = create_tree(a, b, &stack, &root, &pt);
    st_to_q(&stack, &qr);
    tree_to_q(&root, &qr, &pt, leaf);
    print(&qf, leaf);
    return 0;
}
