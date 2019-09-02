#include <stdio.h>

int N, B;
int hi[21];
int sum, small_sum, a;
int i;


void calheight(int a, int sum){
	if (sum >= B){
		if (sum < small_sum)
			small_sum = sum;
		return;
	}
	if (a >= N)
		return;

	calheight(a + 1, sum + hi[a]);
	calheight(a + 1, sum);
}

int main(void)
{
	int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &B);
		hi[0] = '\0';
		for (i = 0; i<N; i++)
			scanf(" %d", &hi[i]);
		small_sum = 200001;
		calheight(0, 0);
		printf("#%d %d\n", test_case, small_sum - B);
	}
	return 0;
}
