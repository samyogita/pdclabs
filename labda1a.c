#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char** argv){
int i,thread_id,j,k,l;
double start,end,time;
start = omp_get_wtime();
i = omp_get_num_procs();
//To get no of processor
printf("Number of processor is: %d\n",i);
//To get the Maximum thread number and Number of threads
#pragma omp parallel
{
j = omp_get_max_threads();
k = omp_get_num_threads();
}
printf("Maximum threads: %d Number of threads: %d\n",j,k);
#pragma omp parallel
{
thread_id = omp_get_thread_num();
//To get thread number
printf("Thread num is: %d\n",thread_id);
}
//To set number of thread
omp_set_num_threads(10);
#pragma omp parallel
{
l=omp_get_num_threads();
}
printf("Number of threads now is: %d\n",l);
//To get the time for the given computation
end=omp_get_wtime();
time=end-start;
printf("Time for computation is: %f\n",time);
}
