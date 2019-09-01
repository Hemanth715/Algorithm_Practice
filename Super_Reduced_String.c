#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[100];
    scanf("%s", s);
    int flag = 0;
    int emp = 0;
    while(flag == 0 && emp == 0){
        flag = 1;
        int i = 0;
        int i0, i1;
        char a;
        while(s[i] != '\0'){
            i0 = i;
            while(s[i] == 'X')
                i++;
            if(s[i] != '\0'){
                a = s[i];
                i1 = i;
                i++;
                while(s[i] == 'X')
                    i++;
                if(s[i] != '\0' && s[i] == a){
                    s[i] = 'X';
                    s[i1] = 'X';
                    flag = 0;
                    i++;
                }
            }
            else if(i0 == 0)
                emp++;
        }
    }
    if(emp > 0)
        printf("Empty String");
    else{
        int i = 0;
        while(s[i] != '\0'){
            if(s[i] != 'X')
                putchar(s[i]);
            i++;
        }
    }
    return 0;
}
