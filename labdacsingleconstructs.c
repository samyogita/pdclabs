#include <stdio.h>
#include <omp.h>
int main() {
 #pragma omp parallel num_threads(2)
 {
 #pragma omp single
 // Only a single thread can read the input.
 printf_s("Read the input\n");
 // Multiple threads in the team compute the results.
 printf_s("Compute the results\n");
 #pragma omp single
 // Only a single thread can write the output.
 printf_s("Display the output\n");
 }
}
