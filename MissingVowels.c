#include<stdio.h>

char s[51];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int i = 0;
		scanf("%s", s);
		printf("#%d ", t);
		while (s[i] != '\0')
		{
			if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
				printf("%c", s[i]);
			i++;
		}
		printf("\n");
	}
	return 0;
}