#include<stdio.h>

char a[101];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%s", a);
		int b;
		int i = 0;
		while (a[i] != '\0')
			i++;
		b = a[i - 1] - '0';
		if (b % 2 == 0)
			printf("#%d Even\n", t);
		else
			printf("#%d Odd\n", t);
	}
	return 0;
}