#include <stdio.h>
#include <omp.h>
#include <math.h>
#define N 20
int main()
{
int i;
int A[20]= {57, 46, 55, 72, 95, 71, 53, 2, 30, 27, 41, 50, 52, 32, 74, 90, 87, 92, 26, 88};
double start, end, total;
omp_set_num_threads(1);
    #pragma omp parallel shared (A)
{
start = omp_get_wtime();
printf("Array elements are:\n");
for(i=0;i<N;i++)
{
    printf("The element at position %d is: %d \t\n",i+1,A[i]);
}
end = omp_get_wtime();
total = end - start;
printf("\n");
printf("The total execution time for printing array elements is: %f", total);
printf("\n");
start = omp_get_wtime();
printf("\n");
printf("Multiplying the matrix with 3 and printing the resultant values\n");
printf("\n");
for (i = 0; i < N; i++)
{
printf("The element at position %d after multiplying is: %d \t\n",i+1,(3*A[i]));
}
end = omp_get_wtime();
total = end - start;
printf("\n");
printf("The execution time for multiplying and printing the elements of the array is: %f\n",total);
printf("\n");
start = omp_get_wtime();
int evensum=0, oddsum=0, totalsum=0;
for (int i = 0; i < N; i++)
{
if (A[i] % 2 == 0)
{
    evensum += A[i];
}
else
{
    oddsum += A[i];
}
}
totalsum = evensum + oddsum;
printf("\n");
printf("The total sum of the even numbers of the array is: %d\n",evensum);
printf("The total sum of the odd numbers of the array is: %d\n", oddsum);
printf("The total sum of the elements of the array is: %d\n", totalsum);
printf("\n");
end = omp_get_wtime();
total = end - start;
printf("\n");
printf("The total execution time for finding sum of the array elements is: %f", total);
printf("\n");
start = omp_get_wtime();
int evencount=0, oddcount = 0;
for (int i = 0; i < N; i++)
{
if (A[i] % 2 == 0)
{
    evencount += 1;
}
else
{
    oddcount += 1;
}
}

printf("\n");
printf("The total number of the even numbers of the array is: %d\n",evencount);
printf("The total number of the odd numbers of the array is: %d\n", oddcount);
printf("\n");
end = omp_get_wtime();
total = end - start;
printf("\n");
printf("The total execution time for counting array elements is: %f\n", total);
printf("\n");
start = omp_get_wtime();
int squaresum=0, cubesum=0,temp,temp1;
for (int i= 0; i < N;i++)
{
temp = 0;
temp1 = 0;
temp = A[i] * A[i];
temp1 = temp * A[i];
squaresum += temp;
cubesum += temp1;
}
printf("The total sum of square of array elements is: %d\n",squaresum);
printf("The total sum of cube of array elements is: %d\n",cubesum);
end = omp_get_wtime();
total = end - start;
printf("\n");
printf("The total execution time for finding the sum of squares and cubes of the array elements is: %f\n",total);
printf("\n");
start = omp_get_wtime();
int max,min;
max = A[0];
for (i = 1; i < N; i++)
{
if (A[i] > max)
{
max = A[i];
}
}
printf("\n");
printf("The maximum value of the array is: %d\n", max);
printf("\n");
min = A[0];
for (i = 1; i < N; i++)
{
if (A[i] < min)
{
min = A[i];
}
}
printf("\n");
printf("The minimum value of the array is: %d\n", min);
printf("\n");
end = omp_get_wtime();
total = end - start;
printf("\n");
printf("The total execution time for finding maximum and minimum array elements is: %f", total);
printf("\n");
printf("Prime Numbers:\n");
int count=0, sum=0;
for (i=0;i<N;i++) {
int flag = 0;
for (int j=2;j<=A[i]/2;j++) {
if(A[i]%j==0) {
flag = 1;
break;
}
}
if(flag==0 && A[i]>=2) {
printf("%d\n", A[i]);
count++;
sum += A[i];
}
 }
printf("Prime Count = %d\n", count);
printf("Sum of the prime numbers = %d\n", sum);
end = omp_get_wtime();
total = end - start;
printf("The execution time for finding, counting and adding prime numbers is %15.15f\n", total);
 start = omp_get_wtime();
 sum=(float) sum;
 float sum1=0;
 float mean, sd, v;
 for (i=0;i<N;i++) {
 sum += A[i];
 }
 mean = sum/ (float) N;
 printf("Mean = %.2f\n", mean);
 for (i = 0; i < N; i++)
 {
 sum1 = sum1 + pow((A[i] - mean), 2);
 }
 v = sum1 / (float) N;
 sd = sqrt(v);
 printf("Standard Deviation = %.2f\n", sd);
 printf("Variance = %.2f\n", v);
end = omp_get_wtime();
total = end - start;
printf("The execution time for finding Mean, SD and Variance is %15.15f\n",
total);
}
}
