int* flip(char* A, int *len1) { //O(n)
	int i, j;
	char a;
	int max = 0;
	int one = 0;
	int Out[2];
	int len = strlen(A);
	int count = 0;
	for (i = 0, j = 0; i < len; ++i)
	{
		a = A[i];
        if(a == '1' && count > 0)
        {
        	one++;
        	count--;
        }
        else if(a == '1')
        {
        	j = i+1;
        	one++;
        }
        else
        {
        	count++;
        	if (count > max)
        	{
        		max = count;
        		Out[0] = j+1;
        		Out[1] = i+1;
        	}
        }
	}
	if(one == len) printf("");
	else printf("%d %d ", Out[0], Out[1]);
	return;
}



int* flip(char* A, int *len1) { //O(n2)
    int max = 0, count;
    int one = 0;
    int Out[2];
    int i, j;
    int len = strlen(A);
    char a;
    for(i = 0; i < len; i++)
    {
        count = 0;
        a = A[i];
        if(a == '1') one++;
        for(j = i; j < len; j++)
        {
            a = A[j];
            if(a == '1') count--;
            else count++;
            
            if(count > max)
            {
                max = count;
                Out[0] = i;
                Out[1] = j;
            }
        }
    }
    if(one == len) printf("");
    else
    {
        Out[0]++;
        Out[1]++;
        printf("%d %d ", Out[0], Out[1]);
    }
    return;
}