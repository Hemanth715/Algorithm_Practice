#include<stdio.h>
#include<malloc.h>

long long cost;

struct subset
{
	int parent;
	int rank;
};

int find(struct subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
	return;
}

int partition(int **arr, int low, int high)
{
	int pivot = arr[high][2];
	int i = low - 1;
	int j, t0, t1, t2;
	for (j = low; j <= high - 1; j++)
	{
		if (arr[j][2] <= pivot)
		{
			i++;
			t0 = arr[i][0];
			t1 = arr[i][1];
			t2 = arr[i][2];
			arr[i][0] = arr[j][0];
			arr[i][1] = arr[j][1];
			arr[i][2] = arr[j][2];
			arr[j][0] = t0;
			arr[j][1] = t1;
			arr[j][2] = t2;
		}
	}
	t0 = arr[i + 1][0];
	t1 = arr[i + 1][1];
	t2 = arr[i + 1][2];
	arr[i + 1][0] = arr[high][0];
	arr[i + 1][1] = arr[high][1];
	arr[i + 1][2] = arr[high][2];
	arr[high][0] = t0;
	arr[high][1] = t1;
	arr[high][2] = t2;
	return (i + 1);
}

void quickSort(int **arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
	return;
}

int main()
{
	int **edges;
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		cost = 0;
		int n, m, i, x, y, s, e, c, count = 0;
		scanf("%d", &n);
		scanf("%d", &m);
		edges = (int**)malloc(m * sizeof(int*));
		for (i = 0; i < m; i++)
		{
			edges[i] = (int*)malloc(3 * sizeof(int));
			scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
		}
		struct subset *subsets = (struct subset*) malloc((n + 1) * sizeof(struct subset));
		for (i = 1; i < n + 1; ++i)
		{
			subsets[i].parent = i;
			subsets[i].rank = 0;
		}

		quickSort(edges, 0, m - 1);
		i = 0;
		while (count < n - 1)
		{
			s = edges[i][0];
			e = edges[i][1];
			c = edges[i][2];
			i++;

			x = find(subsets, s);
			y = find(subsets, e);

			if (x != y)
			{
				cost += c;
				Union(subsets, x, y);
				count++;
			}
		}

		printf("#%d %lld\n", t, cost);
	}
	return 0;
}