/*#include<iostream>
#include<fstream>
using namespace std;*/

#include<stdio.h>
#include<malloc.h>

struct Point
{
	long long x, y;
};

struct Point p0;

struct Stack
{
	int top;
	unsigned capacity;
	struct Point* arr;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->arr = (struct Point*)malloc(stack->capacity * sizeof(struct Point));
	return stack;
}

int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, struct Point item)
{
	if (isFull(stack))
		return;
	stack->arr[++stack->top] = item;
}

struct Point pop(struct Stack* stack)
{
	return stack->arr[stack->top--];
}

struct Point peek(struct Stack* stack)
{
	return stack->arr[stack->top];
}

struct Point peek1(struct Stack* stack)
{
	return stack->arr[stack->top - 1];
}

void swap(struct Point *p1, struct Point *p2)
{
	struct Point *temp = (struct Point*) malloc(sizeof(struct Point));
	*temp = *p1;
	*p1 = *p2;
	*p2 = *temp;
	free(temp);
}

long long distSq(struct Point p1, struct Point p2)
{
	return (((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

int orientation(struct Point p, struct Point q, struct Point r)
{
	long long val = (((q.y - p.y) * (r.x - q.x)) - ((q.x - p.x) * (r.y - q.y)));

	if (val == 0)
		return 0;
	return (val > 0) ? 1 : 2;
}

int compare(struct Point p1, struct Point p2)
{
	int o = orientation(p0, p1, p2);

	if (o == 0)
		return (distSq(p0, p2) >= distSq(p0, p1)) ? 0 : 1;

	return (o == 2) ? 0 : 1;
}

int partition(struct Point arr[], int low, int high)
{
	struct Point pivot = arr[high];
	int j, i = low - 1;

	for (j = low; j < high; j++)
	{
		if (compare(pivot, arr[j]))
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(struct Point arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int convexHull(struct Point points[], int n)
{
	int ymin = points[0].y;
	int i, y, min = 0, count = 0;
	for (i = 1; i < n; i++)
	{
		y = points[i].y;
		if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
		{
			ymin = points[i].y;
			min = i;
		}
	}
	//cout << points[min].y << endl;
	swap(&points[0], &points[min]);
	//cout << points[0].y << endl;
	p0 = points[0];
	quickSort(points, 1, n - 1);

	int m = 1;

	for (i = 1; i < n; i++)
	{
		while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
			i++;
		points[m] = points[i];
		m++;
	}

	if (m < 3)
		return 0;

	//cout << "-------------" << endl;

	struct Stack* stack = createStack(n + 1);

	push(stack, points[0]);
	push(stack, points[1]);
	push(stack, points[2]);

	struct Point discard;

	for (i = 3; i < m; i++)
	{
		while (orientation(peek1(stack), peek(stack), points[i]) != 2)
			discard = pop(stack);
		push(stack, points[i]);
	}

	while (!isEmpty(stack))
	{
		discard = pop(stack);
		count++;
	}

	return count;
}


int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int n, i;
		struct Point *points;
		scanf("%d", &n);
		points = (struct Point*) malloc(n * sizeof(struct Point));
		for (i = 0; i < n; i++)
		{
			scanf("%lld %lld", &points[i].x, &points[i].y);
		}
		printf("#%d %d\n", t, convexHull(points, n));
		free(points);
	}
	return 0;
}