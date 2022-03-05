#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
int a = 60, b = 10, x, y, i, j;
float h;
#pragma omp parallel
{
#pragma omp sections
{
#pragma omp section
{
x = a + b;
printf("Adding two numbers:%d\n", x);
}
#pragma omp section
{
i = a * b;
printf("Multiplying two numbers:%d\n", i);
}
#pragma omp section
{
y = a - b;
printf("Subtracting two numbers:%d\n", y);
}

#pragma omp section
{
h = (float)a / b;
printf("Quotient:%f\n", h);
}
#pragma omp section
{
j = a % b;
printf("Reminder of two numbers:%d\n", j);
}
}
}
return 0;
}
