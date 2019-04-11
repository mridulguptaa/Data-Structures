#include<stdio.h>
#include<stdlib.h>

int fibo(int n,int a,int b)
{   if(n==1)
    return 0;

    while(n!=1)
    {
        printf("%d",a+b);
        fibo(n-1,b,a+b);
        return 0;
    }
    return 0;
}


int main()
{
    int n,fac,a=1,b=1,sum;;
    scanf("%d",&n);
    printf("1 1");
    fibo(n-1,a,b);



}
