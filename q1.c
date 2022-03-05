#include <omp.h>
#include <stdio.h>
int fib(int n)
{
    int i, j;
    if (n < 2)
        return n;
    else
    {
#pragma omp task shared(i)
        i = fib(n - 1);
#pragma omp task shared(j)
        j = fib(n - 2);
#pragma omp taskwait
        return i + j;
    }
}
int sum(int n)
{
    int i;
    if (n < 2)
        return n;
    else
    {
#pragma omp task shared(i)
        i = sum(n - 1);
#pragma omp taskwait
        return i + n;
    }
}
int main()
{
    int i = 0;
    omp_set_num_threads(2);
#pragma omp parallel private(i)
    if(omp_get_thread_num()==0){
#pragma omp for schedule(dynamic, 1)
        for (i = 1; i <= 20; i++)
        {
            printf("Sum upto %d: %d\n", i, sum(i));
        }
    }
    else{
        #pragma omp for schedule(dynamic, 1)
        for (i = 1; i <= 20; i++)
        {
            printf("Fibonacci upto %d: %d\n", i, fib(i));
        }
    }
    return 0;
}
