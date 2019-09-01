/**
 * @input A : Integer
 * 
 * @Output string array. You need to malloc memory. 
 *   Fill in len1 as number of strings. Make sure every string ends with null character
 */
char** fizzBuzz(int A, int *len1) {
    int len = len1;
    char **result = (char **)malloc(A * sizeof(char *));
    int i;
    for (i = 0; i < A; i++)
        result[i] = (char *)malloc(10 * sizeof(char));
    for (i = 0; i < A; ++i)
    {
    	if ((i+1) % 15)
    	{
    		strcpy(result[i], "FizzBuzz");
    	}
    	else if ((i+1) % 5)
    	{
    		strcpy(result[i], "Buzz");
    	}
    	else if ((i+1) % 3)
    	{
    		strcpy(result[i], "Fizz");
    	}
    	else
    		strcpy(result[i], (i+1));
    }
    return result;
}
