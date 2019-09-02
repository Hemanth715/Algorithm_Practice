#include<stdio.h>
#include<malloc.h>

void hash1(int x, int y)
{
	int res;

	res = (x + y - 2)(x + y - 1) / 2;
	res += x;

	printf("%d\n", res);
}

void amp1(int p)
{
	int resx, resy;
	int val = 1, i = 1;
	while (val <= p)
	{
		resy = i;
		val += i;
		i++;
	}
	resx = p + i - val;
	resy -= resx;
	printf("%d %d\n", resx, resy);
}

void main()
{
	hash1(4, 4);
	amp1(25);
}