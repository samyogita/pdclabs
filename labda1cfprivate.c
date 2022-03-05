#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(void){
int i;
int shared_var;
shared_var=100;
#pragma omp parallel for firstprivate(shared_var)
for(i=0;i<=10;i++){
shared_var=i;
printf("The thread number is: %d shared_var: %d\n",
       omp_get_thread_num(),shared_var);
}
printf("shared_var is %d\n", shared_var);
}
