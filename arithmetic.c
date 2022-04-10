#include <mpi.h>
#include<stdio.h>
int main(int argc, char **argv)
{
int pid,a,b,c,add,sub,mul,mod,c5,c6;
a=10;
b=0;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD, &pid);
if( pid == 0 ) {
add=a+b;
}
else if( pid == 1 ) {
sub=a-b;
}
else if( pid == 2 ) {
mul=a*b;
}
else if( pid==3){
mod=a%b;
}
else if(pid==4){
c5= a>b;
}
else{
c6=a<b;
}
printf("The addition of two numbers %d and %d is: %d \n",a,b,add);
printf("The subtraction of two numbers %d and %d is: %d \n",a,b,sub);
printf("The multiplication of two numbers %d and %d is: %d \n",a,b,mul);
printf("The modulo of two numbers %d and %d is: %d \n",a,b,mod);
MPI_Finalize();
return 0;
}

