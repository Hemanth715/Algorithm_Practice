#include<stdio.h>

int a[102];
int n;

void f1()
{
	int i;
	int count = n;
	for (i = 0; i < n - 3; i++)
	{
		if (a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3])
			count++;
	}
	printf("%d", count);
}

void f2()
{
	int i;
	int count = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (a[i] == a[i + 1])
			count++;
	}
	printf("%d", count);
}

void f3()
{
	int i;
	int count = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (i != n - 1 && a[i] == a[i + 1] && a[i] == a[i + 2] - 1)
			count++;
		if (a[i] == a[i + 1] + 1)
			count++;
	}
	printf("%d", count);
}

void f4()
{
	int i;
	int count = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (i != n - 1 && a[i] == a[i + 1] + 1 && a[i] == a[i + 2] + 1)
			count++;
		if (a[i] == a[i + 1] - 1)
			count++;
	}
	printf("%d", count);
}

void f5()
{
	int i;
	int count = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (i != n - 1 && a[i] == a[i + 1] && a[i] == a[i + 2])
			count++;
		if (i != n - 1 && a[i] == a[i + 1] + 1 && a[i] == a[i + 2])
			count++;
		if (a[i] == a[i + 1] - 1)
			count++;
		if (a[i] == a[i + 1] + 1)
			count++;
	}
	printf("%d", count);
}

void f6()
{
	int i;
	int count = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (i != n - 1 && a[i] == a[i + 1] && a[i] == a[i + 2])
			count++;
		if (i != n - 1 && a[i] == a[i + 1] - 1 && a[i] == a[i + 2] - 1)
			count++;
		if (a[i] == a[i + 1])
			count++;
		if (a[i] == a[i + 1] + 2)
			count++;
	}
	printf("%d", count);
}

void f7()
{
	int i;
	int count = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (i != n - 1 && a[i] == a[i + 1] && a[i] == a[i + 2])
			count++;
		if (i != n - 1 && a[i] == a[i + 1] && a[i] == a[i + 2] + 1)
			count++;
		if (a[i] == a[i + 1])
			count++;
		if (a[i] == a[i + 1] - 2)
			count++;
	}
	printf("%d", count);
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int i, p;
		scanf("%d %d", &n, &p);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("#%d ", t);
		switch (p)
		{
		case 1:
			f1();
			break;
		case 2:
			f2();
			break;
		case 3:
			f3();
			break;
		case 4:
			f4();
			break;
		case 5:
			f5();
			break;
		case 6:
			f6();
			break;
		case 7:
			f7();
			break;
		}
		printf("\n");
	}
	return 0;
}