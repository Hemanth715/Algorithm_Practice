#include <stdio.h>

int main(void)
{
	int test_case;
	int T, a, b, c, d;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("#%d ", test_case);
		if ((b == 0 && c == 0 && a != 0 && d != 0) || (b - c>1 || b - c<-1)) printf("impossible\n");
		else {
			if (b>c) {
				for (int i = 0; i < a + 1; i++) printf("0");
				for (int i = 0; i < d + 1; i++) printf("1");
				for (int i = 0; i < b - 1; i++) printf("01");
			}
			else if (c>b) {
				for (int i = 0; i < d + 1; i++) printf("1");
				for (int i = 0; i < a + 1; i++) printf("0");
				for (int i = 0; i < c - 1; i++) printf("10");
			}
			else {
				if (b + c == 0)  {
					if (a > 0)  { for (int i = 0; i < a + 1; i++) printf("0"); }
					else { for (int i = 0; i < d + 1; i++) printf("1"); }
				}
				else {
					for (int i = 0; i < a + 1; i++) printf("0");
					for (int i = 0; i < d + 1; i++) printf("1");
					for (int i = 0; i < b - 1; i++) printf("01");
					printf("0");
				}
			}
			printf("\n");
		}

	}
	return 0;
}
