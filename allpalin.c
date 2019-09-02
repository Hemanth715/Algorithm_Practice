#include<stdio.h>

char s[21];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int i, j;
		int size = 0;
		scanf("%s", s);
		while (s[size] != '\0')
			size++;
		i = 0;
		j = size - 1;
		while (i < size / 2 && (s[i] == s[j] || s[i] == '?' || s[j] == '?'))
		{
			i++;
			j--;
		}
		printf("#%d ", t);
		if (i == size / 2)
			printf("Exist");
		else
			printf("Not Exist");
		printf("\n");
	}
	return 0;
}