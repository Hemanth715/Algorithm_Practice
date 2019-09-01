#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    for(int loop = 0; loop < t; loop++){
    	long int n, m;
        scanf("%ld %ld", &n, &m);
        if (m == 1 || n % 2 == 0)
        {
        	printf("2\n");
        }
        else
        	printf("1\n");
    }
    return 0;
}
