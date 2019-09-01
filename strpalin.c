/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
int isPalindrome(char* A) {
	int len = strlen(A);
	int i = 0, j = len - 1;
	while(!isalnum(A[i]))
		i++;
	while(!isalnum(A[j]))
		j--;
	while(i <= j)
	{
		if (tolower(A[i]) == tolower(A[j]))
		{
		    //printf("%c \n", A[i]);
			while(!isalnum(A[i]))
				i++;
			while(!isalnum(A[j]))
				j--;
		}
		else
			return 0;
	}
	return 1;
}