#include<stdio.h>

int main()
{
	int t, T;
	scanf("%d", &T);

	for (t = 1; t <= T; t++)
	{
		int m, d;
		scanf("%d %d", &m, &d);
		int i;
		int sum = 0;
		for (i = 1; i < m; i++)
		{
			switch (i)
			{
			case 1: sum += 31;
				break;
			case 2: sum += 29;
				break;
			case 3: sum += 31;
				break;
			case 4: sum += 30;
				break;
			case 5: sum += 31;
				break;
			case 6: sum += 30;
				break;
			case 7: sum += 31;
				break;
			case 8: sum += 31;
				break;
			case 9: sum += 30;
				break;
			case 10: sum += 31;
				break;
			case 11: sum += 30;
				break;
			}
		}
		sum += d;
		sum += 4;
		sum %= 7;
		printf("#%d %d\n", t, sum);
	}
	return 0;
}