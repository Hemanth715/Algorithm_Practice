#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* time = (char *)malloc(10240 * sizeof(char));
    scanf("%s",time);
    char hh[2];
    hh[0] = time[0];
    hh[1] = time[1];
    if (time[8] == 'P')
    {
    	int pm = atoi(hh);
    	pm += 12;
    	sprintf(hh, "%d", pm);
    	time[0] = hh[0];
    	time[1] = hh[1];
    }
    char* time1 = (char *)malloc(10240 * sizeof(char));
    for (int i = 0; i < 9; ++i)
    {
    	time1[i] = time[i];
    }
    printf("%s\n", time1);
    return 0;
}
