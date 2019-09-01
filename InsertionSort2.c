#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(int ar_size, int *  ar) {
   int temp;
   for (int i = 1; i < ar_size; ++i)
   {
      temp = ar[i];
      int j = i-1;
      while(j >= 0 && ar[j] > temp){
         ar[j+1] = ar[j];
         j--;
      }
      ar[j+1] = temp;
      for (int k = 0; k < ar_size; ++k)
      {
         printf("%d ", ar[k]);
      }
      printf("\n");
   }
}

int main(void) {
   
   int _ar_size;
   scanf("%d", &_ar_size);
   int _ar[_ar_size], _ar_i;
   for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
   scanf("%d", &_ar[_ar_i]); 
}

insertionSort(_ar_size, _ar);
   
    return 0;
}

