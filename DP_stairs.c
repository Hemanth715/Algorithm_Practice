/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int climbStairs(int A) {
	int *memo = (int *) malloc ((A+1) * sizeof(int));
	int i;
	memo[A] = 1;
	memo[A-1] = 1;
	memo[A-2] = 2;
	for (i = A - 3; i >= 0; --i)
	{
		memo[i] = memo[i+1] + memo[i+2];
	}
	return memo[0];
}