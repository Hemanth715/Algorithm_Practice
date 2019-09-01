/**
 * @input gas : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( gas ) length
 * @input cost : Read only ( DON'T MODIFY ) Integer array
 * @input n2 : Integer array's ( cost ) length
 * 
 * @Output Integer
 */
int canCompleteCircuit(const int* gas, int n1, const int* cost, int n2) {
	int gassum = 0;
	int costsum = 0;
	int i, j, prev, k;
	if (n1 == 1)
	{
	    if (cost[0] <= gas[0])
	        return 0;
	}
	for (i = 0; i < n1; ++i)
	{
		j = i;
		k = 0;
		if (i == 0)
			prev = n1 - 1;
		else
			prev = i - 1;
		gassum = 0;
		costsum = 0;
		while(j != prev && k == 0)
		{
			gassum += gas[j];
			costsum += cost[j];
			if (costsum > gassum)
				k++;
			j++;
			if (j == n1)
				j = 0;
		}
		if (j == prev && k == 0)
		{
		    costsum += cost[j];
		    gassum += gas[j];
			if (costsum <= gassum)
			{
				return i;
			}
		}
	}
	return -1;
}