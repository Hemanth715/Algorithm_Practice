/**
 * @input A : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */
int lengthOfLastWord(const char* A) {
    int i = 0;
    int count = 0;
    while(A[i] != '\0')
    {
    	if (A[i] == ' ')
    	{
    		while(A[i] == ' ')
    			i++;
    		if (A[i] != '\0')
    			count = 0;
    		i--;
    	}
        i++;
        count++;
    }
    return count;
}