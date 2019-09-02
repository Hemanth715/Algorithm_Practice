#include <iostream>
using namespace std;

#define MAX_HEAP_SIZE (100000)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])


inline
void Exch(int &a, int &b)
{
	int aux = a;
	a = b;
	b = aux;
}

bool Greater(int a, int b)
{
	return a > b;
}

bool Smaller(int a, int b)
{
	return a < b;
}

float Average(int a, int b)
{
	return ((float)a + (float)b) / 2;
}

/*int Signum(int a, int b)
{
if (a == b)
return 0;

return a < b ? -1 : 1;
}*/


class Heap
{
public:

	Heap(int *b, bool(*c)(int, int)) : A(b), comp(c)
	{
		heapSize = -1;
	}

	virtual ~Heap()
	{
		if (A)
		{
			delete[] A;
		}
	}

	virtual bool Insert(int e) = 0;
	virtual int  GetTop() = 0;
	virtual int  ExtractTop() = 0;
	virtual int  GetCount() = 0;

protected:


	int left(int i)
	{
		return 2 * i + 1;
	}

	int right(int i)
	{
		return 2 * (i + 1);
	}

	int parent(int i)
	{
		if (i <= 0)
		{
			return -1;
		}

		return (i - 1) / 2;
	}


	int   *A;

	bool(*comp)(int, int);

	int   heapSize;
	int top(void)
	{
		int max = -1;

		if (heapSize >= 0)
		{
			max = A[0];
		}

		return max;
	}

	int count()
	{
		return heapSize + 1;
	}


	void heapify(int i)
	{
		int p = parent(i);

		if (p >= 0)
		{
			int lar = p;
			int left = 2 * p + 1;
			int right = 2 * (p + 1);
			if (left < heapSize && comp(A[left], A[lar])) lar = left;
			if (right < heapSize && comp(A[right], A[lar])) lar = right;
			if (lar != p){
				Exch(A[lar], A[p]);
				heapify(p);
			}
		}
	}

	int deleteTop()
	{
		int del = -1;

		if (heapSize > -1)
		{
			del = A[0];

			Exch(A[0], A[heapSize]);
			heapSize--;
			heapify(parent(heapSize + 1));
		}

		return del;
	}
	bool insertHelper(int key)
	{
		bool ret = false;

		if (heapSize < MAX_HEAP_SIZE)
		{
			ret = true;
			heapSize++;
			A[heapSize] = key;
			heapify(heapSize);
		}

		return ret;
	}
};

class MaxHeap : public Heap
{
private:

public:
	MaxHeap() : Heap(new int[MAX_HEAP_SIZE], &Greater)  {  }

	~MaxHeap()  { }

	int GetTop()
	{
		return top();
	}

	int ExtractTop()
	{
		return deleteTop();
	}

	int  GetCount()
	{
		return count();
	}

	bool Insert(int key)
	{
		return insertHelper(key);
	}
};

class MinHeap : public Heap
{
private:

public:

	MinHeap() : Heap(new int[MAX_HEAP_SIZE], &Smaller) { }

	~MinHeap() { }
	int GetTop()
	{
		return top();
	}

	int ExtractTop()
	{
		return deleteTop();
	}

	int  GetCount()
	{
		return count();
	}
	bool Insert(int key)
	{
		return insertHelper(key);
	}
};

float getMedian(int e, float &m, Heap &l, Heap &r)
{
	if (l.GetCount() == r.GetCount())
	{
		if (l.GetCount() == 0)
		{
			l.Insert(e);
			//printf("#0 ");
		}
		else if ((float)e <= m)
		{
			l.Insert(e);
			//printf("#1 ");
		}
		else
		{
			l.Insert(r.ExtractTop());
			r.Insert(e);
			//printf("#2 ");
		}
		//printf("$%d %d ", l.GetTop(), r.GetTop());
		m = (float)l.GetTop();
	}
	else
	{
		if ((float)e <= m)
		{
			r.Insert(l.ExtractTop());
			l.Insert(e);
			//printf("#3 ");
		}
		else
		{
			r.Insert(e);
			//printf("#4 ");
		}
		//printf("$%d %d ", l.GetTop(), r.GetTop());
		m = Average(l.GetTop(), r.GetTop());
	}
	return m;
}

void printMedian(int A[], int size)
{
	float m = 0;
	Heap *left = new MaxHeap();
	Heap *right = new MinHeap();

	for (int i = 0; i < size; i++)
	{
		m = getMedian(A[i], m, *left, *right);
		printf("%.1f\n", m);
	}

	delete left;
	delete right;
}

int main()
{
	int t, T, n;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		int i;
		int A[n];
		for (i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
		}
		printMedian(A, n);
	}

	return 0;
}