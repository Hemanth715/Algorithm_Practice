#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
   int q; 
   scanf("%d",&q);
   for(int a0 = 0; a0 < q; a0++){
      int n; 
      int m; 
      int x; 
      int y; 
      scanf("%d %d %d %d",&n,&m,&x,&y);
      int city_1[m], city_2[m];
      for(int a1 = 0; a1 < m; a1++){
         scanf("%d %d",&city_1[a1],&city_2[a1]);
      }
      if (y >= x)
      {
         printf("%d\n", x*n);
      }
      else{
         
      }
   }
   return 0;
}
