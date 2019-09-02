#include<stdio.h>

int main()
{
	int t, T;
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		float a, b, c, d;
		scanf("%f %f %f %f", &a, &b, &c, &d);
		printf("#%d ", t);
		if(a/(a + b) > c/(c + d))
			printf("ALICE\n");
		else if(a/(a + b) < c/(c + d))
			printf("BOB\n");
		else
			printf("DRAW\n");
	}
	return 0;
}