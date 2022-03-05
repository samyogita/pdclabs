#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char** argv){
int a,b,c,tid;
a=99;
b=50;
c=9;
omp_set_num_threads(2);
#pragma omp parallel shared(a,b,c) private (tid)
{
tid=omp_get_thread_num();
//Calculate maximum number
if(tid==0){
if (a>b && a>c){
printf("The greatest number is: %d from thread: %d\n",a,tid);
}
else if(b>a && b>c){
printf("The greatest number is: %d from thread: %d\n",b,tid);
}
else{
printf("The greatest number is: %d from thread: %d\n",c,tid);
}
}
//Calculate minimum number
else if(tid==1){
if (a<b && a<c){
printf("The smallest number is: %d from thread: %d\n",a,tid);
}
else if(b<a && b<c){
printf("The smallest number is: %d from thread: %d\n",b,tid);
}
else{
printf("The smallest number is: %d from thread: %d\n",c,tid);
}
}
}
}
