#include<stdio.h>

char a[8], a1[8];
int b[8], b1[8];

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		int i;
		int ca[27], cb[14];
		int count = 1, max = 0, flag = 0;
		scanf("\n");
		for (i = 0; i < 7; i++)
		{
			scanf("%c %d\n", &a[i], &b[i]);
		}

		for (i = 1; i < 14; i++)
		{
			cb[i] = 0;
		}

		for (i = 0; i < 7; i++)
		{
			cb[b[i]]++;
		}

		for (i = 2; i < 14; i++)
		{
			cb[i] += cb[i - 1];
		}

		for (i = 6; i >= 0; i--)
		{
			b1[cb[b[i]] - 1] = b[i];
			a1[cb[b[i]] - 1] = a[i];
			cb[b[i]]--;
		}

		for (i = 0; i < 26; i++)
		{
			ca[i] = 0;
		}

		for (i = 0; i < 7; i++)
		{
			ca[a1[i] - 'A']++;
		}

		for (i = 1; i <= 26; i++)
		{
			ca[i] += ca[i - 1];
		}

		for (i = 6; i >= 0; i--)
		{
			a[ca[a1[i] - 'A'] - 1] = a1[i];
			b[ca[a1[i] - 'A'] - 1] = b1[i];
			ca[a1[i] - 'A']--;
		}

		/*for (i = 0; i < 7; i++)
		{
			printf("%c %d\n", a[i], b[i]);
		}*/
		if (flag == 0)
		{
			for (i = 1; i < 7; i++)
			{
				if (a[i] == a[i - 1] && b[i] == b[i - 1] + 1)
					count++;
				else
					count = 1;
				if (count > max)
					max = count;
			}
			if (max >= 5)
			{
				printf("#%d Straight Flush\n", t);
				flag = 1;
			}
		}
		if (flag == 0)
		{

		}
	}
	return 0;
}