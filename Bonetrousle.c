#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long int maxsum(long int k, long int b){
    if(b == 0)
        return 0;
    return k + maxsum(k - 1, b - 1);
}

long int minsum(long int k, long int b){
    if(b == 0)
        return 0;
    return k + minsum(k + 1, b - 1);
}

/*void printval(long int n, long int k, long int b){
    long int add = (n - minsum(1, b))/b;
    for(long int i = 1; i <= b - 1; i++)
        printf("%ld ", i + add);
    if((n - minsum(1, b))%b != 0)
        printf("%ld", b + (n - minsum(1, b))%b);
    else
        printf("%ld", b + add);
}

void printval(long int n, long int k, long int b){
    if(n - minsum(1, b) >= k - b){
        printf("%ld ", k);
        printval(n - k, k - 1, b - 1);
    }
    else{
        printf("%ld ", n - minsum(1, b - 1));
        for(long int i = 1; i <= b - 1; i++)
            printf("%ld ", i);
    }
}*/

int main() {
    int t;
    scanf("%d", &t);
    for(int l = 0; l < t; l++){
        long int n, k, b;
        scanf("%ld %ld %ld", &n, &k, &b);
        if(n > maxsum(k, b) || n < minsum(1, b))
            printf("-1\n");
        else{
            printval(n, k, b);
            printf("\n");
        }
    }
    return 0;
}
