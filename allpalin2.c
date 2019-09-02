#include <stdio.h>

int main()
{
	int t, T;
	char s[21];
	int size;
	int isPalin;

	scanf("%d", &T);

	for (t = 1; t <= T; t++)
	{
		size = 0;
		isPalin = 0;

		scanf("%s", s);

		while (s[size] != '\0')
			size++;

		for (int i = 0; i < (size >> 1) + 2; i++)
		{
			if (i > (size - i))
			{
				isPalin = 1;
				break;
			}

			if (s[i] == '*' || s[size - i - 1] == '*')
			{
				isPalin = 1;
				break;
			}
			else if (s[i] == s[size - i - 1])
				continue;
			else
				break;
		}

		if (isPalin)
			printf("#%d Exist\n", t);
		else
			printf("#%d Not exist\n", t);
	}
	return 0;
}
