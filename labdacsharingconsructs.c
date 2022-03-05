#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
int i, a[100];
 #pragma omp parallel
{
#pragma omp for
for (i = 0; i < 10; i++)
{
a[i] = i * i * i;
}
#pragma omp for
for (i = 0; i < 10; i++) {
printf("a[%d]=%d\n", i, a[i]);
}
}
return 0;
}
