#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int BinarySearch(int ar[], int p, int q, int v)
{
   int m = (p + q)/2;
   if (ar[m] == v)
      return m;
   else if (ar[m] > v)
      return BinarySearch(ar, p, m-1, v);
   else
      return BinarySearch(ar, m+1, q, v);
}

int main() {
   int v, n;
   scanf("%d %d", &v, &n);
   int ar[n];
   for (int i = 0; i < n; ++i)
   {
      scanf("%d", &ar[i]);
   }
   printf("%d", BinarySearch(ar, 0, n-1, v));
   return 0;
}
