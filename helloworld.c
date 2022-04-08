#include <stdio.h> 
#include <mpi.h> 
 
 int main(int argc, char **argv) 
 { 
 int init, num_procs, my_id; 
 init = MPI_Init(&argc, &argv); 
 //process ID, num of processes which were started
 init = MPI_Comm_rank(MPI_COMM_WORLD, &my_id); 
 init = MPI_Comm_size(MPI_COMM_WORLD, &num_procs); 
 printf("Hello world! This is process %i printing this out of %i total processes\n", 
 my_id, num_procs); 
 init = MPI_Finalize(); 
 } 
