#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
void sum(int);
void oddeven(int );
void prime(int);
void palindrome(int);
void main(void){
int n=1982;
int tid;
printf("The number is: %d",n);
printf("\n");
#pragma omp parallel shared(n) private(tid)
{
    tid=omp_get_thread_num();
    if(tid==0)
 {
    printf("\nOdd even is from thread number: %d\t\n",tid);
    oddeven(n);

 }
 else if(tid==1)
 {
    printf("\nSum is from thread no %d\t\n",tid);
    sum(n);

 }
 else if(tid==2)
 {
    printf("\nPalindrome is from thread no %d\t\n",tid);
    palindrome(n);

 }
 else if (tid==3){
    printf("\nPrime is from thread no %d\t\n",tid);
    prime(n);

 }
}
}
void sum(int n){
 int s=0;
 int r=0;
 while(n>0){
 r=n%10;
 s=s+r;
 n=n/10;
 }
 printf("\nThe sum of digits is: %d\n",s);
 printf("\n");
}

void oddeven(int n){
 int co=0;
 int ce=0;
 int so=0;
 int se=0;
 int r=0;
 while(n>0){
 r=n%10;
 if(r%2==0){
 ce++;
 se=se+r;
 }
 else{
 co++;
 so=so+r;
 }
 n=n/10;
 }
 printf("\nNumber of odd digits: %d\n",co);
 printf("\nNumber of even digits: %d\n",ce);
 printf("\nSum of odd digits: %d\n",so);
 printf("\nSum of even digits: %d\n",se);
 printf("\n");
}

void prime(int n){
 int flag=0;
 if(n==0 || n==1){
 flag=1;
 }
 for(int i=2;i<n/2;i++){
 if(n%i==0){
 flag=1;
 break;
 }
 }
 if(flag==1){
 printf("\nThe number is not prime \n");
 printf("\n");
 }
 else{
 printf("\nThe number is prime \n");
 printf("\n");
 }
}
void palindrome(int n){
 int original =n;
 int s=0;
 int r=0;
 while(n!=0){
 r=n%10;
 s=s*10+r;
 n=n/10;
 }
 if(s==original){
 printf("\nThe number is palindrome\n");
 printf("\n");
 }
 else{
 printf("\nThe number is not palindrome \n");
 printf("\n");
 }
}
