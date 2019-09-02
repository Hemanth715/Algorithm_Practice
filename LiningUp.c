#include<stdio.h>
#include<malloc.h>

int visit[50002];

struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};

struct AdjList
{
	struct AdjListNode *head;
};

struct Graph
{
	int V;
	struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode* newNode =
		(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph* graph =
		(struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;

	graph->array =
		(struct AdjList*) malloc(V * sizeof(struct AdjList));

	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
	struct AdjListNode* newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	/*newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;*/
}

struct node
{
	int val;
	struct node* next;
};

struct node* root;

struct node* newNode(int val)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->next = NULL;
	temp->val = val;
	return temp;
}

int isEmpty()
{
	return !root;
}

void push(int val)
{
	struct node* temp = newNode(val);
	temp->next = root;
	root = temp;
}

int pop()
{
	if (isEmpty())
		return -1;
	struct node* temp = root;
	root = root->next;
	int popped = temp->val;
	free(temp);
	return popped;
}

/*int peek()
{
	if (isEmpty())
		return -1;
	return root->val;
}*/

void topoSort(struct Graph* graph, int x, int n)
{
	visit[x] = 1;
	struct AdjListNode* pCrawl = graph->array[x].head;

	while (pCrawl)
	{
		if (visit[pCrawl->dest] == 0)
			topoSort(graph, pCrawl->dest, n);
		pCrawl = pCrawl->next;
	}

	push(x);
	return;
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		root = NULL;
		int n, m, i, j, x, y;
		scanf("%d %d", &n, &m);
		struct Graph* graph = createGraph(n + 1);
		for (i = 0; i < n + 1; i++)
			visit[i] = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);
			addEdge(graph, x, y);
		}

		for (i = 1; i <= n; i++)
		{
			if (visit[i] == 0)
				topoSort(graph, i, n);
		}
		printf("#%d ", t);

		while (!isEmpty())
			printf("%d ", pop());
		printf("\n");
	}
	return 0;
}