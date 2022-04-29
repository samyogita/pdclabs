#include<stdio.h>
#include<omp.h>
#include<math.h>
double factorial(int num)
{
    double factor=1.0;
    if(num<=1)
    {
        return 1;
    }
    else
    {
        while(num>=1)
        {
            factor=factor * num;
            num--;
        }
        return factor;
    }
}
int main()
{
double sum=0.0;
int x=10;
#pragma omp parallel for reduction(+:sum)
for(int i=0;i<100;i++)
{
    sum = sum + pow(x,i)/factorial(i);
}
printf("e^%d = %f",x,sum);
return 0;
}
