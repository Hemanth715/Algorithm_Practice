#include<stdio.h>

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		char a[52];
		int i, j, size;
		scanf("%s", a);
		size = 0;
		while (a[size] != '\0')
			size++;
		size = (4 * size) + 1;
		for (i = 0; i < size; i++)
		{
			if (i % 4 == 2)
				printf("#");
			else
				printf(".");
		}
		printf("\n");

		for (i = 0; i < size; i++)
		{
			if (i % 2 == 1)
				printf("#");
			else
				printf(".");
		}
		printf("\n");
		j = 0;
		for (i = 0; i < size; i++)
		{
			if (i % 4 == 0)
				printf("#");
			else if (i % 4 == 2)
				printf("%c", a[j++]);
			else
				printf(".");
		}
		printf("\n");
		for (i = 0; i < size; i++)
		{
			if (i % 2 == 1)
				printf("#");
			else
				printf(".");
		}
		printf("\n");

		for (i = 0; i < size; i++)
		{
			if (i % 4 == 2)
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
	return 0;
}