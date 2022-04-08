#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<omp.h> 
#define PI 3.1415926538837211 
int main() 
{ 
int intervals, i; 
float sum, x, total_sum, h, partial_sum, sum_thread; 
printf("Enter the number of intervals you want: \n"); 
scanf("%d", &intervals); 
if (intervals <= 0) { 
printf("The number of intervals can't be a negative integer\n"); 
exit(1); 
} 
sum = 0.0; 
h = 1.0 / intervals; 
#pragma omp parallel for private(x) shared(sumthread) 
for (i = 1; i < intervals + 1; i = i + 1) { 
 x = h * (i - 0.5); 
#pragma omp critical 
sum_thread = sum_thread + 4.0 / (1 + x * x); 
} 
partial_sum = sum_thread * h; 
#pragma omp critical 
sum = sum + partial_sum; 
printf("The value of PI is: %f \n The error is: S%1.16f\n", sum, fabs(sum - PI)); 
} 
