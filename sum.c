#include<stdio.h>
#include<omp.h>
#include<math.h>
int main()
{
double sum=0.0;
int number=50;
#pragma omp parallel for reduction(+:sum)
for(int i=0;i<10000;i++)
{
    sum = sum + 1/pow(number,i);
}
printf("Sum : %f",sum);
return 0;
}
