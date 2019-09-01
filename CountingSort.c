#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int i, n, count[100];
	scanf("%d", &n);
	int a[n];
	char b[n][10];
	char c[n][10];
	for (i = 0; i < 100; ++i)
	{
		count[i] = 0;
	}
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		scanf("%s", b[i]);
	}
	for (i = 0; i < n; ++i)
	{
		count[a[i]]++;
	}
	for (i = 1; i < 100; ++i)
	{
        count[i] += count[i-1];
	}
	for (i = n-1; i >= 0; --i)
	{
		count[a[i]]--;
		if (i > n/2)
			strcpy(c[count[a[i]]], b[i]);
		else
			strcpy(c[count[a[i]]], "-");
	}
	for (i = 0; i < n; ++i)
	{
		printf("%s ", c[i]);
	}
    return 0;
}
