
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include <omp.h>

#define ARRAY_SIZE 10
#define NUM_THREADS 3

int main (int argc, char *argv[])
{
	int * x;
	int * y;
	int * z;
    double start,end;
    double total;
    int n = ARRAY_SIZE;
	int n_per_thread;
	int total_threads = NUM_THREADS;
	int i;
    x = (int *) malloc(sizeof(int)*n);
	y = (int *) malloc(sizeof(int)*n);
	z = (int *) malloc(sizeof(int)*n);

    start=omp_get_wtime();
        for(i=0; i<n; i++) {
            x[i] = i;
        }
        for(i=0; i<n; i++) {
            y[i] =  rand()%10;
        }
	omp_set_num_threads(total_threads);

	n_per_thread = n/total_threads;

	#pragma omp parallel for shared(x, y, z) private(i) schedule(static, n_per_thread)
        for(i=0; i<n; i++) {
		z[i] = x[i]+y[i];
		printf("The thread %d is working on the element: %d \n", omp_get_thread_num(), i);
        }

	printf("i\tx[i]\t+\ty[i]\t=\tz[i]\n");
        for(i=0; i<n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\n", i, x[i], y[i], z[i]);
        }

        end=omp_get_wtime();
        total=start - end;
        printf("Total time required for execution is %lf \n  ",total);


        free(x);  free(y); free(z);

	return 0;
}
