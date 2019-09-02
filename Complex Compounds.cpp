struct SHash{
	int x1, x2, x3, x4, x5;
}HashDB[5000];

int calchash(char* s)
{
	int x, i;
	for (i = 0; i < strlen(s); i++)
	{
		x = (x * 7 + s[i] * 77) % 203;
	}
	return x;
}

