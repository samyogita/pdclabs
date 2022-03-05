#include <stdio.h>
#include<omp.h>
int addNumbers(int n);

int main() {
  int n;
  int num;
  printf("Enter a positive integer: ");
  scanf("%d", &num);

 omp_set_num_threads(omp_get_num_procs());

        #pragma omp parallel private(n)
        {
                #pragma omp for schedule(dynamic, 1)
                for (n = 0; n <= num; n++) {
                        printf("Sum of %d numbers is %d \n", n, addNumbers(n));
                }

        }
        return 0;
}

int addNumbers(int n) {
  if (n != 0)
    return n + addNumbers(n - 1);
  else
    return n;
}
