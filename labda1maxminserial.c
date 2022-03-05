#include<stdio.h>
int main()
{
   int a,b,c,min, max;
   a = 99;
   b = 50;
   c = 9;
    if(a>b && a>c)
        printf("Maximum number is a = %d \n",a);
    else if(b>a && b>c)
        printf("Maximum number is b = %d \n",b);
    else
        printf("Maximum number is c = %d \n",c);
    if(a<b && a<c)
        printf("Minimum number is a = %d \n",a);
    else if(b<a && b<c)
        printf("Minimum number is b = %d \n",b);
    else
        printf("Minimum number is c = %d \n",c);
return 0;
}
