#include<stdio.h>
#include<malloc.h>

struct QNode
{
	char key;
	struct QNode *next;
};

struct Queue
{
	struct QNode *front, *rear;
	int size;
};

struct QNode* newNode(char k)
{
	struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

struct Queue *createQueue()
{
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	q->size = 0;
	return q;
}

void enQueue(struct Queue *q, char k)
{
	struct QNode *temp = newNode(k);
	q->size++;

	if (q->rear == NULL)
	{
		q->front = q->rear = temp;
		return;
	}

	q->rear->next = temp;
	q->rear = temp;
}

struct QNode *deQueue(struct Queue *q)
{
	if (q->front == NULL)
		return NULL;

	q->size--;

	struct QNode *temp = q->front;
	q->front = q->front->next;

	if (q->front == NULL)
		q->rear = NULL;
	return temp;
}

int retsize(struct Queue *q)
{
	return q->size;
}

char croak[2502];

int main()
{
	int t, T;
	struct QNode *temp;
	struct Queue *q1, *q2, *q3, *q4, *q5;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		q1 = createQueue();
		q2 = createQueue();
		q3 = createQueue();
		q4 = createQueue();
		q5 = createQueue();

		int i = 0, max = 0, flag = 0;
		char c;

		scanf("%s", croak);

		while (croak[i] != '\0')
		{
			c = croak[i];
			switch (c)
			{
			case 'c':
				enQueue(q1, c);
				break;
			case 'r':
				enQueue(q2, c);
				break;
			case 'o':
				enQueue(q3, c);
				break;
			case 'a':
				enQueue(q4, c);
				break;
			case 'k':
				enQueue(q5, c);
				break;
			}
			while (retsize(q1) > 0 && retsize(q2) > 0 && retsize(q3) > 0 && retsize(q4) > 0 && retsize(q5) > 0)
			{
				temp = deQueue(q1);
				temp = deQueue(q2);
				temp = deQueue(q3);
				temp = deQueue(q4);
				temp = deQueue(q5);
			}
			if (retsize(q1) >= retsize(q2) && retsize(q2) >= retsize(q3) && retsize(q3) >= retsize(q4) && retsize(q4) >= retsize(q5))
			{
				if (retsize(q1) > max)
					max = retsize(q1);
			}
			else
				flag++;
			i++;
		}
		if (retsize(q1) == 0 && retsize(q2) == 0 && retsize(q3) == 0 && retsize(q4) == 0 && retsize(q5) == 0)
		{
			if (flag == 0)
				printf("#%d %d\n", t, max);
			else
				printf("#%d %d\n", t, -1);
		}
		else
			printf("#%d %d\n", t, -1);
	}
	return 0;
}