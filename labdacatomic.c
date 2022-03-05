#include <stdio.h>
#include <omp.h>
#define MAX 15
int main() {
 int c = 0;
 #pragma omp parallel num_threads(MAX)
 {
 #pragma omp atomic
 c++;
 }
 printf_s("The number of threads: %d\n", c);
}
