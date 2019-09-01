#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char B[100];
    char A[100];
    printf("ENTER A STRING\n");
    scanf("%s\n", B);
    printf("ENTER A STRING\n");
    scanf("%s\n", A);
    if(strcmp(A, B) == 0){
        printf("YES");
    }
    else
        printf("NO");
    return 0;
}
