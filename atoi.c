/**
 * @input A : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */
int atoi(const char* A) {
	int i, sign = 1;
	long long res = 0;
	while(A[i] == ' ')
		i++;
	if (!isdigit(A[i]) && A[i] != '+' && A[i] != '-')
	{
		return 0;
	}
	if (A[i] == '+')
	{
		i++;
	}
	else if (A[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (!isdigit(A[i]))
	{
		return 0;
	}
	while(isdigit(A[i]))
	{
		res = res*10 + A[i] - '0';
	}
	if (res*sign > 65535)
	{
		return INT_MAX;
	}
	else if (res*sign < -65536)
	{
		return INT_MIN;
	}
	return res*sign;
}
