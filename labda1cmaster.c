#include <omp.h>
#include <stdio.h>
int main( )
{
 int a[15], i;
 #pragma omp parallel
 {
 #pragma omp for
 for (i = 0; i < 15; i++)
 a[i] = i * i;
 #pragma omp master
 for (i = 0; i < 15; i++)
 printf_s("a[%d] = %d\n", i, a[i]);
 #pragma omp barrier
 #pragma omp for
 for (i = 0; i < 15; i++)
 a[i] += i;
 }
}
