#include<stdio.h>

int main()
{
	int t, T;
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		int a, b, c, d;
		scanf("%d %d %d", &a, &b, &c);
		if(a == b)
			d = c;
		else if(a == c)
			d = b;
		else
			d = a;
		printf("#%d %d\n", t, d);
	}
	return 0;
}