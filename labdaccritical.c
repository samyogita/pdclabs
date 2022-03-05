#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
int main()
{
 int i;
 int maximum;
 int a[SIZE];
 for (i = 0; i < SIZE; i++)
 {
 a[i] = rand();
 printf_s("%d\n", a[i]);
 }
 maximum = a[0];
 #pragma omp parallel for num_threads(7)
 for (i = 1; i < SIZE; i++)
 {
 if (a[i] > maximum)
 {
 #pragma omp critical
 {
 if (a[i] > maximum)
 maximum = a[i];
 }
 }
 }
 printf_s("max = %d\n", maximum);
}
